import os
import random
from collections import namedtuple

MAX_TOTAL_MASS = 10**9

sample_cases = ["sub1_sample", "sub2.sample", "sub3.extra", "sub4.extra"]

Subtask = namedtuple("Subtask", "name, score, max_n, max_sum")
subtasks = [
    Subtask(name="sub1", score=32, max_n=2, max_sum=MAX_TOTAL_MASS),
    Subtask(name="sub2", score=28, max_n=100, max_sum=10**4),
    Subtask(name="sub3", score=24, max_n=1000, max_sum=MAX_TOTAL_MASS),
    Subtask(name="sub4", score=16, max_n=10**5, max_sum=MAX_TOTAL_MASS),
]

CaseData = namedtuple("CaseData", "masses, answer")


def MinimalInitialCharge(masses):
    answer = 0
    prefix_sum = 0
    for mass in sorted(masses):
        answer = max(answer, mass - prefix_sum)
        prefix_sum += mass
    return answer


def PositivePartition(total, parts):
    assert 1 <= parts <= total
    if parts == 1:
        return [total]

    cap = max(min(total, 7 * parts), int(total ** (1 / (parts - 1))))
    cuts = sorted(random.sample(range(1, cap), parts - 1))
    return [b - a for a, b in zip([0] + cuts, cuts + [total])]


def BuildFromAnswerIncrements(increments, max_sum):
    masses = []
    answer = 0
    prefix_sum = 0

    for increase in increments:
        if increase > 0:
            answer += increase
            mass = prefix_sum + answer
            low = mass
        else:
            offset = 77 if max_sum == MAX_TOTAL_MASS else 7
            mass = low + random.randint(0, offset)

        masses.append(mass)
        prefix_sum += mass

        if prefix_sum > max_sum:
            return None

    return masses


def InterleaveZeroes(parts, zeroes):
    parts.sort()
    parts.reverse()
    interleaved = [parts.pop()]

    while zeroes or len(parts) > 0:
        if random.random() < len(parts) / (zeroes + 1) ** 1.5:
            interleaved.append(parts.pop())
        else:
            interleaved.append(0)
            zeroes -= 1

    return interleaved


def MakeIncrementCase(
        n,
        answer,
        max_sum,
        positive_parts,
        attempts=2000):
    assert n >= 1
    assert answer >= 1

    positive_parts = min(positive_parts, n, answer)
    zeroes = n - positive_parts

    for _ in range(attempts):
        parts = PositivePartition(answer, positive_parts)
        increments = InterleaveZeroes(parts, zeroes)
        masses = BuildFromAnswerIncrements(increments, max_sum)

        if not masses or MinimalInitialCharge(masses) != answer:
            continue

        random.shuffle(masses)
        return CaseData(masses=masses, answer=answer)

    raise RuntimeError("Could not generate increment case")


# pylint: disable=too-many-arguments
def MakeBigSmallCase(
        n,
        answer,
        huge_count,
        small_max,
        max_sum,
        attempts=2000):
    assert 1 <= huge_count <= n
    small_count = n - huge_count

    for _ in range(attempts):
        smalls = [random.randint(1, small_max) for _ in range(small_count)]
        smalls.sort()

        if smalls and MinimalInitialCharge(smalls) >= answer:
            continue

        total = sum(smalls)
        first_huge = total + answer
        if first_huge <= 0:
            continue

        huge = [first_huge]
        total += first_huge
        last_huge = first_huge

        ok = total <= max_sum
        while ok and len(huge) < huge_count:
            remaining = huge_count - len(huge) - 1
            low = last_huge
            high = total + answer
            budget_high = max_sum - total - remaining * low
            high = min(high, budget_high)

            if high < low:
                ok = False
                break

            mass = random.randint(low, high)
            huge.append(mass)
            total += mass
            last_huge = mass

        if not ok or total > max_sum:
            continue

        masses = smalls + huge
        if MinimalInitialCharge(masses) != answer:
            continue

        random.shuffle(masses)
        return CaseData(masses=masses, answer=answer)

    raise RuntimeError("Could not generate big-small case")


def MakeRandomSmallCase(n, low, high, max_sum, attempts=2000):
    for _ in range(attempts):
        masses = [random.randint(low, high) for _ in range(n)]
        if sum(masses) <= max_sum:
            answer = MinimalInitialCharge(masses)
            random.shuffle(masses)
            return CaseData(masses=masses, answer=answer)

    raise RuntimeError("Could not generate random small case")


def MakeManualCase(masses, do_shuffle=True):
    masses = list(masses)
    if do_shuffle:
        random.shuffle(masses)
    return CaseData(masses=masses, answer=MinimalInitialCharge(masses))


def ValidateCase(case, subtask):
    masses = case.masses
    assert 1 <= len(masses) <= subtask.max_n
    assert all(mass >= 1 for mass in masses)
    assert sum(masses) <= subtask.max_sum
    assert MinimalInitialCharge(masses) == case.answer


def GenerateCasesData(subtask):
    if subtask.name == "sub1":
        data = [
            MakeManualCase([1], False),
            MakeManualCase([7777777], False),
            MakeManualCase([1, 10**9 - 1], False),
            MakeManualCase([23, 32], False),
            MakeManualCase([5 * 10**8, 5 * 10**8], False),
            MakeManualCase([10**9 - 1, 1], False),
            MakeManualCase([777777777, 777], False),
            MakeManualCase([242424242, 42], False),
        ]
    elif subtask.name == "sub2":
        data = [
            MakeManualCase([9999]),
            MakeRandomSmallCase(100, 1, 1, subtask.max_sum),
            MakeRandomSmallCase(100, 1, 100, subtask.max_sum),
            MakeIncrementCase(30, 77, subtask.max_sum, 7),
            MakeIncrementCase(50, 250, subtask.max_sum, 5),
            MakeIncrementCase(100, 4321, subtask.max_sum, 4),
            MakeIncrementCase(100, 777, subtask.max_sum, 2),
            MakeBigSmallCase(100, 2000, 2, 10, subtask.max_sum),
            MakeBigSmallCase(100, 2500, 3, 5, subtask.max_sum),
            MakeBigSmallCase(35, 4000, 2, 20, subtask.max_sum),
        ]
    elif subtask.name == "sub3":
        data = [
            MakeRandomSmallCase(1000, 1, 10**4, subtask.max_sum),
            MakeRandomSmallCase(1000, 1, 10**6, subtask.max_sum),
            MakeIncrementCase(1000, 1000, subtask.max_sum, 12),
            MakeIncrementCase(1000, 75321, subtask.max_sum, 10),
            MakeIncrementCase(700, 42424242, subtask.max_sum, 7),
            MakeIncrementCase(100, 123456789, subtask.max_sum, 5),
            MakeBigSmallCase(1000, 5 * 10**4, 2, 100, subtask.max_sum),
            MakeBigSmallCase(1000, 10**6, 3, 100, subtask.max_sum),
            MakeBigSmallCase(1000, 10**7, 2, 100, subtask.max_sum),
            MakeManualCase([1, 2, 4, 8, 16, 10**9 - 31]),
            MakeManualCase([10**6] * 1000),
            MakeManualCase([12321]),
        ]
    elif subtask.name == "sub4":
        data = [
            MakeRandomSmallCase(10**5, 1, 10**4, subtask.max_sum),
            MakeRandomSmallCase(10**5, 1000, 10**4, subtask.max_sum),
            MakeRandomSmallCase(10**5, 9000, 10000, subtask.max_sum),
            MakeIncrementCase(100, 777, subtask.max_sum, 13),
            MakeIncrementCase(1000, 4242, subtask.max_sum, 11),
            MakeIncrementCase(10**4, 10**5, subtask.max_sum, 7),
            MakeIncrementCase(10**5, 1234321, subtask.max_sum, 5),
            MakeIncrementCase(10**5, 5 * 10**8, subtask.max_sum, 3),
            MakeIncrementCase(10**5, 42, subtask.max_sum, 2),
            MakeBigSmallCase(10**5, 10**7, 2, 100, subtask.max_sum),
            MakeBigSmallCase(10**5, 2 * 10**7, 3, 100, subtask.max_sum),
            MakeBigSmallCase(10**4, 4 * 10**8, 2, 10, subtask.max_sum),
            MakeManualCase([10**9]),
            MakeManualCase([1] * 99999 + [999901]),
            MakeManualCase([12345] * 80000),
        ]
    else:
        raise ValueError(f"Unknown subtask: {subtask.name}")

    for case in data:
        ValidateCase(case, subtask)

    return data


def GenerateCaseString(case):
    masses = " ".join(str(mass) for mass in case.masses)
    return f"{len(case.masses)}\n{masses}\n"


def GetCaseName(subtask, case_number):
    separator = "." if subtask.name != "sub1" else "_"
    return f"{subtask.name}{separator}{case_number + 1}"


def WriteTestplan(all_cases):
    with open("testplan", "w", encoding="utf-8", newline="\n") as testplan:
        for sample in sample_cases:
            testplan.write(f"{sample} 0\n")

        total_score = 0
        for subtask in subtasks:
            total_cases = len(all_cases[subtask.name])
            cases_with_extra_point = subtask.score % total_cases

            for case_number in range(total_cases):
                if subtask.name != "sub1":
                    case_score = 0 if case_number > 0 else subtask.score
                else:
                    case_score = subtask.score // total_cases
                    if case_number < cases_with_extra_point:
                        case_score += 1

                case_name = GetCaseName(subtask, case_number)
                testplan.write(f"{case_name} {case_score}\n")
                total_score += case_score

        assert total_score == 100


def GenerateCases():
    random.seed("tapia, si estas leyendo esto, eres el mejor!")
    os.makedirs("cases", exist_ok=True)

    all_cases = {}
    for subtask in subtasks:
        all_cases[subtask.name] = GenerateCasesData(subtask)

    WriteTestplan(all_cases)

    for subtask in subtasks:
        for case_number, case_data in enumerate(all_cases[subtask.name]):
            case_name = GetCaseName(subtask, case_number)
            print(
                f"Generating {case_name}: "
                f"n={len(case_data.masses)}, "
                f"sum={sum(case_data.masses)}, "
                f"answer={case_data.answer}"
            )

            case_path = os.path.join("cases", f"{case_name}.in")
            with open(case_path, "w", encoding="utf-8", newline="\n") as case:
                case.write(GenerateCaseString(case_data))

    print("The cases have been generated")


if __name__ == "__main__":
    GenerateCases()
