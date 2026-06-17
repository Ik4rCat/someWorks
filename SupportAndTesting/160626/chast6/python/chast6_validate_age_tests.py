import unittest


def validate_age(age) -> bool:
    if not isinstance(age, int) or isinstance(age, bool):
        return False
    return 18 <= age <= 100


class TestValidateAge(unittest.TestCase):

    def test_below_minimum(self):
        self.assertFalse(validate_age(17))

    def test_minimum_valid(self):
        self.assertTrue(validate_age(18))

    def test_maximum_valid(self):
        self.assertTrue(validate_age(100))

    def test_above_maximum(self):
        self.assertFalse(validate_age(101))

    def test_negative_value(self):
        self.assertFalse(validate_age(-1))

    def test_zero(self):
        self.assertFalse(validate_age(0))

    def test_float_value(self):
        self.assertFalse(validate_age(25.5))

    def test_string_value(self):
        self.assertFalse(validate_age("25"))

    def test_none_value(self):
        self.assertFalse(validate_age(None))

    def test_normal_age(self):
        self.assertTrue(validate_age(30))


if __name__ == "__main__":
    unittest.main(verbosity=2)
