using System.Windows;
using System.Windows.Controls;

namespace PR9;

public partial class Task1_BubbleEvents : Window
{
    public Task1_BubbleEvents() => InitializeComponent();

    // Обработчик на уровне TextBox (первый — до всплытия)
    private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
    {
        rbTextBox.IsChecked = true;
        // Событие продолжает всплывать к Grid и Window
    }

    // Обработчик на уровне Grid
    private void Grid_TextChanged(object sender, TextChangedEventArgs e)
    {
        rbGrid.IsChecked = true;
        MessageBox.Show("Событие поднялось в Grid", "Grid",
                        MessageBoxButton.OK, MessageBoxImage.Information);
    }

    // Обработчик на уровне Window
    private void Window_TextChanged(object sender, TextChangedEventArgs e)
    {
        rbWindow.IsChecked = true;
        // Уже поймали на уровне Grid, здесь можно просто отметить
    }
}
