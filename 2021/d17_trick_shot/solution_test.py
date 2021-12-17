import unittest

from d17_trick_shot.solution import parse_target_area, find_trajectory_with_the_highest_y_coord


class MyTestCase(unittest.TestCase):
    def test_target_parsing_target_area(self):
        input_text = "target area: x=20..30, y=-10..-5"
        expected = ((-5, 20), (-10, 30))
        self.assertEqual(expected, parse_target_area(input_text))

        input_text = "target area: x=124..174, y=-123..-86"
        expected = ((-86, 124), (-123, 174))
        self.assertEqual(expected, parse_target_area(input_text))

    def test_find_trajectory_with_the_highest_y_coord(self):
        target = ((-5, 20), (-10, 30))
        solution = find_trajectory_with_the_highest_y_coord(target)
        self.assertEqual(45, solution)


if __name__ == '__main__':
    unittest.main()
