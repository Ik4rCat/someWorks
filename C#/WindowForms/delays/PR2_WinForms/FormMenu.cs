using System;
using System.Windows.Forms;

public class FormMenu : Form
{
    public FormMenu()
    {
        Text = "ПР2 — Выберите задание";
        ClientSize = new System.Drawing.Size(300, 240);
        StartPosition = FormStartPosition.CenterScreen;
        FormBorderStyle = FormBorderStyle.FixedSingle;
        MaximizeBox = false;

        var panel = new FlowLayoutPanel
        {
            Dock = DockStyle.Fill,
            FlowDirection = FlowDirection.TopDown,
            Padding = new Padding(20),
            WrapContents = false
        };

        (string text, Func<Form> factory)[] items =
        {
            ("Задание 1: Составить сообщение",  () => new Task1_MessageSelector()),
            ("Задание 2: Заказ в кафе",          () => new Task2_CafeOrder()),
            ("Задание 3: Калькулятор со скидкой",() => new Task3_Discount()),
            ("Задание 4: Форма регистрации",     () => new Task4_Registration()),
        };

        foreach (var (text, factory) in items)
        {
            var btn = new Button { Text = text, Width = 255, Height = 44, Margin = new Padding(0, 0, 0, 6) };
            var f = factory;
            btn.Click += (_, _) => f().Show();
            panel.Controls.Add(btn);
        }

        Controls.Add(panel);
    }
}
