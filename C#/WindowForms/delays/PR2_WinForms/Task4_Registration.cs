using System;
using System.Drawing;
using System.Text.RegularExpressions;
using System.Windows.Forms;

/// <summary>
/// Задание 4: Форма регистрации с валидацией.
/// Поля: Имя, Email, Телефон, Пароль, Подтверждение пароля.
/// </summary>
public class Task4_Registration : Form
{
    private readonly TextBox txtName, txtEmail, txtPhone, txtPass, txtPass2;
    private readonly Label   lblError;

    public Task4_Registration()
    {
        Text = "Задание 4: Форма регистрации";
        ClientSize = new Size(400, 420);
        StartPosition = FormStartPosition.CenterScreen;
        FormBorderStyle = FormBorderStyle.FixedSingle;
        MaximizeBox = false;

        int y = 16;
        txtName  = AddField("Имя:",                  ref y, false);
        txtEmail = AddField("Email:",                 ref y, false);
        txtPhone = AddField("Телефон (+7...):",       ref y, false);
        txtPass  = AddField("Пароль:",                ref y, true);
        txtPass2 = AddField("Подтверждение пароля:", ref y, true);

        // Подсветка совпадения паролей
        txtPass2.TextChanged += (_, _) =>
        {
            txtPass2.BackColor = txtPass2.Text == txtPass.Text
                ? Color.LightGreen : Color.LightCoral;
        };

        lblError = new Label
        {
            Location = new Point(16, y + 4),
            Size = new Size(368, 44),
            ForeColor = Color.Red,
            Font = new Font("Segoe UI", 9)
        };

        var btnRegister = new Button { Text = "Зарегистрироваться", Location = new Point(16, y + 54), Size = new Size(368, 38) };
        btnRegister.Click += OnRegister;

        Controls.AddRange(new Control[] { lblError, btnRegister });
    }

    private TextBox AddField(string label, ref int y, bool isPassword)
    {
        Controls.Add(new Label { Text = label, Location = new Point(16, y), AutoSize = true });
        y += 22;
        var txt = new TextBox
        {
            Location = new Point(16, y),
            Size = new Size(368, 26),
            UseSystemPasswordChar = isPassword
        };
        Controls.Add(txt);
        y += 38;
        return txt;
    }

    private void OnRegister(object? sender, EventArgs e)
    {
        lblError.Text = "";

        if (string.IsNullOrWhiteSpace(txtName.Text))
        { lblError.Text = "Введите имя."; return; }

        if (!Regex.IsMatch(txtEmail.Text, @"^[^@\s]+@[^@\s]+\.[^@\s]+$"))
        { lblError.Text = "Некорректный email."; return; }

        if (!Regex.IsMatch(txtPhone.Text, @"^\+7\d{10}$"))
        { lblError.Text = "Телефон должен быть в формате +7XXXXXXXXXX."; return; }

        if (txtPass.Text.Length < 6)
        { lblError.Text = "Пароль должен содержать не менее 6 символов."; return; }

        if (txtPass.Text != txtPass2.Text)
        { lblError.Text = "Пароли не совпадают."; return; }

        MessageBox.Show(
            $"Регистрация успешна!\nИмя: {txtName.Text}\nEmail: {txtEmail.Text}",
            "Готово", MessageBoxButtons.OK, MessageBoxIcon.Information);
    }
}
