using System;
using System.Drawing;
using System.Windows.Forms;

/// <summary>
/// Задание 2: Форма заказа в кафе.
/// CheckBox для блюд, кнопка расчёта суммы.
/// </summary>
public class Task2_CafeOrder : Form
{
    public Task2_CafeOrder()
    {
        Text = "Задание 2: Заказ в кафе";
        ClientSize = new Size(380, 420);
        StartPosition = FormStartPosition.CenterScreen;
        FormBorderStyle = FormBorderStyle.FixedSingle;
        MaximizeBox = false;

        var grp = new GroupBox { Text = "Меню", Location = new Point(16, 12), Size = new Size(344, 300) };

        (string name, decimal price)[] dishes =
        {
            ("Борщ",                   150m),
            ("Суп куриный",            120m),
            ("Котлета с гарниром",     280m),
            ("Рыба жареная",           320m),
            ("Салат «Цезарь»",        240m),
            ("Пюре картофельное",       90m),
            ("Компот",                  60m),
            ("Чай / кофе",              80m),
        };

        var checkboxes = new CheckBox[dishes.Length];
        for (int i = 0; i < dishes.Length; i++)
        {
            var (name, price) = dishes[i];
            checkboxes[i] = new CheckBox
            {
                Text = $"{name}  —  {price} руб.",
                Location = new Point(12, 24 + i * 32),
                AutoSize = true
            };
            grp.Controls.Add(checkboxes[i]);
        }

        var lblTotal = new Label
        {
            Text = "Итого: 0 руб.",
            Location = new Point(16, 322),
            Size = new Size(344, 38),
            Font = new Font("Segoe UI", 13, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleCenter,
            BackColor = Color.LightYellow,
            BorderStyle = BorderStyle.FixedSingle
        };

        var btnCalc = new Button { Text = "Подсчитать", Location = new Point(16, 370), Size = new Size(344, 36) };
        btnCalc.Click += (_, _) =>
        {
            decimal total = 0;
            for (int i = 0; i < checkboxes.Length; i++)
                if (checkboxes[i].Checked) total += dishes[i].price;
            lblTotal.Text = $"Итого: {total} руб.";
        };

        Controls.AddRange(new Control[] { grp, lblTotal, btnCalc });
    }
}
