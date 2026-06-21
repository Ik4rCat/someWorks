using System;
using System.Drawing;
using System.Windows.Forms;

/// <summary>
/// Задание 1: Конвертер температуры.
/// VScrollBar изменяет температуру по Фаренгейту, Цельсий рассчитывается автоматически.
/// Настройки по PDF: Min=20, Max=60, Value=32.
/// </summary>
public class Task1_Temperature : Form
{
    private readonly VScrollBar vScroll;
    private readonly Label      labelFarTemp;
    private readonly Label      labelCTemp;

    public Task1_Temperature()
    {
        Text = "Измерение температуры";
        ClientSize = new Size(300, 280);
        StartPosition = FormStartPosition.CenterScreen;
        FormBorderStyle = FormBorderStyle.FixedSingle;
        MaximizeBox = false;

        // Заголовки шкал
        var lblFarTitle = new Label
        {
            Text = "Фаренгейт",
            Location = new Point(20, 20),
            Size = new Size(100, 28),
            Font = new Font("Segoe UI", 11, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleCenter
        };
        var lblCTitle = new Label
        {
            Text = "Цельсий",
            Location = new Point(170, 20),
            Size = new Size(100, 28),
            Font = new Font("Segoe UI", 11, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleCenter
        };

        // Отображение значений
        labelFarTemp = new Label
        {
            Name = "labelFarTemp",
            Text = "32",
            Location = new Point(20, 60),
            Size = new Size(100, 60),
            Font = new Font("Arial", 22, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleCenter,
            BackColor = Color.White,
            BorderStyle = BorderStyle.FixedSingle
        };
        labelCTemp = new Label
        {
            Name = "labelCTemp",
            Text = "0",
            Location = new Point(170, 60),
            Size = new Size(100, 60),
            Font = new Font("Arial", 22, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleCenter,
            BackColor = Color.White,
            BorderStyle = BorderStyle.FixedSingle
        };

        // VScrollBar (по PDF: Min=20, Max=60, Value=32)
        vScroll = new VScrollBar
        {
            Minimum    = 20,
            Maximum    = 60 + 9,  // +LargeChange-1 для корректного max
            SmallChange = 1,
            LargeChange = 10,
            Value      = 32,
            Location   = new Point(132, 20),
            Size       = new Size(26, 220)
        };
        vScroll.Scroll += OnScroll;

        var lblHint = new Label
        {
            Text = "Потяните ползунок ↕",
            Location = new Point(16, 240),
            Size = new Size(270, 24),
            TextAlign = ContentAlignment.MiddleCenter,
            ForeColor = Color.Gray
        };

        Controls.AddRange(new Control[]
        {
            lblFarTitle, lblCTitle,
            labelFarTemp, labelCTemp,
            vScroll, lblHint
        });

        UpdateLabels(32);
    }

    private void OnScroll(object? sender, ScrollEventArgs e)
    {
        int f = vScroll.Value;
        // VScrollBar растёт вниз, нам нужно перевернуть:
        // верхний край = max (60), нижний = min (20)
        int far = vScroll.Maximum - 9 + vScroll.Minimum - f; // зеркалируем
        far = Math.Max(20, Math.Min(60, far));
        UpdateLabels(far);
    }

    private void UpdateLabels(int fahrenheit)
    {
        double celsius = (fahrenheit - 32) * 5.0 / 9.0;
        labelFarTemp.Text = fahrenheit.ToString();
        labelCTemp.Text   = $"{celsius:F1}";
    }
}
