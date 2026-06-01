using Npgsql;
using System.Data;
using System.Text;

const string CONN_STR = "Host=localhost;Port=5432;Database=lab9db;Username=lab9user;Password=lab9pass;Pooling=false;";

string TblStr(DataTable t)
{
    var s = new StringBuilder();
    s.AppendLine($"{"Id",-5} {"Имя",-12} {"Фамилия",-16} {"Возраст",-10} {"Группа",-10} {"Курс"}");
    s.AppendLine(new string('-', 60));
    foreach (DataRow r in t.Rows)
        s.AppendLine($"{r["id"],-5} {r["name"],-12} {r["surname"],-16} {r["age"],-10} {r["group"],-10} {r["kurs"]}");
    return s.ToString();
}

DataTable Load()
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    var a = new NpgsqlDataAdapter(@"SELECT * FROM ""Студенты"" ORDER BY Id", c);
    var ds = new DataSet(); a.Fill(ds, "Студенты");
    return ds.Tables["Студенты"]!.Copy();
}

// ── Инициализация таблицы ─────────────────────────────────────────────────
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    using var cmd = new NpgsqlCommand("""
        DROP TABLE IF EXISTS "Студенты";
        CREATE TABLE "Студенты"(
            Id      SERIAL PRIMARY KEY,
            Name    VARCHAR(50) NOT NULL,
            Surname VARCHAR(50) NOT NULL,
            Age     INTEGER     NOT NULL,
            "Group" VARCHAR(20) NOT NULL,
            Kurs    INTEGER     NOT NULL,
            UNIQUE(Name, Surname)
        );
        INSERT INTO "Студенты"(Name, Surname, Age, "Group", Kurs) VALUES
            ('Иван',    'Петров',    19, 'РПО-1', 1),
            ('Мария',   'Сидорова',  20, 'РПО-1', 1),
            ('Алексей', 'Козлов',    21, 'РПО-2', 2),
            ('Ольга',   'Иванова',   22, 'РПО-2', 2),
            ('Дмитрий', 'Фролов',    20, 'РПО-3', 3);
        """, c);
    cmd.ExecuteNonQuery();
}

// ── Создать функции и процедуру ───────────────────────────────────────────
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    using var cmd = new NpgsqlCommand("""
        -- Функция 1: количество студентов на курсе
        CREATE OR REPLACE FUNCTION count_students_on_kurs(p_kurs INTEGER)
        RETURNS INTEGER AS $$
        BEGIN
            RETURN (SELECT COUNT(*) FROM "Студенты" WHERE Kurs = p_kurs);
        END;
        $$ LANGUAGE plpgsql;

        -- Процедура: добавить студента в существующую группу
        CREATE OR REPLACE PROCEDURE add_student(
            p_name    VARCHAR(50),
            p_surname VARCHAR(50),
            p_age     INTEGER,
            p_group   VARCHAR(20),
            p_kurs    INTEGER
        )
        AS $$
        BEGIN
            IF NOT EXISTS (SELECT 1 FROM "Студенты" WHERE "Group" = p_group) THEN
                RAISE EXCEPTION 'Группа % не существует', p_group;
            END IF;
            INSERT INTO "Студенты"(Name, Surname, Age, "Group", Kurs)
            VALUES (p_name, p_surname, p_age, p_group, p_kurs);
        END;
        $$ LANGUAGE plpgsql;

        -- Функция 3: общее количество студентов
        CREATE OR REPLACE FUNCTION get_total_students()
        RETURNS INTEGER AS $$
        DECLARE
            total INTEGER;
        BEGIN
            SELECT COUNT(*) INTO total FROM "Студенты";
            RETURN total;
        END;
        $$ LANGUAGE plpgsql;
        """, c);
    cmd.ExecuteNonQuery();
}

DataTable initState = Load();

// ── Задание 1: count_students_on_kurs ─────────────────────────────────────
int countKurs1, countKurs2, countKurs3;
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    using var cmd = new NpgsqlCommand("SELECT count_students_on_kurs(@p_kurs)", c);
    cmd.Parameters.AddWithValue("p_kurs", 1);
    countKurs1 = (int)cmd.ExecuteScalar()!;
    cmd.Parameters["p_kurs"].Value = 2;
    countKurs2 = (int)cmd.ExecuteScalar()!;
    cmd.Parameters["p_kurs"].Value = 3;
    countKurs3 = (int)cmd.ExecuteScalar()!;
}

// ── Задание 2: add_student ────────────────────────────────────────────────
DataTable before2 = Load();
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    using var cmd = new NpgsqlCommand(
        @"CALL add_student(@p_name, @p_surname, @p_age, @p_group, @p_kurs)", c);
    cmd.Parameters.AddWithValue("p_name",    "Екатерина");
    cmd.Parameters.AddWithValue("p_surname", "Волкова");
    cmd.Parameters.AddWithValue("p_age",     20);
    cmd.Parameters.AddWithValue("p_group",   "РПО-1");
    cmd.Parameters.AddWithValue("p_kurs",    1);
    cmd.ExecuteNonQuery();
}
DataTable after2 = Load();

// ── Задание 3: get_total_students ─────────────────────────────────────────
int totalStudents;
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    using var cmd = new NpgsqlCommand("SELECT get_total_students()", c);
    totalStudents = (int)cmd.ExecuteScalar()!;
}

// ── Вывод ─────────────────────────────────────────────────────────────────
var out_ = new StringBuilder();

out_.AppendLine("=== Начальное состояние таблицы Студенты ===");
out_.Append(TblStr(initState));

out_.AppendLine("\n=== Задание 1: count_students_on_kurs ===");
out_.AppendLine($"  Курс 1: {countKurs1} студент(ов)");
out_.AppendLine($"  Курс 2: {countKurs2} студент(ов)");
out_.AppendLine($"  Курс 3: {countKurs3} студент(ов)");

out_.AppendLine("\n=== Задание 2: add_student (до) ===");
out_.Append(TblStr(before2));
out_.AppendLine("=== Задание 2: add_student (после) ===");
out_.Append(TblStr(after2));

out_.AppendLine("\n=== Задание 3: get_total_students ===");
out_.AppendLine($"  Всего студентов в таблице: {totalStudents}");

Console.Write(out_.ToString());
