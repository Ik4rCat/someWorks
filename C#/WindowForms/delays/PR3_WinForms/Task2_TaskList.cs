using System;
using System.Drawing;
using System.Windows.Forms;

/// <summary>
/// Задание 2: Список задач.
/// TextBox — ввод, кнопка добавить, ListBox — список, кнопка удалить, Label — счётчик.
/// </summary>
public class Task2_TaskList : Form
{
    private readonly ListBox listBox;
    private readonly Label   lblCount;

    public Task2_TaskList()
    {
        Text = "Задание 2: Список задач";
        ClientSize = new Size(420, 460);
        StartPosition = FormStartPosition.CenterScreen;
        FormBorderStyle = FormBorderStyle.FixedSingle;
        MaximizeBox = false;

        var lblInput = new Label { Text = "Новая задача:", Location = new Point(16, 16), AutoSize = true };
        var txtInput = new TextBox { Location = new Point(16, 38), Size = new Size(304, 26) };
        var btnAdd   = new Button  { Text = "Добавить", Location = new Point(328, 36), Size = new Size(76, 28) };

        listBox = new ListBox
        {
            Location = new Point(16, 80),
            Size = new Size(388, 300),
            IntegralHeight = false
        };

        // Добавить тестовые задачи
        listBox.Items.AddRange(new object[] { "Сделать домашнее задание", "Купить продукты", "Позвонить маме" });

        var btnDelete = new Button { Text = "Удалить выбранное", Location = new Point(16, 392), Size = new Size(200, 34) };
        var btnClear  = new Button { Text = "Очистить всё",      Location = new Point(224, 392), Size = new Size(180, 34) };

        lblCount = new Label
        {
            Location = new Point(16, 434),
            AutoSize = true,
            Font = new Font("Segoe UI", 10, FontStyle.Bold)
        };

        // Добавление по Enter
        txtInput.KeyPress += (_, e) =>
        {
            if (e.KeyChar == (char)13) AddTask(txtInput);
        };
        btnAdd.Click  += (_, _) => AddTask(txtInput);
        btnDelete.Click += (_, _) =>
        {
            if (listBox.SelectedIndex >= 0)
                listBox.Items.RemoveAt(listBox.SelectedIndex);
            UpdateCount();
        };
        btnClear.Click += (_, _) => { listBox.Items.Clear(); UpdateCount(); };

        Controls.AddRange(new Control[]
        {
            lblInput, txtInput, btnAdd,
            listBox, btnDelete, btnClear, lblCount
        });

        UpdateCount();
    }

    private void AddTask(TextBox txt)
    {
        string task = txt.Text.Trim();
        if (string.IsNullOrEmpty(task)) return;
        listBox.Items.Add(task);
        txt.Clear();
        UpdateCount();
    }

    private void UpdateCount() =>
        lblCount.Text = $"Задач в списке: {listBox.Items.Count}";
}
