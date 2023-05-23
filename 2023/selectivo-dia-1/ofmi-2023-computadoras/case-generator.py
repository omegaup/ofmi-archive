import os
import random

base_string = """
{N}
{arr}
""".strip(" \t\n\r")

num_subtareas = 4
puntos_por_subtarea = [15, 25, 40, 20]
casos_por_subtarea = [15, 15, 25, 25]
subtarea_agrupada = [True for _ in range(num_subtareas)]
sample_case_names = ['sub1.sample', 'sub1.15']


def generate_case(subtarea, case_number):
    max_n = linear_incremental(
        subtarea, case_number, 5000) if subtarea != 1 else 10
    n = random.randint(1, max_n)

    maxai = power_incremental(subtarea, case_number, 10**6)
    P = [random.randint(1, maxai) for _ in range(n + 1)]
    M = [random.randint(1, maxai) for _ in range(n + 1)]

    if subtarea in [2, 3]:
        # Los valores de P son distintos
        P = list(set(P))
        M = M[:len(P)]
        n = len(P) - 1

    # Inject some sortedness to avoid 0 as output
    m = random.randint(1, n + 1)
    P[:m] = sorted(P[:m])
    M[:m] = sorted(M[:m])

    if subtarea == 2:
        # p y m son los mínimos
        for i in range(1, n + 1):
            if P[i] < P[0]:
                P[i], P[0] = P[0], P[i]
                M[i], M[0] = M[0], M[i]

        # Asegurate que M[i] sea el minimo también
        min_m = min(M[1:])
        if M[0] >= min_m:
            M[0] = min_m
            for i in range(1, n + 1):
                if M[i] == min_m:
                    M[i] = min_m + 1

    # Shuffle the rest
    p = P[0]
    m = M[0]
    P = P[1:]
    M = M[1:]

    random.shuffle(P)
    random.shuffle(M)
    n = len(P)
    assert len(P) == len(M)

    # Reinsert the first element
    P = [p] + P
    M = [m] + M

    lines = [f'{p} {m}' for p, m in zip(P, M)]
    return {
        'N': n,
        'arr': '\n'.join(line for line in lines),
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
                case_string = base_string.format(**case)
                f.write(f'{case_string}\n')


def main():
    random.seed(348101)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == '__main__':
    main()
