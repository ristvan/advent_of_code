from util import read_file


def extend_polymer(polymer_template, rules):
    result_polymer = ""
    for index in range(len(polymer_template) - 1):
        pair = polymer_template[index:index+2]
        result_polymer = result_polymer + pair[0] + rules.get(pair, "?")
    return result_polymer + polymer_template[-1]


def diff_between_most_and_least_common_elements(polymer):
    element_counter = dict()
    for element in polymer:
        element_counter[element] = 1 + element_counter.get(element, 0)
    minimum = min(element_counter.values())
    maximum = max(element_counter.values())
    return maximum - minimum


def convert_to_rule(line_of_file):
    pair_and_value = line_of_file.split(" -> ")
    return pair_and_value[0], pair_and_value[1]


def solve():
    lines_of_file = read_file("d14_extended_polymerization/input.txt")
    polymer_template = lines_of_file[0]
    rules = {convert_to_rule(line_of_file)[0]: convert_to_rule(line_of_file)[1] for line_of_file in lines_of_file[2:]}

    polymer = polymer_template
    for _ in range(10):
        polymer = extend_polymer(polymer, rules)

    diff_part_1 = diff_between_most_and_least_common_elements(polymer)

    print("Day 14")
    print(f"  - Part 1: {diff_part_1}")
