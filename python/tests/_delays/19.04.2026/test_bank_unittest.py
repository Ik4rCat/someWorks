# test_bank_unittest.py — те же тесты через unittest
# Демонстрация: TestCase, setUp, assertRaises, assertEqual

import unittest
from bank import BankAccount


class TestBankAccountCreation(unittest.TestCase):

    def test_default_balance(self):
        acc = BankAccount("Alice")
        self.assertEqual(acc.balance, 0.0)

    def test_initial_balance(self):
        acc = BankAccount("Bob", 500.0)
        self.assertEqual(acc.balance, 500.0)

    def test_negative_balance_raises(self):
        with self.assertRaises(ValueError):
            BankAccount("Charlie", -100.0)

    def test_owner(self):
        acc = BankAccount("Dave")
        self.assertEqual(acc.owner, "Dave")


class TestDeposit(unittest.TestCase):

    def setUp(self):
        """Вызывается перед каждым тестом."""
        self.acc = BankAccount("Alice")

    def tearDown(self):
        """Вызывается после каждого теста."""
        del self.acc

    def test_deposit_increases_balance(self):
        self.acc.deposit(100.0)
        self.assertEqual(self.acc.balance, 100.0)

    def test_deposit_returns_new_balance(self):
        result = self.acc.deposit(250.0)
        self.assertEqual(result, 250.0)

    def test_deposit_zero_raises(self):
        with self.assertRaises(ValueError):
            self.acc.deposit(0)

    def test_deposit_negative_raises(self):
        with self.assertRaises(ValueError):
            self.acc.deposit(-50)

    def test_multiple_deposits(self):
        self.acc.deposit(100.0)
        self.acc.deposit(200.0)
        self.assertAlmostEqual(self.acc.balance, 300.0)


class TestWithdraw(unittest.TestCase):

    def setUp(self):
        self.acc = BankAccount("Bob", 1000.0)

    def test_withdraw_decreases_balance(self):
        self.acc.withdraw(200.0)
        self.assertEqual(self.acc.balance, 800.0)

    def test_withdraw_full_balance(self):
        self.acc.withdraw(1000.0)
        self.assertEqual(self.acc.balance, 0.0)

    def test_withdraw_insufficient_funds(self):
        with self.assertRaises(ValueError) as ctx:
            self.acc.withdraw(1500.0)
        self.assertIn("Недостаточно средств", str(ctx.exception))

    def test_withdraw_zero_raises(self):
        with self.assertRaises(ValueError):
            self.acc.withdraw(0)

    def test_withdraw_negative_raises(self):
        with self.assertRaises(ValueError):
            self.acc.withdraw(-100)


class TestTransfer(unittest.TestCase):

    def setUp(self):
        self.sender   = BankAccount("Alice", 500.0)
        self.receiver = BankAccount("Bob",   100.0)

    def test_transfer_deducts_from_sender(self):
        self.sender.transfer(self.receiver, 200.0)
        self.assertAlmostEqual(self.sender.balance, 300.0)

    def test_transfer_adds_to_receiver(self):
        self.sender.transfer(self.receiver, 200.0)
        self.assertAlmostEqual(self.receiver.balance, 300.0)

    def test_transfer_insufficient_funds(self):
        with self.assertRaises(ValueError):
            self.sender.transfer(self.receiver, 9999.0)

    def test_receiver_unchanged_on_failed_transfer(self):
        try:
            self.sender.transfer(self.receiver, 9999.0)
        except ValueError:
            pass
        self.assertAlmostEqual(self.receiver.balance, 100.0)


class TestHistory(unittest.TestCase):

    def setUp(self):
        self.acc = BankAccount("Alice", 500.0)

    def test_deposit_recorded(self):
        self.acc.deposit(100.0)
        history = self.acc.get_history()
        self.assertEqual(len(history), 1)
        self.assertEqual(history[0], ("deposit", 100.0))

    def test_withdraw_recorded(self):
        self.acc.withdraw(50.0)
        history = self.acc.get_history()
        self.assertEqual(history[0], ("withdraw", 50.0))

    def test_history_is_copy(self):
        self.acc.deposit(100.0)
        h = self.acc.get_history()
        h.clear()
        self.assertEqual(len(self.acc.get_history()), 1)

    def test_empty_history(self):
        acc = BankAccount("New")
        self.assertEqual(acc.get_history(), [])


if __name__ == "__main__":
    unittest.main()
