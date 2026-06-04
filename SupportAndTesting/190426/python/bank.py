# bank.py — модуль который будем тестировать

class BankAccount:
    """Банковский счёт."""

    def __init__(self, owner: str, balance: float = 0.0):
        if balance < 0:
            raise ValueError("Начальный баланс не может быть отрицательным")
        self.owner = owner
        self._balance = balance
        self._history = []

    @property
    def balance(self) -> float:
        return self._balance

    def deposit(self, amount: float) -> float:
        if amount <= 0:
            raise ValueError("Сумма пополнения должна быть положительной")
        self._balance += amount
        self._history.append(("deposit", amount))
        return self._balance

    def withdraw(self, amount: float) -> float:
        if amount <= 0:
            raise ValueError("Сумма снятия должна быть положительной")
        if amount > self._balance:
            raise ValueError("Недостаточно средств")
        self._balance -= amount
        self._history.append(("withdraw", amount))
        return self._balance

    def transfer(self, target: "BankAccount", amount: float) -> None:
        self.withdraw(amount)
        target.deposit(amount)

    def get_history(self) -> list:
        return self._history.copy()

    def __repr__(self):
        return f"BankAccount(owner={self.owner!r}, balance={self._balance})"
