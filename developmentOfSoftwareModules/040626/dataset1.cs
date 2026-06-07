// Разработка программных модулей (040626)
// Задание: создать DataSet вручную, определить структуру таблицы, добавить данные

using System;
using System.Data;

class DataSet1
{
    static void Main()
    {
        // 1. Создаём DataSet и DataTable
        DataSet ds = new DataSet("StudentsDS");
        DataTable table = new DataTable("Students");

        // 2. Определяем структуру (колонки)
        table.Columns.Add("Id",         typeof(int));
        table.Columns.Add("Name",       typeof(string));
        table.Columns.Add("Age",        typeof(int));
        table.Columns.Add("Grade",      typeof(double));
        table.Columns.Add("Course",     typeof(int));

        // Первичный ключ
        table.PrimaryKey = new DataColumn[] { table.Columns["Id"] };

        // 3. Добавляем данные (10 строк)
        object[][] rows = {
            new object[] { 1, "Алиса Иванова",   20, 4.8, 2 },
            new object[] { 2, "Борис Петров",    21, 3.5, 3 },
            new object[] { 3, "Виктор Сидоров",  19, 4.2, 1 },
            new object[] { 4, "Галина Кузнецова", 22, 4.0, 4 },
            new object[] { 5, "Дмитрий Орлов",   20, 3.8, 2 },
            new object[] { 6, "Елена Смирнова",  21, 4.5, 3 },
            new object[] { 7, "Жанна Козлова",   19, 3.2, 1 },
            new object[] { 8, "Иван Новиков",    23, 4.9, 5 },
            new object[] { 9, "Карина Морозова", 20, 4.1, 2 },
            new object[] {10, "Лев Фёдоров",     22, 3.7, 4 },
        };

        foreach (var r in rows)
            table.Rows.Add(r);

        // 4. Добавляем таблицу в DataSet
        ds.Tables.Add(table);

        // 5. Вывод содержимого
        Console.WriteLine($"DataSet: {ds.DataSetName}");
        Console.WriteLine($"Таблица: {table.TableName}, строк: {table.Rows.Count}\n");

        Console.WriteLine("{0,-4} {1,-20} {2,-5} {3,-7} {4}",
            "Id", "Name", "Age", "Grade", "Course");
        Console.WriteLine(new string('-', 50));

        foreach (DataRow row in table.Rows)
        {
            Console.WriteLine("{0,-4} {1,-20} {2,-5} {3,-7} {4}",
                row["Id"], row["Name"], row["Age"], row["Grade"], row["Course"]);
        }
    }
}
