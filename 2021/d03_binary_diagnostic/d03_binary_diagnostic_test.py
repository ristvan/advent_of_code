import unittest

import d03_binary_diagnostic as d03


class BinaryDiagnosticTestCase(unittest.TestCase):
    def test_most_common_bits_simple_zero(self):
        binary_numbers = [
            "0"
        ]
        self.assertEqual("0", d03.most_common_bits(binary_numbers))

    def test_most_common_bits_simple_one(self):
        binary_numbers = [
            "1"
        ]
        self.assertEqual("1", d03.most_common_bits(binary_numbers))

    def test_most_common_bits_one_length_more_numbers_result_zero(self):
        binary_numbers = [
            "1",
            "0",
            "0",
            "1",
            "0"
        ]
        self.assertEqual("0", d03.most_common_bits(binary_numbers))

    def test_most_common_bits_one_length_more_numbers_result_one(self):
        binary_numbers = [
            "0",
            "1",
            "1",
            "1",
            "0"
        ]
        self.assertEqual("1", d03.most_common_bits(binary_numbers))

    def test_most_common_bits_more_than_one_length_for_one_number_result_is_the_number(self):
        binary_numbers = [
            "01110"
        ]
        self.assertEqual("01110", d03.most_common_bits(binary_numbers))

    def test_most_common_bits_more_than_one_length_for_multiple_numbers(self):
        binary_numbers = [
            "00100",
            "11110",
            "10110",
            "10111",
            "10101",
            "01111",
            "00111",
            "11100",
            "10000",
            "11001",
            "00010",
            "01010"
        ]
        self.assertEqual("10110", d03.most_common_bits(binary_numbers))

    def test_binary_inverse(self):
        testcases = [
            ("00100", "11011"),
            ("11110", "00001"),
            ("10110", "01001"),
            ("10111", "01000"),
            ("10101", "01010"),
            ("01111", "10000"),
            ("00111", "11000"),
            ("11100", "00011"),
            ("10000", "01111"),
            ("11001", "00110"),
            ("00010", "11101"),
            ("01010", "10101")
        ]
        for binary_number, expected_result in testcases:
            self.assertEqual(expected_result, d03.binary_inverse(binary_number))

    def test_oxygen_generator_rating(self):
        binary_numbers = [
            "00100",
            "11110",
            "10110",
            "10111",
            "10101",
            "01111",
            "00111",
            "11100",
            "10000",
            "11001",
            "00010",
            "01010"
        ]
        self.assertEqual("10111", d03.find_numbers(binary_numbers, d03.most_common_bits))

    def test_CO2_scrubber_rating(self):
        binary_numbers = [
            "00100",
            "11110",
            "10110",
            "10111",
            "10101",
            "01111",
            "00111",
            "11100",
            "10000",
            "11001",
            "00010",
            "01010"
        ]
        self.assertEqual("01010", d03.find_numbers(binary_numbers, d03.least_common_bits))


if __name__ == '__main__':
    unittest.main()
