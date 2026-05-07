// Задание 8: подсчёт гласных букв в предложении

class Program
{
    static readonly HashSet<char> Vowels = new HashSet<char>("aeiouAEIOUаеёиоуыьъэюяАЕЁИОУЫЬЪЭЮЯ");

    public static void Main()
    {
        Console.Write("Введите предложение: ");
        string input = Console.ReadLine();

        if (string.IsNullOrWhiteSpace(input))
        {
            Console.WriteLine("Пустой ввод.");
            return;
        }

        int count = 0;
        foreach (char c in input)
            if (Vowels.Contains(c)) count++;

        Console.WriteLine($"Количество гласных: {count}");
    }
}
