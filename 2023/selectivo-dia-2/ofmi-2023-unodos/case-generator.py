import os
import random

base_string = """
{N} {M}
{edges}
""".strip(" \t\n\r")

num_subtareas = 5
puntos_por_subtarea = [10, 5, 15, 20, 50]
casos_por_subtarea = [10, 7, 10, 8, 15]
subtarea_agrupada = [True for _ in range(num_subtareas)]
sample_case_names = ['sub1.sample']


# We will do Prufer Code into Labeled Tree
# https://en.wikipedia.org/wiki/Pr%C3%BCfer_sequence
def generate_random_tree(N):
    if N == 1:
        return []
    prufer_code = [random.randint(1, N) for _ in range(N - 2)]

    # For each node set its degree to the number of times it appears in
    # the prufer code plus one
    degree = {node: 1 for node in range(1, N + 1)}
    for node in prufer_code:
        degree[node] += 1

    # Lets keep the leaves
    leaves = set({})
    for node in range(1, N + 1):
        if degree[node] == 1:
            leaves.add(node)

    # For each number u in the prufer code, find the first node
    # (lowest-numbered) v with degree 1 and add an edge between them.
    # Then decrease the degrees of u and v by one.
    edges = []
    for u in prufer_code:
        # Find the first node (lowest-numbered) v with degree 1 (leaf)
        v = leaves.pop()  # Remove the leaf since we will add an edge to it
        edges.append((u, v))
        degree[u] -= 1
        degree[v] -= 1
        if degree[u] == 1:
            leaves.add(u)

    # At the end of this loop two nodes with degree 1 will remain, connect them
    u, v = leaves
    edges.append((u, v))

    return edges


def generate_base_tree(n, weights, subtarea):
    if subtarea == 4:
        # We want a line
        edges = [(i, i + 1) for i in range(1, n)]
    else:
        edges = generate_random_tree(n)

    e = set(edges)
    edges = [(u, v, random.choice(weights)) for u, v in e]
    return e, edges


def generate_random_graph(n, max_m, subtarea):
    allow_odd_cycles = subtarea != 4 and random.randint(0, 4) == 0
    allow_even_cycles = subtarea != 4
    allow_self_loops = subtarea != 4 and random.randint(0, 10) == 0
    should_generate_invalid = random.randint(0, 9) == 0
    weights = [2, 4] if subtarea != 2 else [2]

    e, edges = generate_base_tree(n, weights, subtarea)

    # Lets assign some values to the nodes
    adj = {node: [] for node in range(1, n + 1)}
    for u, v, t in edges:
        adj[u].append((v, t))
        adj[v].append((u, t))
    values = {1: 0}
    level = {1: 0}
    q = [1]
    while len(q) > 0:
        nodo = q.pop()
        for v, t in adj[nodo]:
            if v not in values:
                values[v] = t - values[nodo]
                level[v] = level[nodo] + 1
                q.append(v)

    # Lets add more edges
    has_added_odd_cycle = False
    for _ in range(max_m):
        u = random.randint(1, n)
        v = random.randint(1, n)
        if ((u, v) in e) or ((v, u) in e):
            # Already added
            continue

        if not allow_self_loops and u == v:
            # Self loop not allowed
            continue

        # Lets check if we can add this edge
        if (level[u] & 1) == (level[v] & 1):
            # It is an odd cycle
            if not allow_odd_cycles:
                continue

            # Odd cycles could change the sum of the values of u and v
            if has_added_odd_cycle:
                # We already added an odd cycle, so we can not change
                # the sum of the values again. Inserting if possible
                if values[u] + values[v] in [2, 4] or should_generate_invalid:
                    # Add the edge
                    e.add((u, v))
                    t = random.choice(weights) \
                        if should_generate_invalid else values[u] + values[v]
                    edges.append((u, v, t))
            else:
                t = random.choice(weights)
                # Insert new edge and change the the values so that
                # the sum of the values of u and v is t
                # if I added x to u, I need to add x to v
                # So values[u] + values[v] + 2x = t
                # => x = (t - values[u] - values[v]) / 2
                x = (t - values[u] - values[v]) // 2
                for node in values:
                    if (level[node] & 1) == (level[u] & 1):
                        # I will be adding x to this node
                        values[node] += x
                    else:
                        # I will be subtracting x to this node
                        values[node] -= x
                # Add the edge
                e.add((u, v))
                edges.append((u, v, t))

                has_added_odd_cycle = True
        else:
            # It is an even cycle
            if not allow_even_cycles:
                continue
            # Even cycles could not change the sum of the values of u and v
            # So just adding if possible
            if values[u] + values[v] in [2, 4]:
                # Add the edge
                e.add((u, v))
                edges.append((u, v, values[u] + values[v]))

    return edges


def generate_case(subtarea, case_number):
    if subtarea == 1:
        max_n = 5
        max_m = 14
    else:
        max_n = power_incremental(subtarea, case_number, 10**5, 3)
        max_m = power_incremental(subtarea, case_number, 2*(10**5), 3)

    if case_number + 1 == casos_por_subtarea[subtarea - 1]:
        n = max_n
    else:
        n = random.randint(1, max(1, max_n))
        if subtarea == 1:
            n = random.randint(n, max_n)

    edges = []
    # Lets generate components
    n_copy = n
    while n_copy > 0:
        cmp_n = random.randint(1, n_copy)
        if subtarea == 1:
            cmp_n = random.randint(cmp_n, n_copy)
        cmp_max_m = max_m // cmp_n
        cmp_edges = generate_random_graph(cmp_n, cmp_max_m, subtarea)

        # We need to shift the nodes of the component
        # so that they are not connected to the previous component
        for i, (u, v, t) in enumerate(cmp_edges):
            cmp_edges[i] = (u + n - n_copy, v + n - n_copy, t)

        edges.extend(cmp_edges)
        n_copy -= cmp_n

    # We re label the nodes of the component
    # and divide the weights by 2
    p = random.sample(range(1, n + 1), n)
    for i, (u, v, t) in enumerate(edges):
        edges[i] = (p[u - 1], p[v - 1], t // 2)

    return {
        'N': n,
        'M': len(edges),
        'edges': '\n'.join(f'{u} {v} {t}' for u, v, t in edges)
    }


# This helper function will generate a number that is linearly increasing
# with the case number. This is useful to make cases bigger as the case_number
def linear_incremental(subtarea, case_number, max_number):
    casos_subtarea = casos_por_subtarea[subtarea - 1]
    # pendiente * casos_subtarea = max_number
    pendiente = max_number // casos_subtarea
    return pendiente * (case_number + 1)


# This helper function will generate a number that is k-power increasing
# with the case number. This is useful to make cases bigger as the case_number
def power_incremental(subtarea, case_number, max_number, k=4):
    casos_subtarea = casos_por_subtarea[subtarea - 1]
    # c* casos_subtarea^4 = max_number
    c = max_number / (casos_subtarea**k)
    return int(c * (case_number + 1) ** k)


def get_case_name(subtarea, case_number):
    agrupados = subtarea_agrupada[subtarea - 1]
    if agrupados:
        return f"sub{subtarea}.{case_number}"
    return f"sub{subtarea}_{subtarea}.{case_number}"


def get_case_points(subtarea, case_number):
    puntos_subtarea = puntos_por_subtarea[subtarea - 1]
    casos_subtarea = casos_por_subtarea[subtarea - 1]
    agrupados = subtarea_agrupada[subtarea - 1]
    if agrupados:
        return puntos_subtarea if case_number == 0 else 0
    return puntos_subtarea // casos_subtarea + (
        1 if puntos_subtarea % casos_subtarea > case_number else 0)


def write_testplan():
    assert len(sample_case_names) == len(set(sample_case_names))
    with open('testplan', 'w') as f:
        for case_name in sample_case_names:
            f.write(f'{case_name} 0\n')

    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_points = get_case_points(subtarea, case_number)
            assert case_name not in sample_case_names
            with open('testplan', 'a') as f:
                f.write(f'{case_name} {case_points}\n')


def write_cases():
    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_path = os.path.join('cases', case_name)
            with open(f'{case_path}.in', 'w') as f:
                case = generate_case(subtarea, case_number)
                case_string = base_string.format(**case).strip(" \t\n\r")
                f.write(f'{case_string}\n')


def main():
    random.seed(896664)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == '__main__':
    main()
