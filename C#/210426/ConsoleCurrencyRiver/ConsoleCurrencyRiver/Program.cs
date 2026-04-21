using System;
using System.Collections.Generic;

public interface IExchangeRateProvider
{
    decimal GetRate(string from, string to);
    void RefreshRates();
}

public class Currency
{
    public string Code { get; }
    public string Symbol { get; }
    
    public Currency(string code, string symbol) => (Code, Symbol) = (code, symbol);
    
    public decimal ConvertTo(Currency target, decimal amount, IExchangeRateProvider provider)
        => Code == target.Code ? amount : provider.GetRate(Code, target.Code) * amount;
    
    public override string ToString() => $"{Symbol}{Code}";
    
    public static class Known
    {
        public static Currency EUR => new("EUR", "€");
        public static Currency USD => new("USD", "$");
        public static Currency CNY => new("CNY", "¥");
        public static Currency RUB => new("RUB", "₽");
    }
}

public class SimpleRateProvider : IExchangeRateProvider
{
    private readonly Dictionary<string, decimal> _r = new();
    
    public SimpleRateProvider()
    {
        var s = new Action<string, string, decimal>((f, t, v) => _r[$"{f}_{t}"] = v);
        s("USD", "EUR", 0.92m); s("USD", "CNY", 7.24m); s("USD", "RUB", 92.50m);
        s("EUR", "USD", 1.09m); s("EUR", "CNY", 7.89m); s("EUR", "RUB", 100.80m);
        s("CNY", "USD", 0.138m); s("CNY", "EUR", 0.127m); s("CNY", "RUB", 12.78m);
        s("RUB", "USD", 0.0108m); s("RUB", "EUR", 0.0099m); s("RUB", "CNY", 0.078m);
    }
    
    public decimal GetRate(string from, string to)
        => from == to ? 1m : _r.TryGetValue($"{from}_{to}", out var v) ? v : throw new Exception($"Курс {from}→{to} не найден");
    
    public void RefreshRates() => Console.WriteLine("Курсы обновлены");
}

public class SavingsAccount
{
    public Currency Currency { get; }
    public decimal Balance { get; private set; }
    public const decimal MonthlyInterest = 0.16m;
    
    public SavingsAccount(Currency currency, decimal initialDeposit = 0)
    {
        Currency = currency;
        Balance = initialDeposit;
    }
    
    public void Deposit(decimal amount)
    {
        if (amount <= 0) throw new ArgumentException("Сумма должна быть положительной");
        Balance += amount;
        Console.WriteLine($"Внесено {amount} {Currency}. Баланс: {Balance:F2} {Currency}");
    }
    
    public decimal CalculateInterest(int months)
        => Balance * ((decimal)Math.Pow((double)(1 + MonthlyInterest), months) - 1);
    
    public decimal GetBalanceAfter(int months)
        => Balance * (decimal)Math.Pow((double)(1 + MonthlyInterest), months);
    
    public void ShowProjection(int months)
    {
        Console.WriteLine($"\nПрогноз счёта {Currency} на {months} мес.:");
        Console.WriteLine($"Начальный баланс: {Balance:F2} {Currency}");
        Console.WriteLine($"Ставка: {MonthlyInterest * 100}% / мес. (сложный процент)");
        for (int m = 1; m <= months; m++)
        {
            var b = GetBalanceAfter(m);
            Console.WriteLine($"Месяц {m,2}: {b:F2} {Currency} (+{b - Balance:F2})");
        }
    }
    
    public override string ToString() => $"Счёт {Currency}: {Balance:F2}";
}

public class CurrencyApp
{
    private static readonly IExchangeRateProvider _provider = new SimpleRateProvider();
    private static readonly Currency _eur = Currency.Known.EUR;
    private static readonly Currency _usd = Currency.Known.USD;
    private static readonly Currency _cny = Currency.Known.CNY;
    private static readonly Currency _rub = Currency.Known.RUB;
    
    private static SavingsAccount _account;
    
    public static void Run()
    {
        Console.WriteLine("Конвертер валют + Накопительный счёт (16%/мес)\n");
        
        while (true)
        {
            Console.WriteLine("\n=== Меню ===");
            Console.WriteLine("1. Конвертация валют");
            Console.WriteLine("2. Открыть накопительный счёт");
            Console.WriteLine("3. Управление счётом");
            Console.WriteLine("4. Выход");
            Console.Write("Выбор: ");
            
            switch (Console.ReadLine()?.Trim())
            {
                case "1": ShowConverter(); break;
                case "2": CreateAccount(); break;
                case "3": ManageAccount(); break;
                case "4": return;
                default: Console.WriteLine("Неверный ввод"); break;
            }
        }
    }
    
    private static void ShowConverter()
    {
        Console.WriteLine("\nКонвертация (пример: 100 единиц):");
        var currencies = new[] { _eur, _usd, _cny, _rub };
        
        foreach (var from in currencies)
        {
            foreach (var to in currencies)
            {
                if (from.Code != to.Code)
                {
                    var result = from.ConvertTo(to, 100m, _provider);
                    Console.WriteLine($"100 {from} = {result:F2} {to}");
                }
            }
            break;
        }
        
        Console.Write("\nВведите сумму: ");
        if (!decimal.TryParse(Console.ReadLine(), out var amount) || amount <= 0)
        {
            Console.WriteLine("Некорректная сумма");
            return;
        }
        
        Console.Write("Из валюты (EUR/USD/CNY/RUB): ");
        var fromCode = Console.ReadLine()?.ToUpper();
        Console.Write("В валюту (EUR/USD/CNY/RUB): ");
        var toCode = Console.ReadLine()?.ToUpper();
        
        var fromCur = GetCurrency(fromCode);
        var toCur = GetCurrency(toCode);
        
        if (fromCur != null && toCur != null)
        {
            var result = fromCur.ConvertTo(toCur, amount, _provider);
            Console.WriteLine($"{amount:F2} {fromCur} = {result:F2} {toCur}");
        }
        else
        {
            Console.WriteLine("Неверный код валюты");
        }
    }
    
    private static void CreateAccount()
    {
        Console.WriteLine("\nОткрытие накопительного счёта");
        Console.WriteLine("Валюты: EUR, USD, CNY, RUB");
        Console.Write("Выберите валюту: ");
        var code = Console.ReadLine()?.ToUpper();
        var currency = GetCurrency(code);
        
        if (currency == null)
        {
            Console.WriteLine("Неверная валюта");
            return;
        }
        
        Console.Write("Начальный взнос (0 для пропуска): ");
        if (!decimal.TryParse(Console.ReadLine(), out var deposit) || deposit < 0)
        {
            Console.WriteLine("Некорректная сумма");
            return;
        }
        
        _account = new SavingsAccount(currency, deposit);
        Console.WriteLine($"Счёт открыт: {_account}");
    }
    
    private static void ManageAccount()
    {
        if (_account == null)
        {
            Console.WriteLine("Сначала откройте счёт (пункт 2)");
            return;
        }
        
        Console.WriteLine($"\n{_account}");
        Console.WriteLine("1. Внести средства");
        Console.WriteLine("2. Показать прогноз (1-12 мес.)");
        Console.WriteLine("3. Назад");
        Console.Write("Выбор: ");
        
        switch (Console.ReadLine()?.Trim())
        {
            case "1":
                Console.Write("Сумма: ");
                if (decimal.TryParse(Console.ReadLine(), out var sum) && sum > 0)
                    _account.Deposit(sum);
                else
                    Console.WriteLine("Некорректная сумма");
                break;
                
            case "2":
                Console.Write("Период в месяцах (1-12): ");
                if (int.TryParse(Console.ReadLine(), out var months) && months is >= 1 and <= 12)
                    _account.ShowProjection(months);
                else
                    Console.WriteLine("Введите число от 1 до 12");
                break;
        }
    }
    
    private static Currency GetCurrency(string code) => code switch
    {
        "EUR" => _eur,
        "USD" => _usd,
        "CNY" => _cny,
        "RUB" => _rub,
        _ => null
    };
}

public class Program
{
    public static void Main() => CurrencyApp.Run();
}