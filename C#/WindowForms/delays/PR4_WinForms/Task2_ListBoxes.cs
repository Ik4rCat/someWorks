using System;
using System.Drawing;
using System.Windows.Forms;

/// <summary>
/// Задание 2: Перенос отмеченных элементов из CheckedListBox в ListBox.
/// </summary>
public class Task2_ListBoxes : Form
{
    private readonly CheckedListBox checkedList;
    private readonly ListBox        resultList;

    public Task2_ListBoxes()
    {
        Text = "List Boxes";
        ClientSize = new Size(520, 360);
        StartPosition = FormStartPosition.CenterScreen;
        FormBorderStyle = FormBorderStyle.FixedSingle;
        MaximizeBox = false;

        checkedList = new CheckedListBox
        {
            Location = new Point(16, 16),
            Size = new Size(200, 300),
            CheckOnClick = true
        };
        checkedList.Items.AddRange(new object[]
        {
            "Один", "Два", "Три", "Четыре", "Пять",
            "Шесть", "Семь", "Восемь", "Девять", "Десять"
        });

        var btnMove = new Button
        {
            Text = "Переместить →",
            Location = new Point(226, 160),
            Size = new Size(120, 34)
        };
        btnMove.Click += OnMove;

        resultList = new ListBox
        {
            Location = new Point(356, 16),
            Size = new Size(148, 300)
        };

        Controls.AddRange(new Control[] { checkedList, btnMove, resultList });
    }

    private void OnMove(object? sender, EventArgs e)
    {
        foreach (object item in checkedList.CheckedItems)
        {
            if (!resultList.Items.Contains(item))
                resultList.Items.Add(item);
        }
    }
}
