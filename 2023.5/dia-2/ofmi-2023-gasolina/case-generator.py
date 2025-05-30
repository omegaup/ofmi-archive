import os
import random

base_string = """
{n} {L}
""".strip(
    " \t\n\r"
)

num_subtareas = 3
puntos_por_subtarea = [10, 25, 65]
casos_por_subtarea = [10, 9, 30]
subtarea_agrupada = [True for _ in range(num_subtareas)]
sample_case_names = ["sub1.sample"]


def generate_case(subtarea, case_number):
    MAX_L = 10**9
    MAX_N = 300
    if subtarea == 1:
        return {
            "n": 2,
            "L": random.randint(
                2,
                max(
                    2,
                    power_incremental(subtarea, case_number, MAX_L),
                ),
            ),
        }

    if subtarea == 2:
        return {
            "n": 2**case_number,
            "L": 2,
        }

    n = (
        random.randint(1, linear_incremental(subtarea, case_number, MAX_N))
        if case_number < 0.9 * casos_por_subtarea[subtarea - 1]
        else MAX_N
    )

    return {
        "n": n,
        "L": (
            random.randint(
                2,
                max(
                    2,
                    power_incremental(subtarea, case_number, MAX_L),
                ),
            )
            if random.choice([True, False])
            else random.randint(2, n)
        ),
    }


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
    return f"sub{subtarea}_{subtarea}.{case_number}"


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
