import os

baseString = """
{a} {b} {c}
""".strip(" \t\n\r")

groupPerCase = [1, 2, 3, 4, 5, 1, 12, 2, 3, 6, 7, 4, 12, 5, 6, 7, 8, 9, 14,
                8, 10, 13, 13, 10, 14, 11, 9]
for a in range(3):
    for b in range(3):
        for c in range(3):
            caseNumber = (3**2)*a + 3*b + c + 1
            groupNumber = groupPerCase[caseNumber - 1]
            caseName = f'g{groupNumber}.{caseNumber}.in'
            case = {
                'a': a + 1,
                'b': b + 1,
                'c': c + 1,
            }
            caseString = baseString.format(**case)
            casePath = os.path.join('cases', caseName)
            with open(casePath, 'w') as f:
                f.write(caseString + "\n")
