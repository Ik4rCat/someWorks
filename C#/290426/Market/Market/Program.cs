
class Order
{
    
    public string Name { get; private set; }
    public int BasePrice { get; private set; }
    public int ItemPrice { get; private set;}
    public int ItemsCount { get; private set; }
    public Type OrderType { get; private set; }

    public Order(string name, int price, int itemsCount, Type orderType)
    {
        Name = name;
        BasePrice = price * itemsCount;
        ItemPrice = price;
        ItemsCount = itemsCount;
        OrderType = orderType;
    }

    // virtual methods - now commented, idk when i will make them
//    virtual decimal GetFinalPrice()
//    {
//        
//    }

//    virtual string GetStatus()
//    {
//        
//    }
    

    // discount methods
    void ApplyDiscount(int percent)
    {
        
    }
    
    void ApplyDiscount(int percent, bool loyalty)
    {
        
    }

    void ApplyDiscount(decimal fuxedAmount)
    {
        
    }

    // static void totals methods
    static void TotalOrders()
    {
        
    }

    static void TotalRevenue()
    {
        
    }
}

//class PhysicalOrder : Order
//{
    //public PhysicalOrder(string newName, int newPrice, ) : base(newName, )
//}

//class DigitalOrder : Order
//{
    
//}

//class GiftOrder : Order
//{
    
//}



class Program
{
    public static void Main()
    {
        Console.WriteLine("WIP - work in process [!]");
    }
}