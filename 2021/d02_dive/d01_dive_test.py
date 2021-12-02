import unittest

from d02_dive.d01_dive import read_command, Submarine, execute_commands, AimingSubmarine


class DiveTestCase(unittest.TestCase):
    def test_read_command(self):
        testcases = [
            ("forward 5", ("forward", 5)),
            ("forward 10", ("forward", 10)),
            ("up 17", ("up", 17)),
            ("down 17", ("down", 17)),
        ]
        for text, expected_command in testcases:
            command = read_command(text)
            self.assertEqual(expected_command, command)

    def test_submarine(self):
        submarine = Submarine()
        self.assertEqual((0, 0), submarine.get_position())

        submarine.down(5)
        self.assertEqual((0, 5), submarine.get_position())

        submarine.up(3)
        self.assertEqual((0, 2), submarine.get_position())

        submarine.forward(5)
        self.assertEqual((5, 2), submarine.get_position())

    def test_execute_commands(self):
        lines = [
            "forward 5",
            "down 5",
            "forward 8",
            "up 3",
            "down 8",
            "forward 2"
        ]
        commands = [read_command(line) for line in lines]
        result = execute_commands(commands, Submarine())
        self.assertEqual((10, 15), result)

    def test_aiming_submarine(self):
        submarine = AimingSubmarine()
        self.assertEqual((0, 0), submarine.get_position())

        submarine.down(5)
        self.assertEqual((0, 0), submarine.get_position())

        submarine.up(3)
        self.assertEqual((0, 0), submarine.get_position())

        submarine.forward(5)
        self.assertEqual((5, 10), submarine.get_position())



if __name__ == '__main__':
    unittest.main()
