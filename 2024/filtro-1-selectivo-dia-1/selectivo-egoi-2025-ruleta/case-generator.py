import os
import random
from typing import List

sample_case_names = ["sub1.sample1", "sub1.sample2"]
n_limit = [1000, 10 ** 6, 10 ** 6, 10 ** 6]
case_count = [10, 10, 10, 10]
case_score = [21, 13, 27, 39]
subtasks = 4


def get_Ns(subtask: int):
    start = 1000 if subtask else 1
    end = n_limit[subtask]
    cases = case_count[subtask]
    sorted_Ns = sorted(random.sample(range(start + 1, end), cases - 2))
    return [start] + sorted_Ns + [end]


def get_Ks(Ns: List[int], subtask: int):
    # Coincide que `subtask` es el valor que queremos para `k`.
    if subtask in [1, 2]:
        return [subtask for n in Ns]
    return [1, Ns[1]] + [random.randint(1, max(1, n // 5)) for n in Ns[2:]]


def biased_flip(p: float):
    return 1 if random.random() < p else 0


def generate_case_dist(case_num: int, n: int, k: int):
    if case_num == 0:
        return [1 for _ in range(n)]
    if case_num == 1:
        return [0 for _ in range(n)]
    if case_num == 2:
        one = random.randint(0, n - 1)
        return [1 if i == one else 0 for i in range(n)]

    # Generamos rango cuya respuesta va a ser exactamente `min_answer`.
    min_answer = random.randint(1, max(1, n - k - 1))
    case_dist = [0 for _ in range(min_answer)] + [1 for _ in range(k - 1)]
    random.shuffle(case_dist)
    case_dist = ([1] + case_dist + [1])[:n]

    # Completamos el caso con segmentos de ruleta al azar.
    case_dist += [biased_flip(0.3) for _ in range(n - len(case_dist))]

    # Le damos una "vuelta" a la ruleta.
    offset = random.randint(0, n - 1)
    return [case_dist[(offset + i) % n] for i in range(n)]


def generate_case_string(case_dist: List[int], k: int):
    values = []
    for bit in case_dist:
        values.append('S' if bit else 'P')
    case_dist_str = ''.join([str(char) for char in values])
    return f"{len(values)} {k}\n{case_dist_str}\n"


def get_case_name(subtask: int, case_num: int):
    return f"sub{subtask}.{case_num}"


if __name__ == "__main__":
    assert subtasks == len(n_limit) == len(case_count) == len(case_score)
    assert sum(case_score) == 100

    random.seed('tome su seed, buen random')

    # Write testplan
    assert len(sample_case_names) == len(set(sample_case_names))
    with open("testplan", "w", encoding="utf-8", newline="\n") as testplan:
        for case_name in sample_case_names:
            testplan.write(f"{case_name} 0\n")
        for sub in range(subtasks):
            case_name = get_case_name(sub + 1, 0)
            assert case_name not in sample_case_names
            testplan.write(f"{case_name} {case_score[sub]}\n")
            for case_number in range(1, case_count[sub]):
                case_name = get_case_name(sub + 1, case_number)
                assert case_name not in sample_case_names
                testplan.write(f"{case_name} 0\n")

    # Write cases
    for sub in range(subtasks):
        subtask_n = get_Ns(sub)
        subtask_k = get_Ks(subtask_n, sub)
        for case_number in range(case_count[sub]):
            case_name = get_case_name(sub + 1, case_number)
            print(f"Generating case #{case_number} for subtask {sub + 1}")
            case_dis = generate_case_dist(case_number, subtask_n[case_number],
                                          subtask_k[case_number])
            assert subtask_n[case_number] == len(case_dis)
            case_str = generate_case_string(case_dis, subtask_k[case_number])
            case_path = os.path.join("cases", f"{case_name}.in")
            with open(case_path, "w+", encoding="utf-8", newline="\n") as case:
                case.write(case_str)

    print("The cases have been generated")
