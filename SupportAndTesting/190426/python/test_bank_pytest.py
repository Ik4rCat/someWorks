# test_bank_pytest.py — тесты через pytest
# Демонстрация: fixtures, parametrize, marks, raises

import pytest
from bank import BankAccount


# ──────────────────────────────────────────
#  Фикстуры
# ──────────────────────────────────────────

@pytest.fixture
def empty_account():
    """Счёт с нулевым балансом."""
    return BankAccount("Alice")


@pytest.fixture
def funded_account():
    """Счёт с балансом 1000."""
    return BankAccount("Bob", 1000.0)


@pytest.fixture
def two_accounts():
    """Два счёта для тестирования переводов."""
    sender = BankAccount("Alice", 500.0)
    receiver = BankAccount("Bob", 100.0)
    return sender, receiver


# ──────────────────────────────────────────
#  Создание счёта
# ──────────────────────────────────────────

def test_create_with_default_balance(empty_account):
    assert empty_account.balance == 0.0
    assert empty_account.owner == "Alice"


def test_create_with_initial_balance():
    acc = BankAccount("Charlie", 500.0)
    assert acc.balance == 500.0


def test_create_negative_balance_raises():
    with pytest.raises(ValueError, match="Начальный баланс"):
        BankAccount("Dave", -100.0)


# ──────────────────────────────────────────
#  Пополнение — параметризация
# ──────────────────────────────────────────

@pytest.mark.parametrize("amount, expected_balance", [
    (100.0,   100.0),
    (0.01,      0.01),
    (9999.99, 9999.99),
    (1000.0,  1000.0),
])
def test_deposit_valid(empty_account, amount, expected_balance):
    result = empty_account.deposit(amount)
    assert result == pytest.approx(expected_balance)
    assert empty_account.balance == pytest.approx(expected_balance)


@pytest.mark.parametrize("invalid_amount", [0, -1, -100, -0.01])
def test_deposit_invalid_raises(empty_account, invalid_amount):
    with pytest.raises(ValueError, match="положительной"):
        empty_account.deposit(invalid_amount)


# ──────────────────────────────────────────
#  Снятие — параметризация
# ──────────────────────────────────────────

@pytest.mark.parametrize("amount, expected_balance", [
    (100.0, 900.0),
    (500.0, 500.0),
    (1000.0, 0.0),
])
def test_withdraw_valid(funded_account, amount, expected_balance):
    result = funded_account.withdraw(amount)
    assert result == pytest.approx(expected_balance)


@pytest.mark.parametrize("invalid_amount", [0, -50, -0.01])
def test_withdraw_invalid_raises(funded_account, invalid_amount):
    with pytest.raises(ValueError, match="положительной"):
        funded_account.withdraw(invalid_amount)


def test_withdraw_insufficient_funds(funded_account):
    with pytest.raises(ValueError, match="Недостаточно средств"):
        funded_account.withdraw(1001.0)


# ──────────────────────────────────────────
#  Перевод
# ──────────────────────────────────────────

def test_transfer_success(two_accounts):
    sender, receiver = two_accounts
    sender.transfer(receiver, 200.0)
    assert sender.balance == pytest.approx(300.0)
    assert receiver.balance == pytest.approx(300.0)


def test_transfer_insufficient_funds(two_accounts):
    sender, receiver = two_accounts
    with pytest.raises(ValueError, match="Недостаточно средств"):
        sender.transfer(receiver, 9999.0)


def test_transfer_does_not_change_receiver_on_failure(two_accounts):
    sender, receiver = two_accounts
    try:
        sender.transfer(receiver, 9999.0)
    except ValueError:
        pass
    assert receiver.balance == pytest.approx(100.0)


# ──────────────────────────────────────────
#  История операций
# ──────────────────────────────────────────

def test_history_records_deposit(empty_account):
    empty_account.deposit(100.0)
    history = empty_account.get_history()
    assert len(history) == 1
    assert history[0] == ("deposit", 100.0)


def test_history_records_multiple_operations(funded_account):
    funded_account.deposit(200.0)
    funded_account.withdraw(50.0)
    history = funded_account.get_history()
    assert len(history) == 2
    assert history[0] == ("deposit", 200.0)
    assert history[1] == ("withdraw", 50.0)


def test_history_returns_copy(funded_account):
    funded_account.deposit(100.0)
    history = funded_account.get_history()
    history.clear()
    assert len(funded_account.get_history()) == 1


# ──────────────────────────────────────────
#  Марки
# ──────────────────────────────────────────

@pytest.mark.skip(reason="Функция ещё не реализована")
def test_interest_calculation():
    acc = BankAccount("Test", 1000.0)
    assert acc.apply_interest(0.05) == 1050.0


@pytest.mark.xfail(reason="Известный баг: перевод самому себе")
def test_self_transfer():
    acc = BankAccount("Alice", 500.0)
    acc.transfer(acc, 100.0)
    assert acc.balance == pytest.approx(500.0)


# ──────────────────────────────────────────
#  Класс тестов
# ──────────────────────────────────────────

class TestBankAccountRepr:
    def test_repr_contains_owner(self):
        acc = BankAccount("Alice", 100.0)
        assert "Alice" in repr(acc)

    def test_repr_contains_balance(self):
        acc = BankAccount("Alice", 100.0)
        assert "100.0" in repr(acc)
