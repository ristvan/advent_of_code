import unittest

from d07_the_treachery_of_whales.d01_the_treachery_of_whales import count_min_fuel_for_crab_moving, \
    count_min_revised_fuel_consumption


class TheTreacheryOfWhalesTestCase(unittest.TestCase):
    def test_minimal_movement(self):
        crabs = [16, 1, 2, 0, 4, 2, 7, 1, 2, 14]
        fuel = count_min_fuel_for_crab_moving(crabs)
        self.assertEqual(37, fuel)

    def test_revised_minimal_fuel_consumption(self):
        crabs = [16, 1, 2, 0, 4, 2, 7, 1, 2, 14]
        fuel = count_min_revised_fuel_consumption(crabs)
        self.assertEqual(168, fuel)


if __name__ == '__main__':
    unittest.main()
