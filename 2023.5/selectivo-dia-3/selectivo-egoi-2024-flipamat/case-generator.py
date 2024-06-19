import os
import random

base_string = """
{N} {M}
{mat}
""".strip(" \t\n\r")

num_subtareas = 4
puntos_por_subtarea = [8, 7, 42, 43]
casos_por_subtarea = [21, 14, 32, 33]
subtarea_agrupada = [False for _ in range(num_subtareas)]
sample_case_names = ["sub1_1.sample"]


def generate_case(subtarea, case_number):
    if subtarea == 1:
        MAX_NM = 10
        n = random.randint(1, MAX_NM)
        m = random.randint(1, MAX_NM)
        res = {
            "N": n,
            "M": m,
            "mat": "\n".join(
                "".join(
                    random.choice(
                        random.choice("01X") if case_number < 2
                        else random.choice("011X"))
                    for _ in range(m))
                for _ in range(n)),
        }

    if subtarea == 2:
        MAX_NM = 300
        n = random.randint(1, MAX_NM)
        m = random.randint(1, MAX_NM)
        res = {
            "N": n,
            "M": m,
            "mat": "\n".join(
                "".join(
                    random.choice("11X") for _ in range(m))
                for _ in range(n)),
        }
        ceros = random.randint(0, 3)
        for _ in range(ceros):
            x = random.randint(0, n-1)
            y = random.randint(0, m-1)
            res["mat"] = res["mat"][:x*m+y]+"0"+res["mat"][x*m+y+1:]

    if subtarea == 3:
        MAX_NM = 100
        n = random.randint(1, MAX_NM)
        m = random.randint(1, MAX_NM)
        res = {
            "N": n,
            "M": m,
            "mat": "\n".join(
                "".join(
                    random.choice("01X") for _ in range(m))
                for _ in range(n)),
        }

    if subtarea == 4:
        MAX_NM = 300
        n = random.randint(1, MAX_NM)
        m = random.randint(1, MAX_NM)
        res = {
            "N": n,
            "M": m,
            "mat": "\n".join(
                "".join(
                    random.choice("01X") for _ in range(m))
                for _ in range(n)),
        }

    return res


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
    random.seed(5374682)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == "__main__":
    main()
