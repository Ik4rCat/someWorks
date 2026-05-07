// Задание 2: количество значений в массиве меньше заданного параметра

class Program
{
    static int[] nums = { 3, 7, 1, 9, 4, 2, 8, 5, 6, 10, 3, 7 };

    public static void Main()
    {
        Console.WriteLine($"Массив: [{string.Join(", ", nums)}]");
        Console.Write("Введите параметр: ");

        while (true)
        {
            if (!int.TryParse(Console.ReadLine(), out int param))
            {
                Console.Write("Ошибка. Повторите: ");
                continue;
            }

            int count = 0;
            foreach (int n in nums)
                if (n < param) count++;

            Console.WriteLine($"Количество значений меньше {param}: {count}");
            Console.Write("\nВведите параметр (или Ctrl+C для выхода): ");
        }
    }
}
