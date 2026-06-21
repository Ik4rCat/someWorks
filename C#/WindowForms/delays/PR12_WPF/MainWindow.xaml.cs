using System.Windows;

namespace PR12;

public partial class MainWindow : Window
{
    private bool _syncing;

    public MainWindow()
    {
        InitializeComponent();

        // Настраиваем системы счисления для каждой строки
        rowHex.NumBase = 16;
        rowDec.NumBase = 10;
        rowOct.NumBase = 8;
        rowBin.NumBase = 2;
    }

    private void Row_ValueChanged(object sender, RoutedEventArgs e)
    {
        if (_syncing) return;
        _syncing = true;

        // Берём значение из изменённой строки и обновляем все остальные
        var source = (NumberInputRow)sender;
        long val = source.Value;

        if (source != rowHex) rowHex.Value = val;
        if (source != rowDec) rowDec.Value = val;
        if (source != rowOct) rowOct.Value = val;
        if (source != rowBin) rowBin.Value = val;

        _syncing = false;
    }
}
