using System;
using System.Windows.Forms;

public class FormMenu : Form
{
    public FormMenu()
    {
        Text = "ПР4 — Прокрутка, индикаторы";
        ClientSize = new System.Drawing.Size(300, 200);
        StartPosition = FormStartPosition.CenterScreen;
        FormBorderStyle = FormBorderStyle.FixedSingle;
        MaximizeBox = false;

        var panel = new FlowLayoutPanel
        {
            Dock = DockStyle.Fill,
            FlowDirection = FlowDirection.TopDown,
            Padding = new Padding(20),
            WrapContents = false
        };

        (string text, Func<Form> factory)[] items =
        {
            ("Задание 1: Конвертер температуры",    () => new Task1_Temperature()),
            ("Задание 2: CheckedListBox → ListBox",  () => new Task2_ListBoxes()),
            ("Задание 3: RGB цвет через ScrollBar",  () => new Task3_RgbColor()),
        };

        foreach (var (text, factory) in items)
        {
            var btn = new Button { Text = text, Width = 255, Height = 44, Margin = new Padding(0, 0, 0, 6) };
            var f = factory;
            btn.Click += (_, _) => f().Show();
            panel.Controls.Add(btn);
        }

        Controls.Add(panel);
    }
}
