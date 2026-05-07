// Задание 1: количество чётных, нечётных, уникальных элементов массива

class Program
{
    static int[] nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 2, 4, 7 };

    public static void Main()
    {
        int evenCount = 0, oddCount = 0;
        var unique = new HashSet<int>();

        foreach (int n in nums)
        {
            if (n % 2 == 0) evenCount++;
            else oddCount++;
            unique.Add(n);
        }

        Console.WriteLine($"Массив: [{string.Join(", ", nums)}]");
        Console.WriteLine($"Чётных: {evenCount}");
        Console.WriteLine($"Нечётных: {oddCount}");
        Console.WriteLine($"Уникальных: {unique.Count}");
    }
}
