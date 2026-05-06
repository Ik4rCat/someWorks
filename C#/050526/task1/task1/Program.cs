class Program
{
    
    public static void Main()
    {
        int[] nums = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

        Console.WriteLine("Массив: " + string.Join(", ", nums));
        Console.Write("Введите первый индекс: ");
        string input1 = Console.ReadLine()!;
        Console.Write("Введите второй индекс: ");
        string input2 = Console.ReadLine()!;

        try
        {
            int index1 = int.Parse(input1);
            int index2 = int.Parse(input2);

            if (index1 < 0 || index1 >= nums.Length || index2 < 0 || index2 >= nums.Length)
                throw new IndexOutOfRangeException(
                    $"Индексы должны быть в диапазоне 0–{nums.Length - 1}. " +
                    $"Введено: {index1} и {index2}.");

            int sum = nums[index1] + nums[index2];
            Console.WriteLine($"nums[{index1}] + nums[{index2}] = {nums[index1]} + {nums[index2]} = {sum}");
        }
        catch (FormatException)
        {
            Console.WriteLine("Ошибка: введено не число.");
        }
        catch (IndexOutOfRangeException ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
        }
    }
}