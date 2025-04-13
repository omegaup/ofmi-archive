import os
import random
from typing import List

sample_case_names = ["sub1.sample", "sub3.sample", "sub2.extra", "sub3.extra1",
                     "sub3.extra2", "sub4.extra1", "sub4.extra2"]
n_limit = [100, 10 ** 5, 10 ** 5, 10 ** 5]
k_limit = [500, 10 ** 5, 5 * 10 ** 5, 10 ** 9]
case_count = [10, 5, 15, 20]
case_score = [27, 13, 29, 31]
subtasks = 4


def get_Ns(subtask: int):
    start, end = 1000 if subtask else 1, n_limit[subtask]
    Ns = random.sample(range(start + 1, end), case_count[subtask] - 2)
    return [start] + sorted(Ns) + [end]


def get_Ks(Ns: List[int], subtask: int):
    if subtask == 1:
        Ks = []
        for n in Ns[1: -1]:
            Ks.append(random.randint(1, n - 1))
        return [0] + Ks + [Ns[-1]]

    return ([random.randint(n, k_limit[subtask]) for n in Ns[:-1]] +
            [k_limit[subtask]])


def generate_case_string(n: int, k: int, subtask: int):
    t_limit = 10 ** 9 if subtask else 100
    Ts = [random.randint(1, t_limit) for _ in range(n)]
    return f"{n} {k}\n{' '.join([str(t) for t in Ts])}\n"


def get_case_name(subtask: int, case_num: int):
    return f"sub{subtask}.{case_num}"


if __name__ == "__main__":
    assert subtasks == len(n_limit) == len(case_count) == len(case_score)
    assert sum(case_score) == 100

    random.seed('echate unos random mi python')

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
            case_str = generate_case_string(subtask_n[case_number],
                                            subtask_k[case_number], sub)
            case_path = os.path.join("cases", f"{case_name}.in")
            with open(case_path, "w+", encoding="utf-8", newline="\n") as case:
                case.write(case_str)

    print("The cases have been generated")
