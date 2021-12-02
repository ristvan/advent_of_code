from util import read_file


def read_command(text):
    text_parts = text.split()
    command = text_parts[0]
    value = int(text_parts[1])
    return command, value


class Submarine:
    def __init__(self):
        self.horizontal_pos = 0
        self.depth = 0

    def get_position(self):
        return self.horizontal_pos, self.depth

    def down(self, depth_change):
        self.depth += depth_change

    def up(self, depth_change):
        self.depth -= depth_change

    def forward(self, distance):
        self.horizontal_pos += distance


class AimingSubmarine:
    def __init__(self):
        self.horizontal_pos = 0
        self.depth = 0
        self.aim = 0

    def get_position(self):
        return self.horizontal_pos, self.depth

    def down(self, change):
        self.aim += change

    def up(self, change):
        self.aim -= change

    def forward(self, distance):
        self.horizontal_pos += distance
        self.depth += self.aim * distance


def solve():
    lines = read_file("d02_dive/input.txt")
    commands = [read_command(line) for line in lines]
    depth, horizontal_pos = execute_commands(commands, Submarine())
    depth_aim, horizontal_pos_aim = execute_commands(commands, AimingSubmarine())
    print("Day 02")
    print(f"  - Part 1: {horizontal_pos * depth}")
    print(f"  - Part 2: {horizontal_pos_aim * depth_aim}")


def execute_commands(commands, submarine):
    for command, value in commands:
        if command == "forward":
            submarine.forward(value)
        elif command == "up":
            submarine.up(value)
        elif command == "down":
            submarine.down(value)
    horizontal_pos, depth = submarine.get_position()
    return depth, horizontal_pos
