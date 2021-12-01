import unittest

import d01_sonar_sweep as d01


class MyTestCase(unittest.TestCase):
    def test_count_simple_increases(self):
        depths = [
            199,
            200,
            208,
            210,
            200,
            207,
            240,
            269,
            260,
            263
        ]
        self.assertEqual(7, d01.count_simple_increases(depths))

    def test_count_simple_increases(self):
        depths = [
            199,
            200,
            208,
            210,
            200,
            207,
            240,
            269,
            260,
            263
        ]
        self.assertEqual(5, d01.count_windowed_increases(depths))


if __name__ == '__main__':
    unittest.main()
