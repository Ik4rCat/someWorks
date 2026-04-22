import pytest
from utils import division


def test_division_good():
    assert division(10, 2) == 5


@pytest.mark.parametrize("a, b, expected_result", [
    (10, 2, 5),
    (20, 10, 2),
    (30, -3, -10),
    (5, 2, 2.5)
])
def test_division_params(a, b, expected_result):
    assert division(a, b) == expected_result

def test_zero_division():
    with pytest.raises(ZeroDivisionError):
        division(10, 0)

@pytest.mark.parametrize("expected_exception, divisionable, divider", [
    (ZeroDivisionError, 10, 0),
    (TypeError, 20, "2")
])
def test_division_with_errors(expected_exception, divisionable, divider):
    with pytest.raises(expected_exception):
        division(divisionable, divider)