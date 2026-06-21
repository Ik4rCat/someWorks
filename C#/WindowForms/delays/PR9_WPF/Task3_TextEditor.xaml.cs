using System.Windows;

namespace PR9;

public partial class Task3_TextEditor : Window
{
    public Task3_TextEditor() => InitializeComponent();

    private void Copy_Click (object s, RoutedEventArgs e) => txtEditor.Copy();
    private void Paste_Click(object s, RoutedEventArgs e) => txtEditor.Paste();
    private void Cut_Click  (object s, RoutedEventArgs e) => txtEditor.Cut();
    private void Undo_Click (object s, RoutedEventArgs e) { if (txtEditor.CanUndo) txtEditor.Undo(); }
    private void Redo_Click (object s, RoutedEventArgs e) { if (txtEditor.CanRedo) txtEditor.Redo(); }
}
