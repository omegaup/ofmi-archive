import os
import random


num_subtareas = 4
puntos_por_subtarea = [20, 20, 40, 20]
casos_por_subtarea = [10, 10, 10, 10]
subtarea_agrupada = [False for _ in range(num_subtareas)]
sample_case_names = ["sub3-sample"]


def esta_entre_los_ultimos_k_casos(subtarea, case_number, k):
    return case_number + k >= casos_por_subtarea[subtarea - 1]


def get_N(subtarea, case_number):
    limite_N = 1000 if subtarea in [1, 2, 3] else 2*10**5
    if esta_entre_los_ultimos_k_casos(subtarea, case_number, k=3):
        return limite_N
    return random.randint(1, limite_N)


def get_A(subtarea, case_number, N):
    limite = 1000 if subtarea in [1, 2, 3] else 10**9
    if subtarea == 1:
        return [2 * random.randint(1, limite // 2) for _ in range(N)]

    A = [random.randint(1, limite) for _ in range(N)]
    if subtarea == 2:
        A.sort()
        return A

    # Estrategia para forzar que los ordenamientos cuadraticos fallen.
    if esta_entre_los_ultimos_k_casos(subtarea, case_number, k=2):
        A.sort()
        A.reverse()
    return A


def generate_case_string(subtarea, case_number):
    N = get_N(subtarea, case_number)
    A = get_A(subtarea, case_number, N)
    A_string = " ".join([str(a) for a in A])
    return f"{N}\n{A_string}\n"


def get_case_name(subtarea, case_number):
    agrupados = subtarea_agrupada[subtarea - 1]
    if agrupados:
        return f"sub{subtarea}.{case_number}"
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
    with open("testplan", "w", newline='\n') as f:
        for case_name in sample_case_names:
            f.write(f"{case_name} 0\n")

    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_points = get_case_points(subtarea, case_number)
            assert case_name not in sample_case_names
            with open("testplan", "a", newline='\n') as f:
                f.write(f"{case_name} {case_points}\n")


def write_cases():
    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_path = os.path.join("cases", case_name)
            with open(f"{case_path}.in", "w", newline='\n') as f:
                case_string = generate_case_string(subtarea, case_number)
                f.write(f"{case_string}\n")


def main():
    random.seed(12345)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == "__main__":
    main()
