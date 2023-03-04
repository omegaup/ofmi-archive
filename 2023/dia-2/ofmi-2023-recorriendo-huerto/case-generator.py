import os
import random

baseString = """
{N}
{evs}
""".strip(" \t\n\r")

MAX = int(10**4)


def getEvent(current_pos, ev):
    if ev == 1:
        x = random.randint(1, MAX)
        return (f'1 {x}', x)
    if ev == 2:
        y = random.randint(1, min(MAX, current_pos))
        return (f'2 {y}', -y)
    if ev == 3:
        return ('3', 0)
    return ('4', 0)


def getRandomCase(sub):
    evs = []
    current_pos = 0
    for _ in range(random.randint(1, MAX)):
        allowed_evs = [1, 2, 3, 4]
        if sub == 1:
            allowed_evs.remove(2)
        elif sub == 2:
            allowed_evs.remove(3)
            allowed_evs.remove(4)

        if current_pos == 0 and 2 in allowed_evs:
            allowed_evs.remove(2)

        ev, delta = getEvent(current_pos, random.choice(allowed_evs))
        current_pos += delta
        evs += [ev]

    if sub == 2:
        # Terminará con un avanzado
        ev, delta = getEvent(current_pos, 3)
        evs += [ev]

    n = len(evs)
    if sub == 3:
        # Nunca se llamará un `adelante` después `atras`
        i = 0
        j = n - 1
        while i < j:
            if evs[i].startswith('2') is False:
                i += 1
            elif evs[j].startswith('1') is False:
                j -= 1
            else:
                evs[i], evs[j] = evs[j], evs[i]
                i += 1
                j -= 1

    return {
        'N': n,
        'evs': '\n'.join(evs),
    }


pointsPerSub = [20, 20, 20, 40]
casesPerSub = 10


def main():
    random.seed(4123921)

    with open('testplan', 'w') as f:
        f.write('sample.sub4 0' + "\n")

    for sub in range(1, 5):
        for caseNumber in range(casesPerSub):
            # Generate case
            case = getRandomCase(sub)
            # Generate case file
            caseName = f'sub{sub}-{caseNumber}'
            caseString = baseString.format(**case)
            casePath = os.path.join('cases', caseName)
            with open(f'{casePath}.in', 'w') as f:
                f.write(f'{caseString}\n')
            # Append to testplan
            with open('testplan', 'a') as f:
                points = pointsPerSub[sub - 1] // casesPerSub + (
                    1 if caseNumber < pointsPerSub[sub - 1] % casesPerSub
                    else 0)
                f.write(f'{caseName} {points}\n')


if __name__ == '__main__':
    main()
