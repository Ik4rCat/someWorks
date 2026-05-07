
class Bank
{
    private List<BankAccount> accounts = new List<BankAccount>();
    private int nextId = 1;

    public BankAccount CreateAccount(decimal initialBalance = 0)
    {
        var account = new BankAccount(nextId++, initialBalance);
        accounts.Add(account);
        Console.WriteLine($"Account #{account.Id} opened. Balance: {account.Balance:F2}");
        return account;
    }

    public BankAccount GetAccount(int id)
    {
        return accounts.Find(a => a.Id == id);
    }

    public void ShowAllAccounts()
    {
        if (accounts.Count == 0)
        {
            Console.WriteLine("No accounts found.");
            return;
        }
        Console.WriteLine("=== All Accounts ===");
        foreach (var acc in accounts)
            Console.WriteLine(acc);
    }
}

class BankAccount
{
    private decimal balance;
    private int id;
    private int counterOfGetOf;   // how many times money was withdrawn today
    private DateTime dateOfGetOf; // date of the last withdrawal

    private const int MaxWithdrawalsPerDay = 3;

    public BankAccount(int id, decimal initialBalance = 0)
    {
        this.id = id;
        this.balance = initialBalance;
        this.counterOfGetOf = 0;
        this.dateOfGetOf = DateTime.MinValue;
    }

    public decimal Balance => balance;

    public int Id => id;

    public int CounterOfGetOf => counterOfGetOf;

    public DateTime DateOfGetOf => dateOfGetOf;

    public void Deposit(decimal amount)
    {
        if (amount <= 0)
        {
            Console.WriteLine("Error: deposit amount must be positive.");
            return;
        }
        balance += amount;
        Console.WriteLine($"Account #{id}: deposited {amount:F2}. Balance: {balance:F2}");
    }

    public bool Withdraw(decimal amount)
    {
        if (amount <= 0)
        {
            Console.WriteLine("Error: withdrawal amount must be positive.");
            return false;
        }

        // Reset counter if the day has changed
        if (dateOfGetOf.Date != DateTime.Today)
        {
            counterOfGetOf = 0;
        }

        if (counterOfGetOf >= MaxWithdrawalsPerDay)
        {
            Console.WriteLine($"Error: daily withdrawal limit reached ({MaxWithdrawalsPerDay}).");
            return false;
        }

        if (amount > balance)
        {
            Console.WriteLine($"Error: insufficient funds. Balance: {balance:F2}");
            return false;
        }

        balance -= amount;
        counterOfGetOf++;
        dateOfGetOf = DateTime.Now;
        Console.WriteLine($"Account #{id}: withdrew {amount:F2}. Balance: {balance:F2} (withdrawals today: {counterOfGetOf}/{MaxWithdrawalsPerDay})");
        return true;
    }

    public override string ToString()
        => $"Account #{id} | Balance: {balance:F2} | Withdrawals today: {counterOfGetOf}/{MaxWithdrawalsPerDay}";
}

class Program
{
    static Bank bank = new Bank();

    public static void Main()
    {
        Console.WriteLine("=== Banking System ===\n");

        while (true)
        {
            Console.WriteLine("\n1. Open account");
            Console.WriteLine("2. Deposit");
            Console.WriteLine("3. Withdraw");
            Console.WriteLine("4. Show all accounts");
            Console.WriteLine("5. Exit");
            Console.Write("Choice: ");

            switch (Console.ReadLine()?.Trim())
            {
                case "1":
                    Console.Write("Initial balance: ");
                    if (decimal.TryParse(Console.ReadLine(), out decimal initBal) && initBal >= 0)
                        bank.CreateAccount(initBal);
                    else
                        Console.WriteLine("Invalid amount.");
                    break;

                case "2":
                    Console.Write("Account number: ");
                    if (int.TryParse(Console.ReadLine(), out int depId))
                    {
                        var acc = bank.GetAccount(depId);
                        if (acc == null) { Console.WriteLine("Account not found."); break; }
                        Console.Write("Deposit amount: ");
                        if (decimal.TryParse(Console.ReadLine(), out decimal depAmt))
                            acc.Deposit(depAmt);
                        else
                            Console.WriteLine("Invalid amount.");
                    }
                    break;

                case "3":
                    Console.Write("Account number: ");
                    if (int.TryParse(Console.ReadLine(), out int wdId))
                    {
                        var acc = bank.GetAccount(wdId);
                        if (acc == null) { Console.WriteLine("Account not found."); break; }
                        Console.Write("Withdrawal amount: ");
                        if (decimal.TryParse(Console.ReadLine(), out decimal wdAmt))
                            acc.Withdraw(wdAmt);
                        else
                            Console.WriteLine("Invalid amount.");
                    }
                    break;

                case "4":
                    bank.ShowAllAccounts();
                    break;

                case "5":
                    return;

                default:
                    Console.WriteLine("Invalid input.");
                    break;
            }
        }
    }
}
