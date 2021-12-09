from util import read_file

NEIGHBOURS = [
    (-1, 0), (0, -1), (0, 1), (1, 0)
]


def is_all_neighbours_are_higher(height_map, row_index, column_index):
    for neighbour_row_delta, neighbour_column_delta in NEIGHBOURS:
        neighbour_row = neighbour_row_delta + row_index
        neighbour_column = neighbour_column_delta + column_index
        if is_valid_neighbour(height_map, neighbour_row, neighbour_column) \
                and height_map[neighbour_row][neighbour_column] <= height_map[row_index][column_index]:
           return False

    return True


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


def solve():
    lines_of_file = read_file("d09_smoke_basin/input.txt")
    sea_floor_height_map = [
        [int(height) for height in line_of_file] for line_of_file in lines_of_file
    ]
    low_points = find_low_points(sea_floor_height_map, find_positions_of_low_points(sea_floor_height_map))
    print("Day09")
    print(f"  - Part 1: {sum(low_points) + len(low_points)}")
