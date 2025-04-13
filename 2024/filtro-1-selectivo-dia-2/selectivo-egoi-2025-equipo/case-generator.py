import os
import random
from typing import List


sample_case_names = ["sub1.sample1", "sub1.sample2", "sub1.sample3",
                     "sub1.extra", "sub2.extra", "sub4.extra"]
n_limit = [200, 2000, 10 ** 6, 2 * 10 ** 6]
v_limit = [10 ** 9, 10 ** 9, 500, 50]
case_count = [10, 10, 10, 10]
case_scores = [21, 25, 17, 37]
subtasks = 4


def biased_flip(p):
    return 1 if random.random() < p else 0


def get_Ns(subtask: int):
    start, end = 10, n_limit[subtask]
    if subtask > 0:
        start = n_limit[subtask - 1]
    cases = case_count[subtask]
    sorted_Ns = sorted(random.sample(range(start, end, 1), cases - 2))
    return [start] + sorted_Ns + [end]


def get_Ks(subtask: int):
    max_k, cases = v_limit[subtask], case_count[subtask]
    return sorted([
        random.randint(2, max_k - 1) for i in range(cases)
    ], reverse=True)


def uniform_case_dist(n: int):
    range_start = random.randint(0, n // 2)
    range_end = range_start + random.randint(1, n // 2)
    range_length = range_end - range_start + 1
    majority = (range_length // 2) + 1

    dist = ([0 for i in range(range_length - majority)] +
            [1 for i in range(majority)])
    random.shuffle(dist)

    return ([0 for i in range(range_start - 1)] + dist +
            [0 for i in range(n - range_end)])


def coin_flip_case_dist(n: int):
    return [biased_flip(0.3) for i in range(n)]


def generate_case_dist(case_num: int, n: int):
    if case_num == 0:
        return [0 for num in range(n)]
    if case_num in range(2, 6):
        return coin_flip_case_dist(n)
    if case_num in range(6, 10):
        return uniform_case_dist(n)

    majority = (n // 2) + 1
    case_dist = [1 for i in range(majority)] + [0 for i in range(n - majority)]
    random.shuffle(case_dist)
    return case_dist


def generate_case_string(case_dist: List[int], subtask: int, k: int):
    values = []
    for bit in case_dist:
        values.append(random.randint(k, v_limit[subtask])
                      if bit else random.randint(1, k - 1))
    if subtask == 2:
        values = sorted(values)
    case_dist_str = ' '.join([str(num) for num in values])
    return f"{len(values)} {k}\n{case_dist_str}\n"


def get_case_name(subtask: int, case_num: int):
    return f"sub{subtask}.{case_num}"


if __name__ == "__main__":
    assert (subtasks == len(n_limit) == len(v_limit)
            == len(case_count) == len(case_scores))
    assert sum(case_scores) == 100

    random.seed("camara mi random, caete con los randints")

    # Write testplan
    assert len(sample_case_names) == len(set(sample_case_names))
    with open("testplan", "w", encoding="utf-8", newline="\n") as testplan:
        for case_number, case_name in enumerate(sample_case_names):
            testplan.write(f"{case_name} 0\n")
        for sub in range(1, subtasks + 1):
            case_name = get_case_name(sub, 0)
            assert case_name not in sample_case_names
            testplan.write(f"{case_name} {case_scores[sub - 1]}\n")
            for case_number in range(1, case_count[sub - 1]):
                case_name = get_case_name(sub, case_number)
                assert case_name not in sample_case_names
                testplan.write(f"{case_name} 0\n")

    # Write cases
    for sub in range(1, subtasks + 1):
        subtask_n = get_Ns(sub - 1)
        subtask_k = get_Ks(sub - 1)
        for case_number in range(case_count[sub - 1]):
            case_name = get_case_name(sub, case_number)
            print(f"Generating case #{case_number} for subtask {sub}")
            case_dis = generate_case_dist(case_number, subtask_n[case_number])
            assert subtask_n[case_number] == len(case_dis)
            case_str = generate_case_string(
                case_dis, sub - 1, subtask_k[case_number]
            )
            case_path = os.path.join("cases", f"{case_name}.in")
            with open(case_path, "w+", encoding="utf-8", newline="\n") as case:
                case.write(case_str)
    print("The cases have been generated")
