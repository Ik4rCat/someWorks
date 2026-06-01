using System;
using System.Data;

namespace DevelopmentLessonTaskII010626
{
    class Program
    {
        static void Main(string[] args)
        {
            DataSet usersSet = new DataSet("UsersSet");
            DataTable users = new DataTable("Users");
            usersSet.Tables.Add(users);

            DataColumn idColumn = new DataColumn("Id", Type.GetType("System.Int32"));
            idColumn.Unique = true;
            idColumn.AllowDBNull = false;
            idColumn.AutoIncrement = true;
            idColumn.AutoIncrementSeed = 1;
            idColumn.AutoIncrementStep = 1;

            DataColumn nameColumn = new DataColumn("Name", Type.GetType("System.String"));
            DataColumn ageColumn = new DataColumn("Age", Type.GetType("System.Int32"));
            ageColumn.DefaultValue = 1;

            users.Columns.Add(idColumn);
            users.Columns.Add(nameColumn);
            users.Columns.Add(ageColumn);
            users.PrimaryKey = new DataColumn[] { users.Columns["Id"] };

            DataRow row = users.NewRow();
            row.ItemArray = new object[] { null, "Tom", 36 };
            users.Rows.Add(row);
            users.Rows.Add(new object[] { null, "Bob", 29 });

            Console.Write("Id\t Имя\t Возраст\t");
            Console.WriteLine();
            foreach (DataRow r in users.Rows)
            {
                foreach (var cell in r.ItemArray)
                    Console.Write("{0}\t", cell);
                Console.WriteLine();
            }
            Console.Read();
        }
    }
}