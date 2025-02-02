import os
import random


num_subtareas = 4
puntos_por_subtarea = [16, 15, 28, 41]
casos_por_subtarea = [12, 12, 12, 12]
subtarea_agrupada = [True for _ in range(num_subtareas)]
sample_case_names = ["sub4.sample", "sub4.sample2"]


def esta_entre_los_ultimos_n_casos(subtarea, case_number, n):
    return case_number + n >= casos_por_subtarea[subtarea - 1]


def get_limite_de_valores_distintos(N, M):
    limite_nm = min(N, M)
    limite_suma = 10**5
    for i in range(1, limite_nm + 1):
        if i > limite_suma:
            return i - 1
        limite_suma -= i
    return limite_nm


def get_N(subtarea, case_number):
    limite_N = 1 if subtarea == 2 else 10**4
    if esta_entre_los_ultimos_n_casos(subtarea, case_number, n=3):
        return limite_N
    return random.randint(1, limite_N)


def get_M(subtarea, case_number):
    limite_M = 1 if subtarea == 1 else 10**5
    if esta_entre_los_ultimos_n_casos(subtarea, case_number, n=3):
        return limite_M
    es_ultimos = esta_entre_los_ultimos_n_casos(subtarea, case_number, n=4)
    if subtarea in [3, 4] and es_ultimos:
        limite_M = 1000
    return random.randint(1, limite_M)


def get_Q(subtarea, case_number, N):
    if subtarea == 3:
        return 1
    if esta_entre_los_ultimos_n_casos(subtarea, case_number, n=4):
        return N + 1
    return random.randint(1, N + 1)


def get_respuestas(subtarea, case_number, N, M):
    # Las caracteristicas de la respuesta K son:
    # - K es no creciente
    # - La cantidad de asistencias totales es sum(K[i])
    # - La cantidad de asistencias esta limitada por N * M
    # - K[i] <= M
    # - Tenemos que sum(K[i]) <= sum(P[i]) <= 10**5

    if esta_entre_los_ultimos_n_casos(subtarea, case_number, n=3):
        # El ultimo ultimo sera el peor peor
        limite_suma = 10**5
        respuestas = []
        limite_valores = get_limite_de_valores_distintos(N, M)
        for i in range(1, limite_valores + 1):
            respuestas.append(i)
            limite_suma -= i
        while len(respuestas) < N:
            numero = random.randint(0, min(M, limite_suma))
            limite_suma -= numero
            respuestas.append(numero)
        respuestas.sort(reverse=True)
        return respuestas

    maximo_posible = min(10**5, N * M)
    # Las respuestas pueden ser de 0 a N
    minima_respuesta = random.randint(0, N)
    if esta_entre_los_ultimos_n_casos(subtarea, case_number, n=5):
        minima_respuesta = random.randint(max(N // 2, 0), N + 1)
    # La primer respuesta es M; todas fueron al menos 0 veces
    K = []
    for i in range(1, N + 1):
        limite_inferior = 1 if i <= minima_respuesta else 0
        # [restantes_asegurados] son las asistencias que debemos de
        # guardar para las siguientes respuestas
        restantes_asegurados = max(minima_respuesta - i, 0)
        limite_superior = min(maximo_posible - restantes_asegurados, M)

        k_i = random.randint(limite_inferior, limite_superior)
        K.append(k_i)
        maximo_posible -= k_i
    return K


def get_P(M, respuestas):
    # Elegir quienes van a aparecer
    elegidos = random.sample(range(1, M + 1), respuestas[0])
    # Hacer que aparezcan los elegidos
    ultimos_elegidos = elegidos
    elegidos_por_dia = []
    for respuesta_i in respuestas:
        ultimos_elegidos = ultimos_elegidos[:respuesta_i]
        elegidos_por_dia.append(ultimos_elegidos)
    # Revolver los dias
    random.shuffle(elegidos_por_dia)
    return elegidos_por_dia


def get_K(subtarea, case_number, N, M, Q):
    if subtarea == 3:
        return [1 for _ in range(Q)]

    if esta_entre_los_ultimos_n_casos(subtarea, case_number, n=3):
        min_valores_diferentes = get_limite_de_valores_distintos(N, M)
        if min_valores_diferentes + 1 >= Q:
            return random.sample(range(0, min_valores_diferentes + 1), Q)

        return list(range(0, min_valores_diferentes + 1)) + random.sample(
            range(min_valores_diferentes + 1, N + 1),
            Q - min_valores_diferentes - 1,
        )

    return random.sample(range(0, N + 1), Q)


def generate_case_string(subtarea, case_number):
    N = get_N(subtarea, case_number)
    M = get_M(subtarea, case_number)
    Q = get_Q(subtarea, case_number, N)
    respuestas = get_respuestas(subtarea, case_number, N, M)
    P = get_P(M, respuestas)
    K = get_K(subtarea, case_number, N, M, Q)
    random.shuffle(K)

    def arreglo_a_string(A, separador=" "):
        return separador.join([str(a) for a in A])

    P_string = "\n".join([f"{len(lst)}\n{arreglo_a_string(lst)}" for lst in P])
    K_string = arreglo_a_string(K, separador="\n")
    return f"{N} {M} {Q}\n{P_string}\n{K_string}"


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
    random.seed(23861)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == "__main__":
    main()
