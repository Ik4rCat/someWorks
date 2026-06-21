using System;
using System.Drawing;
using System.Windows.Forms;

/// <summary>
/// Задание 3: Калькулятор со скидкой.
/// TextBox для суммы, RadioButton для % скидки, вывод итога.
/// </summary>
public class Task3_Discount : Form
{
    public Task3_Discount()
    {
        Text = "Задание 3: Калькулятор со скидкой";
        ClientSize = new Size(380, 320);
        StartPosition = FormStartPosition.CenterScreen;
        FormBorderStyle = FormBorderStyle.FixedSingle;
        MaximizeBox = false;

        var lblSum = new Label { Text = "Сумма покупки (руб.):", Location = new Point(16, 16), AutoSize = true };
        var txtSum = new TextBox { Location = new Point(16, 38), Size = new Size(344, 26) };

        // Только цифры
        txtSum.KeyPress += (_, e) =>
        {
            if (!char.IsDigit(e.KeyChar) && e.KeyChar != '.' && e.KeyChar != '\b')
                e.Handled = true;
        };

        var grp = new GroupBox { Text = "Размер скидки", Location = new Point(16, 76), Size = new Size(344, 120) };
        int[] discounts = { 0, 5, 10, 15, 20 };
        var radios = new RadioButton[discounts.Length];
        for (int i = 0; i < discounts.Length; i++)
        {
            radios[i] = new RadioButton
            {
                Text = $"{discounts[i]}%",
                Location = new Point(12 + i * 66, 30),
                AutoSize = true
            };
            grp.Controls.Add(radios[i]);
        }
        radios[0].Checked = true;

        var lblResult = new Label
        {
            Location = new Point(16, 208),
            Size = new Size(344, 60),
            Font = new Font("Segoe UI", 12),
            TextAlign = ContentAlignment.MiddleCenter,
            BackColor = Color.White,
            BorderStyle = BorderStyle.FixedSingle
        };

        var btnCalc = new Button { Text = "Рассчитать", Location = new Point(16, 274), Size = new Size(344, 36) };
        btnCalc.Click += (_, _) =>
        {
            if (!decimal.TryParse(txtSum.Text.Replace('.', ','), out decimal sum))
            {
                MessageBox.Show("Введите корректную сумму.", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            int discount = 0;
            for (int i = 0; i < radios.Length; i++)
                if (radios[i].Checked) discount = discounts[i];

            decimal discountAmt = sum * discount / 100m;
            decimal total = sum - discountAmt;
            lblResult.Text = $"Скидка {discount}%: −{discountAmt:F2} руб.   Итого: {total:F2} руб.";
        };

        Controls.AddRange(new Control[] { lblSum, txtSum, grp, lblResult, btnCalc });
    }
}
