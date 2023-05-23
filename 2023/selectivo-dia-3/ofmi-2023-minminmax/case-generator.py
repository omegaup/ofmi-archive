import os
import random

baseString = """
{n} {m}
{arr}
""".strip(" \t\n\r")

cases = 40


def generate_case(caseNumber):
    max_n = 1e5 // (cases - caseNumber)
    min_ai = -1e9
    max_ai = 1e9

    n = random.randint(1, max_n)

    m = random.randint(1, min(n, 3))
    if m == 3:
        m = random.randint(3, n)

    arr = [random.randint(min_ai, max_ai) for _ in range(n)]
    return {
        'n': n,
        'm': m,
        'arr': arr,
    }


def main():
    random.seed(2134)

    with open('testplan', 'w') as f:
        f.write('sub1.sample 0' + "\n")

    for caseNumber in range(cases):
        # Generate case
        case = generate_case(caseNumber)
        case['arr'] = ' '.join([str(x) for x in case['arr']])
        # Generate case file
        caseName = f'{caseNumber}'
        caseString = baseString.format(**case)
        casePath = os.path.join('cases', caseName)
        with open(f'{casePath}.in', 'w') as f:
            f.write(f'{caseString}\n')
        # Append to testplan
        with open('testplan', 'a') as f:
            points = 100 // cases
            points += 1 if 100 % cases > caseNumber else 0
            f.write(f'{caseName} {points}' + "\n")


if __name__ == '__main__':
    main()
