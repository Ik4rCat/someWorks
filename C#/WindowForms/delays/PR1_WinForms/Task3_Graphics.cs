using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

/// <summary>
/// Задание 3: Трансформации GDI+.
/// R/L — вращение, U/D — масштаб, WASD — сдвиг.
/// </summary>
public class Task3_Graphics : Form
{
    private float _angle  = 0f;
    private float _scale  = 1f;
    private float _tx     = 0f;
    private float _ty     = 0f;

    public Task3_Graphics()
    {
        Text = "Задание 3: Трансформации (RotateTransform / ScaleTransform / TranslateTransform)";
        ClientSize = new Size(600, 500);
        StartPosition = FormStartPosition.CenterScreen;
        DoubleBuffered = true;
        KeyPreview = true;

        var hint = new Label
        {
            Text = "← → Вращение   ↑ ↓ Масштаб   W A S D Сдвиг   Пробел Сброс",
            Dock = DockStyle.Bottom,
            Height = 28,
            TextAlign = ContentAlignment.MiddleCenter,
            BackColor = Color.LightYellow
        };

        Controls.Add(hint);
        KeyDown += OnKeyDown;
        Paint   += OnPaint;
    }

    private void OnKeyDown(object? sender, KeyEventArgs e)
    {
        const float dAngle = 10f;
        const float dScale = 0.1f;
        const float dMove  = 15f;

        switch (e.KeyCode)
        {
            case Keys.Left:  _angle -= dAngle; break;
            case Keys.Right: _angle += dAngle; break;
            case Keys.Up:    _scale += dScale; break;
            case Keys.Down:  _scale = Math.Max(0.1f, _scale - dScale); break;
            case Keys.W:     _ty -= dMove; break;
            case Keys.S:     _ty += dMove; break;
            case Keys.A:     _tx -= dMove; break;
            case Keys.D:     _tx += dMove; break;
            case Keys.Space: _angle = 0; _scale = 1; _tx = 0; _ty = 0; break;
        }
        Invalidate();
    }

    private void OnPaint(object? sender, PaintEventArgs e)
    {
        var g = e.Graphics;
        g.SmoothingMode = SmoothingMode.AntiAlias;
        g.Clear(Color.White);

        // Сохраняем исходное состояние
        var state = g.Save();

        // Центр формы
        float cx = ClientSize.Width  / 2f;
        float cy = ClientSize.Height / 2f - 14;

        // Применяем трансформации
        g.TranslateTransform(cx + _tx, cy + _ty);  // сдвиг к центру + пользовательский
        g.RotateTransform(_angle);                   // вращение
        g.ScaleTransform(_scale, _scale);            // масштаб

        // Рисуем звезду из треугольников
        using var brush = new SolidBrush(Color.DodgerBlue);
        using var pen   = new Pen(Color.Navy, 2);

        var rect = new RectangleF(-60, -60, 120, 120);
        g.FillEllipse(brush, rect);
        g.DrawEllipse(pen, rect);

        var innerRect = new RectangleF(-30, -30, 60, 60);
        g.FillRectangle(Brushes.Orange, innerRect);
        g.DrawRectangle(pen, -30, -30, 60, 60);

        // Перекрёстные линии
        g.DrawLine(pen, -60, 0, 60, 0);
        g.DrawLine(pen, 0, -60, 0, 60);

        g.Restore(state);

        // HUD с текущими значениями
        g.DrawString(
            $"Угол: {_angle:F1}°   Масштаб: {_scale:F2}   Сдвиг: ({_tx:F0}, {_ty:F0})",
            new Font("Consolas", 10), Brushes.Black, 8, 8);
    }
}
