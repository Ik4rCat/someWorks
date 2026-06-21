using System.Windows;
using PR11.AppData;
using PR11.PageMain;

namespace PR11;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();

        // Инициализировать БД при запуске
        AppConnect.Initialize();

        // Сохранить ссылку на фрейм
        AppFrame.FrmMain = FrmMain;

        // Открыть страницу авторизации
        FrmMain.Navigate(new PageLogin());
    }

    /// <summary>Обновляет заголовок в шапке при переходе между страницами</summary>
    public void SetTitle(string title) => tbTitle.Text = title;
}
