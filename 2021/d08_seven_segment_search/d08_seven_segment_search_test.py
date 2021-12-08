import unittest

import d08_seven_segment_search as d08


class SevenSegmentSearchTestCase(unittest.TestCase):
    def test_separate_signal_and_digit_output(self):
        line_of_file = "acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab | cdfeb fcadb cdfeb cdbaf"
        expected_output = (["acedgfb", "cdfbe", "gcdfa", "fbcad", "dab", "cefabd", "cdfgeb", "eafb", "cagedb", "ab"],
                           ["cdfeb", "fcadb", "cdfeb", "cdbaf"])
        self.assertEqual(expected_output, d08.separate_signal_and_digit_output(line_of_file))

        line_of_file = "be cfbegad cbdgef fgaecd cgeb fdcge agebfd fecdb fabcd edb | fdgacbe cefdb cefbgd gcbe"
        expected_output = (["be", "cfbegad", "cbdgef", "fgaecd", "cgeb", "fdcge", "agebfd", "fecdb", "fabcd", "edb"],
                           ["fdgacbe", "cefdb", "cefbgd", "gcbe"])
        self.assertEqual(expected_output, d08.separate_signal_and_digit_output(line_of_file))

    def test_count_easy_digits(self):
        testcases = [
            (["cdfeb", "fcadb", "cdfeb", "cdbaf"], 0),
            (["fdgacbe", "cefdb", "cefbgd", "gcbe"], 2),
            (["cg", "cg", "fdcagb", "cbg"], 3)
        ]

        for output_digits, expected_result in testcases:
            self.assertEqual(expected_result, d08.count_easy_digits(output_digits))

    def test_calculate_segments(self):
        signal_patterns = ["acedgfb", "cdfbe", "gcdfa", "fbcad", "dab", "cefabd", "cdfgeb", "eafb", "cagedb", "ab"]
        expected_segments = "deafgbc"
        actual_segments = d08.calculate_segments(signal_patterns)
        self.assertEqual(expected_segments, actual_segments)

    def test_show_number(self):
        segment_connections = "deafgbc"
        numbers_to_show = ["cdfeb", "fcadb", "cdfeb", "cdbaf"]
        actual_number = d08.show_number(segment_connections, numbers_to_show)
        self.assertEqual(5353, actual_number)

        segment_connections = "abcdefg"
        numbers_to_show = ["acf", "acdeg", "abcdfg", "cf"]
        actual_number = d08.show_number(segment_connections, numbers_to_show)
        self.assertEqual(7291, actual_number)

    def test_full_conversions(self):
        testcases = [
            (["edbfga", "begcd", "cbg", "gc", "gcadebf", "fbgde", "acbgfd", "abcde", "gfcbed", "gfec"],
             ["fcgedb", "cgb", "dgebacf", "gc"], 9781),
            (["egadfb", "cdbfeg", "cegd", "fecab", "cgb", "gbdefca", "cg", "fgcdab", "egfdb", "bfceg"],
             ["gbdfcae", "bgc", "cg", "cgb"], 8717),
            (["fgeab", "ca", "afcebg", "bdacfeg", "cfaedg", "gcfdb", "baec", "bfadeg", "bafgc", "acf"],
             ["gebdcfa", "ecba", "ca", "fadegcb"], 8418),
            (["dbgcae", "gdeaf", "cefga", "cfa", "dcbgfa", "cgfabe", "cefb", "cf", "ebfgcda", "acgbe"],
             ["gebacdf", "fcgdeab", "bacdge", "cfeb"], 8864)
        ]

        for signal_patterns, numbers_to_show, expected_number in testcases:
            segments = d08.calculate_segments(signal_patterns)
            number = d08.show_number(segments, numbers_to_show)
            self.assertEqual(expected_number, number)


if __name__ == '__main__':
    unittest.main()
