from util import read_file


class TransparentPaper:
    def __init__(self, dots: list):
        width = max([x for x, _ in dots])
        height = max([y for _, y in dots])
        self._paper = [["." for _ in range(width + 1)] for _ in range(height + 1)]
        for x, y in dots:
            self._paper[y][x] = '#'

    def fold_horizontally(self, row):
        height = len(self._paper)
        upper_height = row
        lower_height = height - row - 1
        max_height = max(upper_height, lower_height)
        folded_paper = list()
        for row_index in range(max_height):
            new_row = list()
            for column_index in range(len(self._paper[0])):
                y1 = row_index + (upper_height - max_height)
                y2 = row + max_height - row_index
                upper_character = "." if y1 < 0 else self._paper[y1][column_index]
                lower_character = "." if y2 >= height else self._paper[y2][column_index]
                new_row.append("#" if "#" in [upper_character, lower_character] else ".")
            folded_paper.append(new_row)
        self._paper = folded_paper

    def fold_vertically(self, column):
        width = len(self._paper[0])
        left_width = column
        right_width = width - column - 1
        max_width = max(left_width, right_width)
        folded_paper = list()
        for row_index in range(len(self._paper)):
            new_row = list()
            for column_index in range(max_width):
                x1 = column_index + (left_width - max_width)
                x2 = column + max_width - column_index
                left_character = "." if x1 < 0 else self._paper[row_index][x1]
                right_character = "." if x2 >= width else self._paper[row_index][x2]
                new_row.append("#" if "#" in [left_character, right_character] else ".")
            folded_paper.append(new_row)
        self._paper = folded_paper

    def get_number_of_visible_dots(self):
        return sum([row.count("#") for row in self._paper])

    def __str__(self):
        data = ""
        for row in self._paper:
            data += "".join(row).replace(".", " ") + "\n"
        return data


def line_to_dot(line_of_file):
    coordinates = line_of_file.split(",")
    return int(coordinates[0].strip()), int(coordinates[1].strip())


def line_to_fold(line_of_file):
    shorted_line = line_of_file.replace("fold along ", "")
    parts = shorted_line.split("=")
    return parts[0].strip(), int(parts[1].strip())


def solve():
    lines_of_file = read_file("d13_transparent_origami/input.txt")
    dots = list()
    folds = list()
    is_dot = True
    for line_of_file in lines_of_file:
        if line_of_file == "":
            is_dot = False
        elif is_dot:
            dots.append(line_to_dot(line_of_file))
        else:
            folds.append(line_to_fold(line_of_file))

    paper = TransparentPaper(dots)
    direction, position = folds.pop(0)
    if direction == "y":
        paper.fold_horizontally(position)
    else:
        paper.fold_vertically(position)

    print("Day 13")
    print(f"  - Part 1: {paper.get_number_of_visible_dots()}")
    for direction, position in folds:
        if direction == "y":
            paper.fold_horizontally(position)
        else:
            paper.fold_vertically(position)
    print(str(paper))

