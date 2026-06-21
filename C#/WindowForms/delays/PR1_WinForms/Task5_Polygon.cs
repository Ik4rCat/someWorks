using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

/// <summary>
/// Задание 5: Рисование полигона кликами мыши.
/// ЛКМ — добавить вершину, ПКМ — очистить.
/// </summary>
public class Task5_Polygon : Form
{
    private readonly List<Point> _points = new();

    public Task5_Polygon()
    {
        Text = "Задание 5: Полигон (ЛКМ — вершина, ПКМ — очистить)";
        ClientSize = new Size(600, 500);
        StartPosition = FormStartPosition.CenterScreen;
        DoubleBuffered = true;

        var hint = new Label
        {
            Text = "Левая кнопка мыши — добавить вершину   Правая кнопка — очистить",
            Dock = DockStyle.Bottom,
            Height = 26,
            TextAlign = ContentAlignment.MiddleCenter,
            BackColor = Color.LightYellow
        };
        Controls.Add(hint);

        MouseClick += OnMouseClick;
        Paint       += OnPaint;
    }

    private void OnMouseClick(object? sender, MouseEventArgs e)
    {
        if (e.Button == MouseButtons.Left)
        {
            _points.Add(e.Location);
            Invalidate();
        }
        else if (e.Button == MouseButtons.Right)
        {
            _points.Clear();
            Invalidate();
        }
    }

    private void OnPaint(object? sender, PaintEventArgs e)
    {
        var g = e.Graphics;
        g.SmoothingMode = SmoothingMode.AntiAlias;
        g.Clear(Color.White);

        // Рисуем точки
        foreach (var p in _points)
        {
            g.FillEllipse(Brushes.Red, p.X - 5, p.Y - 5, 10, 10);
            g.DrawEllipse(Pens.DarkRed, p.X - 5, p.Y - 5, 10, 10);
        }

        // Рисуем линии и заливку
        if (_points.Count >= 2)
        {
            var pts = _points.ToArray();

            if (_points.Count >= 3)
            {
                using var brush = new SolidBrush(Color.FromArgb(80, Color.DodgerBlue));
                g.FillPolygon(brush, pts);
            }

            using var pen = new Pen(Color.DodgerBlue, 2);
            for (int i = 0; i < pts.Length - 1; i++)
                g.DrawLine(pen, pts[i], pts[i + 1]);

            // Замкнуть полигон если >= 3 точки
            if (_points.Count >= 3)
                g.DrawLine(pen, pts[^1], pts[0]);
        }

        // Подсказка с количеством точек
        g.DrawString($"Вершин: {_points.Count}", new Font("Segoe UI", 10), Brushes.Gray, 8, 8);
    }
}
