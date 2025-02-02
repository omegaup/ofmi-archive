import os
import random


num_subtareas = 4
puntos_por_subtarea = [19, 17, 28, 36]
# Los casos son muy grandes, obtenemos OLE si generamos 10 casos
casos_por_subtarea = [16, 8, 8, 10]
subtarea_agrupada = [True for _ in range(num_subtareas)]
sample_case_names = ["sub1.sample", "sub1.sample2"]

# Movimientos caballo
movimientos_caballo = [
    (0, 0),  # No se mueve también lo contaremos como movimiento
    (2, 1),
    (1, 2),
    (-2, 1),
    (-1, 2),
    (2, -1),
    (1, -2),
    (-2, -1),
    (-1, -2),
]


class RandomCollection:
    def __init__(self, elementos):
        self.indice_a_elemento = list(elementos)
        self.elemento_a_indice = {x: i for i, x in enumerate(elementos)}

    # Obtiene un elemento aleatorio de la coleccion en O(1)
    def elemento_aleatorio(self):
        if not self.indice_a_elemento:
            return None
        indice = random.randint(0, len(self.indice_a_elemento) - 1)
        return self.indice_a_elemento[indice]

    # Elimina un elemento de la coleccion en O(1)
    def elimina(self, elemento):
        if elemento not in self.elemento_a_indice:
            raise ValueError(f"Elemento {elemento} ya fue eliminado")

        indice_a_remover = self.elemento_a_indice[elemento]
        ultimo_elemento = self.indice_a_elemento[-1]

        self.indice_a_elemento[indice_a_remover] = ultimo_elemento
        self.elemento_a_indice[ultimo_elemento] = indice_a_remover

        self.indice_a_elemento.pop()
        del self.elemento_a_indice[elemento]

    # Obtiene la cantidad de elementos en la coleccion en O(1)
    def __len__(self):
        return len(self.indice_a_elemento)

    # Verifica si un elemento esta en la coleccion en O(1)
    def __contains__(self, elemento):
        return elemento in self.elemento_a_indice


def esta_entre_los_ultimos_n_casos(subtarea, case_number, n):
    return case_number + n >= casos_por_subtarea[subtarea - 1]


def get_N(subtarea, case_number):
    limite_N = 1000000
    if subtarea == 1:
        return 8
    if subtarea == 4 and case_number == 3:
        return 1000
    if esta_entre_los_ultimos_n_casos(subtarea, case_number, n=1):
        return limite_N
    return random.randint(50000, 100000)


def get_reina_position(N):
    return (random.randint(1, N), random.randint(1, N))


def get_posiciones_disponibles(reina_posicion, N):
    (ReinaX, ReinaY) = reina_posicion
    posiciones_disponibles = set()

    # Posiciones en la misma fila y columna
    posiciones_disponibles.update((i, ReinaY) for i in range(1, N+1))
    posiciones_disponibles.update((ReinaX, j) for j in range(1, N+1))

    # Diagonal principal como secundaria
    for i in range(1, N+1):
        # Diagonal principal hacia abajo y a la derecha
        if ReinaX - i >= 1 and ReinaY - i >= 1:
            posiciones_disponibles.add((ReinaX - i, ReinaY - i))
        # Diagonal principal hacia arriba y a la la izquierda
        if ReinaX + i <= N and ReinaY + i <= N:
            posiciones_disponibles.add((ReinaX + i, ReinaY + i))
        # Diagonal secundaria hacia abajo y a la izquierda
        if ReinaX - i >= 1 and ReinaY + i <= N:
            posiciones_disponibles.add((ReinaX - i, ReinaY + i))
        # Diagonal secundaria hacia arriba y a la derecha
        if ReinaX + i <= N and ReinaY - i >= 1:
            posiciones_disponibles.add((ReinaX + i, ReinaY - i))

    return posiciones_disponibles


def generar_torre(
        posicion,
        filas_posibles,
        columnas_posibles,
        piezas_puestas: set
):
    if random.randint(0, 1):
        # Torre en la fila posicion[0]
        if len(columnas_posibles) == 0:
            return None

        columna = columnas_posibles.elemento_aleatorio()

        if (posicion[0], columna) not in piezas_puestas:
            columnas_posibles.elimina(columna)
            piezas_puestas.add((posicion[0], columna))
            return ('T', (posicion[0], columna))

        return None

    # Torre en la columna posicion[1]
    if len(filas_posibles) == 0:
        return None

    fila = filas_posibles.elemento_aleatorio()

    if (fila, posicion[1]) not in piezas_puestas:
        filas_posibles.elimina(fila)
        piezas_puestas.add((fila, posicion[1]))
        return ('T', (fila, posicion[1]))

    return None


def generar_alfil(
        N,
        posicion,
        diagonales_principales_posibles,
        diagonales_secundarias_posibles,
        piezas_puestas
):
    if random.randint(0, 1):
        # Alfil diagonal principal
        diagonal_actual = posicion[0] - posicion[1]
        if diagonal_actual in diagonales_principales_posibles:
            fila = random.randint(1, N)
            columna = fila - diagonal_actual

            if 1 <= columna <= N:
                if (fila, columna) in piezas_puestas:
                    return None
                diagonales_principales_posibles.elimina(diagonal_actual)

                piezas_puestas.add((fila, columna))
                return ('A', (fila, columna))
        return None

    # Alfil diagonal secundaria
    diagonal_actual = posicion[0] + posicion[1]
    if diagonal_actual in diagonales_secundarias_posibles:
        fila = random.randint(1, N)
        columna = diagonal_actual - fila
        if 1 <= columna <= N:
            if (fila, columna) in piezas_puestas:
                return None
            diagonales_secundarias_posibles.elimina(diagonal_actual)

            piezas_puestas.add((fila, columna))
            return ('A', (fila, columna))

    return None


def generar_caballo(N, posicion, piezas_puestas):
    random.shuffle(movimientos_caballo)
    for dx, dy in movimientos_caballo:
        fila = posicion[0] + dx
        columna = posicion[1] + dy
        if (
                1 <= fila <= N
                and 1 <= columna <= N
                and (fila, columna) not in piezas_puestas
        ):
            piezas_puestas.add((fila, columna))
            return ('C', (fila, columna))

    return None


def get_respuestas(
        subtarea,
        case_number,
        N,
        reina_posicion,
        reina_posiciones_disponibles: set
):
    # Escogemos un numero entre 1 y min(25, len(reina_posiciones_disponibles))
    # para la cantidad de posiciones que seran seguras
    cantidad_posiciones_seguras = random.randint(
        1, min(20, len(reina_posiciones_disponibles))
    )

    if subtarea == 1:
        cantidad_posiciones_seguras = random.randint(
            1, min(5, len(reina_posiciones_disponibles))
        )

    if case_number == 3:
        cantidad_posiciones_seguras = 0

    # Escogemos las posiciones inseguras de forma aleatoria
    posiciones_inseguras = random.sample(
        list(reina_posiciones_disponibles),
        len(reina_posiciones_disponibles) - cantidad_posiciones_seguras
    )
    posiciones_seguras = (
        reina_posiciones_disponibles
        - set(posiciones_inseguras)
    )

    # Crearemos una lista de posiciones que van a atacar a la posicion
    # insegura, al igual que el tipo de pieza que lo hara
    # 'T' -> Torre
    # 'A' -> Alfil
    # 'C' -> Caballo
    # El formato es (tipo_pieza, posicion_atacante)
    posiciones_atacantes = []

    # Creamos un set de las filas, columnas, diagonales principales
    # y diagonales secundarias posibles
    filas_posibles = (
        set(range(1, N+1))
        - set(pos[0] for pos in posiciones_seguras)
    )
    columnas_posibles = (
        set(range(1, N+1))
        - set(pos[1] for pos in posiciones_seguras)
    )
    diagonales_principales_posibles = (
        set(range(-(N-1), N))
        - set(pos[0] - pos[1] for pos in posiciones_seguras)
    )
    diagonales_secundarias_posibles = (
        set(range(2, 2 * N + 1))
        - set(pos[0] + pos[1] for pos in posiciones_seguras)
    )

    filas_posibles = RandomCollection(filas_posibles)
    columnas_posibles = RandomCollection(columnas_posibles)
    diagonales_principales_posibles = RandomCollection(
        diagonales_principales_posibles
    )
    diagonales_secundarias_posibles = RandomCollection(
        diagonales_secundarias_posibles
    )

    piezas_puestas = {reina_posicion}

    for posicion in posiciones_inseguras:
        if len(posiciones_atacantes) == 200000:
            break
        nueva_posicion = None
        if subtarea == 2:
            tipo_pieza = 'T'
            # Solo Torres
            nueva_posicion = generar_torre(
                posicion,
                filas_posibles,
                columnas_posibles,
                piezas_puestas
            )

            if nueva_posicion is not None:
                posiciones_atacantes.append(nueva_posicion)
        elif subtarea == 3:
            # Solo Torres y Alfiles
            tipo_pieza = random.choice(['T', 'A'])

            if case_number in [4, 5, 6]:
                # Solo alfiles
                tipo_pieza = 'A'

            # Escogemos una posicion aleatoria que atacan a la posicion
            # insegura, y la agregamos a la lista.
            # Tiene que ser aleatorio entre las filas y columnas posibles
            if tipo_pieza == 'T':
                nueva_posicion = generar_torre(
                    posicion,
                    filas_posibles,
                    columnas_posibles,
                    piezas_puestas
                )
            else:
                nueva_posicion = generar_alfil(
                    N,
                    posicion,
                    diagonales_principales_posibles,
                    diagonales_secundarias_posibles,
                    piezas_puestas
                )

            if nueva_posicion is not None:
                posiciones_atacantes.append(nueva_posicion)
        else:
            # Torre, Alfil y Caballo
            tipo_pieza = random.choice(['T', 'A', 'C'])
            if case_number in [3, 4, 5]:
                # Solo caballos
                tipo_pieza = 'C'

            if tipo_pieza == 'T':
                nueva_posicion = generar_torre(
                    posicion,
                    filas_posibles,
                    columnas_posibles,
                    piezas_puestas
                )
            elif tipo_pieza == 'A':
                nueva_posicion = generar_alfil(
                    N,
                    posicion,
                    diagonales_principales_posibles,
                    diagonales_secundarias_posibles,
                    piezas_puestas
                )
            else:
                nueva_posicion = generar_caballo(N, posicion, piezas_puestas)

            if nueva_posicion is not None:
                posiciones_atacantes.append(nueva_posicion)

    return posiciones_atacantes


def generate_case_string(subtarea, case_number):
    N = get_N(subtarea, case_number)
    reina_posicion = get_reina_position(N)
    reina_posiciones_disponibles = get_posiciones_disponibles(
        reina_posicion,
        N
    )

    respuestas = get_respuestas(
        subtarea,
        case_number,
        N,
        reina_posicion,
        reina_posiciones_disponibles
    )

    K = len(respuestas)

    def arreglo_a_string(A, separador=" "):
        return separador.join([str(a) for a in A])

    posiciones = "\n".join([f"{tipo_pieza} {arreglo_a_string(posicion)}" for
                            tipo_pieza, posicion in respuestas])

    reina_posicion_str = arreglo_a_string(reina_posicion)

    return f"{N} {K}\n{reina_posicion_str}\n{posiciones}"


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
    random.seed(18052)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == "__main__":
    main()
