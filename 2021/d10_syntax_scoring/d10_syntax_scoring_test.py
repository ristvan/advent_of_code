import unittest

import d10_syntax_scoring as d10


class SyntaxScoringTestCase(unittest.TestCase):
    def test_valid_chunks(self):
        valid_chunks = [
            "()",
            "[]",
            "([])",
            "{()()()}",
            "<([{}])>",
            "[<>({}){}[([])<>]]",
            "(((((((((())))))))))"
        ]
        for chunk in valid_chunks:
            is_valid, _, _ = d10.parse_chunk(chunk)
            self.assertTrue(is_valid)

    def test_invalid_chunks(self):
        invalid_chunks = [
            ("(]", "]"),
            ("[}", "}"),
            ("([]]", "]"),
            ("{()()()>", ">"),
            ("(((((((((()))))))))}", "}"),
            ("<([]){()}[{}])", ")")
        ]
        for chunk, expected_first_invalid_character in invalid_chunks:
            is_valid, first_invalid_character, _ = d10.parse_chunk(chunk)
            self.assertFalse(is_valid)
            self.assertEqual(expected_first_invalid_character, first_invalid_character)

    def test_with_example(self):
        chunks = [
            ("[({(<(())[]>[[{[]{<()<>>", True, ""),
            ("[(()[<>])]({[<{<<[]>>(", True, ""),
            ("{([(<{}[<>[]}>{[]{[(<()>", False, "}"),
            ("(((({<>}<{<{<>}{[]{[]{}", True, ""),
            ("[[<[([]))<([[{}[[()]]]", False, ")"),
            ("[{[{({}]{}}([{[{{{}}([]", False, "]"),
            ("{<[[]]>}<{[{[{[]{()[[[]", True, ""),
            ("[<(<(<(<{}))><([]([]()", False, ")"),
            ("<{([([[(<>()){}]>(<<{{", False, ">"),
            ("<{([{{}}[<[[[<>{}]]]>[]]", True, "")
        ]
        for chunk, expected_validity, expected_first_error in chunks:
            is_valid, first_invalid_character, _ = d10.parse_chunk(chunk)
            self.assertEqual(expected_validity, is_valid, chunk)
            self.assertEqual(expected_first_error, first_invalid_character, chunk)

    def test_count_completion_score(self):
        testcases = [
            ("[({<", 294),
            ("({<[{(", 5566),
            ("{{<{<((((", 1480781)
        ]
        for completion_string_of_chunk, expected_score in testcases:
            total_score = d10.calculate_completion_score(completion_string_of_chunk)
            self.assertEqual(expected_score, total_score)


if __name__ == '__main__':
    unittest.main()
