import os
import math
import random

sample_case_names = [
    "2_sub3.sample",
    "3_sub2.sample"
]
n_limit = 2 * 10**5
t_limit = [3, 10**9, 10**6, 10**9]
case_count = [9, 13, 16, 16]
case_score = [11, 21, 25, 43]
case_order = [1, 3, 2, 4]
subtasks = 4


def generate_Ns(subtask: int):
    Ns = random.sample(range(101, n_limit), case_count[subtask] - 4)
    return [100] + sorted(Ns) + [n_limit] * 3


def generate_partition(n: int, k: int, max_t: int = 1e9):
    last_end, pieces = -1, []
    for end in sorted(random.sample(range(n - 1), k - 1) + [n - 1]):
        pieces.append(end - last_end)
        last_end = end

    curr = 0
    while curr < len(pieces):
        if pieces[curr] > max_t:
            smaller = random.randint(1, max_t)
            pieces.append(pieces[curr] - smaller)
            pieces[curr] = smaller
        curr += 1

    random.shuffle(pieces)
    return pieces


def generate_case_sizes(n: int, subtask: int, case_num: int):
    if not subtask:
        return [random.randint(1, t_limit[subtask]) for _ in range(n)]

    sizes = []
    sqrt_n = int(math.sqrt(n))
    k = (random.randint(n // 2, n) if case_num < 2
         else random.randint(1, 2 * sqrt_n))

    if subtask == 1:
        start = 1
        for piece in sorted(generate_partition(t_limit[subtask], k)):
            group_size = min(n // k, piece)

            offset = random.randint(start, start + piece - group_size)
            for i in range(group_size):
                sizes.append(offset + i)

            n -= group_size
            start += piece
            k -= 1
    else:
        if case_num == case_count[subtask] - 1:
            # Generate a big case with many repeated elements
            max_t = random.randint(2, 7)
        else:
            max_t = (t_limit[subtask] if case_num < 2
                     else random.randint(sqrt_n, min(t_limit[subtask], 10000)))

        range_offset = random.randint(1, t_limit[subtask] - max_t + 1)

        for piece in generate_partition(n, k, max_t):
            piece_offset = random.randint(0, max_t - piece)
            for i in range(piece):
                sizes.append(range_offset + piece_offset + i)

    random.shuffle(sizes)
    return sizes


def generate_case_string(n: int, subtask: int, case_num: int):
    T = generate_case_sizes(n, subtask, case_num)
    assert len(T) == n
    return f"{n}\n{' '.join(str(T_i) for T_i in T)}\n"


def get_case_name(subtask: int, case_num: int):
    return f"{case_order[subtask]}_sub{subtask + 1}.{case_num}"


if __name__ == "__main__":
    assert len(sample_case_names) == len(set(sample_case_names))
    assert subtasks == len(case_count) == len(case_score)
    assert sum(case_score) == 100

    random.seed("random, crea unos casos buenazos")

    # Write testplan
    with open("testplan", "w", encoding="utf-8", newline="\n") as testplan:
        for case_name in sample_case_names:
            testplan.write(f"{case_name} 0\n")

        for sub in range(subtasks):
            case_name = get_case_name(sub, 0)
            assert case_name not in sample_case_names
            testplan.write(f"{case_name} {case_score[sub]}\n")

            for case_number in range(1, case_count[sub]):
                case_filename = get_case_name(sub, case_number)
                assert case_filename not in sample_case_names
                testplan.write(f"{case_filename} 0\n")

    # Write cases
    for sub in range(subtasks):
        subtask_Ns = generate_Ns(sub)

        for case_number in range(case_count[sub]):
            case_name = get_case_name(sub, case_number)
            print(f"Generating case #{case_number} for subtask {sub + 1}")
            case_str = generate_case_string(
                subtask_Ns[case_number], sub, case_number)
            case_path = os.path.join("cases", f"{case_name}.in")
            with open(case_path, "w", encoding="utf-8", newline="\n") as case:
                case.write(case_str)

    print("The cases have been generated")
