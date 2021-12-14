import unittest

import d13_transparent_origami as d13


class TransparentOrigamiTestCase(unittest.TestCase):
    def setUp(self):
        self.maxDiff = None

    def test_horizontal_folding_a_paper(self):
        dots = [
            (6, 10),
            (0, 14),
            (9, 10),
            (0, 3),
            (10, 4),
            (4, 11),
            (6, 0),
            (6, 12),
            (4, 1),
            (0, 13),
            (10, 12),
            (3, 4),
            (3, 0),
            (8, 4),
            (1, 10),
            (2, 14),
            (8, 10),
            (9, 0)
        ]
        paper = d13.TransparentPaper(dots)
        paper.fold_horizontally(7)
        expected_paper = [
            ["#", ".", "#", "#", ".", ".", "#", ".", ".", "#", "."],
            ["#", ".", ".", ".", "#", ".", ".", ".", ".", ".", "."],
            [".", ".", ".", ".", ".", ".", "#", ".", ".", ".", "#"],
            ["#", ".", ".", ".", "#", ".", ".", ".", ".", ".", "."],
            [".", "#", ".", "#", ".", ".", "#", ".", "#", "#", "#"],
            [".", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."],
            [".", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."]
        ]
        self.assertListEqual(expected_paper, paper._paper)

    def test_vertical_folding_a_paper(self):
        dots = [
            (0, 0),
            (2, 0),
            (3, 0),
            (6, 0),
            (9, 0),
            (0, 1),
            (4, 1),
            (6, 2),
            (10, 2),
            (0, 3),
            (4, 3),
            (1, 4),
            (3, 4),
            (6, 4),
            (8, 4),
            (9, 4),
            (10, 4)
        ]
        paper = d13.TransparentPaper(dots)
        paper.fold_vertically(5)
        expected_paper = [
            ["#", "#", "#", "#", "#"],
            ["#", ".", ".", ".", "#"],
            ["#", ".", ".", ".", "#"],
            ["#", ".", ".", ".", "#"],
            ["#", "#", "#", "#", "#"]
        ]
        self.assertListEqual(expected_paper, paper._paper)

    def test_total_folding_a_paper(self):
        dots = [
            (6, 10),
            (0, 14),
            (9, 10),
            (0, 3),
            (10, 4),
            (4, 11),
            (6, 0),
            (6, 12),
            (4, 1),
            (0, 13),
            (10, 12),
            (3, 4),
            (3, 0),
            (8, 4),
            (1, 10),
            (2, 14),
            (8, 10),
            (9, 0)
        ]
        paper = d13.TransparentPaper(dots)
        paper.fold_horizontally(7)
        expected_paper = [
            ["#", ".", "#", "#", ".", ".", "#", ".", ".", "#", "."],
            ["#", ".", ".", ".", "#", ".", ".", ".", ".", ".", "."],
            [".", ".", ".", ".", ".", ".", "#", ".", ".", ".", "#"],
            ["#", ".", ".", ".", "#", ".", ".", ".", ".", ".", "."],
            [".", "#", ".", "#", ".", ".", "#", ".", "#", "#", "#"],
            [".", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."],
            [".", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."]
        ]
        self.assertListEqual(expected_paper, paper._paper)
        self.assertEqual(17, paper.get_number_of_visible_dots())
        paper.fold_vertically(5)
        expected_paper = [
            ["#", "#", "#", "#", "#"],
            ["#", ".", ".", ".", "#"],
            ["#", ".", ".", ".", "#"],
            ["#", ".", ".", ".", "#"],
            ["#", "#", "#", "#", "#"],
            [".", ".", ".", ".", "."],
            [".", ".", ".", ".", "."]
        ]
        self.assertListEqual(expected_paper, paper._paper)
        self.assertEqual(16, paper.get_number_of_visible_dots())
        paper.fold_vertically(2)
        expected_paper = [
            ["#", "#"],
            ["#", "."],
            ["#", "."],
            ["#", "."],
            ["#", "#"],
            [".", "."],
            [".", "."]
        ]
        self.assertListEqual(expected_paper, paper._paper)
        self.assertEqual(7, paper.get_number_of_visible_dots())

    def test_vertical_folding_a_paper_with_even_number_of_columns(self):
        dots = [
            (0, 0),
            (2, 0),
            (3, 0),
            (6, 0),
            (9, 0),
            (0, 1),
            (4, 1),
            (6, 2),
            (10, 2),
            (0, 3),
            (4, 3),
            (1, 4),
            (3, 4),
            (6, 4),
            (8, 4),
            (9, 4),
            (10, 4),
            (11, 0)
        ]
        paper = d13.TransparentPaper(dots)
        paper.fold_vertically(5)
        expected_paper = [
            ["#", "#", "#", "#", "#", "#"],
            [".", "#", ".", ".", ".", "#"],
            [".", "#", ".", ".", ".", "#"],
            [".", "#", ".", ".", ".", "#"],
            [".", "#", "#", "#", "#", "#"]
        ]
        self.assertListEqual(expected_paper, paper._paper)

    def test_vertical_folding_a_paper_with_even_number_of_columns_2(self):
        dots = [
            (1, 0),
            (3, 0),
            (4, 0),
            (7, 0),
            (10, 0),
            (1, 1),
            (5, 1),
            (7, 2),
            (11, 2),
            (1, 3),
            (5, 3),
            (2, 4),
            (4, 4),
            (7, 4),
            (9, 4),
            (10, 4),
            (11, 4),
            (0, 0)
        ]
        paper = d13.TransparentPaper(dots)
        paper.fold_vertically(6)
        expected_paper = [
            ["#", "#", "#", "#", "#", "#"],
            [".", "#", ".", ".", ".", "#"],
            [".", "#", ".", ".", ".", "#"],
            [".", "#", ".", ".", ".", "#"],
            [".", "#", "#", "#", "#", "#"]
        ]
        self.assertListEqual(expected_paper, paper._paper)

    def test_horizontal_folding_a_paper_with_even_rows_extra_at_the_end(self):
        dots = [
            (6, 10),
            (0, 14),
            (9, 10),
            (0, 3),
            (10, 4),
            (4, 11),
            (6, 0),
            (6, 12),
            (4, 1),
            (0, 13),
            (10, 12),
            (3, 4),
            (3, 0),
            (8, 4),
            (1, 10),
            (2, 14),
            (8, 10),
            (9, 0),
            (0, 15)
        ]
        paper = d13.TransparentPaper(dots)
        paper.fold_horizontally(7)
        expected_paper = [
            ["#", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."],
            ["#", ".", "#", "#", ".", ".", "#", ".", ".", "#", "."],
            ["#", ".", ".", ".", "#", ".", ".", ".", ".", ".", "."],
            [".", ".", ".", ".", ".", ".", "#", ".", ".", ".", "#"],
            ["#", ".", ".", ".", "#", ".", ".", ".", ".", ".", "."],
            [".", "#", ".", "#", ".", ".", "#", ".", "#", "#", "#"],
            [".", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."],
            [".", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."]
        ]
        self.assertListEqual(expected_paper, paper._paper)

    def test_horizontal_folding_a_paper_with_even_rows_extra_at_the_begin(self):
        dots = [
            (6, 11),
            (0, 15),
            (9, 11),
            (0, 4),
            (10, 5),
            (4, 12),
            (6, 1),
            (6, 13),
            (4, 2),
            (0, 14),
            (10, 13),
            (3, 5),
            (3, 1),
            (8, 5),
            (1, 11),
            (2, 15),
            (8, 11),
            (9, 1),
            (0, 0)
        ]
        paper = d13.TransparentPaper(dots)
        paper.fold_horizontally(8)
        expected_paper = [
            ["#", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."],
            ["#", ".", "#", "#", ".", ".", "#", ".", ".", "#", "."],
            ["#", ".", ".", ".", "#", ".", ".", ".", ".", ".", "."],
            [".", ".", ".", ".", ".", ".", "#", ".", ".", ".", "#"],
            ["#", ".", ".", ".", "#", ".", ".", ".", ".", ".", "."],
            [".", "#", ".", "#", ".", ".", "#", ".", "#", "#", "#"],
            [".", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."],
            [".", ".", ".", ".", ".", ".", ".", ".", ".", ".", "."]
        ]
        self.assertListEqual(expected_paper, paper._paper)


if __name__ == '__main__':
    unittest.main()
