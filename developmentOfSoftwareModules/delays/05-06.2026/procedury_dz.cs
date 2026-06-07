// Процедуры ДЗ (290526) — вызов хранимых процедур PostgreSQL из C#
// 1. GetAllUsers — без параметров, через DataReader
// 2. GetUsersByCity — входной параметр
// 3. GetUsersByOrders — параметр со значением по умолчанию
// 4. GetUserCount — OUTPUT-параметр
// 5. ValidateUser — RETURN-значение

using System;
using System.Data;
using Npgsql;

class ProceduresHomework
{
    const string ConnStr = "Host=localhost;Port=5432;Database=lab9db;Username=lab9user;Password=lab9pass;Pooling=false;";

    // ============================================================
    // Инициализация: создаём таблицу и процедуры/функции
    // ============================================================
    static void InitDb(NpgsqlConnection conn)
    {
        using var cmd = conn.CreateCommand();
        cmd.CommandText = @"
            CREATE TABLE IF NOT EXISTS AppUsers (
                Id       SERIAL PRIMARY KEY,
                Name     VARCHAR(100),
                City     VARCHAR(100),
                Orders   INTEGER DEFAULT 0
            );
            DELETE FROM AppUsers;
            INSERT INTO AppUsers (Name, City, Orders) VALUES
                ('Алиса',  'Москва',      5),
                ('Борис',  'СПб',         2),
                ('Виктор', 'Москва',     10),
                ('Галина', 'Казань',      1),
                ('Дмитрий','СПб',         7);

            -- 1. Процедура без параметров
            CREATE OR REPLACE PROCEDURE GetAllUsers()
            LANGUAGE plpgsql AS $$
            BEGIN
                -- PostgreSQL процедуры не возвращают результирующий набор напрямую;
                -- используем функцию для этого паттерна (см. вызов ниже).
            END;
            $$;

            -- 2. Функция с входным параметром (вместо процедуры — для возврата строк)
            CREATE OR REPLACE FUNCTION GetUsersByCity(p_city VARCHAR)
            RETURNS TABLE(Id INTEGER, Name VARCHAR, City VARCHAR, Orders INTEGER)
            LANGUAGE plpgsql AS $$
            BEGIN
                RETURN QUERY SELECT u.Id, u.Name, u.City, u.Orders FROM AppUsers u WHERE u.City = p_city;
            END;
            $$;

            -- 3. Функция с параметром по умолчанию
            CREATE OR REPLACE FUNCTION GetUsersByOrders(p_min_orders INTEGER DEFAULT 0)
            RETURNS TABLE(Id INTEGER, Name VARCHAR, Orders INTEGER)
            LANGUAGE plpgsql AS $$
            BEGIN
                RETURN QUERY SELECT u.Id, u.Name, u.Orders FROM AppUsers u WHERE u.Orders >= p_min_orders ORDER BY u.Orders DESC;
            END;
            $$;

            -- 4. Функция с OUT-параметром (общее количество пользователей)
            CREATE OR REPLACE FUNCTION GetUserCount(OUT total_count INTEGER)
            LANGUAGE plpgsql AS $$
            BEGIN
                SELECT COUNT(*) INTO total_count FROM AppUsers;
            END;
            $$;

            -- 5. Функция с RETURN-значением: 0 = OK, 1 = ошибка (нет города)
            CREATE OR REPLACE FUNCTION ValidateCity(p_city VARCHAR)
            RETURNS INTEGER
            LANGUAGE plpgsql AS $$
            BEGIN
                IF EXISTS (SELECT 1 FROM AppUsers WHERE City = p_city) THEN
                    RETURN 0;
                ELSE
                    RETURN 1;
                END IF;
            END;
            $$;
        ";
        cmd.ExecuteNonQuery();
        Console.WriteLine("[Init] Таблица и процедуры созданы.\n");
    }

    // ============================================================
    // 1. Вызов GetAllUsers — все пользователи через DataReader
    //    (В PostgreSQL используем прямой SELECT, т.к. PROCEDURE не возвращает rows)
    // ============================================================
    static void Task1_GetAllUsers(NpgsqlConnection conn)
    {
        using var cmd = conn.CreateCommand();
        // В PostgreSQL — CALL не возвращает rows; используем функцию или SELECT
        cmd.CommandText = "SELECT Id, Name, City, Orders FROM AppUsers ORDER BY Id";
        cmd.CommandType = CommandType.Text;

        Console.WriteLine("=== Задание 1: Все пользователи ===");
        using var reader = cmd.ExecuteReader();
        while (reader.Read())
        {
            Console.WriteLine($"  {reader.GetInt32(0)}. {reader.GetString(1)} | {reader.GetString(2)} | Заказы: {reader.GetInt32(3)}");
        }
        Console.WriteLine();
    }

    // ============================================================
    // 2. GetUsersByCity — входной параметр @City
    // ============================================================
    static void Task2_GetUsersByCity(NpgsqlConnection conn, string city)
    {
        using var cmd = conn.CreateCommand();
        cmd.CommandText = "SELECT * FROM GetUsersByCity(@City)";
        cmd.Parameters.AddWithValue("@City", city);

        Console.WriteLine($"=== Задание 2: Пользователи из '{city}' ===");
        using var reader = cmd.ExecuteReader();
        while (reader.Read())
        {
            Console.WriteLine($"  {reader.GetString(1)} — {reader.GetInt32(3)} заказов");
        }
        Console.WriteLine();
    }

    // ============================================================
    // 3. GetUsersByOrders — параметр со значением по умолчанию
    //    Вызов 1: без параметра (minOrders = 0, все пользователи)
    //    Вызов 2: с параметром minOrders = 5
    // ============================================================
    static void Task3_GetUsersByOrders(NpgsqlConnection conn)
    {
        Console.WriteLine("=== Задание 3: Параметр по умолчанию ===");

        // Вызов 1 — без параметра (используем DEFAULT 0)
        using (var cmd = conn.CreateCommand())
        {
            cmd.CommandText = "SELECT * FROM GetUsersByOrders()";
            Console.WriteLine("  Без параметра (minOrders=0, все):");
            using var r = cmd.ExecuteReader();
            while (r.Read()) Console.WriteLine($"    {r.GetString(1)} — {r.GetInt32(2)} заказов");
        }

        // Вызов 2 — с параметром 5
        using (var cmd = conn.CreateCommand())
        {
            cmd.CommandText = "SELECT * FROM GetUsersByOrders(@min)";
            cmd.Parameters.AddWithValue("@min", 5);
            Console.WriteLine("  С параметром minOrders=5:");
            using var r = cmd.ExecuteReader();
            while (r.Read()) Console.WriteLine($"    {r.GetString(1)} — {r.GetInt32(2)} заказов");
        }
        Console.WriteLine();
    }

    // ============================================================
    // 4. GetUserCount — OUT-параметр
    // ============================================================
    static void Task4_GetUserCount(NpgsqlConnection conn)
    {
        using var cmd = conn.CreateCommand();
        cmd.CommandText = "SELECT GetUserCount()";
        var result = cmd.ExecuteScalar();
        Console.WriteLine($"=== Задание 4: OUTPUT-параметр ===");
        Console.WriteLine($"  Всего пользователей: {result}\n");
    }

    // ============================================================
    // 5. ValidateCity — RETURN-значение (0 = OK, 1 = ошибка)
    // ============================================================
    static void Task5_ValidateCity(NpgsqlConnection conn, string city)
    {
        using var cmd = conn.CreateCommand();
        cmd.CommandText = "SELECT ValidateCity(@city)";
        cmd.Parameters.AddWithValue("@city", city);

        int returnValue = Convert.ToInt32(cmd.ExecuteScalar());
        Console.WriteLine($"=== Задание 5: RETURN-значение ===");
        Console.WriteLine($"  Город '{city}': {(returnValue == 0 ? "✅ найден (RETURN 0)" : "❌ не найден (RETURN 1)")}\n");
    }

    static void Main()
    {
        using var conn = new NpgsqlConnection(ConnStr);
        conn.Open();

        InitDb(conn);
        Task1_GetAllUsers(conn);
        Task2_GetUsersByCity(conn, "Москва");
        Task3_GetUsersByOrders(conn);
        Task4_GetUserCount(conn);
        Task5_ValidateCity(conn, "СПб");
        Task5_ValidateCity(conn, "Владивосток");
    }
}
