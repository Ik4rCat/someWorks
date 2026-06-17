import unittest
from collections import Counter


def char_count(s: str) -> dict:
    result = {}
    for c in s:
        result[c] = result.get(c, 0) + 1
    return result


class TestCharCount(unittest.TestCase):

    def test_empty_string(self):
        self.assertEqual(char_count(""), {})

    def test_only_digits(self):
        self.assertEqual(char_count("11223"), {"1": 2, "2": 2, "3": 1})

    def test_only_letters(self):
        self.assertEqual(char_count("aabbc"), {"a": 2, "b": 2, "c": 1})

    def test_mixed_string(self):
        result = char_count("a1b1c")
        self.assertEqual(result["1"], 2)
        self.assertEqual(result["a"], 1)
        self.assertEqual(result["b"], 1)
        self.assertEqual(result["c"], 1)

    def test_spaces(self):
        self.assertEqual(char_count("a b a"), {"a": 2, " ": 2, "b": 1})

    def test_single_char(self):
        self.assertEqual(char_count("x"), {"x": 1})

    def test_all_same(self):
        self.assertEqual(char_count("aaaa"), {"a": 4})

    def test_special_chars(self):
        result = char_count("!@!#")
        self.assertEqual(result["!"], 2)
        self.assertEqual(result["@"], 1)
        self.assertEqual(result["#"], 1)

    def test_result_matches_counter(self):
        s = "hello world"
        self.assertEqual(char_count(s), dict(Counter(s)))

    def test_unicode(self):
        result = char_count("привет")
        self.assertEqual(result["п"], 1)
        self.assertEqual(result["е"], 1)


if __name__ == "__main__":
    unittest.main(verbosity=2)
