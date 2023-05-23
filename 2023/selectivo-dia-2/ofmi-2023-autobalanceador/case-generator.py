import os
import random
import math

base_string = """
{N}
{S}
""".strip(" \t\n\r")

num_subtareas = 4
puntos_por_subtarea = [15, 25, 30, 30]
casos_por_subtarea = [10, 10, 15, 15]
subtarea_agrupada = [True for _ in range(num_subtareas)]
already_generated = [
    'sub4.sample',
    'sub1.10',
    'sub2.10',
    'sub2.11',
    'sub4.15',
    'sub4.16',
    'sub4.17',
]


def random_balanced_brackets(n):
    if n == 0:
        return ""
    if n & 1:
        raise "n is odd, could not generate random balanced brackets"
    pairs = n // 2
    k = random.randint(0, pairs - 1)
    return "(" \
        + random_balanced_brackets(k * 2) \
        + ")" \
        + random_balanced_brackets((pairs - 1 - k) * 2)


def generate_case(subtarea, case_number):
    max_n = power_incremental(subtarea, case_number, 10**5)
    n = random.randint(1, max_n)
    if case_number > 8:
        n = random.randint(n, max_n)
    if subtarea != 3 and random.randint(0, 8) == 0:
        # make n odd
        n = n ^ (n & 1) ^ 1
        s = random_balanced_brackets(n + 1)
        # remove one random element
        idx = random.randint(0, n)
        s = s[:idx] + s[idx+1:]
    else:
        # Make n even
        n = n ^ (n & 1)
        if n == 0:
            n = 2
        s = random_balanced_brackets(n)

    # Vamos a desbalancearlos un poquito los casos
    should_make_unbalanced = (random.randint(0, 8) == 0)
    if subtarea == 1:
        should_make_unbalanced = (random.randint(0, 1) == 0)
    elif subtarea == 3:
        should_make_unbalanced = False

    s_copy = list(c for c in s)
    if should_make_unbalanced:
        changes = random.randint(1, random.randint(1, n))
        for _ in range(changes):
            idx = random.randint(0, n - 1)
            if random.randint(0, 1) == 0:
                s_copy[idx] = '('
            else:
                s_copy[idx] = ')'

    # Insertar el caracter mágico
    positions = [idx for idx, c in enumerate(s_copy) if c == ')']
    k = random.randint(
        0, len(positions) // random.randint(1, int(math.sqrt(len(positions)))))
    if subtarea == 1:
        k = 0
    elif subtarea == 2:
        k = 1
    while k > 0:
        k -= 1
        idx = random.choice(positions)
        if s_copy[idx] != ')':
            continue
        s_copy[idx] = ']'
        while random.randint(0, 2) and idx < n - 1 and s_copy[idx + 1] == ')':
            idx += 1
            s_copy[idx] = '*'
            k -= 1

    # Compress
    s = ''.join(c for c in s_copy if c != '*')
    n = len(s)

    return {
        'N': n,
        'S': s,
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
    assert len(already_generated) == len(set(already_generated))
    with open('testplan', 'w') as f:
        for case_name in already_generated:
            f.write(f'{case_name} 0\n')

    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_points = get_case_points(subtarea, case_number)
            assert case_name not in already_generated
            with open('testplan', 'a') as f:
                f.write(f'{case_name} {case_points}\n')


def write_cases():
    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_path = os.path.join('cases', case_name)
            with open(f'{case_path}.in', 'w') as f:
                case = generate_case(subtarea, case_number)
                case_string = base_string.format(**case)
                f.write(f'{case_string}\n')


def main():
    random.seed(748121)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    write_testplan()
    write_cases()


if __name__ == '__main__':
    main()
