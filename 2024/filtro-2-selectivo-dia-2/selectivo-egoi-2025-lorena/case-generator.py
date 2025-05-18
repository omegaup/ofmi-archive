import os
import math
import random

sample_case_names = [
    "sub1.sample1",
    "sub1.sample2"
]
n_limit = 10**4
a_i_limit = 10**9
subtask_k = [10000, 60, 60, 16]
case_count = [20, 20, 20, 20]
case_score = [8, 19, 38, 35]
subtasks = 4


def generate_case_string(k: int, subtask: int, case_num: int):
    # Let's make it big
    n = (n_limit if case_num + 6 >= case_count[subtask - 1]
         else random.randint(int(math.sqrt(n_limit)), n_limit))

    if case_num % 2:
        # Present in the array
        As = random.sample(range(1, a_i_limit), n)
        x = As[random.randint(0, n - 1)]
    else:
        # Not present in the array
        # Get n+1
        As = random.sample(range(1, a_i_limit), n + 1)
        # Select last one
        x = As[n]
        # Remove from the list
        As.pop()

    As = sorted(As)
    if subtask != 2:
        # Re order
        mod = random.randint(0, n - 1)
        As = As[mod:] + As[:mod]

    return f"{n} {x}\n{' '.join([str(t) for t in As])}\n{k}\n"


def get_case_name(subtask: int, case_num: int):
    return f"sub{subtask}.{case_num}"


if __name__ == "__main__":
    assert subtasks == len(case_count) == len(case_score)
    assert sum(case_score) == 100

    random.seed("la semilla de la suerte")

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
                case_filename = get_case_name(sub + 1, case_number)
                assert case_filename not in sample_case_names
                testplan.write(f"{case_filename} 0\n")

    # Write cases
    for sub in range(subtasks):
        for case_number in range(case_count[sub]):
            case_name = get_case_name(sub + 1, case_number)
            print(f"Generating case #{case_number} for subtask {sub + 1}")
            case_str = generate_case_string(subtask_k[sub], sub + 1,
                                            case_number)
            case_path = os.path.join("cases", f"{case_name}.in")
            with open(case_path, "w", encoding="utf-8", newline="\n") as case:
                case.write(case_str)

    print("The cases have been generated")
