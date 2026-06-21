using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

/// <summary>
/// Задание 4: Timer + Random.
/// По тику таймера рисует случайный закрашенный круг в случайном месте.
/// </summary>
public class Task4_Timer : Form
{
    private readonly Timer   _timer   = new();
    private readonly Random  _rng     = new();
    private readonly List<(Rectangle rect, Color color)> _circles = new();

    public Task4_Timer()
    {
        Text = "Задание 4: Timer + Random цвет/позиция";
        ClientSize = new Size(600, 480);
        StartPosition = FormStartPosition.CenterScreen;
        DoubleBuffered = true;

        // Панель управления
        var panel = new Panel { Dock = DockStyle.Bottom, Height = 50, BackColor = Color.WhiteSmoke };

        var lblInterval = new Label { Text = "Интервал (мс):", Location = new Point(10, 15), AutoSize = true };
        var nud = new NumericUpDown
        {
            Location = new Point(110, 12),
            Size = new Size(80, 26),
            Minimum = 100, Maximum = 3000, Value = 500, Increment = 100
        };
        nud.ValueChanged += (_, _) => _timer.Interval = (int)nud.Value;

        var btnStart = new Button { Text = "▶ Старт", Location = new Point(210, 12), Size = new Size(80, 26) };
        var btnStop  = new Button { Text = "■ Стоп",  Location = new Point(300, 12), Size = new Size(80, 26) };
        var btnClear = new Button { Text = "Очистить",Location = new Point(390, 12), Size = new Size(80, 26) };

        btnStart.Click += (_, _) => { _timer.Start(); btnStart.Enabled = false; btnStop.Enabled = true; };
        btnStop.Click  += (_, _) => { _timer.Stop();  btnStart.Enabled = true;  btnStop.Enabled = false; };
        btnClear.Click += (_, _) => { _circles.Clear(); Invalidate(); };

        btnStop.Enabled = false;
        panel.Controls.AddRange(new Control[] { lblInterval, nud, btnStart, btnStop, btnClear });

        _timer.Interval = 500;
        _timer.Tick += OnTick;

        Controls.Add(panel);
        Paint += OnPaint;
    }

    private void OnTick(object? sender, EventArgs e)
    {
        int drawH = ClientSize.Height - 50; // за вычетом панели
        int r = _rng.Next(15, 50);
        int x = _rng.Next(0, ClientSize.Width - r * 2);
        int y = _rng.Next(0, drawH - r * 2);
        var color = Color.FromArgb(_rng.Next(256), _rng.Next(256), _rng.Next(256));

        _circles.Add((new Rectangle(x, y, r * 2, r * 2), color));

        // Не накапливаем больше 200 кругов
        if (_circles.Count > 200) _circles.RemoveAt(0);

        Invalidate();
    }

    private void OnPaint(object? sender, PaintEventArgs e)
    {
        e.Graphics.Clear(Color.White);
        foreach (var (rect, color) in _circles)
        {
            using var brush = new SolidBrush(color);
            e.Graphics.FillEllipse(brush, rect);
        }
    }
}
