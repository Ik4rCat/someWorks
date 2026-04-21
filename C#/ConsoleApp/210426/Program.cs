namespace DefaultNamespace;

class Currency
{
    public string Code { get; }
    public string Symbol { get; }
    
    protected Currency(string code, string symbol)
    {
        Code = code;
        Symbol = symbol;
    }
    
    public abstract decimal ConvertTo(Currency targetCurrency, decimal amount, IExchangeRateProvider rateProvider);
    public override string ToString() => $"{Code} ({Symbol})";    
}

namespace DefaultNamespace;

public class Euro : Currency
{
    public Euro() : base("EUR", "€") { }
    public override decimal ConvertTo(Currency target, decimal amount, IExchangeRateProvider provider) => target is Euro ? amount : provider.GetRate(Code, target.Code) * amount;
}

public class Dollar : Currency
{
    public Dollar() : base("USD", "$") { }
    public override decimal ConvertTo(Currency target, decimal amount, IExchangeRateProvider provider) => target is Dollar ? amount : provider.GetRate(Code, target.Code) * amount;
}

public class Yuan : Currency  // Китайский юань (CNY)
{
    public Yuan() : base("CNY", "¥") { }
    public override decimal ConvertTo(Currency target, decimal amount, IExchangeRateProvider provider) => target is Yuan ? amount : provider.GetRate(Code, target.Code) * amount;
}

public class Ruble : Currency
{
    public Ruble() : base("RUB", "₽") { }
    public override decimal ConvertTo(Currency target, decimal amount, IExchangeRateProvider provider) => target is Ruble ? amount : provider.GetRate(Code, target.Code) * amount;
}


public class Program
{
    // $ euro UANI Руб конвертация реализация
    public static void Main()
    {
        var provider = new InMemoryExchangeRateProvider();
        
        var eur = new Euro();
        var usd = new Dollar();
        var cny = new Yuan();
        var rub = new Ruble();
        
        Console.WriteLine("=== Конвертация валют ===");
        
        // Конвертация 100 единиц каждой валюты
        ShowConversion(100m, eur, usd, provider);
        ShowConversion(100m, eur, cny, provider);
        ShowConversion(100m, eur, rub, provider);
        
        ShowConversion(100m, usd, eur, provider);
        ShowConversion(100m, usd, cny, provider);
        ShowConversion(100m, usd, rub, provider);
        
        ShowConversion(100m, cny, rub, provider);
        ShowConversion(100m, rub, usd, provider);
    }
    
    private static void ShowConversion(decimal amount, Currency from, Currency to, IExchangeRateProvider provider)
    {
        var result = from.ConvertTo(to, amount, provider);
        Console.WriteLine($"{amount:F2} {from.Symbol}{from.Code} = {result:F2} {to.Symbol}{to.Code}");
    }
}