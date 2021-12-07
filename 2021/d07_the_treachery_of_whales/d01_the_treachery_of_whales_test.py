import unittest

from d07_the_treachery_of_whales.d01_the_treachery_of_whales import count_min_fuel_for_crab_moving


class TheTreacheryOfWhalesTestCase(unittest.TestCase):
    def test_minimal_movement(self):
        crabs = [16, 1, 2, 0, 4, 2, 7, 1, 2, 14]
        fuel = count_min_fuel_for_crab_moving(crabs)
        self.assertEqual(37, fuel)


if __name__ == '__main__':
    unittest.main()
