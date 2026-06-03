"""
Часть 2 — Практическая часть Python
Написать функцию генерации списка квадратов чисел от 1 до N.
"""
import pytest


# ==============================
# РЕАЛИЗАЦИЯ
# ==============================

def generate_squares(n: int) -> list:
    """Возвращает список квадратов чисел от 1 до N включительно."""
    if n < 0:
        raise ValueError("N не может быть отрицательным")
    if n == 0:
        return []
    return [i * i for i in range(1, n + 1)]


# ==============================
# ЧЕК-ЛИСТ
# ==============================
# 1. N = 0 → пустой список                                  +
# 2. Отрицательные значения → ValueError                    +
# 3. Большие значения → корректность вычислений             +
# 4. Тип возвращаемого значения — list                      +
# 5. N = 1 → [1]                                           +
# 6. Обычное значение N = 5 → [1, 4, 9, 16, 25]            +


# ==============================
# ТЕСТ-КЕЙСЫ
# ==============================
# №  N    Ожидаемый                    Описание
# 1  5    [1, 4, 9, 16, 25]            стандартный случай
# 2  0    []                           N = 0
# 3  1    [1]                          минимальное N
# 4  -1   ValueError                   отрицательное
# 5  10   список из 10 элементов        большое N


# ==============================
# UNIT-ТЕСТЫ
# ==============================

@pytest.mark.parametrize("n, expected", [
    (5, [1, 4, 9, 16, 25]),
    (0, []),
    (1, [1]),
    (3, [1, 4, 9]),
    (10, [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]),
])
def test_generate_squares_parametrized(n, expected):
    assert generate_squares(n) == expected


def test_n_zero_returns_empty():
    assert generate_squares(0) == []


def test_negative_raises():
    with pytest.raises(ValueError):
        generate_squares(-1)


def test_return_type_is_list():
    result = generate_squares(5)
    assert isinstance(result, list)


def test_large_n():
    result = generate_squares(100)
    assert len(result) == 100
    assert result[-1] == 10000


def test_n_one():
    assert generate_squares(1) == [1]
