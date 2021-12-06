import unittest

import d06_lanternfish as d06


class LanternFishesTestCase(unittest.TestCase):
    def test_creating_object(self):
        lantern_fishes = d06.LanternFishes([3, 4, 3, 1, 2])
        self.assertEqual(5, lantern_fishes.get_number_of_fishes())

    def test_iterate_lantern_fishes(self):
        testcases = [
            ([3, 4, 3, 1, 2], 5),
            ([2, 3, 2, 0, 1], 6),
        ]
        for fishes, expected_number_of_fishes in testcases:
            lantern_fishes = d06.LanternFishes(fishes)
            lantern_fishes.iterate_one_day()
            self.assertEqual(expected_number_of_fishes, lantern_fishes.get_number_of_fishes())

    def test_iterate_several_days(self):
        lantern_fishes = d06.LanternFishes([3, 4, 3, 1, 2])
        lantern_fishes.iterate_several_days(18)
        self.assertEqual(26, lantern_fishes.get_number_of_fishes())
        lantern_fishes.iterate_one_day()
        self.assertEqual(29, lantern_fishes.get_number_of_fishes())
        lantern_fishes.iterate_one_day()
        self.assertEqual(34, lantern_fishes.get_number_of_fishes())

        lantern_fishes = d06.LanternFishes([3, 4, 3, 1, 2])
        lantern_fishes.iterate_several_days(80)
        self.assertEqual(5934, lantern_fishes.get_number_of_fishes())
        lantern_fishes.iterate_several_days(176)
        self.assertEqual(26984457539, lantern_fishes.get_number_of_fishes())


if __name__ == '__main__':
    unittest.main()
