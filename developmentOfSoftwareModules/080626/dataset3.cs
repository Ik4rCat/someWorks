// Разработка программных модулей (080626)
// Задание: создать пустую таблицу в PostgreSQL, затем через DataSet/DataTable/DataColumn/DataRow
//          заполнить колонками и рядами и перенести в PostgreSQL

using System;
using System.Data;
using Npgsql;

class DataSet3
{
    static readonly string ConnStr =
        "Host=localhost;Database=testdb;Username=postgres;Password=12345";

    static void Main()
    {
        using var conn = new NpgsqlConnection(ConnStr);
        conn.Open();

        // 1. Создаём пустую таблицу в PostgreSQL (без колонок — просто заготовка)
        using (var cmd = new NpgsqlCommand(@"
            DROP TABLE IF EXISTS products;
            CREATE TABLE products ();", conn))
        {
            cmd.ExecuteNonQuery();
            Console.WriteLine("Пустая таблица 'products' создана в PostgreSQL.");
        }

        // 2. Строим структуру через DataSet / DataTable / DataColumn
        DataSet ds = new DataSet("ShopDS");
        DataTable table = new DataTable("products");

        // DataColumn — добавляем колонки
        var colId     = new DataColumn("id",       typeof(int))    { AutoIncrement = true, AutoIncrementSeed = 1 };
        var colName   = new DataColumn("name",     typeof(string));
        var colPrice  = new DataColumn("price",    typeof(double));
        var colStock  = new DataColumn("stock",    typeof(int));
        var colActive = new DataColumn("is_active",typeof(bool))   { DefaultValue = true };

        table.Columns.AddRange(new[] { colId, colName, colPrice, colStock, colActive });
        table.PrimaryKey = new[] { colId };
        ds.Tables.Add(table);

        // 3. DataRow — добавляем строки
        object[][] data = {
            new object[] { 1, "Клавиатура",   1990.0,  15, true  },
            new object[] { 2, "Мышь",          890.0,  30, true  },
            new object[] { 3, "Монитор",     18500.0,   5, true  },
            new object[] { 4, "Наушники",     3200.0,  12, true  },
            new object[] { 5, "Веб-камера",   2100.0,   0, false },
        };

        foreach (var row in data)
            table.Rows.Add(row);

        Console.WriteLine($"DataTable заполнен: {table.Rows.Count} строк, {table.Columns.Count} колонок.");

        // 4. Добавляем колонки в реальную таблицу PostgreSQL через ALTER TABLE
        using (var cmd = new NpgsqlCommand(@"
            ALTER TABLE products
                ADD COLUMN id        SERIAL PRIMARY KEY,
                ADD COLUMN name      VARCHAR(100),
                ADD COLUMN price     DOUBLE PRECISION,
                ADD COLUMN stock     INTEGER,
                ADD COLUMN is_active BOOLEAN DEFAULT TRUE;", conn))
        {
            cmd.ExecuteNonQuery();
            Console.WriteLine("Колонки добавлены в PostgreSQL.");
        }

        // 5. Переносим данные из DataTable в PostgreSQL
        foreach (DataRow row in table.Rows)
        {
            using var cmd = new NpgsqlCommand(
                "INSERT INTO products (name, price, stock, is_active) VALUES (@n, @p, @s, @a)", conn);
            cmd.Parameters.AddWithValue("n", row["name"]);
            cmd.Parameters.AddWithValue("p", row["price"]);
            cmd.Parameters.AddWithValue("s", row["stock"]);
            cmd.Parameters.AddWithValue("a", row["is_active"]);
            cmd.ExecuteNonQuery();
        }

        Console.WriteLine("Данные перенесены в PostgreSQL.");

        // 6. Проверка — читаем обратно
        Console.WriteLine("\nСодержимое таблицы products в PostgreSQL:");
        using var checkCmd = new NpgsqlCommand("SELECT * FROM products ORDER BY id", conn);
        using var reader = checkCmd.ExecuteReader();
        while (reader.Read())
        {
            Console.WriteLine($"  id={reader["id"]}, name={reader["name"]}, " +
                              $"price={reader["price"]}, stock={reader["stock"]}, active={reader["is_active"]}");
        }
    }
}
