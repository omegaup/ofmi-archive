import random
import os


def generaCaso(caseName, points, N, M, restrictions):
    allow_repetitions = restrictions.get('allow_repetitions', True)
    allow_walls = restrictions.get('allow_walls', 0.15)
    n = random.randint(2, N)
    m = random.randint(2, M)
    casePath = os.path.join('cases', caseName + '.in')
    with open(casePath, "w+") as f:
        f.write(f'{n} {m}\n')

        valid_values = set(list(range(0, n * m)))
        matriz = []
        for _ in range(n):
            row = []
            for _ in range(m):
                # Con una probabilidad de 'allow_walls', poner un -1
                if random.random() < allow_walls:
                    next_value = -1
                else:
                    next_value = random.choice(list(valid_values))

                # Agregar valor al renglon
                row.append(str(next_value))
                if not allow_repetitions and next_value != -1:
                    # Eliminar valor si no se permite repetidos
                    valid_values.remove(next_value)

            # Imprimir renglon
            f.write(' '.join(row) + '\n')
            matriz.append(row)

        # Obtener posiciones validas
        def obtener_posiciones():
            x, y = random.randint(0, n - 1), random.randint(0, m - 1)
            while matriz[x][y] == "-1":
                x, y = random.randint(0, n - 1), random.randint(0, m - 1)
            return x, y

        # Inicio y fin distintos
        r1, c1 = obtener_posiciones()
        r2, c2 = obtener_posiciones()
        while r1 == r2 and c1 == c2:
            r2, c2 = obtener_posiciones()

        # Imprimir posiciones
        f.write(f'{r1} {c1}\n')
        f.write(f'{r2} {c2}\n')

    # Empty .out
    open(os.path.join('cases', caseName + '.out'), "w+").close()

    # Append to testplan
    with open('testplan', "a") as f:
        f.write(caseName + " " + str(points) + "\n")


if __name__ == "__main__":
    with open('testplan', "w+") as testplan:
        testplan.write("sub4.sample 0\n")

    random.seed(10)

    # Subtarea 1
    for i in range(10):
        puntos = 10 if i == 0 else 0
        generaCaso(
            "sub1.{}".format(i),
            puntos,
            N=200, M=200,
            restrictions={
                'allow_repetitions': False,
                'allow_walls': 0
            })

    # Subtarea 2
    for i in range(10):
        puntos = 20 if i == 0 else 0
        generaCaso(
            "sub2.{}".format(i),
            puntos,
            N=5, M=5,
            restrictions={
                'allow_repetitions': True,
                'allow_walls': (0.035 * (i + 1))
            })

    # Subtarea 3
    for i in range(10):
        puntos = 40 if i == 0 else 0
        generaCaso(
            "sub3.{}".format(i),
            puntos,
            N=200, M=200,
            restrictions={
                'allow_repetitions': False,
                'allow_walls': (0.035 * (i + 1))
            })

    # Subtarea 4
    for i in range(10):
        puntos = 30 if i == 0 else 0
        generaCaso(
            "sub4.{}".format(i),
            puntos,
            N=200, M=200,
            restrictions={
                'allow_repetitions': True,
                'allow_walls': (0.035 * (i + 1))
            })
