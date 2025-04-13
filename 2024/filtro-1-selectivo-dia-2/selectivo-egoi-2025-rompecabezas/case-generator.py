import os
import math
import heapq
import random
from collections import Counter


sample_case_names = ["sub1.sample", "sub2.sample", "sub3.extra", "sub4.extra"]
case_count = [10, 5, 10, 15]
case_scores = [17, 23, 29, 31]
subtasks = 4


def coin_flip(p: float = 0.5):
    return random.random() < p


def get_Ns(subtask: int):
    start, end = (1000, 10**9) if subtask else (10, 100)
    Ns = random.sample(range(start, end, 1), case_count[subtask] - 2)
    return [end] + sorted(Ns, reverse=True) + [start]


def get_Qs(subtask: int):
    start = 10**4 if subtask else 100
    Qs = random.sample(range(start, 2 * 10**5), case_count[subtask] - 4)
    return [2 * 10**5] * 3 + sorted(Qs, reverse=True) + [start]


def generate_adds_then_removes(n: int, q: int):
    adds = q // 2 + random.randint(0, q // 7)

    max_puzzles = min(n, adds)
    puzzles = list(range(max_puzzles))

    for _ in range(adds - max_puzzles):
        if max_puzzles == n or coin_flip(0.995):
            puzzle = random.randint(0, max_puzzles - 1)
        else:
            puzzle = random.randint(max_puzzles, n - 1)
        puzzles.append(puzzle)

    random.shuffle(puzzles)
    events = [("+", puzzle) for puzzle in puzzles]

    random.shuffle(puzzles)
    puzzles = sorted(puzzles[:q - len(puzzles)], reverse=True)
    events += [("-", puzzle) for puzzle in puzzles]
    return events


def generate_always_min_events(n: int, q: int):
    puzzles = set(range(min(n, q // 3)))
    events = [("+", puzzle) for puzzle in puzzles]

    max_puzzles = len(puzzles)
    min_puzzles = int(max_puzzles * 0.77)
    q -= max_puzzles
    missing = []

    while q:
        removes = random.randint(1, min(q, len(puzzles) - min_puzzles))
        for gift in random.sample(sorted(puzzles)[min_puzzles:], removes):
            heapq.heappush(missing, gift)
            events.append(("-", gift))
            puzzles.remove(gift)
        q -= removes

        if not q:
            break

        max_adds = min(2 * removes, n - len(puzzles))
        adds = random.randint(1, min(q, max_adds))

        for _ in range(adds):
            if missing:
                received = heapq.heappop(missing)
                events.append(("+", received))
                puzzles.add(received)
            else:
                events.append(("+", max_puzzles))
                puzzles.add(max_puzzles)
                max_puzzles += 1
        q -= adds

    return events


def generate_random_events(n: int, q: int):
    max_puzzles = n if n < q else q // 2
    min_puzzles = max_puzzles - int(math.sqrt(max_puzzles))

    different_puzzles = 0
    events, puzzles = [], []
    puzzle_count = Counter()
    missing = list(range(max_puzzles))

    for _ in range(q):
        should_add = different_puzzles < min_puzzles or (
            different_puzzles < max_puzzles and coin_flip(0.3))

        if should_add:
            while missing and puzzle_count[missing[0]]:
                heapq.heappop(missing)

            if missing and coin_flip(0.85):
                puzzle = heapq.heappop(missing)
            elif max_puzzles == n or coin_flip(0.98):
                puzzle = random.randint(0, max_puzzles - 1)
            else:
                puzzle = random.randint(max_puzzles, n - 1)

            puzzles.append(puzzle)
            if not puzzle_count[puzzle] and puzzle < max_puzzles:
                different_puzzles += 1
            puzzle_count[puzzle] += 1

            events.append(("+", puzzle))
        else:
            idx = random.randint(0, len(puzzles) - 1)
            puzzles[idx], puzzles[-1] = puzzles[-1], puzzles[idx]

            puzzle = puzzles.pop()
            puzzle_count[puzzle] -= 1
            if not puzzle_count[puzzle] and puzzle < max_puzzles:
                heapq.heappush(missing, puzzle)
                different_puzzles -= 1

            events.append(("-", puzzle))

    return events


def generate_events(n: int, q: int, subtask: int, case_number: int):
    if subtask == 1 or (subtask == 3 and case_number == 2):
        return generate_adds_then_removes(n, q)
    if subtask == 2 or case_number < 2:
        return generate_always_min_events(n, q)
    return generate_random_events(n, q)


def generate_case_string(n: int, q: int, subtask: int, case_number: int):
    events = generate_events(n, q, subtask, case_number)
    assert len(events) == q

    events_str = "\n".join(event_type + " " + str(Ri + 1)
                           for (event_type, Ri) in events)
    return f"{n} {q}\n{events_str}\n"


def get_case_name(subtask: int, case_number: int):
    return f"sub{subtask + 1}.{case_number}"


if __name__ == "__main__":
    assert subtasks == len(case_count) == len(case_scores)
    assert sum(case_scores) == 100

    random.seed("ya llegaron los randomshhh")

    # Write testplan
    assert len(sample_case_names) == len(set(sample_case_names))
    with open("testplan", "w", encoding="utf-8", newline="\n") as testplan:
        for case_num, case_name in enumerate(sample_case_names):
            testplan.write(f"{case_name} 0\n")
        for sub in range(subtasks):
            case_name = get_case_name(sub, 0)
            assert case_name not in sample_case_names
            testplan.write(f"{case_name} {case_scores[sub]}\n")
            for case_num in range(1, case_count[sub]):
                case_name = get_case_name(sub, case_num)
                assert case_name not in sample_case_names
                testplan.write(f"{case_name} 0\n")

    # Write cases
    for sub in range(subtasks):
        subtask_n = get_Ns(sub)
        subtask_q = get_Qs(sub)
        for case_num in range(case_count[sub]):
            case_name = get_case_name(sub, case_num)
            print(f"Generating case #{case_num} for subtask {sub + 1}")
            case_str = generate_case_string(
                subtask_n[case_num], subtask_q[case_num], sub, case_num)
            case_path = os.path.join("cases", f"{case_name}.in")
            with open(case_path, "w", encoding="utf-8", newline="\n") as case:
                case.write(case_str)

    print("The cases have been generated")
