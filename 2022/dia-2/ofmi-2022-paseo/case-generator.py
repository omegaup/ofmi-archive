import random
import os

# dangerous-default-value
# pylint: disable=W0102

baseString = """
{n} {k}
{arr}
""".strip(" \t\n\r")


def case_provider(case_gen, manual_tests=[]):
    for x in manual_tests:
        yield x
    while True:
        yield case_gen()


def random_case(n, k):
    # We want that sum of diffs does not exceed 1e9
    diffs = [
        random.randint(0, x)
        for x in random.choices([1e9 // n, 1e6 // n, 10, 1],
                                weights=(5, 15, 70, 10), k=n-1)
    ]
    s = sum(diffs)
    if s > 1e9:
        # try again
        return random_case(n, k)
    arr = [random.randint(0, min(100, 1e9 - s))]
    for i in range(n-1):
        arr += [arr[i] + diffs[i]]
    random.shuffle(arr)

    return {"n": n, "k": k, "arr": arr}


def sub1_case_provider():
    def sub1_random_case():
        n = random.randint(2,
                           random.choices([1e5, 1000, 100],
                                          weights=(5, 3, 2))[0])
        return random_case(n=n, k=2)

    return case_provider(case_gen=sub1_random_case)


def sub2_case_provider():
    def sub2_random_case():
        n = random.randint(3, random.choices(
            [1e5, 1000, 100], weights=(5, 3, 2))[0])
        return random_case(n=n, k=3)

    return case_provider(case_gen=sub2_random_case)


def sub3_case_provider():
    def sub3_random_case():
        n = random.randint(1, 20)
        k = random.randint(1, n)
        return random_case(n=n, k=k)

    return case_provider(case_gen=sub3_random_case)


def sub4_case_provider():
    def sub4_random_case():
        n = random.randint(1, 1e5)
        k = random.randint(1, n)
        return random_case(n=n, k=k)

    return case_provider(case_gen=sub4_random_case)


random.seed(7)
cases = [10, 10, 10, 10]
providers = [sub1_case_provider(),
             sub2_case_provider(),
             sub3_case_provider(),
             sub4_case_provider()]

for sub, count in enumerate(cases):
    provider = providers[sub]
    for caseNum in range(count):
        caseName = 'sub{}_{}.in'.format(sub + 1, caseNum)
        case = next(provider)

        case["arr"] = " ".join(str(x) for x in case["arr"])
        caseString = baseString.format(**case)
        casePath = os.path.join('cases', caseName)
        with open(casePath, 'w') as f:
            f.write(caseString + "\n")
