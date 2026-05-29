using Npgsql;
using System.Data;
using NpgsqlTypes;

namespace ConcoleA
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string connectionString = "host=localhost;Database=tt; port=5432;UserName=postgres;Password=12345";
            Console.WriteLine("____________");
            using var conn = new NpgsqlConnection(connectionString);

            //Параметры
            string strSQL1 = "SELECT * FROM @Name";
            using var Command = new NpgsqlCommand(strSQL1, conn);
            Command.Parameters.AddWithValue("Name", "Ret");
            Command.Parameters.Add("FD", NpgsqlDbType.Integer).Value = 0;

            //Процедуры и функции
            using (NpgsqlConnection con = new NpgsqlConnection(connectionString))
            {
                
                string createProc = @"
                    CREATE OR REPLACE PROCEDURE get_fa(p_name VARCHAR(100))
                        LANGUAGE plpgsql
                        AS $$       
                        DECLARE
                            t_d  INTEGER;
                        BEGIN
                            SELECT COUNT(*) 
                            FROM ww
             
                        END;
                        $$";


                //@"CREATE OR REPLACE FUNCTION get_fa(p_name VARCHAR(100))
                //        RETURN INTEGER
                //        LANGUAGE plpgsql
                //        AS $$
                //        DECLARE
                //            t_d  INTEGER;
                //        BEGIN
                //           SELECT COUNT(*) INTO t_d
                //           FROM ww
                //          RETURN t_d;

                //        END;
                //$$";


                //Возвратный параметр 
                //@"CREATE OR REPLACE FUNCTION get_fa(p_name VARCHAR(100) result OUT INTEGER)
                //        RETURN INTEGER
                //        LANGUAGE plpgsql
                //        AS $$
                //        
                //        BEGIN
                //           SELECT COUNT(*) INTO result
                //           FROM ww

                //        END;
                //$$";
                using (var v = new NpgsqlCommand(createProc, con))
                {
                    con.Open();
                    v.ExecuteNonQuery();
                    con.Close();
                }

                using (var cmd = new NpgsqlCommand("CALL get_fa(@p_n)", con))
                {
                    cmd.Parameters.AddWithValue("p_n", "dd");

                    con.Open();
                    cmd.ExecuteNonQuery();

                    // работа с функцией возвратной
                    //+++
                    //int i = Convert.ToInt32(cmd.ExecuteScalar());
                    //Console.WriteLine(i);

                    ////Работа с возвратными пармаметром
                    ///+++
                    //var resultPar = new NpgsqlParameter("result", NpgsqlDbType.Integer);
                    //resultPar.Direction = ParameterDirection.Output;
                    //cmd.Parameters.Add(resultPar);

                    //con.Open();
                    //cmd.ExecuteNonQuery(); // не возвращает значение

                    //int sum = (int)resultPar.Value;
                    con.Close();
                }

                // если не создаем функцию
                //var ca = new NpgsqlCommand("SELECT fgrty()", con);
                //ca.CommandType = System.Data.CommandType.StoredProcedure; 
            }
        }
    }
}
