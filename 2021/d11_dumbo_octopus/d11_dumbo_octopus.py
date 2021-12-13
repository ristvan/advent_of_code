from util import read_file


class DumboOctopus:
    def __init__(self, starting_status: list):
        self._already_flashed = set()
        self._needs_to_flash = set()
        self._energy_levels = starting_status.copy()
        self._all_flashes = 0
        self._neighbour_deltas = [(y, x) for y in range(-1, 2) for x in range(-1, 2) if y != 0 or x != y]

    def next_state(self):
        self._needs_to_flash = set()
        for row_index in range(len(self._energy_levels)):
            for column_index in range(len(self._energy_levels[row_index])):
                self._energy_levels[row_index][column_index] += 1
                if self._energy_levels[row_index][column_index] >= 10:
                    self._needs_to_flash.add((row_index, column_index))

        self._already_flashed = set()
        while len(self._needs_to_flash):
            row_to_flash, column_to_flash = self._needs_to_flash.pop()
            self._already_flashed.add((row_to_flash, column_to_flash))
            self._energy_levels[row_to_flash][column_to_flash] = 0
            self._energize_neighbours(row_to_flash, column_to_flash)

        self._all_flashes += len(self._already_flashed)

    def _energize_neighbours(self, row_to_flash, column_to_flash):
        for neighbour_delta_row, neighbour_delta_column in self._neighbour_deltas:
            neighbour_row = row_to_flash + neighbour_delta_row
            neighbour_column = column_to_flash + neighbour_delta_column
            if self._is_needs_to_be_energized(neighbour_row, neighbour_column):
                self._energy_levels[neighbour_row][neighbour_column] += 1
                if self._energy_levels[neighbour_row][neighbour_column] >= 10:
                    self._needs_to_flash.add((neighbour_row, neighbour_column))

    def _is_needs_to_be_energized(self, neighbour_row, neighbour_column):
        is_already_flashed = (neighbour_row, neighbour_column) not in self._already_flashed
        return is_already_flashed and self._is_valid_coordinate(neighbour_row, neighbour_column)

    def _is_valid_coordinate(self, neighbour_row, neighbour_column):
        return 0 <= neighbour_row < len(self._energy_levels) and 0 <= neighbour_column < len(self._energy_levels[0])

    def get_total_flashes(self):
        return self._all_flashes


def solve():
    lines_of_file = read_file("d11_dumbo_octopus/input.txt")
    octopus_energies = [[int(octopus) for octopus in line_of_file] for line_of_file in lines_of_file]
    octopus = DumboOctopus(octopus_energies)
    for _ in range(100):
        octopus.next_state()

    print("Day 11:")
    print(f"  - Part 1: {octopus.get_total_flashes()}")
