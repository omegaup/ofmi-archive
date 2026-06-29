import os
import random

base_string = """
{a} {b} {c} {d}
""".strip(
    " \t\n\r"
)

num_subtareas = 1
puntos_por_subtarea = [100]
casos_por_subtarea = [20]
sample_case_names = ["sub1_sample1", "sub1_sample2"]


def get_case_name(subtarea, case_number):
    return f"sub{subtarea}_{case_number}"


def get_case_points(subtarea, case_number):
    puntos_subtarea = puntos_por_subtarea[subtarea - 1]
    casos_subtarea = casos_por_subtarea[subtarea - 1]
    return puntos_subtarea // casos_subtarea + (
        1 if puntos_subtarea % casos_subtarea > case_number else 0
    )


def generate_case(case_number):
    cases = [
        {"a": 0, "b": 0, "c": 0, "d": 0},
        {"a": 100, "b": 100, "c": 100, "d": 100},
        {"a": 6, "b": 10, "c": 20, "d": 30},
        {"a": 10, "b": 7, "c": 20, "d": 30},
        {"a": 10, "b": 20, "c": 8, "d": 30},
        {"a": 10, "b": 20, "c": 30, "d": 9},
        {"a": 1, "b": 5, "c": 10, "d": 20},
        {"a": 5, "b": 2, "c": 10, "d": 20},
        {"a": 5, "b": 10, "c": 3, "d": 20},
        {"a": 5, "b": 10, "c": 20, "d": 4},
        {"a": 100, "b": 99, "c": 98, "d": 97},
        {"a": 50, "b": 50, "c": 50, "d": 50},
        {"a": 12, "b": 34, "c": 56, "d": 78},
        {"a": 78, "b": 56, "c": 34, "d": 13},
        {"a": 5, "b": 10, "c": 5, "d": 100},
    ]

    if case_number < len(cases):
        return cases[case_number]

    return {
        "a": random.randint(14, 100),
        "b": random.randint(14, 100),
        "c": random.randint(14, 100),
        "d": random.randint(14, 100)
    }


def write_testplan():
    assert len(sample_case_names) == len(set(sample_case_names))
    with open("testplan", "w", newline="\n") as f:
        for case_name in sample_case_names:
            f.write(f"{case_name} 0\n")

    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_points = get_case_points(subtarea, case_number)
            assert case_name not in sample_case_names
            with open("testplan", "a", newline="\n") as f:
                f.write(f"{case_name} {case_points}\n")


def write_cases():
    os.makedirs("cases", exist_ok=True)
    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_path = os.path.join("cases", case_name)
            with open(f"{case_path}.in", "w", newline="\n") as f:
                case = generate_case(case_number)
                case_string = base_string.format(**case)
                f.write(f"{case_string}\n")


def main():
    random.seed(42)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == "__main__":
    main()
