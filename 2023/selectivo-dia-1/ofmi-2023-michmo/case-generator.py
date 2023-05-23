import os
import random

baseString = """
{N} {M}
{P} {A} {B}
""".strip(" \t\n\r")


def tiroValido(N, M, P, A, B):
    # Funcion auxiliar
    def evaluar(m, x, c):
        return m * x + c

    # Pendiente
    m = A / B

    if 0 <= P <= M:
        # En medio
        x = evaluar(m, N/2, P)
        if x < 0 or M < x:
            return False
    elif P < 0:
        # Arriba
        x = evaluar(m, N/2, P)
        if M < x:
            return False
        x = evaluar(m, N, P)
        if x < 0:
            return False
    elif M < P:
        # Abajo
        x = evaluar(m, N, P)
        if M < x:
            return False
        x = evaluar(m, N/2, P)
        if x < 0:
            return False

    # Cubierto
    return True


def subcasoGenerico(iniciarEnMesa=False, forzarFallo=False, tiroRecto=False):
    # N, M
    params = {
        "N": random.randint(1, 5e5) * 2,
        "M": random.randint(1, 1e6),
    }

    # P
    if iniciarEnMesa:
        params["P"] = random.randint(0, params["M"])
    else:
        limiteP = min(random.randint(0, 3 * params["M"]), 1e6)
        params["P"] = random.randint(-limiteP, limiteP)

    # A / B
    if tiroRecto:
        params["A"] = 0
        params["B"] = 1
    elif forzarFallo:
        if params["M"] - params["P"] + 1 <= 1e6:
            # Objeto ira a (N/2, M+1)
            params["B"] = params["N"] // 2
            params["A"] = random.randint(params["M"] - params["P"] + 1, 1e6)
            # Este es si o si invalido para P <= M + 1
            if tiroValido(**params):
                # Para P > M + 1, el objeto puede ir a (N, M + 1)
                params["B"] = params["N"]
        else:
            # Objeto a (N/2, -1)
            params["B"] = params["N"] // 2
            params["A"] = random.randint(-1e6, -params["P"] - 1)
            if tiroValido(**params):
                # Objeto a (N, -1)
                params["B"] = params["N"]
    else:
        # B
        params["B"] = random.randint(-5e4, 5e4)
        while params["B"] == 0:
            params["B"] = random.randint(-5e4, 5e4)

        # A
        limite = min(
            abs(
                (3 * params["M"] - params["P"]) * params["B"]
                ),
            1e6)
        params["A"] = random.randint(-limite, limite)
    return params


def main():
    puntos_por_subtarea = [5, 20, 30, 45]
    casos_subtarea = [10, 15, 15, 20]

    # Validadores por subtarea
    def validador(subtarea, params, debeTirarValido):
        esTiroValido = tiroValido(**params)
        if subtarea == 0:
            if 0 <= params["P"] <= params["M"]:
                # Debe acertar
                return esTiroValido
            # Debe fallar si esta fuera
            return not esTiroValido
        if subtarea == 1:
            # Tiro debe ser valido
            return esTiroValido
        if subtarea == 2:
            # Objeto inicia en la mesa
            return 0 <= params["P"] <= params["M"]
        if subtarea == 3:
            # Sin restricciones adicionales
            return esTiroValido == debeTirarValido
        return True

    # Random seed
    random.seed(2345)

    with open('testplan', 'w') as f:
        f.write('sub4.sample 0' + "\n")

    extras_por_subtarea = [0, 2, 1, 1]

    for subtarea in range(4):
        # Puntos de la subtarea
        puntos = puntos_por_subtarea[subtarea]

        extras_subtarea = extras_por_subtarea[subtarea]
        for caseNumber in range(extras_subtarea):
            caseName = f"sub{subtarea + 1}.{caseNumber}"
            with open("testplan", "a") as f:
                f.write(f"{caseName} {puntos}\n")
                puntos = 0

        for caseNumber in range(extras_subtarea,
                                extras_subtarea + casos_subtarea[subtarea]):
            # Nombre de la subtarea
            caseName = f"sub{subtarea + 1}.{caseNumber}"

            # Parametros
            if subtarea == 1:
                forzarTiro = True
            else:
                forzarTiro = random.randint(0, 1)
            params = subcasoGenerico(subtarea == 2,
                                     not forzarTiro, subtarea == 0)
            while not validador(subtarea, params, forzarTiro):
                params = subcasoGenerico(subtarea == 2,
                                         not forzarTiro, subtarea == 0)

            # Imprimir caso
            caseString = baseString.format(**params)
            casePath = os.path.join("cases", caseName)
            with open(f"{casePath}.in", "w") as f:
                f.write(f"{caseString}\n")
            # Append to testplan
            with open("testplan", "a") as f:
                f.write(f"{caseName} {puntos}\n")
                puntos = 0


if __name__ == "__main__":
    main()
