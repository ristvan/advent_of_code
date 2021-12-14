import unittest

from d14_extended_polymerization.solution import create_pairs_from_polymer, extend_polymer_pairs, \
    diff_between_most_and_least_common_elements_from_pairs


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

    def test_create_pairs_for_polymer(self):
        polymer = "NNCB"
        expected_pairs = {
            "NN": 1,
            "NC": 1,
            "CB": 1
        }
        self.assertDictEqual(expected_pairs, create_pairs_from_polymer(polymer))

    def test_create_pairs_for_polymer_for_input(self):
        polymer = "COPBCNPOBKCCFFBSVHKO"
        expected_pairs = {
            "CO": 1,
            "OP": 1,
            "PB": 1,
            "BC": 1,
            "CN": 1,
            "NP": 1,
            "PO": 1,
            "OB": 1,
            "BK": 1,
            "KC": 1,
            "CC": 1,
            "CF": 1,
            "FF": 1,
            "FB": 1,
            "BS": 1,
            "SV": 1,
            "VH": 1,
            "HK": 1,
            "KO": 1
        }
        self.assertDictEqual(expected_pairs, create_pairs_from_polymer(polymer))

    def test_extend_polymer_pairs(self):
        polymer_pairs = {
            "NN": 1,
            "NC": 1,
            "CB": 1
        }
        expected_polymer_pairs = {
            "NC": 1,
            "CN": 1,
            "NB": 1,
            "BC": 1,
            "CH": 1,
            "HB": 1
        }
        actual_polymer_pairs = extend_polymer_pairs(polymer_pairs, self.rules)
        self.assertEqual(expected_polymer_pairs, actual_polymer_pairs)

        expected_polymer_pairs = {
            "CN": 1,
            "CB": 2,
            "NB": 2,
            "BC": 2,
            "CC": 1,
            "BB": 2,
            "HC": 1,
            "BH": 1
        }
        actual_polymer_pairs = extend_polymer_pairs(actual_polymer_pairs, self.rules)
        self.assertEqual(expected_polymer_pairs, actual_polymer_pairs)

    def test_solution_part_2(self):
        polymer_template = "NNCB"
        polymer_pairs = create_pairs_from_polymer(polymer_template)
        self.assertEqual(1, diff_between_most_and_least_common_elements_from_pairs(polymer_pairs, polymer_template))

        polymer_pairs = extend_polymer_pairs(polymer_pairs, self.rules)
        self.assertEqual(1, diff_between_most_and_least_common_elements_from_pairs(polymer_pairs, polymer_template))

        polymer_pairs = extend_polymer_pairs(polymer_pairs, self.rules)
        self.assertEqual(5, diff_between_most_and_least_common_elements_from_pairs(polymer_pairs, polymer_template))

        for _ in range(2):
            polymer_pairs = extend_polymer_pairs(polymer_pairs, self.rules)
        self.assertEqual(18, diff_between_most_and_least_common_elements_from_pairs(polymer_pairs, polymer_template))

        for _ in range(6):
            polymer_pairs = extend_polymer_pairs(polymer_pairs, self.rules)
        self.assertEqual(1588, diff_between_most_and_least_common_elements_from_pairs(polymer_pairs, polymer_template))

        for _ in range(30):
            polymer_pairs = extend_polymer_pairs(polymer_pairs, self.rules)
        self.assertEqual(2188189693529, diff_between_most_and_least_common_elements_from_pairs(polymer_pairs, polymer_template))


if __name__ == '__main__':
    unittest.main()
