import math
import unittest

import d09_smoke_basin as d09


class SmokeBasinTestCase(unittest.TestCase):
    def test_find_positions_of_low_points(self):
        height_map = [
            [2, 1, 9, 9, 9, 4, 3, 2, 1, 0],
            [3, 9, 8, 7, 8, 9, 4, 9, 2, 1],
            [9, 8, 5, 6, 7, 8, 9, 8, 9, 2],
            [8, 7, 6, 7, 8, 9, 6, 7, 8, 9],
            [9, 8, 9, 9, 9, 6, 5, 6, 7, 8]
        ]
        expected_positions_of_low_points = [(0, 1), (0, 9), (2, 2), (4, 6)]
        actual_positions_of_low_points = d09.find_positions_of_low_points(height_map)
        self.assertListEqual(expected_positions_of_low_points, actual_positions_of_low_points)

    def test_find_low_points(self):
        height_map = [
            [2, 1, 9, 9, 9, 4, 3, 2, 1, 0],
            [3, 9, 8, 7, 8, 9, 4, 9, 2, 1],
            [9, 8, 5, 6, 7, 8, 9, 8, 9, 2],
            [8, 7, 6, 7, 8, 9, 6, 7, 8, 9],
            [9, 8, 9, 9, 9, 6, 5, 6, 7, 8]
        ]
        expected_low_points = [1, 0, 5, 5]
        actual_positions_of_low_points = d09.find_positions_of_low_points(height_map)
        self.assertListEqual(expected_low_points, d09.find_low_points(height_map, actual_positions_of_low_points))

    def test_count_size_of_basin(self):
        height_map = [
            [2, 1, 9, 9, 9, 4, 3, 2, 1, 0],
            [3, 9, 8, 7, 8, 9, 4, 9, 2, 1],
            [9, 8, 5, 6, 7, 8, 9, 8, 9, 2],
            [8, 7, 6, 7, 8, 9, 6, 7, 8, 9],
            [9, 8, 9, 9, 9, 6, 5, 6, 7, 8]
        ]
        self.assertEqual(3, d09.count_size_of_basin(height_map, (0, 1)))
        self.assertEqual(9, d09.count_size_of_basin(height_map, (0, 9)))
        self.assertEqual(14, d09.count_size_of_basin(height_map, (2, 2)))
        self.assertEqual(9, d09.count_size_of_basin(height_map, (4, 6)))

    def test_get_all_the_size_of_basins(self):
        height_map = [
            [2, 1, 9, 9, 9, 4, 3, 2, 1, 0],
            [3, 9, 8, 7, 8, 9, 4, 9, 2, 1],
            [9, 8, 5, 6, 7, 8, 9, 8, 9, 2],
            [8, 7, 6, 7, 8, 9, 6, 7, 8, 9],
            [9, 8, 9, 9, 9, 6, 5, 6, 7, 8]
        ]
        low_points = [(0, 1), (0, 9), (2, 2), (4, 6)]
        self.assertListEqual([3, 9, 14, 9], d09.get_all_the_size_of_basins(height_map, low_points))
        self.assertEqual(1134, math.prod(list(sorted([3, 9, 14, 9], reverse=True))[0:3]))


if __name__ == '__main__':
    unittest.main()
