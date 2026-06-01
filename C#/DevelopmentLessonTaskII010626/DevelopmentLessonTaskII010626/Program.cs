using System;
using System.Data;
using Npgsql;

namespace DevelopmentLessonTaskII010626
{
    class Program
    {
        static void Main(string[] args)
        {
            string connectionString = "";
            string sql = "SELECT * FROM Users";
            using (NpgsqlConnection connection = new NpgsqlConnection(connectionString))
            {
                // Создаем объект DataAdapter
                NpgsqlDataAdapter adapter = new NpgsqlDataAdapter(sql, connection);
                // Создаем объект Dataset
                DataSet ds = new DataSet();
                // Заполняем Dataset
                adapter.Fill(ds);
                DataTable dt = ds.Tables[0];
                // добавим новую строку
                DataRow newRow = dt.NewRow();
                newRow["Name"] = "Rick";
                newRow["Age"] = 24;
                dt.Rows.Add(newRow);
                // Изменим значение в столбце Age для первой строки
                dt.Rows[0]["Age"] = 17;
                // создаем объект SqlCommandBuilder
                NpgsqlCommandBuilder commandBuilder = new NpgsqlCommandBuilder(adapter);
                adapter.Update(ds);
                // альтернативный способ - обновление только одной таблицы
                //adapter.Update(dt);
                // заново получаем данные из бд
                // очищаем полностью DataSet
                ds.Clear();
                // перезагружаем данные
                adapter.Fill(ds);
                // Отображаем данные
                // перебор всех таблиц
                foreach (DataColumn column in dt.Columns)
                    Console.Write($"{column.ColumnName}\t");
                Console.WriteLine();
                // перебор всех строк таблицы
                foreach (DataRow row in dt.Rows)
                {
                    // получаем все ячейки строки
                    var cells = row.ItemArray;
                    foreach (object cell in cells)
                        Console.Write($"{cell}\t");
                    Console.WriteLine();
                }
                Console.Read();
            }
        }
    }
}