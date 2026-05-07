// Пользователь с клавиатуры вводит шестизначное число, необходимо перевернуть число и отобразить результат

public class Program
{

    public static int ReverFunc(int reverNum)
    {
        int source= reverNum, result = 0;

        while(true)
        {
            int digit = source % 10;
            result = result * 10;
            result = result + digit;
            source = source / 10;

            if (source == 0)
                return result;
        }
        
    }
    
    
    public static void Main()
    {
        while (true)
        {
            int userNum;
            Console.WriteLine("Write num: ");
            string userInput = Console.ReadLine();

            if (string.IsNullOrEmpty(userInput) || userInput.Length != 6)
            {
                Console.WriteLine("error: u need 6 nums.\n");
                continue;
            }

            bool onlyDigits = true;
            foreach (char c in userInput)
            {
                if (!char.IsDigit(c))
                {
                    onlyDigits = false;
                    break;
                }
            }
            if (!onlyDigits)
            {
                Console.WriteLine("error: u need only nums.\n");
                continue;
            }
            
            if (!int.TryParse(userInput, out userNum))
            {
                Console.WriteLine("error: too big num bruh\n");
                continue;
            }

            if (userNum < 100000 || userNum > 999999)
            {
                Console.WriteLine("❌ Ошибка: число должно быть от 100000 до 999999.\n");
                continue;
            }
            
            long newUserNum = ReverFunc(userNum);
        
            Console.WriteLine(newUserNum);   
        }
    }
    
}