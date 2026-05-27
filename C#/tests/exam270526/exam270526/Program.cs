
class Program
{
    public static void Main()
    {
        // переменные 
        int xNum, xNumbackup, nNum = 0; 
        
        // user вводит число x
        Console.WriteLine("Write num: ");
        xNum = int.Parse(Console.ReadLine());

        xNumbackup = xNum;
        
        // проверка
        while ((xNum >> nNum) > 1) nNum++;

        if (xNumbackup > 0 && (1 << nNum) == xNumbackup)
            Console.WriteLine($"2^{nNum} = {xNumbackup}");
        else
            Console.WriteLine($"Нет такого n, что 2^n = {xNumbackup}");
    }
}