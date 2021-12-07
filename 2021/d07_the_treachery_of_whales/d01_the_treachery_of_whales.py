from util import read_file


def count_min_fuel_for_crab_moving(crabs):
    count_of_crabs = dict()
    minimum_position_of_crabs = min(crabs)
    maximum_position_of_crabs = max(crabs) + 1
    for number_of_crabs in range(minimum_position_of_crabs, maximum_position_of_crabs):
        count_of_crabs[number_of_crabs] = crabs.count(number_of_crabs)
    number_of_left_crabs = 0
    number_of_right_crabs = len(crabs) - crabs.count(minimum_position_of_crabs)
    number_of_movements = sum(map(lambda x: x[1] * (x[0] - minimum_position_of_crabs), count_of_crabs.items()))
    minimal_movement = number_of_movements
    for index in range(minimum_position_of_crabs + 1, maximum_position_of_crabs):
        number_of_left_crabs += count_of_crabs.get(index - 1, 0)
        number_of_movements += number_of_left_crabs
        number_of_movements -= number_of_right_crabs
        number_of_right_crabs -= count_of_crabs.get(index, 0)
        if number_of_movements < minimal_movement:
            minimal_movement = number_of_movements
        else:
            break
    return minimal_movement


def fuel_consumption(distance):
    delta = 1 if distance > 0 else -1
    return (distance + delta) * distance // 2


def count_min_revised_fuel_consumption(crabs):
    count_of_crabs = dict()
    minimum_position_of_crabs = min(crabs)
    maximum_position_of_crabs = max(crabs) + 1
    for number_of_crabs in range(minimum_position_of_crabs, maximum_position_of_crabs):
        count_of_crabs[number_of_crabs] = crabs.count(number_of_crabs)
    minimal_fuel_consumption = 999999999999999
    for index in range(minimum_position_of_crabs, maximum_position_of_crabs):
        sum_fuel_consumption = 0
        for crab_index, count in count_of_crabs.items():
            sum_fuel_consumption += fuel_consumption(index - crab_index) * count
        if sum_fuel_consumption < minimal_fuel_consumption:
            minimal_fuel_consumption = sum_fuel_consumption
        else:
            break
    return minimal_fuel_consumption


def solve():
    lines_of_file = read_file("d07_the_treachery_of_whales/input.txt")
    crabs_positions = [int(crab_position.strip()) for crab_position in lines_of_file[0].split(",")]
    minimal_movement = count_min_fuel_for_crab_moving(crabs_positions)
    revised_minimal_movement = count_min_revised_fuel_consumption(crabs_positions)
    print("Day 7:")
    print(f"  - Part 1: {minimal_movement}")
    print(f"  - Part 2: {revised_minimal_movement}")
