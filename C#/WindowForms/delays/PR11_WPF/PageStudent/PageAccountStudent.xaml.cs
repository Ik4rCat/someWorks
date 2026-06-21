using System.Windows;
using System.Windows.Controls;
using PR11.AppData;
using PR11.PageMain;

namespace PR11.PageStudent;

public partial class PageAccountStudent : Page
{
    public PageAccountStudent(string name)
    {
        InitializeComponent();
        lblWelcome.Text = $"Здравствуйте, {name}!\nРоль: Ученик";
    }

    private void Logout_Click(object sender, RoutedEventArgs e)
        => AppFrame.FrmMain?.Navigate(new PageLogin());
}
