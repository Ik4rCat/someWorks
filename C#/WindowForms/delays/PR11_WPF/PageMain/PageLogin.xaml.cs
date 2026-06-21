using System;
using System.Windows;
using System.Windows.Controls;
using Microsoft.Data.Sqlite;
using PR11.AppData;
using PR11.PageAdmin;
using PR11.PageStudent;

namespace PR11.PageMain;

public partial class PageLogin : Page
{
    public PageLogin() => InitializeComponent();

    private void Login_Click(object sender, RoutedEventArgs e)
    {
        lblError.Text = "";
        try
        {
            using var conn = AppConnect.GetConnection();
            conn.Open();

            var cmd = conn.CreateCommand();
            cmd.CommandText = "SELECT idUser, Name, idRole FROM User WHERE Login=@l AND Password=@p";
            cmd.Parameters.AddWithValue("@l", txtLogin.Text.Trim());
            cmd.Parameters.AddWithValue("@p", pbPassword.Password);

            using var reader = cmd.ExecuteReader();
            if (!reader.Read())
            {
                lblError.Text = "Неверный логин или пароль.";
                return;
            }

            string name   = reader.GetString(1);
            int    idRole = reader.GetInt32(2);

            MessageBox.Show($"Добро пожаловать, {name}!", "Вход выполнен",
                            MessageBoxButton.OK, MessageBoxImage.Information);

            // Навигация в зависимости от роли
            if (idRole == 1)
                AppFrame.FrmMain?.Navigate(new PageMenuAdmin(name));
            else
                AppFrame.FrmMain?.Navigate(new PageAccountStudent(name));
        }
        catch (Exception ex)
        {
            lblError.Text = $"Ошибка: {ex.Message}";
        }
    }

    private void Register_Click(object sender, RoutedEventArgs e)
        => AppFrame.FrmMain?.Navigate(new PageCreateAcc());
}
