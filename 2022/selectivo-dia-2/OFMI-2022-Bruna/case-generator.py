import os
import random

random.seed(1083037576)


def guardar_caso(sub_caso: int, numero: int, lineas: list):
    nombre_archivo = \
        'sub{}.{}.'.format(sub_caso, numero)
    ruta_archivo = os.path.join('cases', nombre_archivo + 'in')
    with open(ruta_archivo, 'w') as archivo:
        for linea in lineas:
            for index, value in enumerate(linea):
                archivo.write(str(value))
                if index + 1 < len(linea):
                    archivo.write(' ')
            archivo.write('\n')

    ruta_archivo = os.path.join('cases', nombre_archivo + 'out')
    with open(ruta_archivo, 'w') as archivo:
        archivo.write('')


def arbol_aleatorio(n: int) -> list:
    lista = []
    nodos = []
    for v in range(n):
        nodos.append(0)
        lista.append(v + 1)
    random.shuffle(lista)

    nodos[lista[0] - 1] = -1
    for v in range(1, n):
        nodos[lista[v] - 1] = lista[random.randint(0, v - 1)]

    return nodos


def arbol_un_padre(n: int) -> list:
    nodos = []
    raiz = random.randint(1, min(n, 1000))
    for v in range(n):
        nodos.append(-1 if v + 1 == raiz else raiz)

    return nodos


def arbol_lista(n: int) -> list:
    lista = []
    nodos = []
    for v in range(n):
        nodos.append(0)
        lista.append(v + 1)
    random.shuffle(lista)

    nodos[lista[0] - 1] = -1
    for v in range(1, n):
        nodos[lista[v] - 1] = lista[v - 1]

    return nodos


def randomQueryType1(n, min_x, max_x):
    inversionista = random.randint(1, n)
    x = random.randint(min_x, max_x)
    return [1, inversionista, x]


def randomQueryType2(n):
    inversionista = random.randint(1, n)
    return [2, inversionista]


def caso_aleatorio(params):
    sub_caso, numero, max_n, max_q, min_x, max_x, solo_un_padre = params
    lineas = []
    n = random.randint(max(1, max_n - 100), max_n)
    q = random.randint(max(1, max_q - 100), max_q)
    linea = [n, q]
    lineas.append(linea)

    # Generar árbol

    if sub_caso != 5:
        if solo_un_padre:
            lineas.append(arbol_un_padre(n))

            # Hacer Q - 1 Updates en el padre
            if sub_caso != 2:
                raiz = lineas[-1].index(-1) + 1
                for _ in range(q - 1):
                    lineas.append([1, raiz, min(max_x, 2)])
                lineas.append(randomQueryType2(n))
                guardar_caso(sub_caso, numero, lineas)
                return

        else:
            lineas.append(arbol_aleatorio(n))
    else:
        lineas.append(arbol_lista(n))

    flag = True
    cantidad_updates = random.randint(1, q)

    # Generar queries
    for _ in range(q):
        # Queries Random
        if sub_caso in (1, 3, 5, 6):
            lineas.append(
                randomQueryType1(n, min_x, max_x) if random.randint(1, 2) == 1
                else randomQueryType2(n)
            )
        # Solo un update al inicio
        elif sub_caso == 2:
            if flag:
                lineas.append(randomQueryType1(n, min_x, max_x))
                flag = False
            else:
                lineas.append(randomQueryType2(n))
        elif sub_caso == 4:
            if flag:
                lineas.append(randomQueryType1(n, min_x, max_x))
                cantidad_updates -= 1
                flag = (cantidad_updates > 0)
            else:
                lineas.append(randomQueryType2(n))
    guardar_caso(sub_caso, numero, lineas)


def tam(maximo: int, index: int, dividir: bool) -> int:
    return maximo if dividir else (maximo / (10 ** (index - 1) / 10))


def sub1Params(j):
    return (1, j, tam(1e5, j, j == 1), tam(1e5, j, j == 1), 1, 1, j == 1)


def sub2Params(j):
    return (2, j, tam(1e5, j, j == 1), tam(1e5, j, j == 1), 1, 1e5, j == 1)


def sub3Params(j):
    return (3, j, tam(1e3, j, j == 1), tam(1e3, j, j == 1), 1, 1e5, j == 1)


def sub4_6Params(i, j):
    return (i, j, tam(1e5, j, j == 1), tam(1e5, j, j == 1), 1, 1e5, j == 1)


def sub6Params(j):
    if j == 5:
        return (6, j, 1, 1e3, 1e9 - 100, 1e9, False)
    return (6, 6, 10, 10, 1, 10, False)


# Sub1
for jj in range(1, 5):
    caso_aleatorio(sub1Params(jj))

# Sub2
for jj in range(1, 5):
    caso_aleatorio(sub2Params(jj))

# Sub3
for jj in range(1, 5):
    caso_aleatorio(sub3Params(jj))

# Sub4-6
for ii in (4, 5, 6):
    for jj in range(1, 5):
        caso_aleatorio(sub4_6Params(ii, jj))

caso_aleatorio(sub6Params(5))
caso_aleatorio(sub6Params(6))
