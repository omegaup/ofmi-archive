import os
import random

base_string = """
{n} {m}
{P}
{q}
{A}
""".strip(
    " \t\n\r"
)

num_subtareas = 4
puntos_por_subtarea = [15, 26, 24, 35]
casos_por_subtarea = [10, 10, 10, 10]
orden_de_subtarea = [3, 2, 1, 4]
subtarea_agrupada = [True for _ in range(num_subtareas)]
sample_case_names = ["2_sub2.sample"]


def get_dimensions(subtarea, case_number):
    MAXN = 10**9 if subtarea != 2 else (2 * 10**5)
    MAXM = 2 * (10**5) if subtarea != 1 else 2
    MAXQ = 2 * (10**5) if subtarea != 3 else 300
    if is_last_case(subtarea, case_number):
        n, m, q = MAXN, MAXM, MAXQ
    else:

        def generator(max_value):
            mu = power_incremental(subtarea, case_number, max_value)
            sigma = (
                (
                    (
                        mu
                        - power_incremental(
                            subtarea,
                            case_number - 1,
                            max_value,
                        )
                    )
                    / 3
                )
                if case_number > 0
                else (mu / 3)
            )
            return int(
                min(
                    max_value,
                    max(1, random.normalvariate(mu=mu, sigma=sigma)),
                )
            )

        n = generator(MAXN)
        m = generator(min(MAXM, n)) if subtarea != 1 else MAXM
        q = generator(MAXQ)

    return (n, m, q)


def generate_partition(n, m):
    # Generates a random array of size m that sums n
    # Generate m-1 random points between 0 and n
    points = sorted(random.sample(range(1, n), m - 1))
    # Add 0 and n as boundaries
    points = [0] + points + [n]
    # Compute differences between consecutive points
    partition = [points[i + 1] - points[i] for i in range(m)]
    return partition


def generate_queries(n, q):
    A = [random.randint(1, n) for _ in range(q)]
    # Let's make sure we have at least one repeated query
    A[random.randint(0, q - 1)] = A[random.randint(0, q - 1)]
    A.sort()
    return A


def generate_case(subtarea, case_number):
    n, m, q = get_dimensions(subtarea, case_number)
    P = generate_partition(n, m)
    A = generate_queries(n, q)
    return {
        "n": n,
        "m": m,
        "q": q,
        "P": " ".join(str(pi) for pi in P),
        "A": "\n".join(str(ai) for ai in A),
    }


def is_within_last_k_cases(subtarea, case_number, k):
    return case_number + k >= casos_por_subtarea[subtarea - 1]


def is_last_case(subtarea, case_number):
    return is_within_last_k_cases(subtarea, case_number, k=1)


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
    orden = orden_de_subtarea[subtarea - 1]
    agrupados = subtarea_agrupada[subtarea - 1]
    if agrupados:
        return f"{orden}_sub{subtarea}.{case_number}"
    return f"{orden}_sub{subtarea}_{case_number}"


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
    random.seed(15161)
    assert num_subtareas == len(puntos_por_subtarea) == len(casos_por_subtarea)
    assert num_subtareas == len(orden_de_subtarea)
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == "__main__":
    main()
