using System;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        ArrayList data = new ArrayList()
        {
            23, "Error 404", true, 17, false, "Error 500", true, 31, true, "Error 403"
        };

        List<int> temperatures = new List<int>();
        List<string> errors = new List<string>();
        int activeCount = 0;

        foreach (var item in data)
        {
            if (item is int temp)
                temperatures.Add(temp);
            else if (item is string err)
                errors.Add(err);
            else if (item is bool status && status == true)
                activeCount++;
        }
        
        int sum = 0;
        for (int i = 0; i < temperatures.Count; i++)
            sum += temperatures[i];
        double avg = (double)sum / temperatures.Count;
        
        string allErrors = string.Join(", ", errors);

        Console.WriteLine($"Среднее температур: {avg:F1}");
        Console.WriteLine($"Ошибки: {allErrors}");
        Console.WriteLine($"Активных состояний: {activeCount}");
    }
}