class Program
{

    static int[] nums = new int[] {
        1, 2, 3, 
        4, 5, 6, 
        7, 8, 9, 
        10, 11, 12 };

    public static bool NumChecker(int checkNum)
    {
        bool isEven;
        
        if (checkNum % 2 == 0) isEven = true;
        else isEven = false;

        return isEven;
    }
    
    public static void Main()
    {
        for(int i =0 ; i < nums.Length; i++)
        {
            if (NumChecker(nums[i]))
            {
                Console.WriteLine($" num {nums[i]} - is even");    
            }
            else
            {
                Console.WriteLine($" num {nums[i]} - is not even");
            }
        }
    }
}