// Задание 7: перевернуть каждое слово в предложении

class Program
{
    static string ReverseWords(string sentence)
    {
        string[] words = sentence.Split(' ');
        for (int i = 0; i < words.Length; i++)
        {
            char[] chars = words[i].ToCharArray();
            Array.Reverse(chars);
            words[i] = new string(chars);
        }
        return string.Join(" ", words);
    }

    public static void Main()
    {
        Console.Write("Введите предложение: ");
        string input = Console.ReadLine();

        if (string.IsNullOrWhiteSpace(input))
        {
            Console.WriteLine("Пустой ввод.");
            return;
        }

        Console.WriteLine(ReverseWords(input));
    }
}
