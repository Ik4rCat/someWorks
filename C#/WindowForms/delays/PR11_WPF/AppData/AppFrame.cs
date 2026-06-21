using System.Windows.Controls;

namespace PR11.AppData;

/// <summary>Хранит ссылку на Frame главного окна для навигации между страницами</summary>
public static class AppFrame
{
    public static Frame? FrmMain { get; set; }
}
