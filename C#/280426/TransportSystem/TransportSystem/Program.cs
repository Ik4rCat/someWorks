// Транспортная система: абстрактный класс Transport, наследники Car, Bus, Bicycle

abstract class Transport
{
    public string Name { get; protected set; }
    public double Speed { get; protected set; }   // km/h
    public double FuelLevel { get; protected set; } // литры (0 у велосипеда)

    public Transport(string name, double speed, double fuelLevel)
    {
        Name = name;
        Speed = speed;
        FuelLevel = fuelLevel;
    }

    public abstract string Move(double distance);

    public virtual string GetInfo()
        => $"{Name} | Скорость: {Speed} км/ч | Топливо: {FuelLevel} л";

    public override string ToString() => GetInfo();
}

class Car : Transport
{
    public int Seats { get; private set; }

    public Car(string name, double speed, double fuelLevel, int seats)
        : base(name, speed, fuelLevel)
    {
        Seats = seats;
    }

    public override string Move(double distance)
    {
        double hours = distance / Speed;
        double fuelUsed = distance * 0.08; // 8 л/100км
        FuelLevel = Math.Max(0, FuelLevel - fuelUsed);
        return $"[Car] {Name} проехал {distance} км за {hours:F1} ч. Топливо: {FuelLevel:F1} л";
    }

    public override string GetInfo()
        => base.GetInfo() + $" | Мест: {Seats}";
}

class Bus : Transport
{
    public int Passengers { get; private set; }

    public Bus(string name, double speed, double fuelLevel, int passengers)
        : base(name, speed, fuelLevel)
    {
        Passengers = passengers;
    }

    public override string Move(double distance)
    {
        double hours = distance / Speed;
        double fuelUsed = distance * 0.25; // 25 л/100км
        FuelLevel = Math.Max(0, FuelLevel - fuelUsed);
        return $"[Bus] {Name} проехал {distance} км за {hours:F1} ч. Топливо: {FuelLevel:F1} л";
    }

    public override string GetInfo()
        => base.GetInfo() + $" | Пассажиров: {Passengers}";
}

class Bicycle : Transport
{
    public string Type { get; private set; } // горный, городской и т.д.

    public Bicycle(string name, double speed, string type)
        : base(name, speed, 0)
    {
        Type = type;
    }

    public override string Move(double distance)
    {
        double hours = distance / Speed;
        return $"[Bicycle] {Name} проехал {distance} км за {hours:F1} ч";
    }

    public override string GetInfo()
        => $"{Name} | Скорость: {Speed} км/ч | Тип: {Type}";
}

class Program
{
    static void Main()
    {
        var vehicles = new List<Transport>
        {
            new Car("Toyota Camry", 120, 50, 5),
            new Car("BMW X5", 160, 70, 5),
            new Bus("Городской автобус", 60, 150, 45),
            new Bicycle("Trek FX3", 30, "городской"),
        };

        Console.WriteLine("=== Транспортная система ===\n");

        foreach (var v in vehicles)
            Console.WriteLine(v.GetInfo());

        Console.WriteLine("\n=== Движение (100 км) ===\n");

        foreach (var v in vehicles)
            Console.WriteLine(v.Move(100));

        Console.WriteLine("\n=== Состояние после поездки ===\n");

        foreach (var v in vehicles)
            Console.WriteLine(v.GetInfo());
    }
}
