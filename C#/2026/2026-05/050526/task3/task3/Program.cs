int? previous = null;

while (true)
{
    Console.Write("Введите число (0–255): ");
    string? input = Console.ReadLine();

    if (!int.TryParse(input, out int number) || number < 0 || number > 255)
    {
        Console.WriteLine("Ошибка: число должно быть в диапазоне от 0 до 255.");
        break;
    }

    if (previous.HasValue && Math.Abs(number - previous.Value) < 7)
    {
        Console.WriteLine($"Ошибка: разница между {previous.Value} и {number} меньше 7.");
        break;
    }

    previous = number;
    Console.WriteLine($"Принято: {number}");
}