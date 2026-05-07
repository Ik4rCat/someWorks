
interface IPayment
{
    void ProcessPayment(decimal amount);
    string PaymentInfo { get; }
}

class PaymentMethod : IPayment
{
    protected string ownerName;

    public PaymentMethod(string ownerName)
    {
        this.ownerName = ownerName;
    }

    public virtual void ProcessPayment(decimal amount)
    {
        Console.WriteLine($"Payment of {amount:F2} from {ownerName}");
    }

    public virtual string PaymentInfo => $"Owner: {ownerName}";
}

class CardPayment : PaymentMethod
{
    private string cardNumber;
    private decimal dailyLimit;
    private decimal spentToday;

    public CardPayment(string ownerName, string cardNumber, decimal dailyLimit = 10000m)
        : base(ownerName)
    {
        this.cardNumber = cardNumber;
        this.dailyLimit = dailyLimit;
        this.spentToday = 0;
    }

    public override void ProcessPayment(decimal amount)
    {
        if (amount <= 0)
        {
            Console.WriteLine("Error: amount must be positive.");
            return;
        }
        if (spentToday + amount > dailyLimit)
        {
            Console.WriteLine($"Error: daily card limit exceeded. Available: {dailyLimit - spentToday:F2}");
            return;
        }
        spentToday += amount;
        // Show only last 4 digits of the card number
        string masked = "**** **** **** " + cardNumber[^4..];
        Console.WriteLine($"[Card] Paid {amount:F2} | Card: {masked} | Owner: {ownerName} | Spent today: {spentToday:F2}/{dailyLimit:F2}");
    }

    public override string PaymentInfo
        => $"Card: **** **** **** {cardNumber[^4..]} | Owner: {ownerName} | Daily limit: {dailyLimit:F2}";
}

class CashPayment : PaymentMethod
{
    private decimal cashOnHand;

    public CashPayment(string ownerName, decimal cashOnHand)
        : base(ownerName)
    {
        this.cashOnHand = cashOnHand;
    }

    public override void ProcessPayment(decimal amount)
    {
        if (amount <= 0)
        {
            Console.WriteLine("Error: amount must be positive.");
            return;
        }
        if (amount > cashOnHand)
        {
            Console.WriteLine($"Error: not enough cash. On hand: {cashOnHand:F2}");
            return;
        }
        cashOnHand -= amount;
        Console.WriteLine($"[Cash] Paid {amount:F2} | Owner: {ownerName} | Remaining cash: {cashOnHand:F2}");
    }

    public override string PaymentInfo
        => $"Cash | Owner: {ownerName} | On hand: {cashOnHand:F2}";
}

class Program
{
    static List<PaymentMethod> methods = new List<PaymentMethod>();

    static void Main()
    {
        Console.WriteLine("=== Payment System ===\n");

        while (true)
        {
            Console.WriteLine("\n1. Add payment method (card)");
            Console.WriteLine("2. Add payment method (cash)");
            Console.WriteLine("3. Make a payment");
            Console.WriteLine("4. Show payment methods");
            Console.WriteLine("5. Exit");
            Console.Write("Choice: ");

            switch (Console.ReadLine()?.Trim())
            {
                case "1":
                    Console.Write("Owner name: ");
                    string cardOwner = Console.ReadLine();
                    Console.Write("Card number (16 digits): ");
                    string cardNum = Console.ReadLine();
                    if (cardNum?.Length != 16)
                    {
                        Console.WriteLine("Invalid card number.");
                        break;
                    }
                    Console.Write("Daily limit (Enter = 10000): ");
                    string limitInput = Console.ReadLine();
                    decimal limit = string.IsNullOrWhiteSpace(limitInput) ? 10000m
                        : decimal.TryParse(limitInput, out decimal l) ? l : 10000m;
                    methods.Add(new CardPayment(cardOwner, cardNum, limit));
                    Console.WriteLine("Card added.");
                    break;

                case "2":
                    Console.Write("Owner name: ");
                    string cashOwner = Console.ReadLine();
                    Console.Write("Cash amount: ");
                    if (decimal.TryParse(Console.ReadLine(), out decimal cash) && cash >= 0)
                    {
                        methods.Add(new CashPayment(cashOwner, cash));
                        Console.WriteLine("Cash payment method added.");
                    }
                    else
                        Console.WriteLine("Invalid amount.");
                    break;

                case "3":
                    if (methods.Count == 0) { Console.WriteLine("No payment methods available."); break; }
                    for (int i = 0; i < methods.Count; i++)
                        Console.WriteLine($"{i + 1}. {methods[i].PaymentInfo}");
                    Console.Write("Select method (number): ");
                    if (int.TryParse(Console.ReadLine(), out int idx) && idx >= 1 && idx <= methods.Count)
                    {
                        Console.Write("Payment amount: ");
                        if (decimal.TryParse(Console.ReadLine(), out decimal amt))
                            methods[idx - 1].ProcessPayment(amt);
                        else
                            Console.WriteLine("Invalid amount.");
                    }
                    else
                        Console.WriteLine("Invalid selection.");
                    break;

                case "4":
                    if (methods.Count == 0) { Console.WriteLine("No payment methods."); break; }
                    Console.WriteLine("=== Payment Methods ===");
                    for (int i = 0; i < methods.Count; i++)
                        Console.WriteLine($"{i + 1}. {methods[i].PaymentInfo}");
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
