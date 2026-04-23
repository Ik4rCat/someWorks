using System;

class Program
{
    
    static int HowManyWords(string sentence)
    {
        if (string.IsNullOrWhiteSpace(sentence))
            return 0;
        string[] wordsBox = sentence.Split(new[] { ' ', '\t', '\n', '\r' }, StringSplitOptions.RemoveEmptyEntries);
        return wordsBox.Length;
    } 
    
    public static void Main()
    {

        string userInput;
        int wordsInSentense = 0;
        
        Console.WriteLine("Enter sentense: ");
        userInput = Console.ReadLine();

        wordsInSentense = HowManyWords(userInput);
        
        Console.WriteLine(wordsInSentense);
        
        
    }
}