
[Flags]
enum Permission
{
    None        = 0,
    Read        = 1 << 0,
    Comment     = 1 << 1,
    Post        = 1 << 2,
    EditUsers   = 1 << 3,
    DeleteUsers = 1 << 4,
}

abstract class User
{
    public string Name { get; private set; }
    public string Email { get; private set; }
    public Type Role { get; private set; }
    public int BonusPoints { get; protected set; }
    public Permission Permissions { get; protected set; }

    public User(string name, string email, Type role, int bonusPoints, Permission permissions)
    {
        Name = name;
        Email = email;
        Role = role;
        BonusPoints = bonusPoints;
        Permissions = permissions;
    }

    public bool Can(Permission p) => (Permissions & p) == p;

    public abstract void PrintInfo();

    protected void PrintBase()
    {
        Console.WriteLine($"  Name:        {Name}");
        Console.WriteLine($"  Email:       {Email}");
        Console.WriteLine($"  Role:        {Role.Name}");
        Console.WriteLine($"  Bonus pts:   {BonusPoints}");
        Console.WriteLine($"  Permissions: {Permissions}");
    }
}


class Guest : User
{
    public Guest() : base(
        "Guest", "none",
        typeof(Guest), 0,
        Permission.Read) { }

    public override void PrintInfo()
    {
        Console.WriteLine("[Guest]");
        PrintBase();
    }
}

class Regular : User
{
    public Regular(string name, string email) : base(
        name, email,
        typeof(Regular), 15,
        Permission.Read | Permission.Comment | Permission.Post) { }

    public void AddBonus(int amount) => BonusPoints += amount;

    public override void PrintInfo()
    {
        Console.WriteLine("[Regular]");
        PrintBase();
    }
}

class Admin : User
{
    public Admin(string name, string email) : base(
        name, email,
        typeof(Admin), 9999,
        Permission.Read | Permission.Comment | Permission.Post |
        Permission.EditUsers | Permission.DeleteUsers) { }

    public override void PrintInfo()
    {
        Console.WriteLine("[Admin]");
        PrintBase();
    }
}

class Program
{
    static void PrintStats(User[] users)
    {
        int totalBonus = 0;
        int guests = 0, regulars = 0, admins = 0;

        foreach (User u in users)
        {
            totalBonus += u.BonusPoints;
            if (u is Guest)   guests++;
            if (u is Regular) regulars++;
            if (u is Admin)   admins++;
        }

        Console.WriteLine("=== Statistics ===");
        Console.WriteLine($"  Total users:   {users.Length}");
        Console.WriteLine($"  Guests:        {guests}");
        Console.WriteLine($"  Regulars:      {regulars}");
        Console.WriteLine($"  Admins:        {admins}");
        Console.WriteLine($"  Total bonuses: {totalBonus}");
        Console.WriteLine($"  Avg bonuses:   {(double)totalBonus / users.Length:F1}");
        Console.WriteLine();
    }

    public static void Main()
    {
        User[] users =
        {
            new Guest(),
            new Regular("Alice", "alice@mail.com"),
            new Regular("Bob",   "bob@mail.com"),
            new Regular("Carol", "carol@mail.com"),
            new Admin("Dave",  "dave@mail.com"),
            new Admin("Eve",   "eve@mail.com"),
        };

        Console.WriteLine("=== All Users ===");
        foreach (User u in users)
        {
            u.PrintInfo();
            Console.WriteLine($"  Can post:         {u.Can(Permission.Post)}");
            Console.WriteLine($"  Can delete users: {u.Can(Permission.DeleteUsers)}");
            Console.WriteLine();
        }

        PrintStats(users);
    }
}