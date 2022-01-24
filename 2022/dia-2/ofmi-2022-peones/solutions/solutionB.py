#!/usr/bin/python
# -*- coding: utf-8 -*-

# too-many-locals
# pylint: disable=R0914

def buscar_peon(mapa, y):
    # Busca la fila del peón negro
    columna_y = [fila[y] for fila in mapa]
    return columna_y.index('1')


def misma_columna(mapa, x, y, a):
    # Calcular la cantidad de movimientos para
    # mover (x, y) a (a, y)

    if x < a:
        # No es posible bajar
        return -1

    peon_y = buscar_peon(mapa, y)

    if peon_y == x - 1:
        # No es posible si el peon esta justo enfrente del (x, y)
        return -1
    if peon_y < a or x < peon_y:
        # Podemos avanzar
        return x - a

    # Hay que esquivar al peón
    columnas_disponibles = []
    if y > 0:
        columnas_disponibles.append(y - 1)
    if y < len(mapa[0]) - 1:
        columnas_disponibles.append(y + 1)

    # Checar que columna es conveniente tomar
    costo_adys = []
    for y_ady in columnas_disponibles:
        # Localizamos al peón negro de la columna
        peon_ady = buscar_peon(mapa, y_ady)

        if peon_ady >= x:
            # No es posible comer al peón
            continue

        # Mover lo menos posible al peón negro
        costo_adys.append(max(0, peon_y + 1 - peon_ady))

    if len(costo_adys) == 0:
        # No podemos hacer zig-zag
        return -1

    # Elegir la columna con menor costo
    return (x - a) + min(costo_adys)


def mover_hasta_destino(mapa, x, y, x_destino, y_destino):
    # Vamos a calcular el costo de ir hasta el destino desde (x, y)
    # Suponemos que en la columna 'y' no hay peón negro que nos interrumpa

    # Vamos a acomodar los peones negros de la columna 'y_destino' a 'y'

    # Costo inicial: Movimientos que sí o sí va a realizar el peón blanco
    costo_actual = x - x_destino

    # Primer fila que debe ser cubierta
    fila_objetivo = x_destino

    # Mover peones negros
    y_actual = y_destino
    while y != y_actual:
        # Movemos lo menos posible al peón negro
        peon_actual = buscar_peon(mapa, y_actual)
        costo_actual += max(0, fila_objetivo - peon_actual)

        # Checamos la siguiente columna
        fila_objetivo = max(peon_actual, fila_objetivo) + 1
        y_actual += -1 if y < y_actual else 1

    # y == y_destino
    if fila_objetivo > x:
        # No podemos llegar a la fila objetivo
        return -1
    # Movemos el peón blanco a la fila objetivo
    return costo_actual


def encontrar_camino(mapa, x_destino, y_destino):
    # Costo de mover el peón blanco al destino

    # Posición del peón blanco
    x_inicio = len(mapa) - 1
    y_inicio = 0

    if y_inicio == y_destino:
        return misma_columna(mapa, x_inicio, y_inicio, x_destino)
    if x_inicio <= x_destino:
        # No es posible bajar o moverse a los lados
        return -1

    # Buscamos el peón negro de la columan 'y_inicio'
    peon_inicio = buscar_peon(mapa, y_inicio)
    limite_busqueda = 0
    if peon_inicio < x_inicio:
        # Máximo que podemos avanzar sin comer peones
        limite_busqueda = peon_inicio + 1

    respuesta_optima = -1
    for fila_valida in range(limite_busqueda, x_inicio + 1):
        # Movernos hasta la fila 'fila_valida'
        costo_subir = x_inicio - fila_valida

        # Movernos a la columna disponible
        y_next = y_inicio + 1
        x_next = fila_valida - 1
        peon_next = buscar_peon(mapa, y_next)

        if peon_next <= x_next:
            # Podemos movernos a la columna
            costo_columna = (x_next - peon_next) + 1

            costo_acomodar = mover_hasta_destino(mapa,
                                                 x_next, y_next,
                                                 x_destino, y_destino)

            if costo_acomodar != -1:
                costo_total = costo_subir + costo_columna + costo_acomodar
                if respuesta_optima == -1:
                    respuesta_optima = costo_total
                else:
                    respuesta_optima = min(respuesta_optima, costo_total)

    # Regresamos la respuesta óptima
    return respuesta_optima


if __name__ == '__main__':
    # Entrada
    # Dimensiones del mapa
    N, M = map(int, input().split(' '))
    # Mapa
    mapa_entrada = [input().split(' ') for _ in range(1, N + 1)]
    # Coordenadas de la salida
    x_salida, y_salida = map(int, input().split(' '))

    print(encontrar_camino(mapa_entrada, x_salida - 1, y_salida - 1))
