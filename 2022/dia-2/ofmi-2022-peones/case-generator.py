#!/usr/bin/python
# -*- coding: utf-8 -*-

# too-many-locals
# pylint: disable=R0914

import random


def generate_subtask(subtask, num_cases, points):
    for curr_case in range(num_cases):
        # Append to testplan
        with open('testplan', "a") as f:
            f.write(f'sub{subtask}_{curr_case} {points // num_cases}\n')

    for curr_case in range(num_cases):
        # Definir n y m
        n = random.randint(3, 100)
        m = random.randint(3, 100)

        # Crear matriz
        matrix = [[0 for _ in range(m)] for _ in range(n)]

        # Distribución propuesta por @Janque
        dist_peones = [((n - i) / n) ** 5 for i in range(n)]
        sum_total = sum(dist_peones)
        dist_peones = [dist_i / sum_total for dist_i in dist_peones]

        if subtask == 1:
            # Todos los peones estan en la primer fila
            dist_subtask = [1] + [0] * (n - 1)
        else:
            # Usamos la distribución de @Janque
            dist_subtask = dist_peones

        # Colocar peones negros
        for column in range(m):
            row = random.choices(range(n), weights=dist_subtask)[0]
            matrix[row][column] = 1

        # Desocupar posición del peón blanco
        while matrix[n - 1][0] == 1:
            matrix[n - 1][0] = 0
            row = random.choices(range(n), weights=dist_peones)[0]
            matrix[row][0] = 1

        if subtask in [1, 4, 5]:
            # La posición final no esta en la primer fila
            row_final = random.choices(range(n), weights=dist_peones)[0] + 1
            column_final = random.randint(2, m)
        elif subtask == 2:
            # La posición final esta en (1, m)
            row_final, column_final = 1, m
        elif subtask == 3:
            # La posición final esta en la primer columna
            row_final = random.randint(1, n)
            column_final = 1
        else:
            raise "subtask does not supported yet"

        with open(f"cases/sub{subtask}_{curr_case}.in", "w") as file:
            file.write(f'{n} {m}\n')
            for row in matrix:
                row = list(map(str, row))
                file.write(' '.join(row) + '\n')
            file.write(f'{row_final} {column_final}\n')


def generate_cases():
    with open('testplan', "w") as testplan:
        testplan.write("sample.sub5.0 0\n")

    subtasks_conf = [(1, 15, 15),
                     (2, 15, 15),
                     (3, 10, 10),
                     (4, 10, 30),
                     (5, 10, 30)]
    for subtask_conf in subtasks_conf:
        generate_subtask(*subtask_conf)


if __name__ == '__main__':
    generate_cases()
