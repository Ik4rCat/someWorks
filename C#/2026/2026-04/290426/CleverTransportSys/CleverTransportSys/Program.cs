class Fuel
{
    public double Liters { get; set; }

    public Fuel(double liters)
    {
        Liters = liters;
    }

    public static Fuel operator +(Fuel a, Fuel b) => new Fuel(a.Liters + b.Liters);
    public static Fuel operator -(Fuel a, Fuel b) => new Fuel(a.Liters - b.Liters);

    public override string ToString() => $"{Liters}L";
}

abstract class Transport
{
    public double Speed { get; set; }
    public double Distance { get; set; }

    private static int _totalTrips;
    public static int TotalTrips => _totalTrips;
    protected static void IncrementTrips() => _totalTrips++;

    public Transport(double speed, double distance)
    {
        Speed = speed;
        Distance = distance;
    }

    public virtual string Move()
    {
        IncrementTrips();
        double hours = CalculateTime((int)Distance);
        return $"{GetType().Name} moved in {hours} hours";
    }

    public virtual double CalculateTime(int distance)
        => distance / Speed;

    public virtual double CalculateTime(int distance, bool traffic)
        => distance / Speed;

    public virtual double CalculateTime(int distance, int stops)
        => distance / Speed;
}

class Car : Transport
{
    public Fuel Fuel { get; set; }

    public Car(double speed, double distance, Fuel fuel) : base(speed, distance)
    {
        Fuel = fuel;
    }

    public override double CalculateTime(int distance, bool traffic)
    {
        double time = distance / Speed;
        return traffic ? time * 1.5 : time;
    }

    public override string Move()
    {
        IncrementTrips();
        double hours = CalculateTime((int)Distance, traffic: true);
        return $"Car moved in {hours} hours";
    }
}

class Bus : Transport
{
    public Fuel Fuel { get; set; }

    public Bus(double speed, double distance, Fuel fuel) : base(speed, distance)
    {
        Fuel = fuel;
    }

    public override double CalculateTime(int distance, int stops)
    {
        double time = distance / Speed;
        return time + stops * 0.1;
    }

    public override string Move()
    {
        IncrementTrips();
        double hours = CalculateTime((int)Distance, stops: 5);
        return $"Bus moved in {hours} hours";
    }
}

class Bicycle : Transport
{
    public Bicycle(double speed, double distance) : base(speed, distance) { }

    public override string Move()
    {
        IncrementTrips();
        double hours = CalculateTime((int)Distance);
        return $"Bicycle moved in {hours} hours";
    }
}

class Program
{
    static void Main()
    {
        Transport car = new Car(speed: 60, distance: 120, new Fuel(30));
        Transport bus = new Bus(speed: 40, distance: 120, new Fuel(60));
        Transport bicycle = new Bicycle(speed: 24, distance: 120);

        Console.WriteLine(car.Move());
        Console.WriteLine(bus.Move());
        Console.WriteLine(bicycle.Move());

        Console.WriteLine();

        Fuel tank1 = new Fuel(25);
        Fuel tank2 = new Fuel(15);

        Fuel combined = tank1 + tank2;
        Console.WriteLine($"Fuel left: {combined.Liters}");

        Fuel consumed = new Fuel(15);
        Fuel afterConsumption = combined - consumed;
        Console.WriteLine($"Fuel after consumption: {afterConsumption.Liters}");

        Console.WriteLine();
        Console.WriteLine($"Total trips: {Transport.TotalTrips}");
    }
}