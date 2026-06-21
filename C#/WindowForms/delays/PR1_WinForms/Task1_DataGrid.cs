using System;
using System.Windows.Forms;

/// <summary>
/// Задание 1: Обработка событий клавиатуры в DataGridView.
/// Стрелки — навигация по ячейкам, Enter — переход на следующую строку.
/// </summary>
public class Task1_DataGrid : Form
{
    private readonly DataGridView dgv;

    public Task1_DataGrid()
    {
        Text = "Задание 1: DataGridView + клавиатура";
        ClientSize = new System.Drawing.Size(520, 380);
        StartPosition = FormStartPosition.CenterScreen;

        var label = new Label
        {
            Text = "↑↓←→ — навигация по ячейкам  |  Enter — следующая строка",
            Dock = DockStyle.Top,
            Height = 30,
            TextAlign = System.Drawing.ContentAlignment.MiddleCenter,
            BackColor = System.Drawing.Color.LightBlue
        };

        dgv = new DataGridView
        {
            Dock = DockStyle.Fill,
            AllowUserToAddRows = false,
            MultiSelect = false,
            SelectionMode = DataGridViewSelectionMode.CellSelect
        };

        // Заполнить тестовыми данными
        dgv.Columns.Add("Фамилия", "Фамилия");
        dgv.Columns.Add("Имя", "Имя");
        dgv.Columns.Add("Оценка", "Оценка");

        dgv.Rows.Add("Иванов",   "Иван",   "5");
        dgv.Rows.Add("Петров",   "Пётр",   "4");
        dgv.Rows.Add("Сидоров",  "Сидор",  "3");
        dgv.Rows.Add("Козлов",   "Кузьма", "5");
        dgv.Rows.Add("Новиков",  "Никита", "4");

        foreach (DataGridViewColumn col in dgv.Columns)
            col.Width = 150;

        // Перехват клавиш до стандартной обработки
        dgv.KeyDown += Dgv_KeyDown;

        Controls.Add(dgv);
        Controls.Add(label);
    }

    private void Dgv_KeyDown(object? sender, KeyEventArgs e)
    {
        int row = dgv.CurrentCell?.RowIndex ?? 0;
        int col = dgv.CurrentCell?.ColumnIndex ?? 0;

        switch (e.KeyCode)
        {
            case Keys.Enter:
                // Переход на следующую строку, первую колонку
                int nextRow = (row + 1) % dgv.Rows.Count;
                dgv.CurrentCell = dgv.Rows[nextRow].Cells[0];
                e.Handled = true;
                e.SuppressKeyPress = true;
                break;

            case Keys.Up:
                if (row > 0)
                    dgv.CurrentCell = dgv.Rows[row - 1].Cells[col];
                e.Handled = true;
                break;

            case Keys.Down:
                if (row < dgv.Rows.Count - 1)
                    dgv.CurrentCell = dgv.Rows[row + 1].Cells[col];
                e.Handled = true;
                break;

            case Keys.Left:
                if (col > 0)
                    dgv.CurrentCell = dgv.Rows[row].Cells[col - 1];
                e.Handled = true;
                break;

            case Keys.Right:
                if (col < dgv.Columns.Count - 1)
                    dgv.CurrentCell = dgv.Rows[row].Cells[col + 1];
                e.Handled = true;
                break;
        }
    }
}
