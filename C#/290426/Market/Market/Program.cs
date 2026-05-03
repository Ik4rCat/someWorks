
class Order
{
    private static readonly List<Order> _trackedOrders = new();

    public static int TotalOrders => _trackedOrders.Count;
    public static decimal TotalRevenue => _trackedOrders.Sum(o => o.GetFinalPrice());

    public decimal BasePrice { get; protected set; }
    protected decimal _discountAmount = 0;

    protected Order(decimal basePrice, bool track = true)
    {
        BasePrice = basePrice;
        if (track) _trackedOrders.Add(this);
    }

    public virtual decimal GetFinalPrice() => System.Math.Max(0, BasePrice - _discountAmount);

    public virtual string GetStatus() =>
        $"{GetType().Name} | Base: {BasePrice} | Final: {GetFinalPrice()}";

    public void ApplyDiscount(int percent)
    {
        if (percent < 0 || percent > 100) return;
        _discountAmount = BasePrice * percent / 100m;
    }

    public void ApplyDiscount(int percent, bool loyalty)
    {
        int effective = loyalty ? System.Math.Min(percent + 5, 100) : percent;
        ApplyDiscount(effective);
    }

    public void ApplyDiscount(decimal fixedAmount)
    {
        _discountAmount = System.Math.Max(0, fixedAmount);
    }

    public static Order operator +(Order a, Order b) =>
        new Order(a.GetFinalPrice() + b.GetFinalPrice(), track: false);
}

class PhysicalOrder : Order
{
    private const decimal DeliveryFee = 200;
    public decimal Weight { get; }

    public PhysicalOrder(decimal basePrice, decimal weight = 1) : base(basePrice)
    {
        Weight = weight;
    }

    // Discount depends on weight: heavier items get less discount
    public new void ApplyDiscount(int percent)
    {
        decimal effective = percent / (1 + Weight * 0.05m);
        _discountAmount = Math.Round(BasePrice * effective / 100m, 2);
    }

    public override decimal GetFinalPrice() =>
        System.Math.Max(0, BasePrice + DeliveryFee - _discountAmount);

    public override string GetStatus() =>
        $"PhysicalOrder | Base: {BasePrice} + Delivery: {DeliveryFee} | Final: {GetFinalPrice()}";
}

class DigitalOrder : Order
{
    public DigitalOrder(decimal basePrice) : base(basePrice) { }

    // No delivery; fixed discount (fixed amount)
    public new void ApplyDiscount(decimal fixedAmount)
    {
        _discountAmount = fixedAmount;
    }

    public override string GetStatus() =>
        $"DigitalOrder | Base: {BasePrice} | Final: {GetFinalPrice()}";
}

class GiftOrder : Order
{
    private const decimal PackagingFee = 100;

    public GiftOrder(decimal basePrice) : base(basePrice) { }

    // Increased discount: +10% bonus on top
    public new void ApplyDiscount(int percent)
    {
        int effective = System.Math.Min(percent + 10, 100);
        _discountAmount = (BasePrice + PackagingFee) * effective / 100m;
    }

    public override decimal GetFinalPrice() =>
        System.Math.Max(0, BasePrice + PackagingFee - _discountAmount);

    public override string GetStatus() =>
        $"GiftOrder | Base: {BasePrice} + Packaging: {PackagingFee} | Final: {GetFinalPrice()}";
}

class Program
{
    public static void Main()
    {
        // PhysicalOrder: 1000 base + 200 delivery = 1200
        // DigitalOrder:  90 base, no delivery = 90
        // GiftOrder:     1400 base + 100 packaging = 1500
        var physical = new PhysicalOrder(1000);
        var digital  = new DigitalOrder(90);
        var gift     = new GiftOrder(1400);

        Console.WriteLine($"Physical order final price: {physical.GetFinalPrice()}");
        Console.WriteLine($"Digital order final price: {digital.GetFinalPrice()}");
        Console.WriteLine($"Gift order final price: {gift.GetFinalPrice()}");
        Console.WriteLine();

        // Сложение заказов через + (до скидок)
        Order combined = physical + digital + gift;
        Console.WriteLine($"Combined order total: {combined.GetFinalPrice()}");
        Console.WriteLine();

        Console.WriteLine($"Total orders: {Order.TotalOrders}");
        Console.WriteLine($"Total revenue: {Order.TotalRevenue}");

        // Демонстрация ApplyDiscount через базовый тип и конкретные типы
        Console.WriteLine();
        physical.ApplyDiscount(10);             // зависит от веса
        digital.ApplyDiscount(5m);              // фиксированная сумма
        gift.ApplyDiscount(5, loyalty: true);   // увеличенная + loyalty

        Order[] allOrders = { physical, digital, gift };
        foreach (Order o in allOrders)          // GetFinalPrice() через базовый тип
            Console.WriteLine(o.GetStatus());
    }
}
