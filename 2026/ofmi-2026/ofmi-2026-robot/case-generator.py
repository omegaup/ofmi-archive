import itertools
import os
import random
from collections import namedtuple

subtasks_are_grouped = False

MAX_N = 10**6
MOVEMENTS = "^<v>"

Subtask = namedtuple("Subtask", "name, cases, score, max_N, extra_cases")
subtasks = [
    Subtask(
        name="sub1",
        cases=4,
        score=12,
        max_N=1,
        extra_cases=[],
    ),
    Subtask(
        name="sub2",
        cases=12,
        score=20,
        max_N=MAX_N,
        extra_cases=[],
    ),
    Subtask(
        name="sub3",
        cases=17,
        score=68,
        max_N=MAX_N,
        extra_cases=[],
    ),
]

CaseData = namedtuple("CaseData", "instructions")


def GetFinalPosition(instructions: str):
    latitude = instructions.count("^") - instructions.count("v")
    longitude = instructions.count(">") - instructions.count("<")
    return latitude, longitude


def GenerateRandomInstructions(n: int, require_all_movements: bool):
    while True:
        instructions = "".join(random.choices(MOVEMENTS, k=n))

        if require_all_movements and set(instructions) != set(MOVEMENTS):
            continue

        if GetFinalPosition(instructions) != (0, 0):
            return instructions


def GenerateSubtask1Cases(subtask: Subtask):
    data = []

    def AddCase(instructions: str):
        assert 1 <= len(instructions) <= subtask.max_N
        assert set(instructions).issubset(set(MOVEMENTS))
        assert GetFinalPosition(instructions) != (0, 0)
        data.append(CaseData(instructions))

    for movement in MOVEMENTS:
        AddCase(movement)

    while len(data) < subtask.cases:
        AddCase(random.choice(MOVEMENTS))

    print(len(data))
    assert len(data) == subtask.cases
    return data


def GenerateSubtask2Cases(subtask: Subtask):
    data = []

    def AddCase(instructions: str):
        assert 1 <= len(instructions) <= subtask.max_N
        assert set(instructions).issubset(set(MOVEMENTS))
        assert GetFinalPosition(instructions) != (0, 0)
        assert len(set(instructions)) == 1
        data.append(CaseData(instructions))

    lengths = [107, 1001, 10_000]
    for movement in MOVEMENTS:
        for length in lengths:
            if len(data) >= subtask.cases:
                break
            AddCase(movement * length)
        if len(data) >= subtask.cases:
            break

    print(len(data))
    assert len(data) == subtask.cases
    return data


def GenerateGeneralCasesData(subtask: Subtask):
    data = []

    def AddCase(instructions: str):
        assert 1 <= len(instructions) <= subtask.max_N
        assert set(instructions).issubset(set(MOVEMENTS))
        assert GetFinalPosition(instructions) != (0, 0)
        data.append(CaseData(instructions))

    # Los seis pares ordenados de dos movimientos distintos.
    for first, second in itertools.combinations(MOVEMENTS, 2):
        n = random.randint(20, 100)
        first_count = random.randint(1, n // 3)
        instructions = (
            [first] * first_count + [second] * (n - first_count)
        )
        random.shuffle(instructions)
        AddCase("".join(instructions))

    # Los cuatro pares ordenados de tres movimientos distintos.
    for first, second, third in itertools.combinations(MOVEMENTS, 3):
        n = random.randint(20, 100)
        first_count = random.randint(1, n // 3)
        second_count = random.randint(1, n // 3)
        instructions = (
            [first] * first_count + [second] * second_count +
            [third] * (n - first_count - second_count)
        )
        random.shuffle(instructions)
        AddCase("".join(instructions))

    # Dos casos aleatorios que todavía respetan n <= 100.
    for _ in range(2):
        n = random.randint(20, 100)
        AddCase(GenerateRandomInstructions(n, require_all_movements=True))

    # Cinco casos aleatorios grandes. Los últimos están muy cerca del límite.
    large_sizes = [77_777, 100_001, 500_000, 999_999, 1_000_000]
    for n in large_sizes:
        AddCase(GenerateRandomInstructions(n, require_all_movements=True))

    print(len(data))
    assert len(data) == subtask.cases
    return data


def GenerateCasesData(subtask: Subtask):
    if subtask.name == "sub1":
        return GenerateSubtask1Cases(subtask)
    if subtask.name == "sub2":
        return GenerateSubtask2Cases(subtask)
    return GenerateGeneralCasesData(subtask)


def GenerateCaseString(case: CaseData):
    return f"{len(case.instructions)}\n{case.instructions}\n"


def GetCaseName(subtask: Subtask, n: int):
    if n < subtask.cases:
        case_name = str(n + 1)
        assert case_name not in subtask.extra_cases
    else:
        case_name = subtask.extra_cases[n - subtask.cases]
    separator = "." if subtasks_are_grouped else "_"
    return f"{subtask.name}{separator}{case_name}"


def GenerateCases():
    random.seed("robot explorador en titan")
    os.makedirs("cases", exist_ok=True)

    # Escribir el testplan.
    with open("testplan", "w", encoding="utf-8", newline="\n") as testplan:
        testplan.write("sub3_sample1 0\n")
        testplan.write("sub3_sample2 0\n")

        total_score = 0
        for subtask in subtasks:
            total_cases = subtask.cases + len(subtask.extra_cases)
            cases_with_extra_point = subtask.score % total_cases

            for case_number in range(total_cases):
                if subtasks_are_grouped:
                    case_score = 0 if case_number > 0 else subtask.score
                else:
                    case_score = subtask.score // total_cases + (
                        1 if case_number < cases_with_extra_point else 0)

                testplan.write(
                    f"{GetCaseName(subtask, case_number)} {case_score}\n")
                total_score += case_score

        assert total_score == 100

    # Escribir los casos.
    for subtask in subtasks:
        cases_data = GenerateCasesData(subtask)
        for case_number, case_data in enumerate(cases_data):
            print(f"Generating case #{case_number + 1} for {subtask.name}")

            case_path = os.path.join(
                "cases", f"{GetCaseName(subtask, case_number)}.in")
            with open(case_path, "w", encoding="utf-8", newline="\n") as case:
                case.write(GenerateCaseString(case_data))

    print("The cases have been generated")


if __name__ == "__main__":
    GenerateCases()
