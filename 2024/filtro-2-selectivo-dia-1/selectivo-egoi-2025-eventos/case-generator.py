import os
import random

OUTPUT_DIR = "cases"
TESTPLAN_FILENAME = "testplan"
SAMPLE_CASES_IN_TESTPLAN = [
    "1_sub1.sample1",
    "1_sub1.sample2",
    "1_sub1.extra",
    "4_sub2.extra",
    "3_sub3.extra",
    "2_sub4.extra",
    "5_sub5.extra"
]

# N_max_subtask: el valor máximo de N para esta subtarea específica.
# S_E_max_coord: el valor máximo para las coordenadas S_i y E_i.
# special_all_V_equal: booleano para la Subtarea 2.
MAX_V = 100
SUBTASK_DEFINITIONS = [
    {
        "id": 1, "points": 21, "cases_count": 10, "order": 1,
        "N_max_subtask": 15, "S_E_max_coord": 10**9,
        "special_all_V_equal": False
    },
    {
        "id": 2, "points": 17, "cases_count": 10, "order": 4,
        "N_max_subtask": 10**5, "S_E_max_coord": 10**9,
        "special_all_V_equal": True
    },
    {
        "id": 3, "points": 19, "cases_count": 13, "order": 3,
        "N_max_subtask": 10**5, "S_E_max_coord": 10**6,
        "special_all_V_equal": False
    },
    {
        "id": 4, "points": 21, "cases_count": 13, "order": 2,
        "N_max_subtask": 1000, "S_E_max_coord": 10**9,
        "special_all_V_equal": False
    },
    {
        "id": 5, "points": 22, "cases_count": 14, "order": 5,
        "N_max_subtask": 10**5, "S_E_max_coord": 10**9,
        "special_all_V_equal": False
    }
]


def get_n_for_case(case_idx, total_cases_in_subtask, n_max_subtask):
    """Determina N para un caso específico, intentando cubrir bordes."""
    # Últimos 3 casos, N máximo
    if case_idx >= total_cases_in_subtask - 3:
        return n_max_subtask
    # Casos intermedios, N aleatorio
    return random.randint(2, n_max_subtask)


def generate_event_data(n, s_e_max_coord, v_range, all_v_equal):
    """Genera los datos para N eventos."""
    events = []
    fixed_v = None
    if all_v_equal:
        fixed_v = random.randint(v_range[0], v_range[1])

    for _ in range(n):
        s_i = random.randint(0, s_e_max_coord - 1)
        e_i = random.randint(s_i + 1, s_e_max_coord)

        v_i = fixed_v if all_v_equal else random.randint(v_range[0],
                                                         v_range[1])
        events.append((s_i, e_i, v_i))
    return events


def generate_cases():
    if not os.path.exists(OUTPUT_DIR):
        os.makedirs(OUTPUT_DIR)

    testplan_content = []
    for sample_case_name in SAMPLE_CASES_IN_TESTPLAN:
        testplan_content.append(f"{sample_case_name} 0")

    total_score_check = 0

    for config in SUBTASK_DEFINITIONS:
        subtask_id = config["id"]
        subtask_order = config["order"]
        points = config["points"]
        num_cases_for_subtask = config["cases_count"]
        n_max_for_this_subtask = config["N_max_subtask"]
        s_e_max_coord = config["S_E_max_coord"]
        v_range = (0, MAX_V)
        all_v_equal = config["special_all_V_equal"]

        print(f"Generating cases for Subtask {subtask_id}...")
        total_score_check += points

        for i in range(num_cases_for_subtask):
            case_name = f"{subtask_order}_sub{subtask_id}.{i+1}"

            n = get_n_for_case(i,
                               num_cases_for_subtask,
                               n_max_for_this_subtask)

            events = generate_event_data(n,
                                         s_e_max_coord,
                                         v_range,
                                         all_v_equal)

            # Escribir el archivo .in
            filepath = os.path.join(OUTPUT_DIR, f"{case_name}.in")
            with open(filepath, "w") as f:
                f.write(f"{n}\n")
                for event in events:
                    f.write(f"{event[0]} {event[1]} {event[2]}\n")

            # Añadir al testplan
            current_points = points if i == 0 else 0
            testplan_content.append(f"{case_name} {current_points}")
            print(f"  Generated {case_name}.in (N={n})")

    # Escribir el archivo testplan
    with open(TESTPLAN_FILENAME, "w") as f:
        for line in testplan_content:
            f.write(f"{line}\n")

    print(f"Generated {TESTPLAN_FILENAME}")
    print(f"Total points in testplan (excluding samples): {total_score_check}")


if __name__ == "__main__":
    random.seed(89092249)
    generate_cases()
    print("Case generation finished.")
    print(f"Input files are in '{OUTPUT_DIR}/'")
    print(f"Testplan is '{TESTPLAN_FILENAME}'")
