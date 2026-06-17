import unittest


def remove_duplicates(lst: list) -> list:
    seen = []
    for item in lst:
        if item not in seen:
            seen.append(item)
    return seen


class TestRemoveDuplicates(unittest.TestCase):

    def test_empty_list(self):
        self.assertEqual(remove_duplicates([]), [])

    def test_all_duplicates(self):
        self.assertEqual(remove_duplicates([1, 1, 1, 1]), [1])

    def test_no_duplicates(self):
        self.assertEqual(remove_duplicates([1, 2, 3]), [1, 2, 3])

    def test_mixed_types(self):
        result = remove_duplicates([1, "a", 1, "a", 2])
        self.assertEqual(result, [1, "a", 2])

    def test_strings(self):
        self.assertEqual(remove_duplicates(["a", "b", "a", "c"]), ["a", "b", "c"])

    def test_multiple_same_chars(self):
        self.assertEqual(remove_duplicates(["x", "x", "x"]), ["x"])

    def test_preserves_order(self):
        self.assertEqual(remove_duplicates([3, 1, 2, 1, 3]), [3, 1, 2])

    def test_single_element(self):
        self.assertEqual(remove_duplicates([42]), [42])


if __name__ == "__main__":
    unittest.main(verbosity=2)
