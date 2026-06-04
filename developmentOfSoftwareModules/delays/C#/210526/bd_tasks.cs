// БД задания (180526 + 210526)
// Задание 1: Создать БД с минимум 5 столбцами и 10 строками
// Задание 2: Добавить 5 строк, посчитать количество строк, вывести названия колонок
// Задание 3: Подключиться и вывести все строки через DataReader

using System;
using System.Text;
using Npgsql;

class BdTasks
{
    const string ConnStr = "Host=localhost;Port=5432;Database=lab9db;Username=lab9user;Password=lab9pass;Pooling=false;";

    // ============================================================
    // Задание 1: Создать таблицу с ≥5 столбцами и 10 строками
    // ============================================================
    static void Task1_CreateTable(NpgsqlConnection conn)
    {
        using var cmd = conn.CreateCommand();
        cmd.CommandText = @"
            DROP TABLE IF EXISTS Books;
            CREATE TABLE Books (
                Id        SERIAL PRIMARY KEY,
                Title     VARCHAR(200) NOT NULL,
                Author    VARCHAR(150) NOT NULL,
                Year      INTEGER,
                Genre     VARCHAR(100),
                Price     NUMERIC(8,2)
            );
            INSERT INTO Books (Title, Author, Year, Genre, Price) VALUES
                ('Мастер и Маргарита',  'Булгаков',    1967, 'Роман',     450.00),
                ('1984',                'Оруэлл',      1949, 'Антиутопия',320.00),
                ('Дюна',                'Херберт',     1965, 'Фантастика', 550.00),
                ('Гарри Поттер',        'Роулинг',     1997, 'Фэнтези',   390.00),
                ('Преступление и нак.', 'Достоевский', 1866, 'Роман',     280.00),
                ('Война и мир',         'Толстой',     1869, 'Роман',     600.00),
                ('Цветы для Элджернона','Киз',         1966, 'Фантастика',410.00),
                ('Автостопом по гал.',  'Адамс',       1979, 'Юмор',      350.00),
                ('Игра престолов',      'Мартин',      1996, 'Фэнтези',   720.00),
                ('Метро 2033',          'Глуховский',  2002, 'Пост-апок.',380.00);
        ";
        cmd.ExecuteNonQuery();
        Console.WriteLine("[Задание 1] Таблица Books создана, 10 строк добавлено.");
    }

    // ============================================================
    // Задание 2: Добавить 5 строк, посчитать количество, вывести названия колонок
    // ============================================================
    static void Task2_AddRowsAndInfo(NpgsqlConnection conn)
    {
        // Добавляем 5 строк
        using (var cmd = conn.CreateCommand())
        {
            cmd.CommandText = @"
                INSERT INTO Books (Title, Author, Year, Genre, Price) VALUES
                    ('Шантарам',          'Робертс',  2003, 'Приключения', 490.00),
                    ('Sapiens',           'Харари',   2011, 'Нон-фикшн',  510.00),
                    ('Тёмные начала',     'Пулман',   1995, 'Фэнтези',    360.00),
                    ('Алхимик',           'Коэльо',   1988, 'Философия',  295.00),
                    ('Нейромант',         'Гибсон',   1984, 'Киберпанк',  430.00);
            ";
            cmd.ExecuteNonQuery();
        }

        var sb = new StringBuilder();

        // Количество строк
        using (var cmd = conn.CreateCommand())
        {
            cmd.CommandText = "SELECT COUNT(*) FROM Books";
            long count = (long)cmd.ExecuteScalar()!;
            sb.AppendLine($"\n[Задание 2] Добавлено 5 строк. Итого строк в таблице: {count}");
        }

        // Названия колонок через information_schema
        using (var cmd = conn.CreateCommand())
        {
            cmd.CommandText = @"
                SELECT column_name, data_type
                FROM information_schema.columns
                WHERE table_name = 'books'
                ORDER BY ordinal_position";
            sb.AppendLine("Колонки таблицы Books:");
            using var reader = cmd.ExecuteReader();
            while (reader.Read())
                sb.AppendLine($"  - {reader.GetString(0)} ({reader.GetString(1)})");
        }

        Console.Write(sb);
    }

    // ============================================================
    // Задание 3: Подключиться и вывести все строки через DataReader
    // ============================================================
    static void Task3_ReadAllRows(NpgsqlConnection conn)
    {
        using var cmd = conn.CreateCommand();
        cmd.CommandText = "SELECT * FROM Books ORDER BY Id";
        using var reader = cmd.ExecuteReader();

        var sb = new StringBuilder();
        sb.AppendLine("\n[Задание 3] Все строки таблицы Books:");
        sb.AppendLine($"{"Id",-4} {"Title",-30} {"Author",-18} {"Year",-6} {"Genre",-12} {"Price",-8}");
        sb.AppendLine(new string('-', 82));

        while (reader.Read())
        {
            sb.AppendLine($"{reader.GetInt32(0),-4} {reader.GetString(1),-30} {reader.GetString(2),-18} " +
                          $"{reader.GetInt32(3),-6} {reader.GetString(4),-12} {reader.GetDecimal(5),-8:F2}");
        }

        Console.Write(sb);
    }

    static void Main()
    {
        using var conn = new NpgsqlConnection(ConnStr);
        conn.Open();

        Task1_CreateTable(conn);
        Task2_AddRowsAndInfo(conn);
        Task3_ReadAllRows(conn);
    }
}
