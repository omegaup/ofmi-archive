import os
import random


subtask_count = 5
subtask_order = [4, 1, 2, 3, 5]
subtask_cases = [10, 10, 10, 13, 17]
subtask_points = [15, 20, 25, 25, 15]
subtask_n = [2 * 10**4, 20, 200, 2000, 2 * 10**4]
sample_cases = ["1_sub2.sample", "4_sub1.sample"]


def pairwise(arr: list):
    # Reemplazo de la funcion pairwise del modulo itertools
    return [(arr[i], arr[i + 1]) for i in range(len(arr) - 1)]


def write_case_to_testplan(subtask: int, case: int, points: int = 0):
    case = f"{subtask_order[subtask - 1]}_sub{subtask}.{case}"
    assert case not in sample_cases
    with open("testplan", "a", encoding="utf-8") as testplan:
        testplan.write(f"{case} {points}\n")


def generate_Ns(subtask: int):
    max_n = subtask_n[subtask - 1]
    min_n = subtask_n[subtask - 2] if subtask > 2 else 0
    cases = subtask_cases[subtask - 1]
    assert cases < max_n

    Ns = random.sample(range(min_n + 1, max_n), cases - 2)
    return sorted(Ns) + [max_n] * 2


def generate_partition(n: int, k: int):
    ends = sorted([0] + random.sample(range(1, n + k), k - 1) + [n + k])
    return [next - curr - 1 for curr, next in pairwise(ends)]


def generate_case(n: int, subtask: int, is_odd_case: bool):
    if subtask != 1:
        Xs = [random.randint(-1000, 1000) for _ in range(n)]
        Ys = [random.randint(-1000, 1000) for _ in range(n)]
        return list(zip(Xs, Ys))

    if is_odd_case:
        Ys = [random.randint(-1000, 1000) for _ in range(n)]
        return list(zip([random.randint(-1000, 1000)] * n, Ys))

    X = random.randint(500, 1000)
    deltas = generate_partition(X - 1, n)
    random.shuffle(deltas)

    Yi, Ys = 0, []
    for d in deltas:
        Yi += d * random.choice([1, -1])
        Ys.append(Yi)
    return list(zip([random.choice([X, -X])] * n, Ys))


if __name__ == "__main__":
    random.seed(187401813644674703178718298643149488866262881351823)

    # Write testplan
    assert sum(subtask_points) == 100
    assert subtask_count == len(subtask_cases) == len(subtask_points)
    with open("testplan", "w", encoding="utf-8") as tp:
        for case_name in sample_cases:
            tp.write(f"{case_name} 0\n")
    for s in range(1, subtask_count + 1):
        write_case_to_testplan(s, 0, subtask_points[s - 1])
        for c in range(1, subtask_cases[s - 1]):
            write_case_to_testplan(s, c)

    # Write cases
    for s in range(1, subtask_count + 1):
        subtask_Ns = generate_Ns(s)
        for c in range(subtask_cases[s - 1]):
            case_n = subtask_Ns[c]
            case_name = f"{subtask_order[s - 1]}_sub{s}.{c}"
            case_path = os.path.join("cases", f"{case_name}.in")

            case_coords = generate_case(case_n, s, c % 2)
            coords_str = "\n".join([" ".join(map(str, coord))
                                    for coord in case_coords])
            with open(case_path, "w", encoding="utf-8") as cf:
                cf.write(f"{case_n}\n{coords_str}\n")
