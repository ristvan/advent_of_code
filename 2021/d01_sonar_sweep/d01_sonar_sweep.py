def read_file(filename):
    with open(filename, "rt") as ifh:
        lines = ifh.readlines()
    return [line.replace("\n", "") for line in lines]


def count_simple_increases(depths):
    previous = depths[0]
    number_of_increases = 0
    for depth in depths:
        if depth > previous:
            number_of_increases += 1
        previous = depth
    return number_of_increases


def count_windowed_increases(depths):
    measurement_window = depths[0:3]
    previous_sum = sum(measurement_window)
    number_of_increases = 0
    for depth in depths[3:]:
        measurement_window.remove(measurement_window[0])
        measurement_window.append(depth)
        if sum(measurement_window) > previous_sum:
            number_of_increases += 1
        previous_sum = sum(measurement_window)
    return number_of_increases


def solve():
    lines = read_file("d01_sonar_sweep/input.txt")
    depths = [int(line) for line in lines]
    print(f"Day 1")
    print(f"  - Part 1: {count_simple_increases(depths)}")
    print(f"  - Part 2: {count_windowed_increases(depths)}")


