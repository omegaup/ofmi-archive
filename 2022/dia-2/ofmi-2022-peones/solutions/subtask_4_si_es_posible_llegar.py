def hacer_zig_zag(mapa, x, y, x_destino):
    columna_destino = [mapa[fila][y] for fila in range(x_destino, x)]
    if '1' not in columna_destino:
        # No hay peón negro en el camino
        return True

    # Sí hay peón negro y hay que esquivarlo
    columna_adj = [mapa[fila][y + 1] for fila in range(x)]
    if '1' in columna_adj:
        if '1' in columna_destino[:-1]:
            # Podemos regresar a la columna original
            return True
        # No podemos regresar a la columna original
        return False
    # No es posible esquivar el peón negro
    return False


def encontrar_camino(mapa, x_destino, y_destino):
    # Checar si es posible llegar al destino

    # Buscamos el peón blanco
    x_inicio = len(mapa) - 1
    y_inicio = 0

    if x_inicio < x_destino:
        # No es posible bajar
        return False
    if x_inicio == x_destino and y_inicio != y_destino:
        # No es posible movernos a los lados sin subir
        return False

    if y_inicio == y_destino:
        # Checamos el caso donde empieza en la misma columna
        return hacer_zig_zag(mapa, x_inicio, y_inicio, x_destino)

    if (x_inicio - x_destino) < abs(y_inicio - y_destino):
        # No será posible alcanzar la columna destino
        return False

    x, y = x_inicio, y_inicio
    while y < y_destino:
        y_siguiente = y + 1

        columna_siguiente = [mapa[fila][y_siguiente] for fila in range(x)]
        if '1' in columna_siguiente:
            # Nos movemos a la siguiente columna
            x, y = x - 1, y_siguiente
        else:
            # No es posible movernos a la siguiente columna
            return False

    # Nos movimos hasta la última columna y podemos subir al destino
    return True


if __name__ == '__main__':
    # Entrada
    # Dimensiones del mapa
    N, M = map(int, input().split(' '))
    # Mapa
    mapa_entrada = [input().split(' ') for _ in range(1, N + 1)]
    # Coordenadas de la salida
    x_salida, y_salida = map(int, input().split(' '))

    if encontrar_camino(mapa_entrada, x_salida - 1, y_salida - 1):
        print(1)
    else:
        print(-1)
