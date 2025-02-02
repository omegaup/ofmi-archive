import os
import random

base_string = """
{n} {m}
{arr}
""".strip(
    " \t\n\r"
)

num_subtareas = 4
puntos_por_subtarea = [17, 18, 30, 35]
casos_por_subtarea = [5, 10, 10, 10]
subtarea_agrupada = [True for _ in range(num_subtareas)]
sample_case_names = ["sub2.sample", "sub4.sample"]


def is_within_last_k_cases(subtarea, case_number, k):
    return case_number + k >= casos_por_subtarea[subtarea - 1]


def is_last_case(subtarea, case_number):
    return is_within_last_k_cases(subtarea, case_number, k=1)


def get_dimensions(subtarea, case_number):
    MAXN = 10 if subtarea == 1 else (1 if subtarea == 3 else 1000)
    MAXM = MAXN if subtarea != 3 else 1000
    if case_number == 0:
        n, m = MAXN, MAXM
    elif subtarea == 1:
        n = random.randint(1, MAXN)
        m = random.randint(1, MAXM)
    else:
        n = random.randint(
            1, max(1, power_incremental(subtarea, case_number, MAXN, k=3))
        )
        m = random.randint(
            1, max(1, power_incremental(subtarea, case_number, MAXM, k=3))
        )
    return (n, m)


def generate_matrix(subtarea, n, m):
    # Lets chose the answer
    i1 = random.randint(0, n - 1)
    i2 = random.randint(0, n - 1)
    i1, i2 = min(i1, i2), max(i1, i2)
    j1 = random.randint(0, m - 1)
    j2 = random.randint(0, m - 1)
    j1, j2 = min(j1, j2), max(j1, j2)
    # This will be the frequency of the most frequent
    freq = {}
    max_frequency = (
        random.randint(1, (j2 - j1 + 1) * (i2 - i1 + 1))
        if subtarea != 1
        else (
            (
                # pylint: disable=E1101
                random.binomialvariate(
                    n=1,
                    p=((casos_por_subtarea[subtarea - 1]) - 1)
                    / (casos_por_subtarea[subtarea - 1]),
                )
                + 1
            )
            if (j2 - j1 + 1) * (i2 - i1 + 1) > 1
            else 1
        )
    )

    d = n * m - (n * m + max_frequency - 1) // max_frequency
    dl = abs(int(random.normalvariate(mu=0, sigma=d / 12)))

    max_num_colors = min(
        n * m,
        (n * m + max_frequency - 1) // max_frequency + dl,
    )
    # Now generate an array of size colors where [frequency] is the
    # greatest and sum arr is n * m
    missing = set((i, j) for i in range(n) for j in range(m))
    possible_in_ans = set(
        (
            i,
            j,
        )
        for i in range(i1, i2 + 1)
        for j in range(j1, j2 + 1)
    )

    matrix = [[0 for _ in range(m)] for _ in range(n)]

    for i, j in random.sample(sorted(possible_in_ans), k=max_frequency):
        color = 1
        freq[color] = freq[color] + 1 if color in freq else 1
        matrix[i][j] = color
        missing.remove((i, j))

    assert (len(missing) + max_frequency) == n * m

    missing_colors = set(color for color in range(2, max_num_colors + 1))
    max_frequency = max_frequency if subtarea != 2 else (max_frequency - 1)
    for i, j in random.sample(sorted(missing), k=len(missing)):
        color = random.randint(
            random.randint(random.randint(2, max_num_colors), max_num_colors),
            max_num_colors,
        )
        while color != 1 and color in freq and (freq[color] >= max_frequency):
            if color in missing_colors:
                missing_colors.remove(color)
            if len(missing_colors) == 0:
                # Sad, we'll have to place a 1
                color = 1
            else:
                color = random.choice(sorted(missing_colors))
        freq[color] = freq[color] + 1 if color in freq else 1
        matrix[i][j] = color

    MAXC = (
        random.randint(max_num_colors, 10**6)
        # pylint: disable=E1101
        if random.binomialvariate(n=1, p=1 / 9) == 1
        else max_num_colors
    )
    change_colors = list(i for i in range(1, MAXC + 1))
    random.shuffle(change_colors)

    def new_color(color):
        if subtarea == 2:
            if color == 1:
                return 1
            if change_colors[color - 1] == 1:
                return change_colors[0]
        return change_colors[color - 1]

    # Change color 1 to hide which is the most frequent
    change_color = int(random.choice(sorted(freq.keys())))
    matrix = [[new_color(color) for color in row] for row in matrix]
    freq[1], freq[change_color] = freq[change_color], freq[1]

    print(
        "Sub",
        subtarea,
        "n=",
        n,
        "m=",
        m,
        "last frequencies=",
        sorted(freq.values())[-10:],
    )
    return matrix


def generate_case(subtarea, case_number):
    n, m = get_dimensions(subtarea, case_number)
    matrix = generate_matrix(subtarea, n, m)
    return {
        "n": n,
        "m": m,
        "arr": "\n".join(" ".join(str(v) for v in row) for row in matrix),
    }


def generate_killer_case():
    n, m = 1000, 1000
    matrix = [range(i*m + 1, i*m + m + 1) for i in range(n)]
    return {
        "n": n,
        "m": m,
        "arr": "\n".join(" ".join(str(v) for v in row) for row in matrix),
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

    with open("testplan", "a") as f:
        f.write("sub4.10 0\n")


def write_cases():
    for subtarea in range(1, num_subtareas + 1):
        for case_number in range(casos_por_subtarea[subtarea - 1]):
            case_name = get_case_name(subtarea, case_number)
            case_path = os.path.join("cases", case_name)
            with open(f"{case_path}.in", "w") as f:
                case = generate_case(subtarea, case_number)
                case_string = base_string.format(**case)
                f.write(f"{case_string}\n")

    case_path = os.path.join("cases", "sub4.10")
    with open(f"{case_path}.in", "w") as f:
        case = generate_killer_case()
        case_string = base_string.format(**case)
        f.write(f"{case_string}\n")


def main():
    random.seed(24017)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == "__main__":
    main()
