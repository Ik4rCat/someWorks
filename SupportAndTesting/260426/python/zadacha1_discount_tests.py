import pytest


def calculate_discount(price, discount_percent):
    if price < 0:
        raise ValueError("Цена не может быть отрицательной")
    if not (0 <= discount_percent <= 100):
        raise ValueError("Скидка должна быть от 0 до 100")
    return price * (1 - discount_percent / 100)


# --- Чек-лист ---
# 1. Обычные значения (price > 0, discount от 0 до 100)     +
# 2. Скидка = 0% → цена не меняется                         +
# 3. Скидка = 100% → цена = 0                               +
# 4. Отрицательная цена → ValueError                        +
# 5. Скидка за пределами 0-100 → ValueError                 +
# 6. Дробная скидка (точность вычислений)                   +

# --- Параметризованные позитивные тесты ---

@pytest.mark.parametrize("price, discount, expected", [
    (100, 20, 80.0),
    (200, 50, 100.0),
    (150, 0, 150.0),     # скидка 0 — цена не меняется
    (99, 100, 0.0),      # скидка 100 — цена = 0
    (60, 10, 54.0),
    (1000, 33, 670.0),
])
def test_calculate_discount_valid(price, discount, expected):
    assert calculate_discount(price, discount) == pytest.approx(expected, rel=1e-6)


# --- Негативные тесты ---

def test_negative_price_raises():
    with pytest.raises(ValueError):
        calculate_discount(-50, 10)

def test_discount_above_100_raises():
    with pytest.raises(ValueError):
        calculate_discount(100, 110)

def test_discount_below_0_raises():
    with pytest.raises(ValueError):
        calculate_discount(100, -5)
