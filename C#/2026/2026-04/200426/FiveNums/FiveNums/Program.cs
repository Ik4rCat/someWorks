// Задание 2: ввести 5 чисел, найти сумму, макс, мин, произведение

class Program
{
    public static void Main()
    {
        int[] nums = new int[5];

        for (int i = 0; i < 5; i++)
        {
            Console.Write($"Введите число {i + 1}: ");
            while (!int.TryParse(Console.ReadLine(), out nums[i]))
                Console.Write("Ошибка. Повторите: ");
        }

        long sum = 0, product = 1;
        int max = nums[0], min = nums[0];

        foreach (int n in nums)
        {
            sum += n;
            product *= n;
            if (n > max) max = n;
            if (n < min) min = n;
        }

        Console.WriteLine($"\nСумма: {sum}");
        Console.WriteLine($"Произведение: {product}");
        Console.WriteLine($"Максимум: {max}");
        Console.WriteLine($"Минимум: {min}");
    }
}
