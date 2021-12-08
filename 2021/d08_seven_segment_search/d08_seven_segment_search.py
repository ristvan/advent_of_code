from util import read_file


def separate_signal_and_digit_output(line_of_file):
    signals_and_outputs = line_of_file.split("|")
    return signals_and_outputs[0].strip().split(), signals_and_outputs[1].strip().split()


def count_easy_digits(digits):
    number_of_easy_digits = 0
    for digit in digits:
        if len(digit) in [2, 3, 4, 7]:
            number_of_easy_digits += 1
    return number_of_easy_digits


def calculate_segments(signal_patterns):
    priority = {8: 0, 7: 1, 4: 2, 3: 3, 2: 4, 5: 5, 6: 6}
    signal_patterns.sort(key=lambda item: priority[len(item)])
    segments = calculate_all_possible_values_for_segments(signal_patterns)

    segment_distribution = set()
    while len(segment_distribution) != 7:
        for index, segment_items in segments.items():
            if len(segment_items) == 1:
                segment_distribution.add(list(segment_items)[0])
            if len(segment_items) > 1:
                remove_already_found_segments(segment_distribution, segment_items)

    return "".join([list(x)[0] for x in segments.values()])


def remove_already_found_segments(segment_distribution, segment_items):
    for seg in segment_distribution:
        if seg in segment_items:
            segment_items.remove(seg)


def calculate_all_possible_values_for_segments(signal_patterns):
    segment_mapping = {
        2: "0010010",
        3: "1010010",
        4: "0111010",
        5: "1001001",
        6: "1100011"
    }
    segments = {index: set(signal_patterns[0]) for index in range(7)}
    signal_patterns.pop(0)
    for signal_pattern in signal_patterns:
        segment_map = segment_mapping[len(signal_pattern)]
        for i in range(len(segment_map)):
            if segment_map[i] == "1":
                segments[i] = segments[i].intersection(set(signal_pattern))
    return segments


def show_number(segment_connections, numbers_to_show):
    number_mapper = {
        "0123456": "8",
        "012456": "0",
        "25": "1",
        "02346": "2",
        "02356": "3",
        "1235": "4",
        "01356": "5",
        "013456": "6",
        "025": "7",
        "012356": "9"
    }
    result = []
    for number_to_show in numbers_to_show:
        x = "".join(sorted([str(segment_connections.index(segment)) for segment in number_to_show]))
        result.append(number_mapper.get(x, "-"))

    return int("".join(result))


def solve():
    lines_of_file = read_file("d08_seven_segment_search/input.txt")
    signal_and_digit_outputs = [separate_signal_and_digit_output(line_of_file) for line_of_file in lines_of_file]
    number_of_easy_digits = sum([count_easy_digits(output_digit) for _, output_digit in signal_and_digit_outputs])

    numbers = list()
    for signal_patterns, numbers_to_show in signal_and_digit_outputs:
        segments = calculate_segments(signal_patterns)
        numbers.append(show_number(segments, numbers_to_show))

    print("Day 08")
    print(f"  - Part 1: {number_of_easy_digits}")
    print(f"  - Part 2: {sum(numbers)}")
