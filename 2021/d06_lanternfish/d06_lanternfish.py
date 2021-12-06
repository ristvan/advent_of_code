from util import read_file


class LanternFishes:
    def __init__(self, beginning_fishes):
        self._fishes = beginning_fishes

    def get_number_of_fishes(self):
        return len(self._fishes)

    def iterate_one_day(self):
        for index in range(len(self._fishes)):
            if self._fishes[index] == 0:
                self._fishes[index] = 6
                self._fishes.append(8)
            else:
                self._fishes[index] -= 1

    def iterate_several_days(self, number_of_iterations):
        for _ in range(number_of_iterations):
            self.iterate_one_day()


def solve():
    lines_of_file = read_file("d06_lanternfish/input.txt")
    fishes = [int(fish.strip()) for fish in lines_of_file[0].split(",")]
    lantern_fishes = LanternFishes(fishes)
    lantern_fishes.iterate_several_days(80)
    print("Day 06")
    print(f"  - Part 1: {lantern_fishes.get_number_of_fishes()}")
