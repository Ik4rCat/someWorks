import pytest


def division(a, b):
    return a / b


# --- Позитивные тесты ---

def test_positive_integers():
    assert division(10, 2) == 5.0

def test_positive_floats():
    assert division(7.5, 2.5) == 3.0

def test_negative_dividend():
    assert division(-10, 2) == -5.0

def test_negative_divisor():
    assert division(10, -2) == -5.0

def test_both_negative():
    assert division(-6, -3) == 2.0

def test_fractional_result():
    assert division(1, 3) == pytest.approx(0.333, rel=1e-2)

def test_zero_dividend():
    assert division(0, 5) == 0.0


# --- Негативные тесты ---

def test_division_by_zero():
    with pytest.raises(ZeroDivisionError):
        division(10, 0)

def test_division_by_zero_float():
    with pytest.raises(ZeroDivisionError):
        division(5.5, 0)

def test_division_by_zero_negative():
    with pytest.raises(ZeroDivisionError):
        division(-3, 0)
