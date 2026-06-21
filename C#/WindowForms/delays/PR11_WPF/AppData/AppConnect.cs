using Microsoft.Data.Sqlite;
using System;
using System.IO;

namespace PR11.AppData;

/// <summary>
/// Подключение к SQLite БД (вместо MS SQL Server для портабельности).
/// Логика та же: таблицы User и Role, LINQ-подобные запросы через ADO.
/// </summary>
public static class AppConnect
{
    private static readonly string DbPath = Path.Combine(
        AppDomain.CurrentDomain.BaseDirectory, "UserDatabase.db");

    public static SqliteConnection GetConnection() => new($"Data Source={DbPath}");

    /// <summary>Инициализация БД при первом запуске</summary>
    public static void Initialize()
    {
        using var conn = GetConnection();
        conn.Open();

        var cmd = conn.CreateCommand();
        cmd.CommandText = @"
            CREATE TABLE IF NOT EXISTS Role (
                idRole   INTEGER PRIMARY KEY AUTOINCREMENT,
                RoleName TEXT NOT NULL
            );
            CREATE TABLE IF NOT EXISTS User (
                idUser   INTEGER PRIMARY KEY AUTOINCREMENT,
                Name     TEXT NOT NULL,
                Login    TEXT NOT NULL UNIQUE,
                Password TEXT NOT NULL,
                idRole   INTEGER NOT NULL REFERENCES Role(idRole)
            );
            INSERT OR IGNORE INTO Role (idRole, RoleName) VALUES (1, 'Администратор');
            INSERT OR IGNORE INTO Role (idRole, RoleName) VALUES (2, 'Ученик');
            INSERT OR IGNORE INTO User (Name, Login, Password, idRole)
                SELECT 'Степан', 'admin', 'admin123', 1
                WHERE NOT EXISTS (SELECT 1 FROM User WHERE Login='admin');
            INSERT OR IGNORE INTO User (Name, Login, Password, idRole)
                SELECT 'Наталья', 'student', 'pass123', 2
                WHERE NOT EXISTS (SELECT 1 FROM User WHERE Login='student');";
        cmd.ExecuteNonQuery();
    }
}
