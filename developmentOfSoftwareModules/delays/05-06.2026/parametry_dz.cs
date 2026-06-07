// Параметры ДЗ (280526)
// 1. Добавление пользователя (NpgsqlParameter, защита от SQL-инъекций)
// 2. Обновление зарплаты (UPDATE с параметрами)
// 3. Поиск по части имени (LIKE с параметром — почему нельзя '%@name%')

using System;
using Npgsql;

class ParametersHomework
{
    const string ConnStr = "Host=localhost;Port=5432;Database=lab9db;Username=lab9user;Password=lab9pass;Pooling=false;";

    // ============================================================
    // Инициализация таблиц
    // ============================================================
    static void InitDb(NpgsqlConnection conn)
    {
        using var cmd = conn.CreateCommand();

        cmd.CommandText = @"
            CREATE TABLE IF NOT EXISTS Users (
                Id SERIAL PRIMARY KEY,
                Name VARCHAR(100) NOT NULL,
                Age  INTEGER
            );
            CREATE TABLE IF NOT EXISTS Employees (
                Id     SERIAL PRIMARY KEY,
                Name   VARCHAR(100),
                Salary NUMERIC(10, 2)
            );
            DELETE FROM Users;
            DELETE FROM Employees;
            INSERT INTO Employees (Name, Salary) VALUES
                ('Алиса', 50000),
                ('Борис', 60000),
                ('Виктор', 45000);
        ";
        cmd.ExecuteNonQuery();
    }

    // ============================================================
    // Задание 1: Добавление пользователя с NpgsqlParameter
    // Почему нельзя конкатенировать? — SQL-инъекция:
    //   name = "'; DROP TABLE Users; --" → сломает запрос.
    //   Параметр передаётся отдельно и никогда не интерпретируется как SQL.
    // ============================================================
    static void AddUser(NpgsqlConnection conn, string name, int age)
    {
        using var cmd = conn.CreateCommand();
        cmd.CommandText = "INSERT INTO Users (Name, Age) VALUES (@name, @age)";
        cmd.Parameters.AddWithValue("@name", name);
        cmd.Parameters.AddWithValue("@age", age);
        cmd.ExecuteNonQuery();
        Console.WriteLine($"[AddUser] Добавлен: {name}, возраст {age}");
    }

    // ============================================================
    // Задание 2: Обновление зарплаты
    // UPDATE Employees SET Salary = @Salary WHERE Id = @Id
    // ============================================================
    static void UpdateSalary(NpgsqlConnection conn, int id, decimal salary)
    {
        using var cmd = conn.CreateCommand();
        cmd.CommandText = "UPDATE Employees SET Salary = @Salary WHERE Id = @Id";
        cmd.Parameters.AddWithValue("@Salary", salary);
        cmd.Parameters.AddWithValue("@Id", id);
        int rows = cmd.ExecuteNonQuery();
        Console.WriteLine($"[UpdateSalary] Id={id} → Salary={salary:F2}. Обновлено строк: {rows}");
    }

    // ============================================================
    // Задание 3: Поиск по части имени — LIKE с параметром
    //
    // Почему НЕЛЬЗЯ написать '%@name%'?
    //   Потому что @name внутри строкового литерала — это просто текст,
    //   а не параметр. PostgreSQL не заменит @name значением из Parameters.
    //   Нужно передать '%' + value + '%' как значение параметра.
    // ============================================================
    static void SearchByName(NpgsqlConnection conn, string partialName)
    {
        using var cmd = conn.CreateCommand();
        cmd.CommandText = "SELECT Id, Name, Salary FROM Employees WHERE Name LIKE @name";
        cmd.Parameters.AddWithValue("@name", "%" + partialName + "%");

        using var reader = cmd.ExecuteReader();
        Console.WriteLine($"\n[SearchByName] Поиск по '{partialName}':");
        while (reader.Read())
        {
            Console.WriteLine($"  Id={reader.GetInt32(0)}, Name={reader.GetString(1)}, Salary={reader.GetDecimal(2):F2}");
        }
    }

    static void Main()
    {
        using var conn = new NpgsqlConnection(ConnStr);
        conn.Open();

        InitDb(conn);

        // Задание 1
        AddUser(conn, "Анна", 20);
        AddUser(conn, "Иван О'Брайен", 22);   // имя с апострофом — безопасно через параметр

        // Задание 2
        UpdateSalary(conn, 1, 55000m);
        UpdateSalary(conn, 2, 70000m);

        // Задание 3
        SearchByName(conn, "ис");   // найдёт «Алиса»
        SearchByName(conn, "ор");   // найдёт «Борис», «Виктор»
    }
}
