import os
import random

base_string = """
{arr}
""".strip(
    " \t\n\r"
)

num_subtareas = 1
puntos_por_subtarea = [100]
casos_por_subtarea = [21]
subtarea_agrupada = [False for _ in range(num_subtareas)]
sample_case_names = ["sample", "sample2"]


def has_solution(arr):
    for x in arr:
        for y in arr:
            z = 100 - x - y
            if z in arr and x != y and x != z and y != z:
                return True
    return False


def generate_case(_, case_number):
    n = 5
    if case_number == 0:
        # Generate impossible case
        arr = [random.randint(1, 100) for _ in range(n)]
        while len(arr) != len(set(arr)) or has_solution(arr):
            arr = [random.randint(1, 100) for _ in range(n)]
    else:
        # Generate random case
        a = random.randint(1, 100)
        b = random.randint(1, 100)
        a, b = min(a, b), max(a, b)
        arr = [a, b - a, 100 - b]
        while len(arr) != len(set(arr)):
            a = random.randint(1, 100)
            b = random.randint(1, 100)
            a, b = min(a, b), max(a, b)
            arr = [a, b - a, 100 - b]
        # shuffle the array
        random.shuffle(arr)
        # add random numbers
        for _ in range(n - 3):
            x = random.randint(1, 100)
            while x in arr:
                x = random.randint(1, 100)
            arr.append(x)
        perm = case_number % 10
        for i in range(n):
            for j in range(i + 1, n):
                perm -= 1
                if perm == 0:
                    arr[i], arr[-2] = arr[-2], arr[i]
                    arr[j], arr[-1] = arr[-1], arr[j]
    return {"arr": " ".join(map(str, arr))}


# This helper function will generate a number that is linearly increasing
# with the case number. This is useful to make cases bigger as the case_number
def linear_incremental(subtarea, case_number, max_number):
    casos_subtarea = casos_por_subtarea[subtarea - 1]
    # pendiente * casos_subtarea = max_number
    pendiente = max_number // casos_subtarea
    return pendiente * (case_number + 1)


# This helper function will generate a number that is k-power increasing
# with the case number. This is useful to make cases bigger as the case_number
def power_incremental(subtarea, case_number, max_number, k=4):
    casos_subtarea = casos_por_subtarea[subtarea - 1]
    # c* casos_subtarea^4 = max_number
    c = max_number / (casos_subtarea**k)
    return int(c * (case_number + 1) ** k)


def get_case_name(subtarea, case_number):
    agrupados = subtarea_agrupada[subtarea - 1]
    if agrupados:
        return f"sub{subtarea}.{case_number}"
    return f"sub{subtarea}_{case_number}"


def get_case_points(subtarea, case_number):
    puntos_subtarea = puntos_por_subtarea[subtarea - 1]
    casos_subtarea = casos_por_subtarea[subtarea - 1]
    agrupados = subtarea_agrupada[subtarea - 1]
    if agrupados:
        return puntos_subtarea if case_number == 0 else 0
    return puntos_subtarea // casos_subtarea + (
        1 if puntos_subtarea % casos_subtarea > case_number else 0
    )


def write_testplan():
    assert len(sample_case_names) == len(set(sample_case_names))
    with open("testplan", "w") as f:
        for case_name in sample_case_names:
            f.write(f"{case_name} 0\n")

    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_points = get_case_points(subtarea, case_number)
            assert case_name not in sample_case_names
            with open("testplan", "a") as f:
                f.write(f"{case_name} {case_points}\n")


def write_cases():
    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_path = os.path.join("cases", case_name)
            with open(f"{case_path}.in", "w") as f:
                case = generate_case(subtarea, case_number)
                case_string = base_string.format(**case)
                f.write(f"{case_string}\n")


def main():
    random.seed(348101)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == "__main__":
    main()
