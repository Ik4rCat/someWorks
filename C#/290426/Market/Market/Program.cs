
class Order
{
    private static List<Order> _orders = new();

    public string Name { get; private set; }
    public int BasePrice { get; private set; }
    public int ItemPrice { get; private set; }
    public int ItemsCount { get; private set; }
    public Type OrderType { get; private set; }
    public decimal FinalPrice { get; private set; }

    public Order(string name, int price, int itemsCount, Type orderType)
    {
        Name = name;
        BasePrice = price * itemsCount;
        ItemPrice = price;
        ItemsCount = itemsCount;
        OrderType = orderType;
        FinalPrice = BasePrice;
        _orders.Add(this);
    }

    public virtual decimal GetFinalPrice() => FinalPrice;

    public virtual string GetStatus() =>
        $"[{OrderType.Name}] {Name} | {ItemsCount}x{ItemPrice} = {BasePrice} | Final: {FinalPrice:F2}";

    // discount by percent
    public void ApplyDiscount(int percent)
    {
        if (percent < 0 || percent > 100) return;
        FinalPrice = BasePrice * (1 - percent / 100m);
    }

    // discount by percent with loyalty bonus (+5%)
    public void ApplyDiscount(int percent, bool loyalty)
    {
        int effective = loyalty ? Math.Min(percent + 5, 100) : percent;
        ApplyDiscount(effective);
    }

    // discount by fixed amount
    public void ApplyDiscount(decimal fixedAmount)
    {
        FinalPrice = Math.Max(0, FinalPrice - fixedAmount);
    }

    public static void TotalOrders() =>
        Console.WriteLine($"Total orders: {_orders.Count}");

    public static void TotalRevenue() =>
        Console.WriteLine($"Total revenue: {_orders.Sum(o => o.FinalPrice):F2}");
}

class PhysicalOrder : Order
{
    public PhysicalOrder(string newName, int newPrice, int itemCounts) : base(newName, newPrice, itemCounts,
        typeof(PhysicalOrder)) {}
}

class DigitalOrder : Order
{
    public DigitalOrder(string newName, int newPrice, int itemCounts) : base(newName, newPrice, itemCounts,
        typeof(DigitalOrder)) {}
}

class GiftOrder : Order
{
    public GiftOrder(string newName, int newPrice, int itemCounts) : base(newName, newPrice, itemCounts,
        typeof(GiftOrder)) {}
}



class Program
{
    public static void Main()
    {
        var physical = new PhysicalOrder("Laptop", 1000, 2);
        var digital = new DigitalOrder("Game", 60, 3);
        var gift = new GiftOrder("Book", 25, 5);

        Console.WriteLine("=== Orders ===");
        Console.WriteLine(physical.GetStatus());
        Console.WriteLine(digital.GetStatus());
        Console.WriteLine(gift.GetStatus());

        Console.WriteLine("\n=== Applying Discounts ===");
        physical.ApplyDiscount(10);                 // -10%
        digital.ApplyDiscount(20, loyalty: true);   // -25% (20+5 loyalty)
        gift.ApplyDiscount(30m);                    // -30 fixed

        Console.WriteLine(physical.GetStatus());
        Console.WriteLine(digital.GetStatus());
        Console.WriteLine(gift.GetStatus());

        Console.WriteLine("\n=== Summary ===");
        Order.TotalOrders();
        Order.TotalRevenue();
    }
}