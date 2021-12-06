from util import read_file


def convert_line_of_file_to_line_segment(line_of_file):
    return tuple([int(number.strip()) for number in line_of_file.replace(" -> ", ",").split(",")])


def calculate_max_coordinates(coordinates):
    x_coords = list()
    y_coords = list()
    for x1, y1, x2, y2 in coordinates:
        x_coords.append(x1)
        x_coords.append(x2)
        y_coords.append(y1)
        y_coords.append(y2)
    max_x, max_y = max(x_coords), max(y_coords)
    return max_x, max_y


def create_horizontal_or_vertical_line(endpoints_of_line):
    x1, y1, x2, y2 = endpoints_of_line
    points_of_line = list()
    if x1 == x2 or y1 == y2:
        points_of_line.extend([(x, y) for y in range(min(y1, y2), max(y1, y2) + 1)
                               for x in range(min(x1, x2), max(x1, x2) + 1)])
    return points_of_line


def create_every_line(endpoints_of_line):
    x1, y1, x2, y2 = endpoints_of_line
    points_of_line = list()
    if x1 == x2 or y1 == y2:
        points_of_line.extend(create_horizontal_or_vertical_line(endpoints_of_line))
    else:
        if x1 < x2:
            x_range = range(x1, x2 + 1)
        else:
            x_range = range(x1, x2 - 1, -1)
        y_range = range(y1, y2 + 1) if y1 < y2 else range(y1, y2 - 1, -1)
        points_of_line.extend([(x, y) for x, y in zip(x_range, y_range)])
    return points_of_line


class HydrothermalVenture:
    def __init__(self, size, line_creator):
        self._line_creator = line_creator
        width, height = size
        self._vents = [[0 for _ in range(width + 1)] for _ in range(height + 1)]

    def add_all_coordinates(self, coordinates):
        for coordinate in coordinates:
            vents = self._line_creator(coordinate)
            for x, y in vents:
                self._vents[y][x] += 1

    def number_of_dangerous_places(self):
        dangerous_places = 0
        for row in self._vents:
            for value in row:
                if value >= 2:
                    dangerous_places += 1
        return dangerous_places


def solve():
    lines_of_file = read_file("d05_hydrothermal_venture/input.txt")

    coordinates = [convert_line_of_file_to_line_segment(line) for line in lines_of_file]
    hydrothermal_venture = HydrothermalVenture(calculate_max_coordinates(coordinates),
                                               create_horizontal_or_vertical_line)
    hydrothermal_venture.add_all_coordinates(coordinates)

    hydrothermal_venture2 = HydrothermalVenture(calculate_max_coordinates(coordinates),
                                                create_every_line)
    hydrothermal_venture2.add_all_coordinates(coordinates)

    print("Day 5:")
    print(f"  - Part 1: {hydrothermal_venture.number_of_dangerous_places()}")
    print(f"  - Part 2: {hydrothermal_venture2.number_of_dangerous_places()}")
