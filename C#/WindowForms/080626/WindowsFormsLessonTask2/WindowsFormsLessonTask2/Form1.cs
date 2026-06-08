using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsLessonTask2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void BoldButton_Click(object sender, EventArgs e)
        {
            if (richTextBox.SelectionFont == null) return;

            FontStyle style = richTextBox.SelectionFont.Style;

            if (style.HasFlag(FontStyle.Bold))
                richTextBox.SelectionFont = new Font(richTextBox.SelectionFont, style & ~FontStyle.Bold);
            else
                richTextBox.SelectionFont = new Font(richTextBox.SelectionFont, style | FontStyle.Bold);

            richTextBox.Focus();
        }


        private void UnderLinedButton_Click(object sender, EventArgs e)
        {
            if (richTextBox.SelectionFont == null) return;

            FontStyle style = richTextBox.SelectionFont.Style;

            if (style.HasFlag(FontStyle.Underline))
                richTextBox.SelectionFont = new Font(richTextBox.SelectionFont, style & ~FontStyle.Underline);
            else
                richTextBox.SelectionFont = new Font(richTextBox.SelectionFont, style | FontStyle.Underline);

            richTextBox.Focus();
        }


        private void InclinedButton_Click(object sender, EventArgs e)
        {
            if (richTextBox.SelectionFont == null) return;

            FontStyle style = richTextBox.SelectionFont.Style;

            if (style.HasFlag(FontStyle.Italic))
                richTextBox.SelectionFont = new Font(richTextBox.SelectionFont, style & ~FontStyle.Italic);
            else
                richTextBox.SelectionFont = new Font(richTextBox.SelectionFont, style | FontStyle.Italic);

            richTextBox.Focus();
        }


        private void InTheCenterButton_Click(object sender, EventArgs e)
        {
            if (richTextBox.SelectionAlignment == HorizontalAlignment.Center)
                richTextBox.SelectionAlignment = HorizontalAlignment.Left;
            else
                richTextBox.SelectionAlignment = HorizontalAlignment.Center;

            richTextBox.Focus();
        }



        private void SizeLabel_Click(object sender, EventArgs e)
        {
            SizeTextBox.Focus();
        }

        private void SizeTextBox_TextChanged(object sender, EventArgs e)
        {
            if (!float.TryParse(SizeTextBox.Text, out float size) || size <= 0)
                return;

            if (richTextBox.SelectionFont != null)
                richTextBox.SelectionFont = new Font(richTextBox.SelectionFont.FontFamily, size, richTextBox.SelectionFont.Style);
        }



        private void richTextBox_TextChanged(object sender, EventArgs e) {}



        private void OpenButton_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog dialog = new OpenFileDialog())
            {
                dialog.Filter = "RTF файлы (*.rtf)|*.rtf|Все файлы (*.*)|*.*";
                dialog.Title = "Открыть файл";

                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    richTextBox.LoadFile(dialog.FileName);
                }
            }
        }


        private void SaveButton_Click(object sender, EventArgs e)
        {
            using (SaveFileDialog dialog = new SaveFileDialog())
            {
                dialog.Filter = "RTF файлы (*.rtf)|*.rtf|Все файлы (*.*)|*.*";
                dialog.Title = "Сохранить файл";
                dialog.FileName = "Test.rtf";

                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    richTextBox.SaveFile(dialog.FileName);
                }
            }
        }
    }
}
