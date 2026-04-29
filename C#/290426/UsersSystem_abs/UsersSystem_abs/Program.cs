

class User
{
    private string _name;
    private string _email;

    public User(string name, string email)
    {
        _name = name;
        _email = email;
    }

    public string GetName()
    {
        return _name;
    }

    public string GetEmail()
    {
        return _email;
    }
}

class Program
{
    public static void Main()
    {
        
    }
}