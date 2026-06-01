using Npgsql;
using System.Data;
using System.Text;

const string CONN_STR = "Host=localhost;Port=5432;Database=lab9db;Username=lab9user;Password=lab9pass;Pooling=false;";
var out_ = new StringBuilder();

string TblStr(DataTable t)
{
    var s = new StringBuilder();
    s.AppendLine($"{"Id",-5} {"Имя",-14} {"Фамилия",-16} {"Возраст",-10} {"Оценка"}");
    s.AppendLine(new string('-', 55));
    foreach (DataRow r in t.Rows)
        s.AppendLine($"{r["id"],-5} {r["firstname"],-14} {r["lastname"],-16} {r["age"],-10} {r["grade"]}");
    return s.ToString();
}

DataTable Load()
{
    using var c = new NpgsqlConnection(CONN_STR);
    var a = new NpgsqlDataAdapter("SELECT * FROM Students ORDER BY Id", c);
    var ds = new DataSet(); a.Fill(ds, "Students");
    return ds.Tables["Students"]!.Copy();
}

// ── Все DB-операции СНАЧАЛА ──────────────────────────────────

// init
DataTable stateInit;
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    using var cmd = new NpgsqlCommand("""
        DROP TABLE IF EXISTS Students;
        CREATE TABLE Students(Id SERIAL PRIMARY KEY,FirstName VARCHAR(50) NOT NULL,LastName VARCHAR(50) NOT NULL,Age INTEGER NOT NULL,Grade VARCHAR(5) NOT NULL);
        INSERT INTO Students(FirstName,LastName,Age,Grade) VALUES('Иван','Петров',19,'4'),('Мария','Сидорова',20,'5'),('Алексей','Козлов',21,'3');
    """, c);
    cmd.ExecuteNonQuery();
}
stateInit = Load();

// task1
string task1rows;
{
    using var c = new NpgsqlConnection(CONN_STR); c.Open();
    using var cmd = new NpgsqlCommand("SELECT * FROM Students ORDER BY Id", c);
    using var r = cmd.ExecuteReader();
    var sb = new StringBuilder();
    sb.AppendLine($"{"Id",-5} {"Имя",-14} {"Фамилия",-16} {"Возраст",-10} {"Оценка"}");
    sb.AppendLine(new string('-', 55));
    while (r.Read())
        sb.AppendLine($"{r["id"],-5} {r["firstname"],-14} {r["lastname"],-16} {r["age"],-10} {r["grade"]}");
    task1rows = sb.ToString();
}

// task2
DataTable stateTask2 = Load();

// task3
DataTable before3 = Load();
{
    using var c = new NpgsqlConnection(CONN_STR);
    var a = new NpgsqlDataAdapter("SELECT * FROM Students ORDER BY Id", c);
    new NpgsqlCommandBuilder(a);
    var ds = new DataSet(); a.Fill(ds, "Students");
    var t = ds.Tables["Students"]!;
    var r1=t.NewRow(); r1["firstname"]="Екатерина"; r1["lastname"]="Новикова"; r1["age"]=19; r1["grade"]="5"; t.Rows.Add(r1);
    var r2=t.NewRow(); r2["firstname"]="Дмитрий"; r2["lastname"]="Фролов"; r2["age"]=22; r2["grade"]="4"; t.Rows.Add(r2);
    a.Update(ds,"Students");
}
DataTable after3 = Load();

// task4
DataTable before4 = Load();
{
    using var c = new NpgsqlConnection(CONN_STR);
    var a = new NpgsqlDataAdapter("SELECT * FROM Students ORDER BY Id", c);
    new NpgsqlCommandBuilder(a);
    var ds = new DataSet(); a.Fill(ds,"Students");
    var t = ds.Tables["Students"]!;
    foreach (DataRow r in t.Rows)
        if (Convert.ToInt32(r["id"])==2) { r.Delete(); break; }
    a.Update(ds,"Students");
}
DataTable after4 = Load();

// ── Теперь весь вывод ──────────────────────────────────────

out_.AppendLine("=== ИНИЦИАЛИЗАЦИЯ БД ===");
out_.AppendLine($"Таблица Students создана. Начальное состояние ({stateInit.Rows.Count} записей):");
out_.Append(TblStr(stateInit));

out_.AppendLine("═══════════════════════════════════════════════════════");
out_.AppendLine("ЗАДАНИЕ 1 — Вывод всех строк через DataReader");
out_.AppendLine("═══════════════════════════════════════════════════════");
out_.Append(task1rows);

out_.AppendLine("═══════════════════════════════════════════════════════");
out_.AppendLine("ЗАДАНИЕ 2 — DataSet через DataAdapter");
out_.AppendLine("═══════════════════════════════════════════════════════");
out_.AppendLine($"Загружено строк через DataAdapter: {stateTask2.Rows.Count}");
out_.Append(TblStr(stateTask2));

out_.AppendLine("═══════════════════════════════════════════════════════");
out_.AppendLine("ЗАДАНИЕ 3 — Добавление двух записей через DataSet + Update()");
out_.AppendLine("═══════════════════════════════════════════════════════");
out_.AppendLine($"Состояние ДО добавления ({before3.Rows.Count} записей):");
out_.Append(TblStr(before3));
out_.AppendLine("Добавлены записи: Екатерина Новикова (19, отл.), Дмитрий Фролов (22, хор.)");
out_.AppendLine("Вызван adapter.Update() — изменения сохранены в БД.");
out_.AppendLine($"Состояние ПОСЛЕ добавления ({after3.Rows.Count} записей):");
out_.Append(TblStr(after3));

out_.AppendLine("═══════════════════════════════════════════════════════");
out_.AppendLine("ЗАДАНИЕ 4 — Удаление записи Id=2 через DataRow.Delete() + Update()");
out_.AppendLine("═══════════════════════════════════════════════════════");
out_.AppendLine($"Состояние ДО удаления ({before4.Rows.Count} записей):");
out_.Append(TblStr(before4));
out_.AppendLine("Найдена строка Id=2 (Мария Сидорова). Вызван DataRow.Delete() + Update().");
out_.AppendLine($"Состояние ПОСЛЕ удаления ({after4.Rows.Count} записей):");
out_.Append(TblStr(after4));
out_.AppendLine("Все задания выполнены.");

Console.Write(out_.ToString());
