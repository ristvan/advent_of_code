import unittest

import d11_dumbo_octopus as d11


class DumboOctopusTestCase(unittest.TestCase):
    def test_simple_output(self):
        starting_status = [
            [1, 1, 1, 1, 1],
            [1, 9, 9, 9, 1],
            [1, 9, 1, 9, 1],
            [1, 9, 9, 9, 1],
            [1, 1, 1, 1, 1]
        ]
        octopus = d11.DumboOctopus(starting_status)
        octopus.next_state()
        self.assertEqual(9, octopus.get_total_flashes())

        octopus.next_state()
        self.assertEqual(9, octopus.get_total_flashes())

    def test_larger_example_input(self):
        starting_energies = [
            [5, 4, 8, 3, 1, 4, 3, 2, 2, 3],
            [2, 7, 4, 5, 8, 5, 4, 7, 1, 1],
            [5, 2, 6, 4, 5, 5, 6, 1, 7, 3],
            [6, 1, 4, 1, 3, 3, 6, 1, 4, 6],
            [6, 3, 5, 7, 3, 8, 5, 4, 7, 8],
            [4, 1, 6, 7, 5, 2, 4, 6, 4, 5],
            [2, 1, 7, 6, 8, 4, 1, 7, 2, 1],
            [6, 8, 8, 2, 8, 8, 1, 1, 3, 4],
            [4, 8, 4, 6, 8, 4, 8, 5, 5, 4],
            [5, 2, 8, 3, 7, 5, 1, 5, 2, 6],
        ]

        octopus = d11.DumboOctopus(starting_energies)
        self.assertEqual(0, octopus.get_total_flashes())

        octopus.next_state()
        self.assertEqual(0, octopus.get_total_flashes())

        octopus.next_state()
        self.assertEqual(35, octopus.get_total_flashes())

        octopus.next_state()
        self.assertEqual(80, octopus.get_total_flashes())

        octopus.next_state()
        self.assertEqual(96, octopus.get_total_flashes())

        for _ in range(6):
            octopus.next_state()
        self.assertEqual(204, octopus.get_total_flashes())

        for _ in range(90):
            octopus.next_state()
        self.assertEqual(1656, octopus.get_total_flashes())


if __name__ == '__main__':
    unittest.main()
