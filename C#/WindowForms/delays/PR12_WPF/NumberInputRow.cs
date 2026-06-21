using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace PR12;

/// <summary>
/// Кастомный элемент управления: строка ввода числа в заданной системе счисления.
/// Автоматически блокирует недопустимые символы.
/// Это UserControl (начальный уровень) — демонстрирует создание пользовательских элементов.
/// </summary>
public class NumberInputRow : UserControl
{
    private readonly TextBox _textBox;
    private readonly Label   _label;
    private int _numBase = 10;

    // Dependency Property для текущего значения (decimal)
    public static readonly DependencyProperty ValueProperty =
        DependencyProperty.Register(
            nameof(Value), typeof(long), typeof(NumberInputRow),
            new FrameworkPropertyMetadata(0L,
                FrameworkPropertyMetadataOptions.BindsTwoWayByDefault,
                OnValueChanged));

    public long Value
    {
        get => (long)GetValue(ValueProperty);
        set => SetValue(ValueProperty, value);
    }

    // Событие изменения значения (всплывающее)
    public static readonly RoutedEvent ValueChangedEvent =
        EventManager.RegisterRoutedEvent(nameof(ValueChanged),
            RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(NumberInputRow));

    public event RoutedEventHandler ValueChanged
    {
        add    => AddHandler(ValueChangedEvent, value);
        remove => RemoveHandler(ValueChangedEvent, value);
    }

    public int NumBase
    {
        get => _numBase;
        set
        {
            _numBase = value;
            _label.Content = value switch
            {
                16 => "HEX",
                10 => "DEC",
                 8 => "OCT",
                 2 => "BIN",
                 _ => value.ToString()
            };
            RefreshText();
        }
    }

    private bool _suppressChange;

    public NumberInputRow()
    {
        var panel = new StackPanel { Orientation = Orientation.Horizontal };

        _label = new Label
        {
            Width = 50,
            FontWeight = FontWeights.Bold,
            VerticalAlignment = VerticalAlignment.Center,
            HorizontalContentAlignment = HorizontalAlignment.Right
        };

        _textBox = new TextBox
        {
            Width = 200,
            Height = 34,
            FontSize = 15,
            FontFamily = new FontFamily("Consolas"),
            VerticalContentAlignment = VerticalAlignment.Center,
            Padding = new Thickness(6, 0, 6, 0),
            Margin = new Thickness(8, 0, 0, 0)
        };

        _textBox.PreviewTextInput += OnPreviewTextInput;
        _textBox.TextChanged      += OnTextChanged;
        DataObject.AddPastingHandler(_textBox, OnPaste);

        panel.Children.Add(_label);
        panel.Children.Add(_textBox);
        Content = panel;
    }

    private void OnPreviewTextInput(object sender, System.Windows.Input.TextCompositionEventArgs e)
    {
        // Разрешены только допустимые символы для текущей системы счисления
        foreach (char c in e.Text.ToUpper())
        {
            if (!IsValidChar(c))
            {
                e.Handled = true;
                return;
            }
        }
    }

    private void OnPaste(object sender, DataObjectPastingEventArgs e)
    {
        // Блокируем вставку недопустимого текста
        if (e.DataObject.GetDataPresent(DataFormats.UnicodeText))
        {
            string text = (string)e.DataObject.GetData(DataFormats.UnicodeText)!;
            foreach (char c in text.ToUpper())
            {
                if (!IsValidChar(c)) { e.CancelCommand(); return; }
            }
        }
    }

    private bool IsValidChar(char c)
    {
        return _numBase switch
        {
            16 => "0123456789ABCDEF".Contains(c),
            10 => char.IsAsciiDigit(c),
             8 => c >= '0' && c <= '7',
             2 => c == '0' || c == '1',
             _ => char.IsAsciiDigit(c)
        };
    }

    private void OnTextChanged(object sender, TextChangedEventArgs e)
    {
        if (_suppressChange) return;
        try
        {
            long newVal = string.IsNullOrEmpty(_textBox.Text)
                ? 0
                : Convert.ToInt64(_textBox.Text, _numBase);
            _suppressChange = true;
            Value = newVal;
            _suppressChange = false;
            RaiseEvent(new RoutedEventArgs(ValueChangedEvent, this));
        }
        catch { /* некорректный ввод — игнорируем */ }
    }

    private static void OnValueChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
    {
        var ctrl = (NumberInputRow)d;
        if (!ctrl._suppressChange)
            ctrl.RefreshText();
    }

    private void RefreshText()
    {
        _suppressChange = true;
        _textBox.Text = _numBase switch
        {
            16 => Value.ToString("X"),
            10 => Value.ToString(),
             8 => Convert.ToString(Value, 8),
             2 => Convert.ToString(Value, 2),
             _ => Value.ToString()
        };
        _suppressChange = false;
    }
}
