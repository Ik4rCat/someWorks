using System;
using System.Windows.Forms;

public class FormMenu : Form
{
    public FormMenu()
    {
        Text = "ПР3 — Выберите задание";
        ClientSize = new System.Drawing.Size(300, 160);
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
            ("Задание 1: TreeView + ListView", () => new Task1_TreeListView()),
            ("Задание 2: Список задач",        () => new Task2_TaskList()),
        };

        foreach (var (text, factory) in items)
        {
            var btn = new Button { Text = text, Width = 255, Height = 44, Margin = new Padding(0, 0, 0, 8) };
            var f = factory;
            btn.Click += (_, _) => f().Show();
            panel.Controls.Add(btn);
        }

        Controls.Add(panel);
    }
}
