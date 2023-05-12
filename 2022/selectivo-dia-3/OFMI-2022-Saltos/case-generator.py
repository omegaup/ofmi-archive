import random
import os

random.seed(207408054)

baseString = """
{k} {n}
{arr}
""".strip(' \t\n\r')


def getPrimes(k):
    primes = []
    if len(primes) > 0:
        return primes
    primes += [2]
    bucket = [True for _ in range(k+1)]
    for i in range(3, k+1, 2):
        if bucket[i] is False:
            continue
        primes += [i]
        for j in range(i*i, k+1, i):
            bucket[j] = False
    return primes


todos_los_primos = getPrimes(3*10**6)


def generateAtRandom(k, n):
    arr = []
    if k > 100000:
        d = {}
        while len(arr) < n:
            x = random.randint(1, k)
            while x in d:
                x = random.randint(1, k)

            d[x] = True
            arr += [x]
    else:
        arr = random.sample(range(1, k+1), k=n)
    return arr


def generateFixed(k, n):
    primes = todos_los_primos[:n]
    while primes[-1] > k:
        primes.pop()

    invalid_div = -1
    if n < k and random.randint(0, 2) > 0:
        idx = random.randint(int(len(primes) * 0.9), len(primes)) - 1
        invalid_div = primes[idx]
        primes.pop(idx)

    for i, p in enumerate(primes):
        primes[i] *= random.randint(1, k // p)
        if invalid_div != -1 and primes[i] % invalid_div == 0:
            primes[i] /= invalid_div

    arr = set(primes)
    # Lo extiendo a n
    if k > 100000:
        while len(arr) < n:
            x = random.randint(1, k)
            while x in arr or (invalid_div != -1 and x % invalid_div == 0):
                x = random.randint(1, k)

            arr.add(x)
        arr = list(arr)
    else:
        missing = [x for x in range(1, k+1) if x not in arr and (
            invalid_div == -1 or (invalid_div != -1 and x % invalid_div))]
        arr = list(arr)
        arr += random.sample(missing, k=n - len(arr))
    return arr


def generateCase(subTask, caseNum, minK, maxK, maxN):
    k = random.randint(minK, maxK)
    n = random.randint(1, min(k, maxN))
    if caseNum > 7:
        k = maxK
        n = random.randint(int(min(k, maxN) * 0.9), min(k, maxN))

    if subTask == 1:
        primes = todos_los_primos.copy()
        while primes[-1] > k:
            primes.pop()
        k = primes[-1] - 1
        n = k - 1

    case = {'k': k, 'n': n}
    if caseNum < 2:
        case['arr'] = generateAtRandom(k, n)
    else:
        case['arr'] = generateFixed(k, n)

    case['arr'] = " ".join([str(x) for x in case['arr']])

    caseName = 'sub{}.{}'.format(subTask, caseNum)
    caseString = baseString.format(**case)
    casePath = os.path.join('cases', caseName)
    with open(casePath + '.in', 'w') as f:
        f.write(caseString + "\n")

    with open(casePath + '.out', 'w') as f:
        f.write('\n')


def main():
    subcases = 10
    # Sub1
    for i in range(subcases):
        generateCase(1, i, 50, 10**3, 10**3)

    # Sub2
    for i in range(subcases):
        generateCase(2, i, 10**4, 10**5, 10**5)

    # Sub3
    for i in range(subcases):
        generateCase(3, i, 10**7, 10**8, 10**5)


if __name__ == "__main__":
    main()
