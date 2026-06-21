using System.Windows;
using System.Windows.Controls;
using PR11.AppData;
using PR11.PageMain;

namespace PR11.PageAdmin;

public partial class PageMenuAdmin : Page
{
    public PageMenuAdmin(string name)
    {
        InitializeComponent();
        lblWelcome.Text = $"Здравствуйте, {name}!\nРоль: Администратор";
    }

    private void Logout_Click(object sender, RoutedEventArgs e)
        => AppFrame.FrmMain?.Navigate(new PageLogin());
}
