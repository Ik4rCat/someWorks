class BankAccount:
    def __init__(self, account_number, balance):
        self.account_number = account_number
        self._balance = balance

    @property
    def balance(self):
        return self._balance

    @balance.setter
    def balance(self, value):
        if value >= 0:
            self._balance = value
        else:
            raise ValueError("Баланс не может быть отрицательным.")

    def deposit(self, amount):
        if amount > 0:
            self._balance += amount
        else:
            raise ValueError("Сумма пополнения должна быть положительной.")

    def withdraw(self, amount):
        if amount > 0 and amount <= self._balance:
            self._balance -= amount
        else:
            raise ValueError("Недостаточно средств или некорректная сумма.")

account = BankAccount("12345678", 1000)
account.deposit(500)
account.withdraw(200)
print(account.balance) 
