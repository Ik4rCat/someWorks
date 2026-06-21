using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace PR10;

public partial class Task1_MenuApp : Window
{
    public Task1_MenuApp() => InitializeComponent();

    private void BgColor_Click(object sender, RoutedEventArgs e)
    {
        string tag = ((FrameworkElement)sender).Tag?.ToString() ?? "White";
        var color = tag == "Default"
            ? SystemColors.ControlBrush
            : new SolidColorBrush((Color)ColorConverter.ConvertFromString(tag));
        mainGrid.Background = color;
        statusText.Text = $"Фон изменён: {tag}";
    }

    private void About_Click(object sender, RoutedEventArgs e)
        => MessageBox.Show("ПР10 — Задание 1\nРазработал: студент IT TOP\nМеню + ToolBar + StatusBar", "О программе");

    private void Close_Click(object sender, RoutedEventArgs e) => Close();

    private void MenuItem_MouseEnter(object sender, System.Windows.Input.MouseEventArgs e)
    {
        if (sender is MenuItem mi)
            statusText.Text = mi.Header?.ToString() ?? "";
    }

    private void MenuItem_MouseLeave(object sender, System.Windows.Input.MouseEventArgs e)
        => statusText.Text = "Готово";

    private void ToolBtn_MouseEnter(object sender, System.Windows.Input.MouseEventArgs e)
    {
        if (sender is Button btn)
            statusText.Text = btn.ToolTip?.ToString() ?? "";
    }

    private void ToolBtn_MouseLeave(object sender, System.Windows.Input.MouseEventArgs e)
        => statusText.Text = "Готово";
}
