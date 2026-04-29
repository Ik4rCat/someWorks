// Задание 4: Числа Фибоначчи в заданном диапазоне

public class Program
{
    public static void Main()
    {
        while (true)
        {
            Console.Write("Введите нижнюю границу: ");
            if (!int.TryParse(Console.ReadLine(), out int min))
            {
                Console.WriteLine("Ошибка: введите целое число.\n");
                continue;
            }

            Console.Write("Введите верхнюю границу: ");
            if (!int.TryParse(Console.ReadLine(), out int max))
            {
                Console.WriteLine("Ошибка: введите целое число.\n");
                continue;
            }

            if (min > max)
            {
                Console.WriteLine("Ошибка: нижняя граница не может быть больше верхней.\n");
                continue;
            }

            var result = new List<int>();
            int a = 0, b = 1;

            while (a <= max)
            {
                if (a >= min)
                    result.Add(a);
                int next = a + b;
                a = b;
                b = next;
            }

            if (result.Count == 0)
                Console.WriteLine("В данном диапазоне нет чисел Фибоначчи.");
            else
                Console.WriteLine(string.Join(", ", result));

            Console.WriteLine();
        }
    }
}
