from util import read_file


class LanternFishes:
    def __init__(self, beginning_fishes):
        self._fishes = beginning_fishes
        self._counters = [
            [beginning_fishes.count(index) for index in range(6)]
        ]

    def get_number_of_fishes(self):
        return sum(self._counters[-1])

    def iterate_one_day(self):
        number_of_iterations = len(self._counters)
        new_iteration = list()
        for index in range(6):
            if index + 1 == number_of_iterations:
                new_iteration.append(self._counters[-1][index] * 2)
            elif number_of_iterations < 9:
                new_iteration.append(self._counters[-1][index])
            else:
                new_iteration.append(self._counters[-7][index] + self._counters[-9][index])
        self._counters.append(new_iteration)

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
    lantern_fishes.iterate_several_days(176)
    print(f"  - Part 2: {lantern_fishes.get_number_of_fishes()}")
