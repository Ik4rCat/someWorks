
class Program
{
    public static void Main()
    {
        int xNum, xNumbackup, nNum = 0; 
        
        Console.WriteLine("Write num: ");
        xNum = int.Parse(Console.ReadLine());

        xNumbackup = xNum;
        
        // сдвигаем xNum вправо, пока результат > 1 — считаем количество бит (потенциальный показатель степени)
        while ((xNum >> nNum) > 1) nNum++;

        // проверяем: число положительное и 2^nNum точно равно исходному (иначе не степень двойки)
        if (xNumbackup > 0 && (1 << nNum) == xNumbackup)
            Console.WriteLine($"2^{nNum} = {xNumbackup}");
        else
            Console.WriteLine($"Нет такого n, что 2^n = {xNumbackup}");
    }
}