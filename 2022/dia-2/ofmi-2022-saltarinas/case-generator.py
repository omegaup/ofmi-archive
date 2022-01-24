import os
import random

random.seed(1504086022)

nMax = 10**5
qMax = 10**6
xMax = 10**9
a_iMax = 16
path = os.path.abspath(os.getcwd())+"/cases/"


def makeCases(params):
    prefix = params[0]
    nBotLim, nTopLim, qBotLim, qTopLim, xBotLim, xTopLim = params[3:]
    for i in range(params[1], params[2]):
        n = random.randint(nBotLim, nTopLim)
        arr = ""
        for _ in range(n):
            arr += str(random.randint(1, a_iMax))
            arr += " "
        arr = arr[:-1]
        arr += "\n"

        q = random.randint(qBotLim, qTopLim)
        x = random.randint(xBotLim, xTopLim)

        with open(path+prefix+"."+str(i)+".in", "w") as file:
            file.write(str(n)+'\n')
            file.write(arr)
            file.write(str(q)+' '+str(x)+'\n')


def sub1Params():
    return ("sub1", 1, 10, 1, 100, 1, 1000, 1, 50)


def sub2Params():
    return ("sub2", 10, 15, 1, nMax, 1, qMax, 1, 1)


def sub3Params():
    return ("sub3", 15, 18, 1, 100, 1, 10**4, 1, xMax)


def sub4Params():
    return ("sub4", 18, 21, 1, nMax, 1, 10**4, 1, xMax)


def sub5Params():
    return ("sub5", 21, 25, nMax/10, nMax, qMax/10, qMax, xMax/10, xMax)


def sub5ExtraParams():
    return ("sub5", 25, 26, nMax, nMax, qMax, qMax, xMax, xMax)


# caso de ejemplo (parte de la subtarea 1)
prueba = """5
2 3 4 8 12
3 4
"""
with open(path+"sub1.0.in", "w") as sampleFile:
    sampleFile.write(prueba)
    sampleFile.close()

# Subtask 1: (10 puntos) N <= 100, Q <= 1,000, X <= 50 -> 10 casos
makeCases(sub1Params())
# Subtask 2: (20 puntos) X <= 1 -> 5 casos
makeCases(sub2Params())
# Subtask 3: (20 puntos) N <= 100, Q <= 10,000 -> 3 casos
makeCases(sub3Params())
# Subtask 4: (30 puntos) Q <= 10,000 -> 3 casos
makeCases(sub4Params())
# Subtask 5: (20 puntos) -> 3 casos (solo casos grandes)
makeCases(sub5Params())
# Extra case Subtask 5: Biggest posible case
makeCases(sub5ExtraParams())
