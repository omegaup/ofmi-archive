import os
import random


num_subtareas = 3
puntos_por_subtarea = [10, 10, 80]
casos_por_subtarea = [10, 10, 15]
subtarea_agrupada = [False for _ in range(num_subtareas)]
sample_case_names = ["sub3-sample"]


def linear_incremental(subtarea, case_number, max_number):
    casos_subtarea = casos_por_subtarea[subtarea - 1]
    pendiente = max_number / casos_subtarea
    return max(int(pendiente * (case_number + 1)), 1)


def get_t(subtarea, case_number):
    limite_superior_t = 1 if subtarea == 2 else 10**5
    limite_inferior_t = linear_incremental(subtarea, case_number,
                                           limite_superior_t)
    assert limite_inferior_t <= limite_superior_t
    return random.randint(limite_inferior_t, limite_superior_t)


def get_h():
    limite_h = 10**5
    return random.randint(1, limite_h)


def get_H(t, h):
    return [random.randint(1, h) for _ in range(t)]


def get_E(subtarea, h):
    limite = 1 if subtarea == 1 else 1000
    return [random.randint(1, limite) for _ in range(h)]


def generate_case_string(subtarea, case_number):
    t = get_t(subtarea, case_number)
    h = get_h()
    H = get_H(t, h)
    E = get_E(subtarea, h)

    def convertir_arreglo_a_string(A):
        return " ".join([str(a) for a in A])
    H_string = convertir_arreglo_a_string(H)
    E_string = convertir_arreglo_a_string(E)
    return f"{t} {h}\n{H_string}\n{E_string}\n"


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
    puntos_para_subcaso = puntos_subtarea // casos_subtarea + (
        1 if puntos_subtarea % casos_subtarea > case_number else 0
    )
    assert puntos_para_subcaso > 0
    return puntos_para_subcaso


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
                case_string = generate_case_string(subtarea, case_number)
                f.write(f"{case_string}\n")


def main():
    random.seed(17060)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == "__main__":
    main()
