// Разработка программных модулей (050626)
// Задание: добавить строку в DataSet, изменить данные, SqlCommandBuilder для сохранения в PostgreSQL

using System;
using System.Data;
using Npgsql;

class DataSet2
{
    static readonly string ConnStr =
        "Host=localhost;Database=testdb;Username=postgres;Password=12345";

    static void Main()
    {
        using var conn = new NpgsqlConnection(ConnStr);
        conn.Open();

        // 1. Загружаем данные из БД в DataSet
        string query = "SELECT * FROM students";
        var adapter = new NpgsqlDataAdapter(query, conn);

        // SqlCommandBuilder автоматически генерирует INSERT/UPDATE/DELETE
        var builder = new NpgsqlCommandBuilder(adapter);

        DataSet ds = new DataSet();
        adapter.Fill(ds, "students");
        DataTable table = ds.Tables["students"];

        Console.WriteLine($"Загружено строк: {table.Rows.Count}");

        // 2. Добавляем новую строку
        DataRow newRow = table.NewRow();
        newRow["name"]   = "Новый Студент";
        newRow["age"]    = 20;
        newRow["grade"]  = 4.0;
        newRow["course"] = 1;
        table.Rows.Add(newRow);
        Console.WriteLine("Добавлена новая строка.");

        // 3. Изменяем существующие данные (первая строка)
        if (table.Rows.Count > 0)
        {
            table.Rows[0]["grade"]  = 5.0;
            table.Rows[0]["course"] = 3;
            Console.WriteLine("Изменена первая строка.");
        }

        // 4. Сохраняем изменения в БД через SqlCommandBuilder
        // builder уже сгенерировал adapter.InsertCommand / UpdateCommand / DeleteCommand
        int affected = adapter.Update(ds, "students");
        Console.WriteLine($"Сохранено изменений в БД: {affected} строк.");

        // 5. Вывод текущего состояния таблицы
        Console.WriteLine("\nТекущее состояние таблицы:");
        foreach (DataRow row in table.Rows)
        {
            Console.WriteLine($"  id={row["id"]}, name={row["name"]}, " +
                              $"age={row["age"]}, grade={row["grade"]}, course={row["course"]}");
        }
    }
}
