from util import read_file


def parse_target_area(input_text: str):
    target_area = input_text.removeprefix("target area:")
    params = [x.strip() for x in target_area.split(",")]
    for param in params:
        if param.startswith("x="):
            x_coordinates = [int(x) for x in param.removeprefix("x=").split("..")]
        else:
            y_coordinates = [int(x) for x in param.removeprefix("y=").split("..")]
    return (max(y_coordinates), min(x_coordinates)), (min(y_coordinates), max(x_coordinates))


def is_missed(x, y, target):
    (_, _), (bottom_y, bottom_x) = target
    return bottom_x < x or bottom_y > y


def is_hit_target(x, y, target):
    (top_y, top_x), (bottom_y, bottom_x) = target
    return top_x <= x <= bottom_x and bottom_y <= y <= top_y


def simulate(starting_y_velocity, starting_x_velocity, target):
    max_y = 0
    x_velocity = starting_x_velocity
    y_velocity = starting_y_velocity
    x, y = 0, 0
    while not is_missed(x, y, target):
        x += x_velocity
        y += y_velocity
        if y > max_y:
            max_y = y
        if is_hit_target(x, y, target):
            break
        if x_velocity > 0:
            x_velocity -= 1
        y_velocity -= 1

    return max_y


def find_trajectory_with_the_highest_y_coord(target):
    (top_y, top_x), (bottom_y, bottom_x) = target
    max_y = 0
    for starting_y_velocity in range(-bottom_y):
        for starting_x_velocity in range(top_x):
            y = simulate(starting_y_velocity, starting_x_velocity, target)
            if max_y < y:
                max_y = y

    return max_y


def solve():
    lines_of_file = read_file("d17_trick_shot/input.txt")
    target_area = parse_target_area(lines_of_file[0])

    max_y = find_trajectory_with_the_highest_y_coord(target_area)

    print("Day 17")
    print(f"  - Part 1: {max_y}")
