import sys


def existsPath(n, m, mdo):
    stack = [(n - 1, 0)]
    use = [[False for _ in range(m)] for _ in range(n)]
    use[n - 1][0] = True

    while len(stack) > 0:
        r, c = stack[-1]
        stack.pop()

        if r == 0 and c == m - 1:
            return True

        if mdo[r][c] == 0:
            r -= 1
        elif mdo[r][c] == 1:
            c += 1
        elif mdo[r][c] == 2:
            r += 1
        elif mdo[r][c] == 3:
            c -= 1

        if r < 0 or r >= n or c < 0 or c >= m or use[r][c]:
            continue

        use[r][c] = True
        stack += [(r, c)]

    return False


def evalua(n, m, mdo, mdo_ans, ans):
    # Los valores de la matriz deben estar en {0, 1, 2, 3}
    valid_set = {0, 1, 2, 3}
    if not all([value in valid_set for row in mdo_ans for value in row]):
        print(0)
        sys.exit(0)

    # Se debieron modificar exactamente ans valores
    diff = sum([int(mdo[i][j] != mdo_ans[i][j])
                for i in range(n) for j in range(m)])
    if diff != ans:
        print(0)
        sys.exit(0)

    # Debe existir un camino de la esquina inferior izquierda a la esquina
    # superior derecha
    if not existsPath(n, m, mdo_ans):
        print(0)
        sys.exit(0)

    print(1)
    sys.exit(0)


def main():
    # Nombre del caso
    caseName = sys.argv[1]

    # Caso de entrada
    with open("data.in", "r") as handle:
        original_input = handle.read()
    lines = original_input.split("\n")
    n, m = [int(value) for value in lines[0].split()]
    mdo = [list(map(int, line.split())) for line in lines[1:-1]]

    # Salida oficial
    with open('data.out', 'r') as handle:
        original_output = handle.read()
    lines = original_output.split("\n")
    min_transformaciones = int(lines[0])

    # Salida de la concursante
    try:
        ans = int(input())
    except EOFError:
        print(0)
        sys.exit(0)

    if "sub2" in caseName:
        if min_transformaciones == 0:
            if ans == 0:
                # Pudo detectar que hay solucion sin modificaciones
                print(1)
                sys.exit(0)
            else:
                # Hay solucion sin modificaciones y no lo detecto
                print(0)
                sys.exit(0)
        else:
            # Pudo detectar que no hay solucion sin modificaciones
            if ans == -1:
                print(1)
                sys.exit(0)

    # Salida de la concursante, ya es una solucion general
    # por lo que se espera una matriz.
    # Una solucion general es para el sub2 cuando hay que hacer modificaciones
    # y NO imprimio -1 o  en el resto de las subtareas
    mdo_ans = []
    for _ in range(n):
        try:
            row = [int(value) for value in input().split()]
        except EOFError:
            print(0)
            sys.exit(0)
        if len(row) != m:
            print(0)
            sys.exit(0)

        mdo_ans += [row]

    # Debe ser la misma cantidad de modificaciones
    if ans != min_transformaciones:
        print(0)
        sys.exit(0)

    evalua(n, m, mdo, mdo_ans, ans)


if __name__ == '__main__':
    main()
