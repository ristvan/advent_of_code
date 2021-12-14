from util import read_file


def convert_to_rule(line_of_file):
    pair_and_value = line_of_file.split(" -> ")
    return pair_and_value[0], pair_and_value[1]


def create_pairs_from_polymer(polymer):
    polymer_pairs = dict()
    for index in range(len(polymer) - 1):
        pair = polymer[index:index+2]
        polymer_pairs[pair] = 1 + polymer_pairs.get(pair, 0)

    return polymer_pairs


def extend_polymer_pairs(polymer_pairs: dict, rules: dict):
    actual_polymer_pairs = list(polymer_pairs.keys())
    new_polymer_pairs = dict()
    for polymer_pair in actual_polymer_pairs:
        extra_element = rules.get(polymer_pair, "?")
        actual_count = polymer_pairs.get(polymer_pair, 1)
        first_polymer_pair = polymer_pair[0] + extra_element
        second_polymer_pair = extra_element + polymer_pair[1]
        new_polymer_pairs[first_polymer_pair] = actual_count + new_polymer_pairs.get(first_polymer_pair, 0)
        new_polymer_pairs[second_polymer_pair] = actual_count + new_polymer_pairs.get(second_polymer_pair, 0)
    return new_polymer_pairs


def diff_between_most_and_least_common_elements_from_pairs(polymer_pairs, polymer):
    element_counter = dict()
    for pair, count in polymer_pairs.items():
        element_counter[pair[0]] = count + element_counter.get(pair[0], 0)
        element_counter[pair[1]] = count + element_counter.get(pair[1], 0)
    first_element = polymer[0]
    last_element = polymer[-1]
    element_counter[first_element] = element_counter.get(first_element) + 1
    element_counter[last_element] = element_counter.get(last_element) + 1
    minimum = min(element_counter.values())
    maximum = max(element_counter.values())
    diff = (maximum - minimum) // 2 + maximum % 1
    return diff


def solve():
    lines_of_file = read_file("d14_extended_polymerization/input.txt")
    polymer_template = lines_of_file[0]
    rules = {convert_to_rule(line_of_file)[0]: convert_to_rule(line_of_file)[1] for line_of_file in lines_of_file[2:]}

    polymer_pairs = create_pairs_from_polymer(polymer_template)
    for _ in range(10):
        polymer_pairs = extend_polymer_pairs(polymer_pairs, rules)
    diff_part_1 = diff_between_most_and_least_common_elements_from_pairs(polymer_pairs, polymer_template)

    for _ in range(30):
        polymer_pairs = extend_polymer_pairs(polymer_pairs, rules)
    diff_part_2 = diff_between_most_and_least_common_elements_from_pairs(polymer_pairs, polymer_template)

    print("Day 14")
    print(f"  - Part 1: {diff_part_1}")
    print(f"  - Part 2: {diff_part_2}")
