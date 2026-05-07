// Задание 6: вывод линии по заданным параметрам (длина, символ, направление)

public class Program
{
    public static void Main()
    {
        while (true)
        {
            Console.Write("Введите длину линии: ");
            if (!int.TryParse(Console.ReadLine(), out int length) || length <= 0)
            {
                Console.WriteLine("Ошибка: введите целое положительное число.\n");
                continue;
            }

            Console.Write("Введите символ заполнитель: ");
            string input = Console.ReadLine();
            if (string.IsNullOrEmpty(input) || input.Length != 1)
            {
                Console.WriteLine("Ошибка: введите ровно один символ.\n");
                continue;
            }
            char fillChar = input[0];

            Console.Write("Введите направление (h - горизонтальная, v - вертикальная): ");
            string direction = Console.ReadLine()?.Trim().ToLower();
            if (direction != "h" && direction != "v")
            {
                Console.WriteLine("Ошибка: введите 'h' или 'v'.\n");
                continue;
            }

            Console.WriteLine();
            if (direction == "h")
            {
                Console.WriteLine(new string(fillChar, length));
            }
            else
            {
                for (int i = 0; i < length; i++)
                    Console.WriteLine(fillChar);
            }
            Console.WriteLine();
        }
    }
}
