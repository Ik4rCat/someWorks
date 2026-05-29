// lab8_1.cpp — исправленная версия BankAccount + SavingsAccount

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <stdexcept>

// ─── Logger ────────────────────────────────────────────────────────────────

class Logger {
public:
    void log(const std::string& msg) {
        std::cout << "[LOG] " << msg << std::endl;
    }
};

// ─── Вспомогательная функция форматирования ────────────────────────────────

static std::string formatAmount(double amount) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << amount;
    return oss.str();
}

// ─── BankAccount (исправленная версия) ────────────────────────────────────

class BankAccount {
private:                                         // исправление #1 — private поля
    std::string owner;
    double balance;
    std::vector<std::string> history;
    Logger& logger;                              // исправление #2 — dependency injection

public:
    BankAccount(const std::string& owner, double initial, Logger& logger)
        : owner(owner), balance(initial), logger(logger)
    {
        if (initial < 0) throw std::invalid_argument("Initial balance cannot be negative");
        history.push_back("Created with " + formatAmount(initial));
    }

    // Геттеры
    double getBalance() const { return balance; }
    const std::string& getOwner() const { return owner; }

    virtual void deposit(double amount) {
        if (amount <= 0) {
            logger.log("Invalid deposit amount: " + formatAmount(amount));
            return;
        }
        balance += amount;
        history.push_back("Deposit: " + formatAmount(amount));
    }

    virtual void withdraw(double amount) {
        if (amount <= 0) {                       // исправление #3 — проверка <= 0
            logger.log("Invalid withdraw amount: " + formatAmount(amount));
            return;
        }
        if (amount > balance) {
            logger.log("Insufficient funds");
            return;
        }
        balance -= amount;
        history.push_back("Withdraw: " + formatAmount(amount));
    }

    void printStatement(std::ostream& out = std::cout) const {   // исправление #6
        out << "Account: " << owner
            << "\nBalance: " << formatAmount(balance) << "\n";
        for (const auto& entry : history) {
            out << " - " << entry << "\n";
        }
    }

    // исправление #4 — transfer использует методы класса
    static void transfer(BankAccount& from, BankAccount& to, double amount) {
        if (amount <= 0) return;
        from.withdraw(amount);
        to.deposit(amount);
    }

    virtual ~BankAccount() = default;
};

// ─── SavingsAccount (доп. задание) ────────────────────────────────────────

class SavingsAccount : public BankAccount {
private:
    double minBalance;    // минимальный остаток
    double interestRate;  // процентная ставка (0.05 = 5%)
    Logger& logger;

public:
    SavingsAccount(const std::string& owner,
                   double initial,
                   Logger& logger,
                   double minBalance = 500.0,
                   double interestRate = 0.05)
        : BankAccount(owner, initial, logger),
          minBalance(minBalance),
          interestRate(interestRate),
          logger(logger)
    {
        if (initial < minBalance) {
            throw std::invalid_argument(
                "Initial balance " + formatAmount(initial) +
                " is below minimum " + formatAmount(minBalance)
            );
        }
    }

    // Переопределяем withdraw — нельзя опуститься ниже minBalance
    void withdraw(double amount) override {
        if (amount <= 0) {
            logger.log("Invalid withdraw amount");
            return;
        }
        if (getBalance() - amount < minBalance) {
            logger.log("Cannot withdraw " + formatAmount(amount) +
                       ": would go below minimum balance of " + formatAmount(minBalance));
            return;
        }
        BankAccount::withdraw(amount);  // вызываем родительский метод
    }

    // Начисление процентов
    void applyInterest() {
        double interest = getBalance() * interestRate;
        deposit(interest);  // используем метод, чтобы запись попала в историю
    }

    double getMinBalance() const { return minBalance; }
    double getInterestRate() const { return interestRate; }
};

// ─── main ──────────────────────────────────────────────────────────────────

int main() {
    Logger logger;

    BankAccount alice("Alice", 1000, logger);
    BankAccount bob("Bob", 500, logger);

    alice.withdraw(200);
    alice.deposit(50);
    BankAccount::transfer(alice, bob, 300);

    alice.printStatement();
    std::cout << "\n";
    bob.printStatement();

    std::cout << "\n=== SavingsAccount ===\n";

    SavingsAccount savings("Carol", 1000, logger, 500, 0.1);
    savings.deposit(200);
    savings.withdraw(800);   // OK: 1200 - 800 = 400 < 500 -> заблокировано
    savings.withdraw(600);   // OK: 1200 - 600 = 600 >= 500 -> разрешено
    savings.applyInterest(); // начислить 10% на остаток

    std::cout << "\n";
    savings.printStatement();

    return 0;
}
