Console.Write("Введите действительное число: ");
string? input = Console.ReadLine();

try
{
    double number = double.Parse(input ?? "");

    if (number < 0)
        throw new ArgumentException("Нельзя вычислить квадратный корень из отрицательного числа.");

    Console.WriteLine($"Квадратный корень из {number} = {Math.Sqrt(number)}");
}
catch (FormatException)
{
    Console.WriteLine("Ошибка: введён недопустимый символ, ожидалось число.");
}
catch (ArgumentException ex)
{
    Console.WriteLine($"Ошибка: {ex.Message}");
}
