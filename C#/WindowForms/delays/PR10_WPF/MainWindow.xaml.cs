using System.Windows;
namespace PR10;
public partial class MainWindow : Window
{
    public MainWindow() => InitializeComponent();
    private void OpenTask1(object s, RoutedEventArgs e) => new Task1_MenuApp().Show();
    private void OpenTask2(object s, RoutedEventArgs e) => new Task2_GraphicEditor().Show();
}
