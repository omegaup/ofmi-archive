import os
import random

base_string = """
{N}
{X}
{V}
""".strip(" \t\n\r")

num_subtareas = 5
puntos_por_subtarea = [10, 15, 10, 15, 50]
casos_por_subtarea = [10, 15, 15, 15, 25]
subtarea_agrupada = [True for _ in range(num_subtareas)]
sample_case_names = ['sub5.sample']
already_generated = [2, 3, 0, 4, 0]


def generate_case(subtarea, case_number):
    max_n = linear_incremental(subtarea, case_number,
                               50000 if subtarea != 4 else 1000)
    n = random.randint(1, max_n)
    if subtarea == 1:
        n = 2
    elif subtarea == 2:
        n = 3

    if random.randint(0, 1) == 0:
        xi_max = power_incremental(subtarea, case_number, 10**9)
    else:
        xi_max = linear_incremental(subtarea, case_number, 10**9)

    if random.randint(0, 1) == 0:
        vi_max = power_incremental(subtarea, case_number, 10**9)
    else:
        vi_max = linear_incremental(subtarea, case_number, 10**9)

    X = [random.randint(1, xi_max) for _ in range(n)]

    if subtarea == 3:
        r = random.randint(1, vi_max)
        V = [r for _ in range(n)]
    else:
        V = [random.randint(1, vi_max) for _ in range(n)]

    return {
        'N': n,
        'X': ' '.join(map(str, X)),
        'V': ' '.join(map(str, V)),
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
            if case_number < already_generated[subtarea - 1]:
                continue
            case_name = get_case_name(subtarea, case_number)
            case_path = os.path.join('cases', case_name)
            with open(f'{case_path}.in', 'w') as f:
                case = generate_case(subtarea, case_number)
                case_string = base_string.format(**case)
                f.write(f'{case_string}\n')


def main():
    random.seed(748121)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == '__main__':
    main()
