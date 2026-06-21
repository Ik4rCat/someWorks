using System;
using System.Drawing;
using System.Windows.Forms;

/// <summary>
/// Задание 2: Демонстрация 5+ свойств Button.
/// Кнопки изменяют свойства друг друга.
/// </summary>
public class Task2_ButtonProps : Form
{
    private readonly Button target;

    public Task2_ButtonProps()
    {
        Text = "Задание 2: Свойства Button";
        ClientSize = new Size(560, 400);
        StartPosition = FormStartPosition.CenterScreen;

        // Кнопка-цель, свойства которой изменяются
        target = new Button
        {
            Text = "Я — целевая кнопка",
            Location = new Point(170, 170),
            Size = new Size(220, 60),
            Font = new Font("Arial", 12),
            BackColor = Color.LightGreen,
            ForeColor = Color.Black,
            FlatStyle = FlatStyle.Standard,
            Cursor = Cursors.Hand
        };

        // Кнопки, изменяющие свойства
        var btnText = MakeBtn("1. Изменить Text", new Point(20, 20));
        btnText.Click += (_, _) =>
        {
            target.Text = target.Text == "Я — целевая кнопка"
                ? "Текст изменён!" : "Я — целевая кнопка";
        };

        var btnBack = MakeBtn("2. BackColor", new Point(20, 70));
        btnBack.Click += (_, _) =>
        {
            target.BackColor = target.BackColor == Color.LightGreen
                ? Color.Tomato : Color.LightGreen;
        };

        var btnFore = MakeBtn("3. ForeColor", new Point(20, 120));
        btnFore.Click += (_, _) =>
        {
            target.ForeColor = target.ForeColor == Color.Black
                ? Color.White : Color.Black;
        };

        var btnFont = MakeBtn("4. Font (Bold)", new Point(20, 170));
        btnFont.Click += (_, _) =>
        {
            target.Font = target.Font.Bold
                ? new Font("Arial", 12, FontStyle.Regular)
                : new Font("Arial", 12, FontStyle.Bold);
        };

        var btnEnabled = MakeBtn("5. Enabled ↔ Disabled", new Point(20, 220));
        btnEnabled.Click += (_, _) =>
        {
            target.Enabled = !target.Enabled;
        };

        var btnFlat = MakeBtn("6. FlatStyle", new Point(20, 270));
        btnFlat.Click += (_, _) =>
        {
            target.FlatStyle = target.FlatStyle == FlatStyle.Standard
                ? FlatStyle.Flat : FlatStyle.Standard;
        };

        var btnSize = MakeBtn("7. Size", new Point(20, 320));
        btnSize.Click += (_, _) =>
        {
            target.Size = target.Width == 220
                ? new Size(280, 80) : new Size(220, 60);
        };

        var btnVisible = MakeBtn("8. Visible (мигнуть)", new Point(20, 370));
        btnVisible.Click += async (_, _) =>
        {
            target.Visible = false;
            await System.Threading.Tasks.Task.Delay(500);
            target.Visible = true;
        };

        Controls.AddRange(new Control[]
        {
            target,
            btnText, btnBack, btnFore, btnFont,
            btnEnabled, btnFlat, btnSize, btnVisible
        });
    }

    private static Button MakeBtn(string text, Point loc)
        => new Button { Text = text, Location = loc, Size = new Size(140, 38) };
}
