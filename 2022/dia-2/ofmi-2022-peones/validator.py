import sys


if __name__ == '__main__':
    # Nombre del caso
    caseName = sys.argv[1]

    # Salida de la concursante
    contestant_output = int(input())

    # Salida del juez
    with open('data.out', 'r') as handle:
        judge_output = int(handle.read())

    # Comparar salidas
    if judge_output == contestant_output:
        print(1)
    elif 'sub4' in caseName:
        # Subcaso donde sólo importa decir si llego o no
        if judge_output >= 0 and contestant_output >= 0:
            print(1)
        else:
            print(0)
    else:
        print(0)
