// Задание 3: подсчитать сколько раз последовательность из трёх чисел встречается в массиве

class Program
{
    static int[] array = { 7, 6, 5, 3, 4, 7, 6, 5, 8, 7, 6, 5 };

    public static void Main()
    {
        Console.WriteLine($"Массив: [{string.Join(", ", array)}]");

        int[] seq = new int[3];
        for (int i = 0; i < 3; i++)
        {
            Console.Write($"Введите число {i + 1} последовательности: ");
            while (!int.TryParse(Console.ReadLine(), out seq[i]))
                Console.Write("Ошибка. Повторите: ");
        }

        int count = 0;
        for (int i = 0; i <= array.Length - 3; i++)
        {
            if (array[i] == seq[0] && array[i + 1] == seq[1] && array[i + 2] == seq[2])
                count++;
        }

        Console.WriteLine($"Последовательность [{string.Join(", ", seq)}] встречается: {count} раз");
    }
}
