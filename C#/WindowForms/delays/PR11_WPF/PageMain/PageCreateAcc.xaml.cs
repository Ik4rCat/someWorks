using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using Microsoft.Data.Sqlite;
using PR11.AppData;

namespace PR11.PageMain;

public partial class PageCreateAcc : Page
{
    public PageCreateAcc() => InitializeComponent();

    // Подсветка поля подтверждения пароля
    private void pbConfirm_Changed(object sender, RoutedEventArgs e)
    {
        bool match = pbConfirm.Password == txtPassword.Text;
        pbConfirm.BorderBrush = new SolidColorBrush(match ? Colors.Green : Colors.Red);
        btnCreate.IsEnabled   = match && pbConfirm.Password.Length > 0;
    }

    private void Create_Click(object sender, RoutedEventArgs e)
    {
        lblError.Text = "";

        if (string.IsNullOrWhiteSpace(txtName.Text)  ||
            string.IsNullOrWhiteSpace(txtLogin.Text) ||
            string.IsNullOrWhiteSpace(txtPassword.Text))
        {
            lblError.Text = "Заполните все поля.";
            return;
        }

        try
        {
            using var conn = AppConnect.GetConnection();
            conn.Open();

            // Проверяем, нет ли такого логина
            var checkCmd = conn.CreateCommand();
            checkCmd.CommandText = "SELECT COUNT(*) FROM User WHERE Login=@l";
            checkCmd.Parameters.AddWithValue("@l", txtLogin.Text.Trim());
            long count = (long)checkCmd.ExecuteScalar()!;
            if (count > 0)
            {
                lblError.Text = "Пользователь с таким логином уже существует.";
                return;
            }

            // Добавляем нового ученика (idRole=2)
            var insertCmd = conn.CreateCommand();
            insertCmd.CommandText = "INSERT INTO User (Name, Login, Password, idRole) VALUES (@n, @l, @p, 2)";
            insertCmd.Parameters.AddWithValue("@n", txtName.Text.Trim());
            insertCmd.Parameters.AddWithValue("@l", txtLogin.Text.Trim());
            insertCmd.Parameters.AddWithValue("@p", txtPassword.Text);
            insertCmd.ExecuteNonQuery();

            MessageBox.Show("Аккаунт создан! Теперь вы можете войти.", "Готово",
                            MessageBoxButton.OK, MessageBoxImage.Information);

            AppFrame.FrmMain?.Navigate(new PageLogin());
        }
        catch (Exception ex)
        {
            lblError.Text = $"Ошибка: {ex.Message}";
        }
    }

    private void Back_Click(object sender, RoutedEventArgs e)
        => AppFrame.FrmMain?.Navigate(new PageLogin());
}
