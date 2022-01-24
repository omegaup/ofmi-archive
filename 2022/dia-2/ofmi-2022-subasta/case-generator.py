import random
import os

# dangerous-default-value
# pylint: disable=W0102

baseString = """
{n}
{arr}
""".strip(" \t\n\r")


def case_provider(case_gen, manual_tests=[]):
    for x in manual_tests:
        yield x
    while True:
        yield case_gen()


def random_case(maxn, maxa_i):
    n = random.randint(1, maxn)
    arr = [random.randint(1, maxa_i) for _ in range(n)]
    return {"n": n, "arr": arr}


def sub1_case_provider():
    return case_provider(
        case_gen=lambda: random_case(3, 100),
        manual_tests=[
            {"n": 3, "arr": [1, 1, 1]}
        ]
    )


def sub2_case_provider():
    def sub2_random_case():
        case = random_case(
            maxn=random.choices([100000, 10000, 100], weights=(2, 3, 5))[0],
            maxa_i=28,
        )
        arr = case["arr"]
        while True:
            sigIdx = min([i if i > 0 and x >= arr[0] else len(
                arr)+1 for i, x in enumerate(arr)])
            if sigIdx < len(arr) and arr[sigIdx] == arr[0]:
                arr[sigIdx] = (arr[sigIdx] - 1
                               if arr[sigIdx] > 1
                               else arr[sigIdx] + 1)
            else:
                break
        case["arr"] = [1 << x for x in arr]
        return case

    return case_provider(
        case_gen=sub2_random_case,
        manual_tests=[{"n": 6, "arr": [32, 16, 8, 4, 2, 1]}]
    )


def generator_no_tan_random(max_n: int, max_ai: int):
    n = random.randint(max_n - 1e4, max_n)
    arr = []
    mayor1 = 0
    mayor2 = 0
    maximas_nuevas_pujas = random.randint(1, 20)
    for _ in range(n):
        if random.randint(1, 100) > 80 and maximas_nuevas_pujas > 0:
            maximas_nuevas_pujas -= 1
            if mayor1 + mayor2 > max_ai:
                arr.append(int(max_ai))
                mayor2 = mayor1
                mayor1 = int(max_ai)
            else:
                x = random.randint(
                    mayor1 + mayor2, min(mayor1 + mayor2 + 1e2, 1e9))
                arr.append(x)
                mayor2 = mayor1
                mayor1 = x
        else:
            if mayor2 == 0:
                x = random.randint(1, 1e2)
                arr.append(x)
                mayor2 = mayor1
                mayor1 = x
            else:
                if random.randint(1, 5) > 2:
                    x = random.randint(1, min(mayor1 + mayor2, 1e9))
                    arr.append(x)
                    mayor2 = mayor1
                    mayor1 = x
                else:
                    x = random.randint(mayor1, min(mayor1 + mayor2 - 1, 1e9))
                    arr.append(x)
                    mayor2 = mayor1
                    mayor1 = x

    return {"n": n, "arr": arr}


def sub3_case_provider():
    def sub3_random_case():
        return generator_no_tan_random(1e5, 1e9)

    return case_provider(case_gen=sub3_random_case)


random.seed(3)
cases = [10, 10, 10]
providers = [sub1_case_provider(), sub2_case_provider(), sub3_case_provider()]
for sub, count in enumerate(cases):
    provider = providers[sub]
    for i in range(count):
        caseName = 'sub{}_{}.in'.format(sub + 1, i)
        caseInfo = next(provider)
        caseInfo["arr"] = " ".join(str(x) for x in caseInfo["arr"])
        caseString = baseString.format(**caseInfo)
        casePath = os.path.join('cases', caseName)
        with open(casePath, 'w') as f:
            f.write(caseString + "\n")
