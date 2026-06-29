import os
import random
from dataclasses import dataclass
from typing import Callable, List, Tuple

subtasks_are_grouped = True

MAX_N = 10**5
MAX_DEGREE_SUM = 5 * 10**5
MAX_M = MAX_DEGREE_SUM // 2


@dataclass(frozen=True)
class CaseData:
    n: int
    degrees: List[int]


@dataclass(frozen=True)
class Subtask:
    name: str
    score: int
    builders: List[Callable[[], CaseData]]


def normalize_edge(u: int, v: int) -> Tuple[int, int]:
    assert u != v
    return (u, v) if u < v else (v, u)


def degrees_from_edges(n: int, edges: List[Tuple[int, int]]) -> List[int]:
    """Convierte un grafo simple no dirigido a su secuencia de grados."""
    degrees = [0] * n
    seen = set()

    for u, v in edges:
        assert 0 <= u < n
        assert 0 <= v < n
        assert u != v
        edge = normalize_edge(u, v)
        assert edge not in seen, f"duplicated edge: {edge}"
        seen.add(edge)
        degrees[u] += 1
        degrees[v] += 1

    # Reetiquetar vértices no cambia si la secuencia es gráfica, pero evita
    # que todas las secuencias no regulares queden ordenadas artificialmente.
    random.shuffle(degrees)
    return degrees


def complete_edges(n: int) -> List[Tuple[int, int]]:
    return [(i, j) for i in range(n) for j in range(i + 1, n)]


def path_edges(n: int) -> List[Tuple[int, int]]:
    return [(i, i + 1) for i in range(n - 1)]


def cycle_edges(n: int) -> List[Tuple[int, int]]:
    assert n >= 3
    return [(i, (i + 1) % n) for i in range(n)]


def matching_edges(n: int, m: int) -> List[Tuple[int, int]]:
    assert 0 <= m <= n // 2
    vertices = list(range(n))
    random.shuffle(vertices)
    return [(vertices[2 * i], vertices[2 * i + 1]) for i in range(m)]


def star_edges(n: int) -> List[Tuple[int, int]]:
    assert n >= 1
    return [(0, i) for i in range(1, n)]


def shifted_complete_edges(
        start: int,
        size: int,
) -> List[Tuple[int, int]]:
    edges = []
    for i in range(size):
        for j in range(i + 1, size):
            edges.append((start + i, start + j))
    return edges


def mixed_low_degree_edges(
        cycle_size: int,
        path_size: int,
        matching_size: int,
) -> List[Tuple[int, int]]:
    assert cycle_size == 0 or cycle_size >= 3
    assert path_size == 0 or path_size >= 2
    assert matching_size % 2 == 0
    assert cycle_size + path_size + matching_size <= MAX_N

    edges = []
    start = 0

    if cycle_size > 0:
        for i in range(cycle_size):
            u = start + i
            v = start + ((i + 1) % cycle_size)
            edges.append((u, v))
        start += cycle_size

    if path_size > 0:
        for i in range(path_size - 1):
            edges.append((start + i, start + i + 1))
        start += path_size

    for i in range(0, matching_size, 2):
        edges.append((start + i, start + i + 1))

    return edges


def varied_degree_edges() -> List[Tuple[int, int]]:
    return mixed_low_degree_edges(40_000, 20_000, 20_000)


def incomplete_cliques_edges(
        sizes: List[int],
        numerator: int,
        denominator: int,
) -> List[Tuple[int, int]]:
    assert 0 <= numerator <= denominator
    edges = []
    start = 0

    for size in sizes:
        block_edges = shifted_complete_edges(start, size)
        random.shuffle(block_edges)
        keep = len(block_edges) * numerator // denominator
        edges.extend(block_edges[:keep])
        start += size

    return edges


def random_edges(n: int, m: int) -> List[Tuple[int, int]]:
    """Genera m aristas distintas de un grafo simple con n vértices."""
    max_edges = n * (n - 1) // 2
    assert 0 <= m <= max_edges

    if max_edges <= 1_000_000 and m > max_edges // 4:
        edges = complete_edges(n)
        random.shuffle(edges)
        return edges[:m]

    edges = []
    seen = set()
    while len(edges) < m:
        u = random.randrange(n)
        v = random.randrange(n - 1)
        if v >= u:
            v += 1
        edge = normalize_edge(u, v)
        key = edge[0] * n + edge[1]
        if key in seen:
            continue
        seen.add(key)
        edges.append(edge)
    return edges


def regular_ring_edges(n: int, degree: int) -> List[Tuple[int, int]]:
    """Construye un grafo simple degree-regular con técnica de anillo."""
    assert 0 <= degree < n
    assert (n * degree) % 2 == 0

    edges = []

    for step in range(1, degree // 2 + 1):
        for u in range(n):
            v = (u + step) % n
            edges.append(normalize_edge(u, v))

    if degree % 2 == 1:
        assert n % 2 == 0
        half = n // 2
        for u in range(half):
            edges.append((u, u + half))

    assert len(edges) == n * degree // 2
    assert len(set(edges)) == len(edges)
    return edges


def make_from_edges(n: int, edges: List[Tuple[int, int]]) -> CaseData:
    degrees = degrees_from_edges(n, edges)
    return CaseData(n=n, degrees=degrees)


def make_empty(n: int) -> CaseData:
    return CaseData(n=n, degrees=[0] * n)


def make_complete(n: int) -> CaseData:
    return make_from_edges(n, complete_edges(n))


def make_matching(n: int, m: int) -> CaseData:
    return make_from_edges(n, matching_edges(n, m))


def make_path(n: int) -> CaseData:
    return make_from_edges(n, path_edges(n))


def make_cycle(n: int) -> CaseData:
    return make_from_edges(n, cycle_edges(n))


def make_random(n: int, m: int) -> CaseData:
    return make_from_edges(n, random_edges(n, m))


def make_regular(n: int, degree: int) -> CaseData:
    edges = regular_ring_edges(n, degree)
    return make_from_edges(n, edges)


def make_clique_with_isolated(n: int, clique_size: int) -> CaseData:
    assert clique_size <= n
    return make_from_edges(n, complete_edges(clique_size))


def make_varied_low_degree() -> CaseData:
    return make_from_edges(MAX_N, varied_degree_edges())


def make_mixed_low_degree_a() -> CaseData:
    edges = mixed_low_degree_edges(30_000, 20_000, 30_000)
    return make_from_edges(MAX_N, edges)


def make_mixed_low_degree_b() -> CaseData:
    edges = mixed_low_degree_edges(10_000, 50_000, 20_000)
    return make_from_edges(MAX_N, edges)


def make_incomplete_cliques() -> CaseData:
    edges = incomplete_cliques_edges([300, 250, 200, 150], 4, 5)
    return make_from_edges(MAX_N, edges)


def make_small_incomplete_cliques() -> CaseData:
    edges = incomplete_cliques_edges([30, 25, 20, 15], 3, 5)
    return make_from_edges(100, edges)


def GenerateCaseString(case: CaseData) -> str:
    return f"{case.n}\n{' '.join(map(str, case.degrees))}\n"


def GetCaseName(subtask: Subtask, case_index: int) -> str:
    prefixes = {
        "sub1": "2_sub1",
        "sub2": "3_sub2",
        "sub3": "4_sub3",
        "sub4": "1_sub4",
        "sub5": "5_sub5",
    }
    separator = "." if subtasks_are_grouped else "_"
    return f"{prefixes[subtask.name]}{separator}{case_index + 1}"


def validate_case(subtask: Subtask, case: CaseData) -> None:
    degrees = case.degrees
    degree_sum = sum(degrees)

    assert 1 <= case.n <= MAX_N, (subtask.name, case.n)
    assert len(degrees) == case.n, subtask.name
    assert all(0 <= d <= case.n - 1 for d in degrees), subtask.name
    assert degree_sum % 2 == 0, subtask.name
    assert degree_sum <= MAX_DEGREE_SUM, (subtask.name, degree_sum)

    if subtask.name == "sub1":
        assert max(degrees, default=0) <= 1, subtask.name
    elif subtask.name == "sub2":
        assert max(degrees, default=0) <= 2, subtask.name
    elif subtask.name == "sub3":
        assert len(set(degrees)) == 1, subtask.name
    elif subtask.name == "sub4":
        assert case.n <= 100, subtask.name


def build_subtasks() -> List[Subtask]:
    return [
        Subtask(
            name="sub1",
            score=14,
            builders=[
                lambda: make_complete(2),
                lambda: make_empty(MAX_N),
                lambda: make_matching(MAX_N, MAX_N // 2),
                lambda: make_matching(MAX_N, 1),
                lambda: make_matching(MAX_N, MAX_N // 4),
                lambda: make_matching(MAX_N, 10_000),
                lambda: make_matching(99_999, 49_999),
                lambda: make_matching(MAX_N, 40_000),
            ],
        ),
        Subtask(
            name="sub2",
            score=17,
            builders=[
                lambda: make_complete(3),
                lambda: make_empty(MAX_N),
                lambda: make_matching(MAX_N, MAX_N // 2),
                lambda: make_path(MAX_N),
                lambda: make_cycle(MAX_N),
                make_varied_low_degree,
                make_mixed_low_degree_a,
                make_mixed_low_degree_b,
            ],
        ),
        Subtask(
            name="sub3",
            score=25,
            builders=[
                lambda: make_complete(20),
                lambda: make_empty(MAX_N),
                lambda: make_regular(MAX_N, 1),
                lambda: make_regular(MAX_N, 5),
                lambda: make_regular(1000, 500),
                lambda: make_complete(707),
                lambda: make_regular(708, 706),
                lambda: make_regular(999, 500),
                lambda: make_regular(6000, 77),
                lambda: make_regular(5000, 100),
            ],
        ),
        Subtask(
            name="sub4",
            score=25,
            builders=[
                lambda: make_empty(1),
                lambda: make_complete(100),
                lambda: make_matching(100, 20),
                lambda: make_random(100, 80),
                lambda: make_random(100, 4000),
                lambda: make_from_edges(100, star_edges(100)),
                lambda: make_random(100, 60),
                lambda: make_random(100, 2400),
                lambda: make_random(100, 3300),
                make_small_incomplete_cliques,
            ],
        ),
        Subtask(
            name="sub5",
            score=19,
            builders=[
                lambda: make_complete(40),
                lambda: make_random(MAX_N, MAX_M),
                lambda: make_random(MAX_N, 1000),
                lambda: make_random(800, MAX_M),
                lambda: make_from_edges(MAX_N, star_edges(MAX_N)),
                lambda: make_clique_with_isolated(MAX_N, 707),
                lambda: make_random(50_000, 150_000),
                lambda: make_random(MAX_N, MAX_M),
                lambda: make_random(MAX_N, MAX_M),
                make_incomplete_cliques,
                lambda: make_random(1771, MAX_M),
                lambda: make_random(5000, MAX_M),
            ],
        ),
    ]


def GenerateCases():
    random.seed("tira paro, amigo random")
    subtasks = build_subtasks()
    os.makedirs("cases", exist_ok=True)

    # Escribir el testplan.
    with open("testplan", "w", encoding="utf-8", newline="\n") as testplan:
        testplan.write("3_sub2.sample 0\n")
        testplan.write("1_sub4.sample 0\n")
        testplan.write("3_sub2.extra 0\n")
        testplan.write("1_sub4.extra 0\n")
        testplan.write("5_sub5.extra 0\n")

        total_score = 0
        for subtask in subtasks:
            total_cases = len(subtask.builders)
            cases_with_extra_point = subtask.score % total_cases

            for case_number in range(total_cases):
                if subtasks_are_grouped:
                    case_score = 0 if case_number > 0 else subtask.score
                else:
                    case_score = subtask.score // total_cases
                    if case_number < cases_with_extra_point:
                        case_score += 1

                case_name = GetCaseName(subtask, case_number)
                testplan.write(f"{case_name} {case_score}\n")
                total_score += case_score

        assert total_score == 100

    # Escribir los casos.
    for subtask in subtasks:
        for case_number, builder in enumerate(subtask.builders):
            case_name = GetCaseName(subtask, case_number)
            print(f"Generating {case_name}")
            case_data = builder()
            validate_case(subtask, case_data)

            case_path = os.path.join("cases", f"{case_name}.in")
            with open(case_path, "w", encoding="utf-8", newline="\n") as file:
                file.write(GenerateCaseString(case_data))

    print("The cases have been generated")


if __name__ == "__main__":
    GenerateCases()
