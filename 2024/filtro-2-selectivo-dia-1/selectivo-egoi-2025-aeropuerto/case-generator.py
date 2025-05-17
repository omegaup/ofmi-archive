import os
import random
from typing import List

sample_case_names = [
    "sub1.sample",
    "sub2.sample",
    "sub1.extra1",
    "sub1.extra2",
    "sub2.extra",
    "sub4.extra"
]
n_limit = [10, 10**4, 10**4, 10**4]
m_limit = [50, 2 * 10**4, 2 * 10**4, 2 * 10**4]
x_limit = [10, 10, 2, 10]
case_count = [8, 10, 15, 17]
case_score = [23, 13, 23, 41]
subtasks = 4


def coin_toss(p: float = 0.5):
    return random.random() < p


def generate_Ns(subtask: int):
    start, end = 1000 if subtask else 4, n_limit[subtask]
    Ns = random.sample(range(start + 1, end), case_count[subtask] - 3)
    return [start] + sorted(Ns) + [end] * 2


def get_complement_list(elements: List[int], n: int):
    complement = []
    for a in range(1, n + 1):
        if a not in elements:
            complement.append(a)
    random.shuffle(complement)
    return complement


def generate_consecutive_edges(nodes: List[int], available_Xs: List[int]):
    edges = []
    for i in range(len(nodes) - 1):
        x = (available_Xs[i] if i < len(available_Xs)
             else random.choice(available_Xs))
        edges.append((nodes[i], nodes[i + 1], x))
    return edges


def generate_case_edges(n: int, subtask: int, is_connected: bool):
    all_Xs = list(range(1, x_limit[subtask] + 1))
    edges = []

    if subtask == 1:
        if is_connected:
            some_Xs = random.sample(
                all_Xs, random.randint(1, x_limit[subtask]))
            other_Xs = get_complement_list(some_Xs, x_limit[subtask])
            other_Xs = all_Xs if not other_Xs else other_Xs

            connected_to_1 = random.sample(range(2, n), n // 2 - 2)
            k = random.randint(0, len(connected_to_1))

            edges += generate_consecutive_edges(
                [1] + connected_to_1[:k] + [n], some_Xs)
            edges += generate_consecutive_edges(
                [n] + connected_to_1[k:] + [1], other_Xs)

            not_connected_to_1 = get_complement_list(
                connected_to_1 + [1, n], n)
            edges += generate_consecutive_edges(
                not_connected_to_1 + [not_connected_to_1[0]], all_Xs)
        else:
            connected_to_1 = [1] + random.sample(range(2, n), n // 2 - 1)
            edges += generate_consecutive_edges(
                connected_to_1 + [connected_to_1[0]], all_Xs)

            connected_to_n = get_complement_list(connected_to_1, n)
            edges += generate_consecutive_edges(
                connected_to_n + [connected_to_n[0]], all_Xs)
    else:
        if is_connected:
            some_Xs = random.sample(
                all_Xs, random.randint(1, min(n - 1, x_limit[subtask])))
            print(f"Possible X_i values: {some_Xs}")

            path = random.sample(
                range(2, n), random.randint(len(some_Xs) - 1, n - 2))
            edges += generate_consecutive_edges([1] + path + [n], some_Xs)

            m = (m_limit[subtask] - len(edges) if n == n_limit[subtask]
                 else random.randint(0, m_limit[subtask] - len(edges)))

            for _ in range(m):
                (u, v) = random.sample(range(1, n + 1), 2)
                u = random.randint(2, n - 1) if u == 1 and v == n else u
                v = random.randint(2, n - 1) if u == n and v == 1 else v
                edges.append((u, v, random.randint(1, x_limit[subtask])))
        else:
            connected_to_1 = [1] + random.sample(range(2, n), n // 2 - 1)
            connected_to_n = get_complement_list(connected_to_1, n)

            for _ in range(random.randint(1, m_limit[subtask])):
                (u, v) = random.sample(
                    connected_to_1 if coin_toss() else connected_to_n, 2)
                edges.append((u, v, random.randint(1, x_limit[subtask])))

    random.shuffle(edges)
    return edges


def generate_case_string(n: int, subtask: int, is_connected: bool):
    edges = generate_case_edges(n, subtask, is_connected)
    edges_str = '\n'.join([f"{u} {v} {x}" for u, v, x in edges])
    return f"{n} {len(edges)}\n{edges_str}\n"


def get_case_name(subtask: int, case_num: int):
    return f"sub{subtask}.{case_num}"


if __name__ == "__main__":
    assert len(sample_case_names) == len(set(sample_case_names))
    assert subtasks == len(case_count) == len(case_score)
    assert sum(case_score) == 100

    random.seed("random, crea unos casos buenazos")

    # Write testplan
    with open("testplan", "w", encoding="utf-8", newline="\n") as testplan:
        for case_name in sample_case_names:
            testplan.write(f"{case_name} 0\n")

        for sub in range(subtasks):
            case_name = get_case_name(sub + 1, 0)
            assert case_name not in sample_case_names
            testplan.write(f"{case_name} {case_score[sub]}\n")

            for case_number in range(1, case_count[sub]):
                case_filename = get_case_name(sub + 1, case_number)
                assert case_filename not in sample_case_names
                testplan.write(f"{case_filename} 0\n")

    # Write cases
    for sub in range(subtasks):
        subtask_Ns = generate_Ns(sub)

        for case_number in range(case_count[sub]):
            case_name = get_case_name(sub + 1, case_number)
            print(f"Generating case #{case_number} for subtask {sub + 1}")
            case_str = generate_case_string(
                subtask_Ns[case_number], sub, case_number > 2)
            case_path = os.path.join("cases", f"{case_name}.in")
            with open(case_path, "w", encoding="utf-8", newline="\n") as case:
                case.write(case_str)

    print("The cases have been generated")
