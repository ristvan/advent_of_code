import unittest

import d12_passage_pathing as d12


class PassagePathingTestCase(unittest.TestCase):
    def test_create_graph(self):
        caves = d12.UndirectedGraph()
        self.assertNotEqual(None, caves)

    def test_route_calculation_on_small_input(self):
        caves = d12.UndirectedGraph()
        edges = [
            ("start", "A"),
            ("start", "b"),
            ("A", "c"),
            ("A", "b"),
            ("b", "d"),
            ("A", "end"),
            ("b", "end")
        ]
        for start, end in edges:
            caves.add_edge(start, end)
        self.assertEqual(10, caves.get_number_of_paths("start"))

    def test_route_calculation_on_middle_input(self):
        caves = d12.UndirectedGraph()
        edges = [
            ("dc", "end"),
            ("HN", "start"),
            ("start", "kj"),
            ("dc", "start"),
            ("dc", "HN"),
            ("LN", "dc"),
            ("HN", "end"),
            ("kj", "sa"),
            ("kj", "HN"),
            ("kj", "dc")
        ]
        for start, end in edges:
            caves.add_edge(start, end)
        self.assertEqual(19, caves.get_number_of_paths("start"))

    def test_route_calculation_on_big_input(self):
        caves = d12.UndirectedGraph()
        edges = [
            ("fs", "end"),
            ("he", "DX"),
            ("fs", "he"),
            ("start", "DX"),
            ("pj", "DX"),
            ("end", "zg"),
            ("zg", "sl"),
            ("zg", "pj"),
            ("pj", "he"),
            ("RW", "he"),
            ("fs", "DX"),
            ("pj", "RW"),
            ("zg", "RW"),
            ("start", "pj"),
            ("he", "WI"),
            ("zg", "he"),
            ("pj", "fs"),
            ("start", "RW")
        ]
        for start, end in edges:
            caves.add_edge(start, end)
        self.assertEqual(226, caves.get_number_of_paths("start"))


if __name__ == '__main__':
    unittest.main()
