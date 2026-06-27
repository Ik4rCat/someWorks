int[] nums = [2, 4, 11, 3];
int target = 6;
int[] result = new Solution().TwoSum(nums, target);

Console.WriteLine("Input:");
Console.WriteLine($"nums = [{string.Join(", ", nums)}]");
Console.WriteLine($"target = {target}");
Console.WriteLine($"Output: [{result[0]}, {result[1]}]");
Console.WriteLine("Expected: [0, 1]");

public class Solution
{
    public int[] TwoSum(int[] nums, int target) {

        for(int i = 0; i < nums.Length - 1; i++)
        {
            for(int j = i + 1; j < nums.Length; j++)
            {
                if(nums[i] + nums[j] == target) return new int[] {i, j};
            }
        }

        return new int[] {-1, -1};

    }
}