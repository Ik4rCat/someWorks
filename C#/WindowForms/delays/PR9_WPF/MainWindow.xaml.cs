using System.Windows;

namespace PR9;

public partial class MainWindow : Window
{
    public MainWindow() => InitializeComponent();

    private void OpenTask1(object sender, RoutedEventArgs e) => new Task1_BubbleEvents().Show();
    private void OpenTask2(object sender, RoutedEventArgs e) => new Task2_Counter().Show();
    private void OpenTask3(object sender, RoutedEventArgs e) => new Task3_TextEditor().Show();
}
