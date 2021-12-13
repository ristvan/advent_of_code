from util import read_file


def is_matching(opening, closing):
    matcher = {"(": ")", "[": "]", "{": "}", "<": ">"}
    return matcher.get(opening, "") == closing


def parse_chunk(chunk):
    stack = list()
    first_invalid_character = ""
    for character in chunk:
        if character in "({[<":
            stack.append(character)
        elif is_matching(stack[-1], character):
            stack.pop()
        else:
            first_invalid_character = character
            break

    stack.reverse()
    return first_invalid_character == "", first_invalid_character, stack


SCORES = {
    "": 0,
    ")": 3,
    "]": 57,
    "}": 1197,
    ">": 25137
}

COMPLETION_SCORES = " ([{<"


def calculate_completion_score(completion_string_of_chunk):
    scores = [str(COMPLETION_SCORES.index(ch)) for ch in completion_string_of_chunk]
    return int("".join(scores), 5)


def solve():
    lines_of_file = read_file("d10_syntax_scoring/input.txt")
    parsed_chunks = [parse_chunk(line_of_file) for line_of_file in lines_of_file]
    scores = [SCORES[parsed_chunk[1]] for parsed_chunk in parsed_chunks]
    completion_string_of_chunks = list(map(lambda x: x[2], filter(lambda x: x[0], parsed_chunks)))
    completion_scores = [calculate_completion_score(completion_string_of_chunk) for completion_string_of_chunk in
                         completion_string_of_chunks]
    completion_scores.sort()
    print("Day 10")
    print(f"  - Part 1: {sum(scores)}")
    print(f"  - Part 2: {completion_scores[len(completion_scores) // 2]}")
