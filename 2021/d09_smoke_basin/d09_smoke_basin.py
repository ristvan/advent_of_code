from math import prod
from util import read_file

NEIGHBOURS = [
    (-1, 0), (0, -1), (0, 1), (1, 0)
]


def is_all_neighbours_are_higher(height_map, row_index, column_index):
    valid_neighbours = get_valid_neighbours(height_map, row_index, column_index)
    higher_neighbours = [(neighbour_row, neighbour_column) for neighbour_row, neighbour_column in valid_neighbours if
                         height_map[neighbour_row][neighbour_column] > height_map[row_index][column_index]]
    return len(valid_neighbours) == len(higher_neighbours)


def get_valid_neighbours(height_map, row_index, column_index):
    valid_neighbours = list()
    for neighbour_row_delta, neighbour_column_delta in NEIGHBOURS:
        neighbour_row = neighbour_row_delta + row_index
        neighbour_column = neighbour_column_delta + column_index
        if is_valid_neighbour(height_map, neighbour_row, neighbour_column):
            valid_neighbours.append((neighbour_row, neighbour_column))
    return valid_neighbours


def is_valid_neighbour(height_map, neighbour_row, neighbour_column):
    return 0 <= neighbour_column < len(height_map[0]) \
           and 0 <= neighbour_row < len(height_map)


def find_positions_of_low_points(height_map):
    low_points = list()
    for row_index in range(len(height_map)):
        for column_index in range(len(height_map[row_index])):
            if is_all_neighbours_are_higher(height_map, row_index, column_index):
                low_points.append((row_index, column_index))
    return low_points


def find_low_points(height_map, positions_of_low_points):
    low_points = list()
    for row_index, column_index in positions_of_low_points:
        low_points.append(height_map[row_index][column_index])
    return low_points


def count_size_of_basin(height_map, position):
    points_of_basin = set()
    next_positions_check = [position]
    while len(next_positions_check):
        row, column = next_positions_check.pop(0)
        points_of_basin.add((row, column))
        for neighbour_row, neighbour_column in get_valid_neighbours(height_map, row, column):
            if 9 > height_map[neighbour_row][neighbour_column] > height_map[row][column] \
                    and (neighbour_row, neighbour_column) not in points_of_basin:
                next_positions_check.append((neighbour_row, neighbour_column))

    return len(points_of_basin)


def get_all_the_size_of_basins(height_map, low_points):
    return [count_size_of_basin(height_map, low_point) for low_point in low_points]


def solve():
    lines_of_file = read_file("d09_smoke_basin/input.txt")
    sea_floor_height_map = [
        [int(height) for height in line_of_file] for line_of_file in lines_of_file
    ]
    positions_of_low_points = find_positions_of_low_points(sea_floor_height_map)
    low_points = find_low_points(sea_floor_height_map, positions_of_low_points)
    size_of_basins = get_all_the_size_of_basins(sea_floor_height_map, positions_of_low_points)
    multiplication_the_three_largest_basins = prod(list(sorted(size_of_basins, reverse=True))[0:3])
    print("Day 09")
    print(f"  - Part 1: {sum(low_points) + len(low_points)}")
    print(f"  - Part 2: {multiplication_the_three_largest_basins}")
