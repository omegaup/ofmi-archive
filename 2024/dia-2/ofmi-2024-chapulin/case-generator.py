import os
import random
import math

num_subtareas = 6
puntos_por_subtarea = [9, 13, 15, 19, 21, 23]
casos_por_subtarea = [6, 6, 10, 12, 13, 15]
casos_con_limite_N = [3, 3, 5, 7, 8, 10]
orden_de_subtarea = [3, 4, 1, 2, 5, 6]
subtarea_agrupada = [True for _ in range(num_subtareas)]
sample_case_names = ["3_sub1.sample", "1_sub3.sample"]


def esta_entre_los_ultimos_n_casos(subtarea, case_number, n):
    return case_number + n >= casos_por_subtarea[subtarea - 1]


def get_N(subtarea, case_number):
    if subtarea == 3:
        limite_N = 100
    elif subtarea == 4:
        limite_N = 5000
    else:
        limite_N = 10**5

    if esta_entre_los_ultimos_n_casos(subtarea, case_number,
                                      n=casos_con_limite_N[subtarea - 1]):
        return limite_N
    return random.randint(1, limite_N)


def get_S(subtarea, case_number, N):
    if subtarea == 2:
        # La respuesta en esta subtarea donde todos los valores son iguales es
        # A[0] * ceil(N / S), PERO si N % S != 1 entonces puedes usar un turbo
        # salto de tamano 1 para agregarle un elemento del arreglo mas.
        # A continuacion queremos forzar ambos escenarios para garantizar que
        # consideraron este caso especial en su solucion.
        if esta_entre_los_ultimos_n_casos(subtarea, case_number, n=1):
            # 100,000 % 33,333 == 1, entonces NO sirve el turbo salto
            assert N % 33333 == 1
            return 33333
        if esta_entre_los_ultimos_n_casos(subtarea, case_number, n=2):
            # 100,000 % 33,332 != 1, entonces SI sirve el turbo salto
            assert N % 33332 != 1
            return 33332
        return random.randint(1, N)

    if esta_entre_los_ultimos_n_casos(subtarea, case_number, n=3):
        # Para tres subcasos poner una S grande que truene soluciones lentas
        return random.randint(N // 2, N)

    if esta_entre_los_ultimos_n_casos(subtarea, case_number, n=5):
        # Para dos subcasos poner una S chiquita que truene no hacer prefix sum
        return random.randint(2, 7)

    return random.randint(2, int(math.sqrt(N)))


def get_T(subtarea, N, S, case_number):
    if subtarea == 1:
        return 0
    if subtarea in [2, 3, 4, 5]:
        return N

    if esta_entre_los_ultimos_n_casos(subtarea, case_number, n=3):
        # Para solo tres subcasos poner una T mayor igual a S
        return random.randint(S, N)
    # Para el resto poner una T menor a S
    return random.randint(1, S - 1)


def get_A(subtarea, N):
    if subtarea == 2:
        valor = random.randint(0, 1000)
        return [valor for _ in range(N)]
    return [random.randint(0, 1000) for _ in range(N)]


def generate_case_string(subtarea, case_number):
    N = get_N(subtarea, case_number)
    S = get_S(subtarea, case_number, N)
    T = get_T(subtarea, N, S, case_number)
    A = get_A(subtarea, N)
    A_string = " ".join([str(a) for a in A])
    return f"{N} {S} {T}\n{A_string}\n"


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
    with open("testplan", "w", newline="\n") as f:
        for case_name in sample_case_names:
            f.write(f"{case_name} 0\n")

    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_points = get_case_points(subtarea, case_number)
            assert case_name not in sample_case_names
            with open("testplan", "a", newline="\n") as f:
                f.write(f"{case_name} {case_points}\n")


def write_cases():
    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_path = os.path.join("cases", case_name)
            with open(f"{case_path}.in", "w", newline="\n") as f:
                case_string = generate_case_string(subtarea, case_number)
                f.write(f"{case_string}\n")


def main():
    random.seed(29023)
    assert (
        num_subtareas
        == len(puntos_por_subtarea)
        == len(casos_por_subtarea)
        == len(casos_con_limite_N)
        == len(orden_de_subtarea)
    )
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == "__main__":
    main()
