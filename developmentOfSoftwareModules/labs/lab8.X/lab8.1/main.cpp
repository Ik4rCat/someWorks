#include "bank_account.h"

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
    savings.withdraw(800);   // заблокировано: 1200 - 800 = 400 < 500
    savings.withdraw(600);   // OK: 1200 - 600 = 600 >= 500
    savings.applyInterest(); // начислить 10% на остаток (600 * 0.1 = 60)

    std::cout << "\n";
    savings.printStatement();

    return 0;
}
