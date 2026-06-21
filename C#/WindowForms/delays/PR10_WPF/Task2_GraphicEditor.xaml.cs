using System.Windows;
using System.Windows.Controls;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;

namespace PR10;

public partial class Task2_GraphicEditor : Window
{
    public Task2_GraphicEditor()
    {
        InitializeComponent();
        UpdatePen();
    }

    private void cmbColor_Changed(object sender, SelectionChangedEventArgs e) => UpdatePen();
    private void sliderSize_Changed(object sender, RoutedPropertyChangedEventArgs<double> e)
    {
        if (lblSize != null) lblSize.Content = ((int)e.NewValue).ToString();
        UpdatePen();
    }

    private void Mode_Changed(object sender, RoutedEventArgs e)
    {
        if (inkCanvas == null) return;
        if (rbInk.IsChecked    == true) inkCanvas.EditingMode = InkCanvasEditingMode.Ink;
        if (rbSelect.IsChecked == true) inkCanvas.EditingMode = InkCanvasEditingMode.Select;
        if (rbErase.IsChecked  == true) inkCanvas.EditingMode = InkCanvasEditingMode.EraseByStroke;
    }

    private void UpdatePen()
    {
        if (inkCanvas == null || cmbColor == null || sliderSize == null) return;

        string colorTag = ((ComboBoxItem?)cmbColor.SelectedItem)?.Tag?.ToString() ?? "Black";
        var color = (Color)ColorConverter.ConvertFromString(colorTag);
        double size = sliderSize.Value;

        inkCanvas.DefaultDrawingAttributes = new DrawingAttributes
        {
            Color  = color,
            Width  = size,
            Height = size,
            FitToCurve = true,
            StylusTip  = StylusTip.Ellipse
        };
    }

    private void Clear_Click(object sender, RoutedEventArgs e) => inkCanvas.Strokes.Clear();
}
