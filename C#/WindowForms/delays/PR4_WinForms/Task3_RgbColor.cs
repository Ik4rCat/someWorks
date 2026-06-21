using System;
using System.Drawing;
using System.Windows.Forms;

/// <summary>
/// Задание 3: Управление цветом фона формы через три HScrollBar (R, G, B).
/// Начальные значения бегунков соответствуют цвету фона по умолчанию.
/// </summary>
public class Task3_RgbColor : Form
{
    private readonly HScrollBar scrollR, scrollG, scrollB;
    private readonly Label lblR, lblG, lblB, lblPreview;

    public Task3_RgbColor()
    {
        Text = "Задание 3: RGB-цвет через ScrollBar";
        ClientSize = new Size(480, 280);
        StartPosition = FormStartPosition.CenterScreen;
        FormBorderStyle = FormBorderStyle.FixedSingle;
        MaximizeBox = false;

        // Цвет фона по умолчанию (SystemColors.Control ≈ 240, 240, 240)
        Color defaultColor = SystemColors.Control;

        scrollR = MakeScroll(defaultColor.R);
        scrollG = MakeScroll(defaultColor.G);
        scrollB = MakeScroll(defaultColor.B);

        // Расположение
        var rows = new[] { ("R (красный)", scrollR), ("G (зелёный)", scrollG), ("B (синий)", scrollB) };
        Label[] valueLabels = { new(), new(), new() };

        int y = 24;
        for (int i = 0; i < rows.Length; i++)
        {
            var (text, scroll) = rows[i];
            var lbl = new Label { Text = text, Location = new Point(16, y + 8), Size = new Size(110, 20) };
            scroll.Location = new Point(132, y);
            scroll.Size = new Size(280, 26);

            valueLabels[i] = new Label
            {
                Location = new Point(422, y + 4),
                Size = new Size(40, 20),
                Text = scroll.Value.ToString(),
                TextAlign = ContentAlignment.MiddleRight
            };

            Controls.Add(lbl);
            Controls.Add(scroll);
            Controls.Add(valueLabels[i]);
            y += 50;
        }

        lblR = valueLabels[0];
        lblG = valueLabels[1];
        lblB = valueLabels[2];

        // Превью цвета
        lblPreview = new Label
        {
            Location = new Point(16, 180),
            Size = new Size(446, 60),
            BorderStyle = BorderStyle.FixedSingle,
            TextAlign = ContentAlignment.MiddleCenter,
            Font = new Font("Consolas", 12, FontStyle.Bold)
        };

        Controls.Add(lblPreview);

        scrollR.Scroll += OnScroll;
        scrollG.Scroll += OnScroll;
        scrollB.Scroll += OnScroll;

        ApplyColor();
    }

    private static HScrollBar MakeScroll(int initValue)
        => new HScrollBar { Minimum = 0, Maximum = 264, SmallChange = 1, LargeChange = 9, Value = Math.Min(initValue, 255) };

    private void OnScroll(object? sender, ScrollEventArgs e)
    {
        lblR.Text = scrollR.Value.ToString();
        lblG.Text = scrollG.Value.ToString();
        lblB.Text = scrollB.Value.ToString();
        ApplyColor();
    }

    private void ApplyColor()
    {
        int r = scrollR.Value;
        int g = scrollG.Value;
        int b = scrollB.Value;

        var color = Color.FromArgb(r, g, b);
        BackColor = color;
        lblPreview.BackColor = color;

        // Контрастный текст
        bool dark = (r * 299 + g * 587 + b * 114) / 1000 < 128;
        lblPreview.ForeColor = dark ? Color.White : Color.Black;
        lblPreview.Text = $"R={r}  G={g}  B={b}   #{r:X2}{g:X2}{b:X2}";
    }
}
