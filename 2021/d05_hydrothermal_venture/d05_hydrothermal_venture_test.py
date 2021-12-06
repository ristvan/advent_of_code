import unittest

import d05_hydrothermal_venture as d05


class HydrothermalVentureTestCase(unittest.TestCase):
    def test_convert_line_of_file_to_line_segment(self):
        testcases = [
            ("0,9 -> 5,9", (0, 9, 5, 9)),
            ("8,0 -> 0,8", (8, 0, 0, 8)),
            ("9,4 -> 3,4", (9, 4, 3, 4)),
            ("2,2 -> 2,1", (2, 2, 2, 1)),
            ("7,0 -> 7,4", (7, 0, 7, 4)),
            ("6,4 -> 2,0", (6, 4, 2, 0)),
            ("0,9 -> 2,9", (0, 9, 2, 9)),
            ("3,4 -> 1,4", (3, 4, 1, 4)),
            ("0,0 -> 8,8", (0, 0, 8, 8)),
            ("5,5 -> 8,2", (5, 5, 8, 2))
        ]
        for line_of_file, expected_output in testcases:
            self.assertEqual(expected_output, d05.convert_line_of_file_to_line_segment(line_of_file))

    def test_get_max_coordinates(self):
        coordinates = [
            (0, 9, 5, 9),
            (8, 0, 0, 8),
            (0, 9, 5, 9),
            (8, 0, 0, 8),
            (9, 4, 3, 4),
            (2, 2, 2, 1),
            (7, 0, 7, 4),
            (6, 4, 2, 0),
            (0, 9, 2, 9),
            (3, 4, 1, 4),
            (0, 0, 8, 8),
            (5, 5, 8, 2)
        ]
        max_x, max_y = d05.calculate_max_coordinates(coordinates)
        self.assertEqual(9, max_x)
        self.assertEqual(9, max_y)

    def test_create_a_line(self):
        testcases = [
            ((8, 0, 0, 8), list()),
            ((0, 9, 5, 9), [(0, 9), (1, 9), (2, 9), (3, 9), (4, 9), (5, 9)]),
            ((9, 4, 3, 4), [(3, 4), (4, 4), (5, 4), (6, 4), (7, 4), (8, 4), (9, 4)]),
            ((2, 2, 2, 1), [(2, 1), (2, 2)]),
            ((7, 0, 7, 4), [(7, 0), (7, 1), (7, 2), (7, 3), (7, 4)]),
            ((0, 0, 8, 8), list()),
            ((5, 5, 8, 2), list())
        ]
        for endpoints_of_line, expected_output in testcases:
            self.assertEqual(expected_output, d05.create_horizontal_or_vertical_line(endpoints_of_line))

    def test_hydrothermal_venture(self):
        coordinates = [
            (0, 9, 5, 9),
            (8, 0, 0, 8),
            (9, 4, 3, 4),
            (2, 2, 2, 1),
            (7, 0, 7, 4),
            (6, 4, 2, 0),
            (0, 9, 2, 9),
            (3, 4, 1, 4),
            (0, 0, 8, 8),
            (5, 5, 8, 2)
        ]
        hydrothermal_venture = d05.HydrothermalVenture(d05.calculate_max_coordinates(coordinates), d05.create_horizontal_or_vertical_line)
        hydrothermal_venture.add_all_coordinates(coordinates)
        self.assertEqual(5, hydrothermal_venture.number_of_dangerous_places())

    def test_hydrothermal_venture_full_version(self):
        coordinates = [
            (0, 9, 5, 9),
            (8, 0, 0, 8),
            (9, 4, 3, 4),
            (2, 2, 2, 1),
            (7, 0, 7, 4),
            (6, 4, 2, 0),
            (0, 9, 2, 9),
            (3, 4, 1, 4),
            (0, 0, 8, 8),
            (5, 5, 8, 2)
        ]
        hydrothermal_venture = d05.HydrothermalVenture(d05.calculate_max_coordinates(coordinates), d05.create_every_line)
        hydrothermal_venture.add_all_coordinates(coordinates)
        self.assertEqual(12, hydrothermal_venture.number_of_dangerous_places())


if __name__ == '__main__':
    unittest.main()
