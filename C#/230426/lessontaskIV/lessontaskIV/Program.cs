// Задание 9: подсчёт количества вхождений подстроки в строку

class Program
{
    static int CountOccurrences(string source, string substring)
    {
        if (string.IsNullOrEmpty(substring)) return 0;

        int count = 0;
        int index = 0;

        while ((index = source.IndexOf(substring, index, StringComparison.OrdinalIgnoreCase)) != -1)
        {
            count++;
            index += substring.Length;
        }

        return count;
    }

    public static void Main()
    {
        Console.Write("Введите строку: ");
        string source = Console.ReadLine();

        Console.Write("Введите подстроку для поиска: ");
        string sub = Console.ReadLine();

        if (string.IsNullOrEmpty(source) || string.IsNullOrEmpty(sub))
        {
            Console.WriteLine("Пустой ввод.");
            return;
        }

        int result = CountOccurrences(source, sub);
        Console.WriteLine($"Количество вхождений \"{sub}\": {result}");
    }
}
