import os
import random

base_string = """
{N}
{arr}
""".strip(" \t\n\r")

num_subtareas = 4
puntos_por_subtarea = [20, 20, 15, 45]
casos_por_subtarea = [10, 10, 10, 20]
subtarea_agrupada = [True for _ in range(num_subtareas)]
sample_case_names = ['sub2.sample']


def generate_random_array(n, min_ai, max_ai):
    return [random.randint(min_ai, max_ai) for _ in range(n)]


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


def generate_case(subtarea, case_number):
    max_n = 10 ** 4
    max_ai = 10 ** 9
    if subtarea == 1:
        n = 2
    elif subtarea == 2:
        n = 3
    else:
        n = random.randint(2, linear_incremental(subtarea, case_number, max_n))

    max_ai_caso = random.randint(
        0, power_incremental(subtarea, case_number, max_ai))

    arr = generate_random_array(n, -max_ai_caso, max_ai_caso)
    return {
        'N': n,
        'arr': ' '.join(map(str, arr))
    }


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
                case_string = base_string.format(**case)
                f.write(f'{case_string}\n')


def main():
    random.seed(348101)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    write_testplan()
    write_cases()


if __name__ == '__main__':
    main()
