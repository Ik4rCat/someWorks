
class Program
{
    private int userNum, nNum;
    private bool isReal;
    
    void CheckIsRealN(int uNum)
    {
        int resl = 2;
        
        for (int i = 0; i < uNum; i++)
        {
            resl = resl * 2;
        }
        
        Console.WriteLine($"num is {isReal}");
    }
    
    public static void Main()
    {
        Console.WriteLine("Write num: ");
        CheckIsRealN(int.Parse(Console.ReadLine()));
        
    }
}