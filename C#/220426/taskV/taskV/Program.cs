// Задание 5: минимальное и максимальное значение в двумерном массиве

class Program
{
    public static void Main()
    {
        int[,] matrix =
        {
            {  5, 12,  3, 18 },
            { 22,  7, 41,  9 },
            { 14,  2, 33, 16 },
            {  8, 27,  6, 11 }
        };

        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);

        int max = matrix[0, 0];
        int min = matrix[0, 0];

        Console.WriteLine("Матрица:");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                Console.Write($"{matrix[i, j],4}");
                if (matrix[i, j] > max) max = matrix[i, j];
                if (matrix[i, j] < min) min = matrix[i, j];
            }
            Console.WriteLine();
        }

        Console.WriteLine($"\nМаксимум: {max}");
        Console.WriteLine($"Минимум: {min}");
    }
}
