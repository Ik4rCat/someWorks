from pathlib import Path
import sys

sys.path.append(str(Path(__file__).resolve().parents[1]))

from utils import division


def test_division_success():
    assert division(10, 2) == 5


def test_division_by_zero():
    try:
        division(10, 0)
        assert False, "Expected ValueError"
    except ValueError:
        assert True
