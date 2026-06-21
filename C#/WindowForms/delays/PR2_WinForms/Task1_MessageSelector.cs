using System.Drawing;
using System.Windows.Forms;

/// <summary>
/// Задание 1: Составление приветственного сообщения.
/// RadioButton для выбора части суток, CheckBox для обращения, TextBox для имени.
/// </summary>
public class Task1_MessageSelector : Form
{
    public Task1_MessageSelector()
    {
        Text = "Задание 1: Составить сообщение";
        ClientSize = new Size(420, 360);
        StartPosition = FormStartPosition.CenterScreen;
        FormBorderStyle = FormBorderStyle.FixedSingle;
        MaximizeBox = false;

        // --- Часть суток ---
        var grpTime = new GroupBox { Text = "Часть суток", Location = new Point(16, 12), Size = new Size(180, 130) };
        var rbMorning = new RadioButton { Text = "Доброе утро",  Location = new Point(12, 24), Checked = true };
        var rbDay     = new RadioButton { Text = "Добрый день",  Location = new Point(12, 48) };
        var rbEvening = new RadioButton { Text = "Добрый вечер", Location = new Point(12, 72) };
        var rbNight   = new RadioButton { Text = "Спокойной ночи", Location = new Point(12, 96) };
        grpTime.Controls.AddRange(new Control[] { rbMorning, rbDay, rbEvening, rbNight });

        // --- Обращение ---
        var grpTitle = new GroupBox { Text = "Обращение", Location = new Point(210, 12), Size = new Size(190, 130) };
        var cbRespected = new CheckBox { Text = "Уважаемый", Location = new Point(12, 24) };
        var cbDear      = new CheckBox { Text = "Дорогой",   Location = new Point(12, 52) };
        var cbMister    = new CheckBox { Text = "Господин",  Location = new Point(12, 80) };
        grpTitle.Controls.AddRange(new Control[] { cbRespected, cbDear, cbMister });

        // --- Имя ---
        var lblName = new Label  { Text = "Имя:", Location = new Point(16, 158), AutoSize = true };
        var txtName = new TextBox { Location = new Point(16, 178), Size = new Size(380, 26), Text = "Иван" };

        // --- Результат ---
        var lblResult = new Label
        {
            Location = new Point(16, 220),
            Size = new Size(384, 60),
            BorderStyle = BorderStyle.FixedSingle,
            BackColor = Color.White,
            TextAlign = ContentAlignment.MiddleCenter,
            Font = new Font("Segoe UI", 11)
        };

        // --- Кнопка ---
        var btnCompose = new Button { Text = "Составить", Location = new Point(16, 296), Size = new Size(384, 36) };
        btnCompose.Click += (_, _) =>
        {
            string greeting = (rbMorning.Checked ? "Доброе утро" :
                               rbDay.Checked     ? "Добрый день" :
                               rbEvening.Checked ? "Добрый вечер" : "Спокойной ночи");

            string titles = string.Join(" ", new[]
            {
                cbRespected.Checked ? "уважаемый" : "",
                cbDear.Checked      ? "дорогой"   : "",
                cbMister.Checked    ? "господин"   : ""
            }).Trim();

            string name = txtName.Text.Trim();
            lblResult.Text = $"{greeting}{(titles.Length > 0 ? ", " + titles : "")}{(name.Length > 0 ? " " + name : "")}!";
        };

        Controls.AddRange(new Control[] { grpTime, grpTitle, lblName, txtName, lblResult, btnCompose });
    }
}
