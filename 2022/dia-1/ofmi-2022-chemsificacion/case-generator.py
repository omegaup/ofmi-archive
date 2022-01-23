import random


testplan = open("testplan", "w")
with open("lemario.txt") as lemario:
    words = list(line.strip() for line in lemario)
vowels = ["a", "e", "i", "o", "u"]


def allFinalVowels(word):
    n = 3
    for i in range(0, len(word), n):
        w = word[i: i + n]
        if w[-1] not in vowels:
            return False
        if len(w) == 1:
            return True
        if w[-2] in vowels:
            return False

    return True


def oneVowel(word):
    n = 3
    for i in range(0, len(word), n):
        w = word[i: i + n]
        if len(w) == 1:
            return True
        if w[-2] in vowels and \
           (w[-1] in vowels or (len(w) > 2 and w[-3] in vowels)):
            return False

    return True


def generate(amount, points, subtask, allvows, onevow):
    limitN = 1000
    for i in range(amount):
        testplan.write(f"{subtask}_{i} " + str(int(points / amount)) + "\n")

        N = random.randint(1, limitN)
        ws = []
        while len(ws) < N:
            w = random.choice(words)
            while len(w) > 10:
                w = random.choice(words)
            if allvows:
                while len(w) > 10 or not allFinalVowels(w):
                    w = random.choice(words)
            elif onevow:
                while len(w) > 10 or not oneVowel(w):
                    w = random.choice(words)
            ws.append(w)

        w = " ".join(ws)
        with open(f"cases/{subtask}_{i}.in", "w") as file:
            file.write(str(N) + "\n")
            file.write(w + "\n")


def generateHardcoded(amount, points, subtask):
    N = 1
    ws = ["a", "y", "la", "el", "cal", "ala", "redoblante",
          "abad", "miel", "equino"]
    for i, w in enumerate(ws):
        testplan.write(f"{subtask}_{i} " + str(int(points / amount)) + "\n")

        with open(f"cases/{subtask}_{i}.in", "w") as file:
            file.write(str(N) + "\n")
            file.write(w + "\n")


testplan.write("sample.sub4.0 0" + "\n")
# Subtask 1: 10 puntos N = 1
generateHardcoded(10, 10, "sub1")

# Subtask 2: 10 puntos 1 <= N <= 1000
generate(10, 10, "sub2", True, False)

# Subtask 3: 10 puntos 1 <= N <= 1000
generate(10, 10, "sub3", False, True)

# Subtask 4: 70 puntos 1 <= N <= 1000
generate(14, 70, "sub4", False, False)

testplan.close()
