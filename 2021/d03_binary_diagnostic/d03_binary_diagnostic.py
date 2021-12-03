from util import read_file


def binary_inverse(binary_number):
    return "".join(["0" if digit == "1" else "1" for digit in binary_number])


def most_common_bits(binary_numbers):
    answer = ""
    for index in range(len(binary_numbers[0])):
        column = [binary_number[index] for binary_number in binary_numbers]
        number_of_ones = column.count("1")
        answer += "1" if column.count("1") >= len(column) - number_of_ones else "0"
    return answer


def least_common_bits(binary_numbers):
    return binary_inverse(most_common_bits(binary_numbers))


def find_numbers(binary_numbers, method):
    def filter_function(i):
        return lambda bn: bn[i] == common_bits[i]
    binary_numbers_to_search = binary_numbers.copy()
    for index in range(len(binary_numbers[0])):
        common_bits = method(binary_numbers_to_search)
        binary_numbers_to_search = list(filter(filter_function(index), binary_numbers_to_search))
        if len(binary_numbers_to_search) == 1:
            break
    return binary_numbers_to_search[0]


def solve():
    lines = read_file("d03_binary_diagnostic/input.txt")
    gamma_rate = most_common_bits(lines)
    epsilon = binary_inverse(gamma_rate)
    power_consumption = int(gamma_rate, 2) * int(epsilon, 2)
    oxygen_generator_rating = int(find_numbers(lines, most_common_bits), 2)
    co2_scrubber_rating = int(find_numbers(lines, least_common_bits), 2)
    print("Day 3")
    print(f"  - Part 1: {power_consumption}")
    print(f"  - Part 2: {oxygen_generator_rating * co2_scrubber_rating}")
