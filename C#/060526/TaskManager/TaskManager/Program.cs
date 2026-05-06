
class Task
{
    public string Name { get; private set; }
    public int Priority { get; private set; }

    public Task(string name, int priority)
    {
        Name = name; 
        Priority = priority;
    }
}

class Program
{
    public static void Main()
    {
        List<Task> tasks = new List<Task>();
        
        tasks.Add(new Task("Срочно сдать просрочки", 1));
        tasks.Add(new Task("Сделать конфигурацию", 3));
        tasks.Add(new Task("убраться и поспать", 5));
        tasks.Add(new Task("Срочно сделать статьи (2 штуки)", 1));

        for (int i = 0; i < tasks.Count; i++)
        {
            Console.WriteLine(tasks[i].Name);
        }
        
        tasks.Sort((a,b)=>a.Priority.CompareTo(b.Priority));

        Console.WriteLine(" ");
        
        for (int i = 0; i < tasks.Count; i++)
        {
            Console.WriteLine(tasks[i].Name);
        }
    } 
}

