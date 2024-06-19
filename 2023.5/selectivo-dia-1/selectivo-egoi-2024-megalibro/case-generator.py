import os
import random

base_string = """
{N} {M}
{mat}
""".strip(" \t\n\r")

num_subtareas = 5
puntos_por_subtarea = [10, 18, 14, 30, 28]
casos_por_subtarea = [3, 4, 3, 6, 6]
orden_de_subtarea = [4, 1, 2, 3, 5]
subtarea_agrupada = [True for _ in range(num_subtareas)]
sample_case_names = ["1_sub2.sample", "1_sub2.sample2"]


def generate_case(subtarea):
    if subtarea == 1:
        MAX_N = 2*10**5
        MAX_A = 10**9
        n = random.randint(1, MAX_N)
        k = random.randint(1, n)
        A = random.randint(1, MAX_A)
        a = [A for _ in range(n)]

    if subtarea == 2:
        MAX_N = 20
        MAX_A = 10**9
        n = random.randint(1, MAX_N)
        k = random.randint(1, n)
        a = [random.randint(1, MAX_A) for _ in range(n)]

    if subtarea == 3:
        MAX_N = 2*10**5
        MAX_A = 10**9
        n = random.randint(1, MAX_N)
        k = 1
        a = [random.randint(1, MAX_A) for _ in range(n)]

    if subtarea == 4:
        MAX_N = 2*10**5
        MAX_A = 10**9
        n = random.randint(1, MAX_N)
        k = random.randint(1, 100)
        a = [random.randint(1, MAX_A) for _ in range(n)]

    if subtarea == 5:
        MAX_N = 2*10**5
        MAX_A = 10**9
        n = random.randint(1, MAX_N)
        k = random.randint(1, n)
        a = [random.randint(1, MAX_A) for _ in range(n)]

    res = {
        "N": n,
        "M": k,
        "mat": " ".join(str(x) for x in a),
    }
    return res


def get_case_name(subtarea, case_number):
    agrupados = subtarea_agrupada[subtarea - 1]
    orden = orden_de_subtarea[subtarea - 1]
    if agrupados:
        return f"{orden}_sub{subtarea}.{case_number}"
    return f"sub{subtarea}_{case_number}"


def get_case_points(subtarea, case_number):
    puntos_subtarea = puntos_por_subtarea[subtarea - 1]
    casos_subtarea = casos_por_subtarea[subtarea - 1]
    agrupados = subtarea_agrupada[subtarea - 1]
    if agrupados:
        return puntos_subtarea if case_number == 0 else 0
    return puntos_subtarea // casos_subtarea + (
        1 if puntos_subtarea % casos_subtarea > case_number else 0
    )


def write_testplan():
    assert len(sample_case_names) == len(set(sample_case_names))
    with open("testplan", "w") as f:
        for case_name in sample_case_names:
            f.write(f"{case_name} 0\n")

    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_points = get_case_points(subtarea, case_number)
            assert case_name not in sample_case_names
            with open("testplan", "a") as f:
                f.write(f"{case_name} {case_points}\n")


def write_cases():
    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_path = os.path.join("cases", case_name)
            with open(f"{case_path}.in", "w") as f:
                case = generate_case(subtarea)
                case_string = base_string.format(**case)
                f.write(f"{case_string}\n")


def main():
    random.seed(1035794)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == "__main__":
    main()
