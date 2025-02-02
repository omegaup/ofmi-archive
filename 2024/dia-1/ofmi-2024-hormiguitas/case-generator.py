import os
import random

base_string = """
{n} {m} {q}
{Q}
""".strip(
    " \t\n\r"
)

num_subtareas = 4
puntos_por_subtarea = [23, 35, 24, 18]
casos_por_subtarea = [10, 10, 10, 10]
orden_de_subtarea = [2, 1, 3, 4]
subtarea_agrupada = [True for _ in range(num_subtareas)]
sample_case_names = ["2_sub1.sample"]


def get_dimensions(subtarea, case_number):
    MAXN = 10**6
    MAXM = 10**6 if subtarea != 3 else 2
    MAXQ = 2 * (10**5) if subtarea != 1 else 2_000
    if is_within_last_k_cases(subtarea, case_number, k=3):
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
        m = generator(MAXM) if subtarea != 3 else MAXM
        q = generator(MAXQ)

    return (n, m, q)


def random_case(subtarea, n, m, q):
    if q == 0:
        return []

    U = [random.randint(1, n) for _ in range(q)]
    V = [random.randint(1, m) for _ in range(q)]

    # Let's make sure we have at least one repeated query
    U[random.randint(0, q - 1)] = U[random.randint(0, q - 1)]
    V[random.randint(0, q - 1)] = V[random.randint(0, q - 1)]

    if subtarea == 2:
        U.sort()

    return list(zip(U, V))


def special_case_1(subtarea, n, m, q):
    num_stages = random.randint(1, 4) * 2
    batch = q // num_stages

    def generate_stage(min_u, max_u, stage_number):
        # u1 v1
        # u2 v2
        # u3 v3  (such that u1 < u2 < ... and v1 < v2 < ...)
        # ... (up to batch size, and then at the end)
        # u_batch, random(v1, v_batch)
        U = [random.randint(min_u, max_u) for _ in range(batch - 1)]
        V = [random.randint(1, m) for _ in range(batch - 1)]
        U.sort()
        V.sort()
        W = list(zip(U, V))
        if subtarea != 2:
            random.shuffle(W)
        W += [(U[-1], random.randint(V[0], V[-1]))]

        if subtarea != 2 and (stage_number % 2 == 0):
            # mirror
            W = [(n - u + 1, m - v + 1) for (u, v) in W]

        return W

    if subtarea != 2:
        stages = (generate_stage(1, n, i) for i in range(num_stages))
    else:
        jump_sz = n // num_stages
        stages = (
            generate_stage(1 + (i * jump_sz), 1 + (i + 1) * jump_sz, i)
            for i in range(num_stages)
        )

    W = list(sum(stages, []))
    missing = random_case(subtarea, n, m, (q % batch))
    W.extend(missing)
    if subtarea == 2:
        W.sort()
    return W


def special_case_2(subtarea, n, m, q):
    num_stages = random.randint(1, 2) * 2
    batch = q // num_stages

    def generate_stage(min_u, max_u, stage_number):
        # u1 v1
        # u2 v2
        # u3 v3  (such that u1 < u2 < ... and v1 < v2 < ...)
        # ... (up to batch size / 2, and then)
        # u_{batch / 2}, v_{batch / 2}
        # u_{batch / 2 + 1}, v_{batch / 2 - shift}

        half_batch = batch // 2
        U = [random.randint(min_u, max_u) for _ in range(batch)]
        V = [random.randint(1, m) for _ in range(half_batch)]
        U.sort()
        V.sort()

        V_reversed = V[::-1]
        V_shift = V_reversed[stage_number:] + V_reversed[:stage_number]
        V = V + V_shift
        if len(V) < len(U):
            V += [V[-1]]

        W = list(zip(U, V))
        if subtarea != 2:
            if stage_number % 2 == 0:
                # mirror
                W = [(n - u + 1, m - v + 1) for (u, v) in W]

            WL = W[:half_batch]
            WR = W[half_batch:]
            random.shuffle(WL)
            W = WL + WR

        return W

    if subtarea != 2:
        stages = (generate_stage(1, n, shift) for shift in range(num_stages))
    else:
        jump_sz = n // num_stages
        stages = (
            generate_stage(1 + (i * jump_sz), 1 + (i + 1) * jump_sz, i)
            for i in range(num_stages)
        )

    W = list(sum(stages, []))
    missing = random_case(subtarea, n, m, (q % batch))
    W.extend(missing)
    if subtarea == 2:
        W.sort()
    return W


def generate_queries(subtarea, case_number, n, m, q):
    if is_within_last_k_cases(subtarea, case_number, k=1):
        return special_case_1(subtarea, n, m, q)
    if is_within_last_k_cases(subtarea, case_number, k=2):
        return special_case_2(subtarea, n, m, q)

    return random_case(subtarea, n, m, q)


def generate_case(subtarea, case_number):
    n, m, q = get_dimensions(subtarea, case_number)
    print(get_case_name(subtarea, case_number))
    print(n, m, q)
    Q = generate_queries(subtarea, case_number, n, m, q)
    assert len(Q) == q
    return {
        "n": n,
        "m": m,
        "q": q,
        "Q": "\n".join(f"{u} {v}" for (u, v) in Q),
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
    prefix = orden_de_subtarea[subtarea - 1]
    agrupados = subtarea_agrupada[subtarea - 1]
    if agrupados:
        return f"{prefix}_sub{subtarea}.{case_number}"
    return f"{prefix}_sub{subtarea}_{case_number}"


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
    assert sum(puntos_por_subtarea) == 100
    write_testplan()
    write_cases()


if __name__ == "__main__":
    main()
