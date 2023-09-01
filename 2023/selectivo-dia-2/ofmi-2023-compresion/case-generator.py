import os
import random

base_string = """
{n} {m}
{arr}
""".strip(" \t\n\r")

puntos_por_subtarea = [15, 15, 20, 50]
casos_por_subtarea = [10, 10, 15, 20]
sample_case_names = ['sub3.sample']

num_subtareas = len(puntos_por_subtarea)
subtarea_agrupada = [True for _ in range(num_subtareas)]


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


def generate_custom_ans(n, m, max_ai):
    # Queremos que la respuesta sea un numero fijo entre 0 y n
    middle = random.randint(m, n)
    left = random.randint(0, n - middle)
    rigth = n - middle - left

    lower = random.randint(0, max_ai)
    upper = random.randint(0, max_ai)
    if lower > upper:
        lower, upper = upper, lower
    left_arr = [random.randint(0, lower) for _ in range(left)]
    rigth_arr = [random.randint(upper, max_ai) for _ in range(rigth)]
    middle_arr = []
    middle_arr_set = set([])
    while len(middle_arr) < middle:
        new_element = random.randint(lower, upper)
        if len(middle_arr_set) >= m:
            new_element = random.choice(middle_arr)
        middle_arr.append(new_element)
        middle_arr_set.add(new_element)

    return left_arr + middle_arr + rigth_arr


def generate_case(subtarea, case_number):
    max_n = 3 * (10**5) if subtarea != 3 else 1000
    max_ai = power_incremental(subtarea, case_number, 10**9)
    n = random.randint(1, max(1, power_incremental(
        subtarea, case_number, max_n, 4 if max_n != 1000 else 2)))

    if case_number + 1 == casos_por_subtarea[subtarea - 1]:
        n = max_n

    m = random.randint(1, n)
    if subtarea == 1:
        m = 1

    if random.randint(0, 3) == 0:
        arr = generate_custom_ans(n, m, max_ai)
    else:
        arr = [random.randint(0, max_ai) for _ in range(n)]

    if subtarea == 2:
        # Todos los valores de A son distintos
        arr = list(set(arr))
        n = len(arr)
        if m > n:
            m = random.randint(1, n)

    random.shuffle(arr)

    print(f"Subtarea {subtarea}, caso {case_number}: n={n}, m={m}")
    print(f"numeros distintos: {len(set(arr))}")

    return {
        'n': n,
        'm': m,
        'arr': ' '.join(map(str, arr)),
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
