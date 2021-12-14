import unittest

from d14_extended_polymerization.solution import extend_polymer, diff_between_most_and_least_common_elements


class ExtendedPolymerizationTestCase(unittest.TestCase):
    def setUp(self):
        self.rules = {
            "CH": "B",
            "HH": "N",
            "CB": "H",
            "NH": "C",
            "HB": "C",
            "HC": "B",
            "HN": "C",
            "NN": "C",
            "BH": "H",
            "NC": "B",
            "NB": "B",
            "BN": "B",
            "BB": "N",
            "BC": "B",
            "CC": "N",
            "CN": "C"
        }

    def test_one_step_polymerization(self):
        polymer_template = "NNCB"
        expected_polymer = "NCNBCHB"
        self.assertEqual(expected_polymer, extend_polymer(polymer_template, self.rules))

    def test_other_step_of_polymerization(self):
        polymer_template = "NCNBCHB"
        expected_polymer = "NBCCNBBBCBHCB"
        self.assertEqual(expected_polymer, extend_polymer(polymer_template, self.rules))

    def test_more_polymerizations(self):
        testcases = {
            ("NNCB", "NCNBCHB"),
            ("NCNBCHB", "NBCCNBBBCBHCB"),
            ("NBCCNBBBCBHCB", "NBBBCNCCNBBNBNBBCHBHHBCHB"),
            ("NBBBCNCCNBBNBNBBCHBHHBCHB", "NBBNBNBBCCNBCNCCNBBNBBNBBBNBBNBBCBHCBHHNHCBBCBHCB"),
            ("NBBNBNBBCCNBCNCCNBBNBBNBBBNBBNBBCBHCBHHNHCBBCBHCB", "NBBNBBNBBBNBBNBBCNCCNBBBCCNBCNCCNBBNBBNBBNBBNBBNBNBBNBBNBBNBBNBBCHBHHBCHBHHNHCNCHBCHBNBBCHBHHBCHB")
        }
        for input_polymer, expected_polymer in testcases:
            self.assertEqual(expected_polymer, extend_polymer(input_polymer, self.rules))

    def test_get_diff_between_most_and_least_common_elements(self):
        testcases = {
            ("NNCB", 1),
            ("NCNBCHB", 1),
            ("NBCCNBBBCBHCB", 5),
            ("NBBBCNCCNBBNBNBBCHBHHBCHB", 7),
            ("NBBNBNBBCCNBCNCCNBBNBBNBBBNBBNBBCBHCBHHNHCBBCBHCB", 18)
        }
        for input_polymer, expected_diff in testcases:
            self.assertEqual(expected_diff, diff_between_most_and_least_common_elements(input_polymer))

    def test_get_diff_between_most_and_least_common_elements_for_the_example(self):
        polymer = "NNCB"
        for _ in range(10):
            polymer = extend_polymer(polymer, self.rules)
        self.assertEqual(1588, diff_between_most_and_least_common_elements(polymer))


if __name__ == '__main__':
    unittest.main()
