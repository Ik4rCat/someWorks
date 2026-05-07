// Задание 4: общие элементы двух массивов без повторений

class Program
{
    public static void Main()
    {
        int[] arrayA = { 1, 2, 3, 4, 5, 6, 2, 4 };
        int[] arrayB = { 3, 4, 5, 6, 7, 8, 5, 6 };

        var common = new HashSet<int>();

        foreach (int a in arrayA)
            foreach (int b in arrayB)
                if (a == b) common.Add(a);

        Console.WriteLine($"Массив A: [{string.Join(", ", arrayA)}]");
        Console.WriteLine($"Массив B: [{string.Join(", ", arrayB)}]");
        Console.WriteLine($"Общие элементы: [{string.Join(", ", common)}]");
    }
}
