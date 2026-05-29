#pragma once  // исправление #8: вместо #ifndef guard

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <stdexcept>

// ─── Вспомогательная функция форматирования ───────────────────────────────
static std::string formatAmount(double amount) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << amount;
    return oss.str();
}

// ─── Logger ───────────────────────────────────────────────────────────────
class Logger {
public:
    void log(const std::string& msg) {
        std::cout << "[LOG] " << msg << std::endl;
    }
};

// ─── BankAccount (исправленная версия) ────────────────────────────────────
class BankAccount {
private:                                          // исправление #1: private поля
    std::string owner;
    double balance;
    std::vector<std::string> history;

protected:
    Logger& logger;                               // исправление #2: dependency injection

public:
    BankAccount(const std::string& owner, double initial, Logger& logger)
        : owner(owner), balance(initial), logger(logger)
    {
        history.push_back("Created with " + formatAmount(initial));
    }

    double getBalance() const { return balance; }
    const std::string& getOwner() const { return owner; }

    virtual void deposit(double amount) {
        if (amount <= 0) {
            logger.log("Invalid deposit amount");
            return;
        }
        balance += amount;
        history.push_back("Deposit: " + formatAmount(amount));  // исправление #5
    }

    virtual void withdraw(double amount) {
        if (amount <= 0) {                        // исправление #3: проверка <= 0
            logger.log("Invalid withdraw amount");
            return;
        }
        if (amount > balance) {
            logger.log("Insufficient funds");
            return;
        }
        balance -= amount;
        history.push_back("Withdraw: " + formatAmount(amount));
    }

    void printStatement(std::ostream& out = std::cout) const {  // исправление #6
        out << "Account: " << owner
            << "\nBalance: " << formatAmount(balance) << "\n";
        for (const auto& entry : history) {
            out << " - " << entry << "\n";
        }
    }

    // исправление #4: transfer использует методы, не лезет в поля напрямую
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
    double minBalance;
    double interestRate;

public:
    SavingsAccount(const std::string& owner,
                   double initial,
                   Logger& logger,
                   double minBalance = 500.0,
                   double interestRate = 0.05)
        : BankAccount(owner, initial, logger),
          minBalance(minBalance),
          interestRate(interestRate)
    {
        if (initial < minBalance)
            throw std::invalid_argument("Initial balance below minimum");
    }

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
        BankAccount::withdraw(amount);
    }

    void applyInterest() {
        double interest = getBalance() * interestRate;
        deposit(interest);
    }
};
