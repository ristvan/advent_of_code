from util import read_file


def get_next_minimal_point(nodes_to_check: set, risk_map: list):
    min_column, min_row = -1, -1
    for row, column in nodes_to_check:
        if min_row < 0 or risk_map[min_row][min_column] > risk_map[row][column]:
            min_row, min_column = row, column
    nodes_to_check.remove((min_row, min_column))
    return min_row, min_column


def get_neighbours(row, column, height, width):
    nb = [(row + y, column + x) for y in range(-1, 2) for x in range(-1, 2) if
              x != y and x != -y and 0 <= row + y < height and 0 <= column + x < width]
    return nb


class CavernMap:
    def __init__(self, cavern_map: list):
        self._map = cavern_map.copy()

    def get_height(self):
        return len(self._map)

    def get_width(self):
        return len(self._map[0])

    def get(self, row: int, column: int):
        return self._map[row][column]

    def sum_of_items(self):
        return sum([sum(row) for row in self._map])


def find_a_route_with_the_lowest_risk(cavern_map: CavernMap):
    infinity = cavern_map.sum_of_items() + 1
    risk_map = [[infinity for _ in range(cavern_map.get_width())] for _ in range(cavern_map.get_height())]
    risk_map[0][0] = 0
    nodes_to_check = {(0, 0)}
    while len(nodes_to_check) > 0:
        row, column = get_next_minimal_point(nodes_to_check, risk_map)
        for new_row, new_column in get_neighbours(row, column, cavern_map.get_height(), cavern_map.get_width()):
            if risk_map[new_row][new_column] > risk_map[row][column] + cavern_map.get(new_row, new_column):
                risk_map[new_row][new_column] = risk_map[row][column] + cavern_map.get(new_row, new_column)
                nodes_to_check.add((new_row, new_column))

    return risk_map[-1][-1]


def solve():
    line_of_files = read_file("d15_chiton/input.txt")
    maze = [[int(column) for column in row] for row in line_of_files]
    cavern_map = CavernMap(maze)

    minimal_risk = find_a_route_with_the_lowest_risk(cavern_map)

    print("Day 15")
    print(f"  - Part 1: {minimal_risk}")
