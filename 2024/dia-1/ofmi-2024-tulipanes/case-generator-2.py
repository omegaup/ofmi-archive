import os

base_string = """
{n} {m}
{arr}
""".strip(
    " \t\n\r"
)


def generate_killer_case():
    n, m = 1000, 1000
    matrix = [range(i*m + 1, i*m + m + 1) for i in range(n)]
    return {
        "n": n,
        "m": m,
        "arr": "\n".join(" ".join(str(v) for v in row) for row in matrix),
    }


def main():
    case_path = os.path.join("cases", "sub4.10")
    with open(f"{case_path}.in", "w") as f:
        case = generate_killer_case()
        case_string = base_string.format(**case)
        f.write(f"{case_string}\n")


if __name__ == "__main__":
    main()
