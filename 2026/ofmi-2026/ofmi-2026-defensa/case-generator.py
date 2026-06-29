import os
import random
from collections import defaultdict, namedtuple

subtasks_are_grouped = True

MAX_N = 10**9
MAX_K = 10**5
MAX_Q = 10**5
MAX_ENERGY = 10**9
ENERGY_TARGET = MAX_ENERGY - 7

Subtask = namedtuple("Subtask", "name cases score extra_cases")
subtasks = [
    Subtask("sub1", 8, 12, ["sample"]),
    Subtask("sub2", 6, 8, ["sample"]),
    Subtask("sub3", 7, 19, ["sample"]),
    Subtask("sub4", 8, 26, []),
    Subtask("sub5", 8, 8, []),
    Subtask("sub6", 8, 16, []),
    Subtask("sub7", 10, 11, []),
]

Update = namedtuple("Update", "left right energy")
CaseData = namedtuple("CaseData", "n updates queries")


def AvoidFullRange(left, right, n, index):
    if left != 1 or right != n:
        return left, right
    if n == 1:
        return left, right
    if index % 2 == 0:
        return 2, right
    return left, n - 1


def DenseWideRanges(n, k, rng):
    margin = max(1, n // 10000)
    ranges = []
    for index in range(k):
        left = 1 + rng.randint(0, margin)
        right = n - rng.randint(0, margin)
        left, right = AvoidFullRange(left, right, n, index)
        ranges.append((left, right))
    return ranges


def StaircaseWideRanges(n, k):
    margin = max(1, n // 2000)
    ranges = []
    for index in range(k):
        left = 1 + (index * 37) % (margin + 1)
        right = n - (index * 91) % (margin + 1)
        left, right = AvoidFullRange(left, right, n, index)
        ranges.append((left, right))
    return ranges


def NestedRanges(n, k):
    middle = (n + 1) // 2
    margin = max(1, n // 4)
    ranges = []
    for index in range(k):
        left = 1 + (index * 53) % (margin + 1)
        right = n - (index * 97) % (margin + 1)
        left = min(left, middle)
        right = max(right, middle)
        left, right = AvoidFullRange(left, right, n, index)
        ranges.append((left, right))
    return ranges


def DispersedRanges(n, k, rng):
    slots = min(n, k)
    ranges = []
    for index in range(k):
        slot = index % slots
        block_left = slot * n // slots + 1
        block_right = (slot + 1) * n // slots
        block_size = block_right - block_left + 1
        length = max(1, block_size // 3)
        offset = rng.randint(0, block_size - length)
        left = block_left + offset
        ranges.append((left, left + length - 1))
    return ranges


def MixedRanges(n, k, rng):
    dense_count = k // 2
    ranges = DenseWideRanges(n, dense_count, rng)
    ranges.extend(DispersedRanges(n, k - dense_count, rng))
    rng.shuffle(ranges)
    return ranges


def CompletelyRandomRanges(n, k, rng):
    ranges = []
    for index in range(k):
        first = rng.randint(1, n)
        second = rng.randint(1, n)
        left = min(first, second)
        right = max(first, second)
        left, right = AvoidFullRange(left, right, n, index)
        ranges.append((left, right))
    return ranges


def CompletelyRandomPoints(n, k, rng):
    return [(point, point) for point in (
        rng.randint(1, n) for _ in range(k)
    )]


def IncreasingMultiplicityPoints(n, k):
    ranges = []
    point = 1
    multiplicity = 1

    while len(ranges) + multiplicity <= k:
        ranges.extend((point, point) for _ in range(multiplicity))
        point += 1
        multiplicity += 1

    remaining = k - len(ranges)
    ranges.extend((n, n) for _ in range(remaining))
    assert len(ranges) == k
    return ranges


def UnitUpdates(ranges, rng):
    rng.shuffle(ranges)
    return [Update(left, right, 1) for left, right in ranges]


def RaiseEnergySumToLimit(energies, rng):
    remaining = ENERGY_TARGET - sum(energies)
    assert remaining >= 0

    indices = list(range(len(energies)))
    rng.shuffle(indices)
    indices = indices[:min(1000, len(indices))]

    for position, index in enumerate(indices):
        slots_left = len(indices) - position
        addition = (remaining + slots_left - 1) // slots_left
        energies[index] += addition
        remaining -= addition

    assert remaining == 0
    assert sum(energies) == ENERGY_TARGET
    return energies


def WeightedEnergies(k, rng, mode):
    if mode == "cyclic":
        energies = [1 + index % 18000 for index in range(k)]
    elif mode == "random":
        energies = [rng.randint(1, 9000) for _ in range(k)]
    elif mode == "alternating":
        energies = [1 if index % 2 == 0 else 15000 for index in range(k)]
    elif mode == "spiky":
        energies = [1 for _ in range(k)]
        for index in range(0, k, 100):
            energies[index] = 500000
    elif mode == "bands":
        energies = [1 + (index // 250) % 12000 for index in range(k)]
    else:
        raise ValueError(f"Unknown energy mode: {mode}")

    assert sum(energies) <= MAX_ENERGY
    return RaiseEnergySumToLimit(energies, rng)


def WeightedUpdates(ranges, rng, mode):
    rng.shuffle(ranges)
    energies = WeightedEnergies(len(ranges), rng, mode)
    return [
        Update(left, right, energy)
        for (left, right), energy in zip(ranges, energies)
    ]


def UnitQueries(k):
    if k == MAX_Q:
        queries = list(range(1, k + 1))
    else:
        values = list(range(1, k + 1))
        if k < MAX_ENERGY:
            values.append(k + 1)
        queries = [values[index % len(values)] for index in range(MAX_Q)]
    return queries


def AttainedEnergies(n, updates):
    events = defaultdict(int)
    for update in updates:
        events[update.left] += update.energy
        if update.right < n:
            events[update.right + 1] -= update.energy

    attained = set()
    current = 0
    previous = 1

    for position in sorted(events):
        if previous < position and current > 0:
            attained.add(current)
        current += events[position]
        previous = position

    if previous <= n and current > 0:
        attained.add(current)
    return attained


def AddImpossibleQueries(n, updates, queries, rng):
    max_attained = max(AttainedEnergies(n, updates))
    assert max_attained + 7 <= MAX_ENERGY

    chosen = rng.sample(range(len(queries)), 2)
    queries[chosen[0]] = max_attained + 1
    queries[chosen[1]] = max_attained + 7
    rng.shuffle(queries)
    return queries


def WeightedQueries(n, updates, rng):
    attained = sorted(AttainedEnergies(n, updates))
    assert attained

    if len(attained) <= MAX_Q:
        queries = list(attained)
    else:
        queries = rng.sample(attained, MAX_Q)

    boundary_values = []
    for value in attained:
        if value < MAX_ENERGY:
            boundary_values.append(value + 1)
        if len(boundary_values) >= MAX_Q // 4:
            break

    rng.shuffle(boundary_values)
    while len(queries) < MAX_Q and boundary_values:
        queries.append(boundary_values.pop())

    while len(queries) < MAX_Q:
        if rng.randint(0, 1) == 0:
            queries.append(rng.choice(attained))
        else:
            queries.append(rng.randint(1, MAX_ENERGY))

    if len(queries) > MAX_Q:
        queries = rng.sample(queries, MAX_Q)

    queries[0] = rng.choice(attained)
    return queries


def PresentQuery(n, updates):
    attained = sorted(AttainedEnergies(n, updates))
    assert attained
    return attained[len(attained) // 2]


def UnitCase(n, ranges, rng):
    updates = UnitUpdates(ranges, rng)
    queries = UnitQueries(len(ranges))
    queries = AddImpossibleQueries(n, updates, queries, rng)
    return CaseData(n, updates, queries)


def BuildUnitRangeCases(n, rng):
    generators = [
        lambda: DenseWideRanges(n, 12345, rng),
        lambda: StaircaseWideRanges(n, 98765),
        lambda: NestedRanges(n, 99991),
        lambda: DispersedRanges(n, 77777, rng),
        lambda: MixedRanges(n, MAX_K, rng),
        lambda: MixedRanges(n, MAX_K, rng),
        lambda: CompletelyRandomRanges(n, MAX_K, rng),
        lambda: CompletelyRandomRanges(n, MAX_K, rng),
    ]
    for generate_ranges in generators:
        yield UnitCase(n, generate_ranges(), rng)


def BuildSub1Cases(rng):
    yield from BuildUnitRangeCases(100, rng)


def BuildSub2Cases(rng):
    n = MAX_N
    ranges = [(123457, n - 765431)]
    yield UnitCase(n, ranges, rng)

    ranges = [(100003, n - 1000003), (700001, n - 400009)]
    yield UnitCase(n, ranges, rng)

    ranges = [(200003, n // 2 - 1009), (n // 2 + 2003, n - 300007)]
    yield UnitCase(n, ranges, rng)

    ranges = [(300007, n - 500009), (n // 5, 4 * n // 5)]
    yield UnitCase(n, ranges, rng)

    ranges = [(17, n // 2), (n // 2 + 1, n - 23)]
    yield UnitCase(n, ranges, rng)

    yield UnitCase(n, CompletelyRandomRanges(n, 2, rng), rng)


def BuildSub3Cases(rng):
    n = 10**6
    middle = n // 2

    ranges = [(middle, middle) for _ in range(MAX_K)]
    yield UnitCase(n, ranges, rng)

    ranges = []
    for index in range(MAX_K):
        point = middle - 50 + (index * index + 17 * index) % 101
        ranges.append((point, point))
    yield UnitCase(n, ranges, rng)

    first = middle - 500
    ranges = []
    for _ in range(MAX_K):
        point = first + rng.randrange(1000)
        ranges.append((point, point))
    yield UnitCase(n, ranges, rng)

    ranges = []
    for index in range(MAX_K):
        point = 1 + index * (n - 1) // (MAX_K - 1)
        ranges.append((point, point))
    yield UnitCase(n, ranges, rng)

    yield UnitCase(n, IncreasingMultiplicityPoints(n, MAX_K), rng)
    yield UnitCase(n, CompletelyRandomPoints(n, MAX_K, rng), rng)
    yield UnitCase(n, CompletelyRandomPoints(n, MAX_K, rng), rng)


def BuildSub4Case(n, ranges, query, rng):
    updates = UnitUpdates(ranges, rng)
    if query is None:
        query = PresentQuery(n, updates)
    return CaseData(n, updates, [query])


def BuildSub4Cases(rng):
    n = 10**6
    ranges = DenseWideRanges(n, MAX_K, rng)
    yield BuildSub4Case(n, ranges, MAX_K, rng)

    ranges = NestedRanges(n, MAX_K)
    yield BuildSub4Case(n, ranges, MAX_K, rng)

    ranges = DispersedRanges(n, MAX_K, rng)
    yield BuildSub4Case(n, ranges, 1, rng)

    ranges = MixedRanges(n, MAX_K, rng)
    yield BuildSub4Case(n, ranges, None, rng)

    ranges = MixedRanges(n, MAX_K, rng)
    yield BuildSub4Case(n, ranges, None, rng)

    ranges = MixedRanges(n, MAX_K, rng)
    yield BuildSub4Case(n, ranges, None, rng)

    ranges = CompletelyRandomRanges(n, MAX_K, rng)
    yield BuildSub4Case(n, ranges, None, rng)

    ranges = CompletelyRandomRanges(n, MAX_K, rng)
    yield BuildSub4Case(n, ranges, None, rng)


def BuildSub5Cases(rng):
    yield from BuildUnitRangeCases(10**6, rng)


def BuildSub6Cases(rng):
    yield from BuildUnitRangeCases(MAX_N, rng)


def WeightedCase(n, ranges, rng, mode):
    updates = WeightedUpdates(ranges, rng, mode)
    queries = WeightedQueries(n, updates, rng)
    queries = AddImpossibleQueries(n, updates, queries, rng)
    return CaseData(n, updates, queries)


def BuildSub7Cases(rng):
    n = MAX_N
    generators = [
        (lambda: DenseWideRanges(n, MAX_K, rng), "cyclic"),
        (lambda: StaircaseWideRanges(n, MAX_K), "random"),
        (lambda: NestedRanges(n, MAX_K), "alternating"),
        (lambda: DispersedRanges(n, MAX_K, rng), "spiky"),
        (lambda: MixedRanges(n, MAX_K, rng), "bands"),
        (lambda: MixedRanges(n, MAX_K, rng), "random"),
        (lambda: MixedRanges(n, MAX_K, rng), "random"),
        (lambda: CompletelyRandomRanges(n, MAX_K, rng), "bands"),
        (lambda: CompletelyRandomRanges(n, MAX_K, rng), "random"),
        (lambda: CompletelyRandomRanges(n, MAX_K, rng), "random"),
    ]
    for generate_ranges, mode in generators:
        yield WeightedCase(n, generate_ranges(), rng, mode)


def GenerateCasesData(subtask, rng):
    builders = {
        "sub1": BuildSub1Cases,
        "sub2": BuildSub2Cases,
        "sub3": BuildSub3Cases,
        "sub4": BuildSub4Cases,
        "sub5": BuildSub5Cases,
        "sub6": BuildSub6Cases,
        "sub7": BuildSub7Cases,
    }
    yield from builders[subtask.name](rng)


def ValidateCase(subtask, case):
    n = case.n
    k = len(case.updates)
    q = len(case.queries)

    assert 1 <= n <= MAX_N
    assert 1 <= k <= MAX_K
    assert 1 <= q <= MAX_Q

    energy_sum = 0
    for update in case.updates:
        assert 1 <= update.left <= update.right <= n
        assert 1 <= update.energy <= MAX_ENERGY
        energy_sum += update.energy
    assert energy_sum <= MAX_ENERGY
    assert all(1 <= query <= MAX_ENERGY for query in case.queries)

    if subtask.name == "sub1":
        assert n == 100 and k <= MAX_K and q == MAX_Q
        assert all(update.energy == 1 for update in case.updates)
    elif subtask.name == "sub2":
        assert n == MAX_N and k in (1, 2) and q == MAX_Q
        assert all(update.energy == 1 for update in case.updates)
    elif subtask.name == "sub3":
        assert n == 10**6 and k == MAX_K and q == MAX_Q
        assert all(update.left == update.right for update in case.updates)
        assert all(update.energy == 1 for update in case.updates)
    elif subtask.name == "sub4":
        assert n == 10**6 and k == MAX_K and q == 1
        assert all(update.energy == 1 for update in case.updates)
        assert case.queries[0] in AttainedEnergies(n, case.updates)
    elif subtask.name == "sub5":
        assert n == 10**6 and k <= MAX_K and q == MAX_Q
        assert all(update.energy == 1 for update in case.updates)
    elif subtask.name == "sub6":
        assert n == MAX_N and k <= MAX_K and q == MAX_Q
        assert all(update.energy == 1 for update in case.updates)
    elif subtask.name == "sub7":
        assert n == MAX_N and k == MAX_K and q == MAX_Q
        assert energy_sum == ENERGY_TARGET
    else:
        raise ValueError(f"Unknown subtask: {subtask.name}")

    if subtask.name != "sub4":
        assert any(query <= energy_sum for query in case.queries)


def WriteCase(case, path):
    with open(path, "w", encoding="utf-8", newline="\n") as output:
        output.write(f"{case.n} {len(case.updates)}\n")
        output.writelines(
            f"{update.left} {update.right} {update.energy}\n"
            for update in case.updates
        )
        output.write(f"{len(case.queries)}\n")
        output.writelines(f"{query}\n" for query in case.queries)


def GetCaseName(subtask, number):
    if number < subtask.cases:
        case_name = str(number + 1)
        assert case_name not in subtask.extra_cases
    else:
        case_name = subtask.extra_cases[number - subtask.cases]
    separator = "." if subtasks_are_grouped else "_"
    return f"{subtask.name}{separator}{case_name}"


def WriteTestplan():
    with open("testplan", "w", encoding="utf-8", newline="\n") as testplan:
        total_score = 0
        for subtask in subtasks:
            total_cases = subtask.cases + len(subtask.extra_cases)
            extra_points = subtask.score % total_cases

            for case_number in range(total_cases):
                if subtasks_are_grouped:
                    case_score = subtask.score if case_number == 0 else 0
                else:
                    case_score = subtask.score // total_cases
                    if case_number < extra_points:
                        case_score += 1

                case_name = GetCaseName(subtask, case_number)
                testplan.write(f"{case_name} {case_score}\n")
                total_score += case_score

        assert total_score == 100


def GenerateCases():
    rng = random.Random("vamos mexico campeon do mundo!")
    os.makedirs("cases", exist_ok=True)
    WriteTestplan()

    for subtask in subtasks:
        generated_cases = 0
        cases = GenerateCasesData(subtask, rng)
        for case_number, case in enumerate(cases):
            assert case_number < subtask.cases
            ValidateCase(subtask, case)

            case_name = GetCaseName(subtask, case_number)
            print(f"Generating case {case_name}")
            path = os.path.join("cases", f"{case_name}.in")
            WriteCase(case, path)
            generated_cases += 1
            del case

        assert generated_cases == subtask.cases

    print("The cases have been generated")


if __name__ == "__main__":
    GenerateCases()
