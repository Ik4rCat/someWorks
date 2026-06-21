using System;
using System.Windows.Forms;

/// <summary>Меню запуска заданий ПР1</summary>
public class FormMenu : Form
{
    public FormMenu()
    {
        Text = "ПР1 — Выберите задание";
        ClientSize = new System.Drawing.Size(300, 320);
        StartPosition = FormStartPosition.CenterScreen;
        FormBorderStyle = FormBorderStyle.FixedSingle;
        MaximizeBox = false;

        var panel = new FlowLayoutPanel
        {
            Dock = DockStyle.Fill,
            FlowDirection = FlowDirection.TopDown,
            Padding = new Padding(20, 20, 20, 0),
            WrapContents = false
        };

        (string text, Func<Form> factory)[] items =
        {
            ("Задание 1: DataGridView + клавиатура", () => new Task1_DataGrid()),
            ("Задание 2: Свойства Button",            () => new Task2_ButtonProps()),
            ("Задание 3: Трансформации GDI+",         () => new Task3_Graphics()),
            ("Задание 4: Timer + случайные круги",    () => new Task4_Timer()),
            ("Задание 5: Полигон по кликам мыши",    () => new Task5_Polygon()),
        };

        foreach (var (text, factory) in items)
        {
            var btn = new Button
            {
                Text = text,
                Width = 255,
                Height = 44,
                Margin = new Padding(0, 0, 0, 8),
                TextAlign = System.Drawing.ContentAlignment.MiddleLeft,
                Padding = new Padding(6, 0, 0, 0)
            };
            var f = factory; // closure capture
            btn.Click += (_, _) => f().Show();
            panel.Controls.Add(btn);
        }

        Controls.Add(panel);
    }
}
