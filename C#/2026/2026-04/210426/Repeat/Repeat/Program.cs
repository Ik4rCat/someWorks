// Задание 5: вывести числа от A до B, каждое число повторяется столько раз, чему равно

public class Program
{
    public static void Main()
    {
        while (true)
        {
            Console.Write("Введите A: ");
            if (!int.TryParse(Console.ReadLine(), out int a) || a <= 0)
            {
                Console.WriteLine("Ошибка: введите целое положительное число.\n");
                continue;
            }

            Console.Write("Введите B: ");
            if (!int.TryParse(Console.ReadLine(), out int b) || b <= 0)
            {
                Console.WriteLine("Ошибка: введите целое положительное число.\n");
                continue;
            }

            if (a >= b)
            {
                Console.WriteLine("Ошибка: A должно быть меньше B.\n");
                continue;
            }

            Console.WriteLine();
            for (int i = a; i <= b; i++)
            {
                Console.WriteLine(string.Join(" ", Enumerable.Repeat(i, i)));
            }
            Console.WriteLine();
        }
    }
}
