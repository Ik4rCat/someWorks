using Npgsql;
using System.Data;
using System.Text;

const string CONN_STR = "Host=localhost;Port=5432;Database=smiling_academy;Username=smiley;Password=happiness123;Pooling=false;";

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
            "Group" VARCHAR(60) NOT NULL,
            Kurs    INTEGER     NOT NULL,
            UNIQUE(Name, Surname)
        );
        INSERT INTO "Студенты"(Name, Surname, Age, "Group", Kurs) VALUES
            ('Charlie',  'Dawson',    25,  'Базовое Счастье',             1),
            ('Pim',      'Simmons',   24,  'Базовое Счастье',             1),
            ('Alan',     'Stein',     30,  'Продвинутое Осчастливливание', 2),
            ('Glover',   'Portis',    28,  'Продвинутое Осчастливливание', 2),
            ('Shrimp',   'Saunders',  19,  'Базовое Счастье',             1),
            ('Desmond',  'Jenkins',  412,  'Работа с Тяжёлыми Случаями',  3),
            ('Poppy',    'Wheeler',   22,  'Продвинутое Осчастливливание', 2),
            ('Satan',    'Himself',  666,  'Работа с Тяжёлыми Случаями',  4),
            ('Tugger',   'McManus',   35,  'Работа с Тяжёлыми Случаями',  3),
            ('Amanda',   'Beach',     27,  'Базовое Счастье',             1);
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
            p_group   VARCHAR(60),
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
    var resultPar1 = new NpgsqlParameter("result", NpgsqlDbType.Integer);
    resultPar1.Direction = ParameterDirection.Output;
    cmd.Parameters.Add(resultPar1);
    cmd.ExecuteNonQuery();
    countKurs1 = (int)resultPar1.Value!;
    cmd.Parameters["p_kurs"].Value = 2;
    cmd.ExecuteNonQuery();
    countKurs2 = (int)resultPar1.Value!;
    cmd.Parameters["p_kurs"].Value = 3;
    cmd.ExecuteNonQuery();
    countKurs3 = (int)resultPar1.Value!;
}

// ── Задание 2: add_student ────────────────────────────────────────────────
DataTable before2 = Load();
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    using var cmd = new NpgsqlCommand(
        @"CALL add_student(@p_name, @p_surname, @p_age, @p_group, @p_kurs)", c);
    cmd.Parameters.AddWithValue("p_name",    "Bliss");
    cmd.Parameters.AddWithValue("p_surname", "O'Happiness");
    cmd.Parameters.AddWithValue("p_age",     23);
    cmd.Parameters.AddWithValue("p_group",   "Базовое Счастье");
    cmd.Parameters.AddWithValue("p_kurs",    1);
    cmd.ExecuteNonQuery();
}
DataTable after2 = Load();

// ── Задание 3: get_total_students ─────────────────────────────────────────
int totalStudents;
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    using var cmd = new NpgsqlCommand("SELECT get_total_students()", c);
    var resultPar = new NpgsqlParameter("result", NpgsqlDbType.Integer);
    resultPar.Direction = ParameterDirection.Output;
    cmd.Parameters.Add(resultPar);
    cmd.ExecuteNonQuery();
    totalStudents = (int)resultPar.Value!;
}

// ── Вывод ─────────────────────────────────────────────────────────────────
var out_ = new StringBuilder();

out_.AppendLine("=== Smiling Friends Academy — начальный состав ===");
out_.Append(TblStr(initState));

out_.AppendLine("\n=== Задание 1: count_students_on_kurs ===");
out_.AppendLine($"  Курс 1 (Базовое Счастье):              {countKurs1} студент(ов)");
out_.AppendLine($"  Курс 2 (Продвинутое Осчастливливание): {countKurs2} студент(ов)");
out_.AppendLine($"  Курс 3 (Работа с Тяжёлыми Случаями):  {countKurs3} студент(ов)");

out_.AppendLine("\n=== Задание 2: add_student — зачислить нового студента (до) ===");
out_.Append(TblStr(before2));
out_.AppendLine("=== Задание 2: add_student — зачислить нового студента (после) ===");
out_.Append(TblStr(after2));

out_.AppendLine("\n=== Задание 3: get_total_students ===");
out_.AppendLine($"  Всего студентов в Академии: {totalStudents}");

Console.Write(out_.ToString());
