using System.Data;

namespace DevelopmentLessonTask10626
{
    class Program
    {
        static void Main(string[] args)
        {
            DataSet usersSet = new DataSet("UsersSet");
            DataTable users = new DataTable("Users");
            // добавляем таблицу в dataset
            usersSet.Tables.Add(users);

            // создаем столбцы для таблицы Users
            DataColumn idColumn = new DataColumn("Id", Type.GetType("System.Int32"));
            idColumn.Unique = true; // столбец будет иметь уникальное значение
            idColumn.AllowDBNull = false; // не может принимать null
            idColumn.AutoIncrement = true; // будет автоинкрементироваться
            idColumn.AutoIncrementSeed = 1; // начальное значение
            idColumn.AutoIncrementStep = 1; // приращении при добавлении новой строки

            DataColumn nameColumn = new DataColumn("Name", Type.GetType("System.String"));
            DataColumn ageColumn = new DataColumn("Age", Type.GetType("System.Int32"));
            ageColumn.DefaultValue = 1; // значение по умолчанию

            users.Columns.Add(idColumn);
            users.Columns.Add(nameColumn);
            users.Columns.Add(ageColumn);
            // определяем первичный ключ таблицы Users
            users.PrimaryKey = new DataColumn[] { users.Columns["Id"] };

            DataRow row = users.NewRow();
            row.ItemArray = new object[] { null, "Tom", 36 };
            users.Rows.Add(row); // добавляем первую строку
            users.Rows.Add(new object[] { null, "Bob", 29 }); // добавляем вторую строку

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