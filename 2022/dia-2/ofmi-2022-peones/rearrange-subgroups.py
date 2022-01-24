#!/usr/bin/python
# -*- coding: utf-8 -*-

# too-many-locals
# pylint: disable=R0914

import os
from solutions.solucion100B import encontrar_camino as solve_peones


def solve_problem(filename):
    # Solve the current problem
    with open(f'cases/{filename}.in', 'r') as handle:
        original_input = handle.read()
    original_input = original_input.split('\n')
    original_input.pop()

    # Dims
    N, _ = map(int, original_input[0].split(' '))
    # Chess matrix
    input_matrix = [original_input[i].split(' ') for i in range(1, N + 1)]
    # Final coords
    x_final, y_final = map(int, original_input[-1].split(' '))

    answer = solve_peones(input_matrix, x_final - 1, y_final - 1)
    return answer >= 0


def rearrenge_subtasks():
    new_testplan = []
    with open('testplan', 'r') as f:
        testplan = f.read()
    testplan = testplan.split('\n')
    testplan.pop()

    # Process tesplan
    cases_subs = dict()
    for case in testplan:
        if 'sample' in case:
            # Ignore sample case
            new_testplan.append(case)
            continue

        filename, points = case.split(' ')
        if '_' in filename:
            subtask, num_case = filename.split('_')
        else:
            raise "Case name not supported yet"

        # Get answer
        answer = solve_problem(filename)

        # Store
        if subtask not in cases_subs:
            cases_subs[subtask] = []
        cases_subs[subtask].append((num_case, points, answer))

    # Rearrange
    new_names = dict()
    for subtask, cases in cases_subs.items():
        cases_pos = [(name, pts) for name, pts, valid in cases if valid]
        cases_neg = [(name, pts) for name, pts, valid in cases if not valid]
        print(subtask, f'{len(cases_neg)}/{len(cases)}')
        if len(cases_neg) > len(cases_pos):
            raise "Rearrange not supported yet"

        # Match each negative with a positive case
        for idx, (pos, neg) in enumerate(zip(cases_pos, cases_neg)):
            name_pos, pts_pos = pos
            name_neg, pts_neg = neg

            old_name_pos = f'{subtask}_{name_pos}'
            old_name_neg = f'{subtask}_{name_neg}'
            new_name_pos = f'{subtask}_group{idx}.{name_pos}'
            new_name_neg = f'{subtask}_group{idx}.{name_neg}'
            new_names[old_name_pos] = new_name_pos
            new_names[old_name_neg] = new_name_neg
            pts_group = int(pts_pos) + int(pts_neg)

            new_testplan.append(f'{new_name_pos} {pts_group}')
            new_testplan.append(f'{new_name_neg} 0')

        # Maintain the remain cases
        for name, pts in cases_pos[len(cases_neg):]:
            new_testplan.append(f'{subtask}_{name} {pts}')

    # Update testplan
    with open('testplan', 'w') as f:
        for case in new_testplan:
            f.write(case + '\n')

    # Rename cases
    for old_name, new_name in new_names.items():
        os.system(f'mv cases/{old_name}.in cases/{new_name}.in')


if __name__ == '__main__':
    rearrenge_subtasks()
