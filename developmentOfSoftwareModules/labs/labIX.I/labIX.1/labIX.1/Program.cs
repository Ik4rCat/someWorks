using Npgsql;
using System.Data;
using System.Text;

const string CONN_STR = "Host=localhost;Port=5432;Database=lab9db;Username=lab9user;Password=lab9pass;Pooling=false;";

// ─── Форматирует DataTable в строку ───────────────────────────────────────
string TblStr(DataTable t)
{
    var s = new StringBuilder();
    s.AppendLine($"{"Id",-5} {"Имя",-14} {"Фамилия",-16} {"Возраст",-10} {"Оценка"}");
    s.AppendLine(new string('-', 55));
    foreach (DataRow r in t.Rows)
        s.AppendLine($"{r["id"],-5} {r["firstname"],-14} {r["lastname"],-16} {r["age"],-10} {r["grade"]}");
    return s.ToString();
}

// ─── Загружает всю таблицу через DataSet ──────────────────────────────────
DataTable Load()
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    var a = new NpgsqlDataAdapter("SELECT * FROM Students ORDER BY Id", c);
    var ds = new DataSet(); a.Fill(ds, "Students");
    return ds.Tables["Students"]!.Copy();
}

// ══ ВСЕ ОПЕРАЦИИ С БД СНАЧАЛА ═══════════════════════════════════════════

// Инициализация: пересоздать таблицу и заполнить 3 строками
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    using var cmd = new NpgsqlCommand("""
        DROP TABLE IF EXISTS Students;
        CREATE TABLE Students(
            Id        SERIAL PRIMARY KEY,
            FirstName VARCHAR(50) NOT NULL,
            LastName  VARCHAR(50) NOT NULL,
            Age       INTEGER     NOT NULL,
            Grade     VARCHAR(5)  NOT NULL
        );
        INSERT INTO Students(FirstName,LastName,Age,Grade) VALUES
            ('Иван',   'Петров',   19, '4'),
            ('Мария',  'Сидорова', 20, '5'),
            ('Алексей','Козлов',   21, '3');
        """, c);
    cmd.ExecuteNonQuery();
}
DataTable stateInit = Load();

// Задание 1: DataReader
string task1rows;
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    using var cmd = new NpgsqlCommand("SELECT * FROM Students ORDER BY Id", c);
    using var dr = cmd.ExecuteReader();
    var sb = new StringBuilder();
    sb.AppendLine($"{"Id",-5} {"Имя",-14} {"Фамилия",-16} {"Возраст",-10} {"Оценка"}");
    sb.AppendLine(new string('-', 55));
    while (dr.Read())
        sb.AppendLine($"{dr["id"],-5} {dr["firstname"],-14} {dr["lastname"],-16} {dr["age"],-10} {dr["grade"]}");
    task1rows = sb.ToString();
}

// Задание 2: DataSet/DataAdapter — просто загрузка
DataTable stateTask2 = Load();

// Задание 3: добавить 2 строки через DataSet + Update
DataTable before3 = Load();
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    var a = new NpgsqlDataAdapter("SELECT * FROM Students ORDER BY Id", c);
    new NpgsqlCommandBuilder(a);
    var ds = new DataSet(); a.Fill(ds, "Students");
    var t = ds.Tables["Students"]!;
    var r1 = t.NewRow(); r1["firstname"]="Ольга";   r1["lastname"]="Иванова"; r1["age"]=20; r1["grade"]="5"; t.Rows.Add(r1);
    var r2 = t.NewRow(); r2["firstname"]="Дмитрий"; r2["lastname"]="Фролов";  r2["age"]=22; r2["grade"]="4"; t.Rows.Add(r2);
    a.Update(ds, "Students");
}
DataTable after3 = Load();

// Задание 4: удалить строку Id=2 через DataRow.Delete + Update
DataTable before4 = Load();
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    var a = new NpgsqlDataAdapter("SELECT * FROM Students ORDER BY Id", c);
    new NpgsqlCommandBuilder(a);
    var ds = new DataSet(); a.Fill(ds, "Students");
    var t = ds.Tables["Students"]!;
    foreach (DataRow row in t.Rows)
        if (Convert.ToInt32(row["id"]) == 2) { row.Delete(); break; }
    a.Update(ds, "Students");
}
DataTable after4 = Load();

// ══ ВЕСЬ ВЫВОД ПОТОМ ════════════════════════════════════════════════════
var out_ = new StringBuilder();

out_.AppendLine("=== Состояние после инициализации ===");
out_.Append(TblStr(stateInit));

out_.AppendLine("\n=== Задание 1: DataReader — чтение всех записей ===");
out_.Append(task1rows);

out_.AppendLine("\n=== Задание 2: DataSet/DataAdapter — загрузка таблицы ===");
out_.Append(TblStr(stateTask2));

out_.AppendLine("\n=== Задание 3: добавление строк (до) ===");
out_.Append(TblStr(before3));
out_.AppendLine("=== Задание 3: добавление строк (после) ===");
out_.Append(TblStr(after3));

out_.AppendLine("\n=== Задание 4: удаление строки Id=2 (до) ===");
out_.Append(TblStr(before4));
out_.AppendLine("=== Задание 4: удаление строки Id=2 (после) ===");
out_.Append(TblStr(after4));

Console.Write(out_.ToString());
