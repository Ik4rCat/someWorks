using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsLessonTask6
{
    public partial class ChildForm : Form
    {
        public ChildForm()
        {
            InitializeComponent();
        }

        private void ToggleForegroundMenuItem_Click(object sender, EventArgs e)
        {
            if (ToggleForegroundMenuItem.Checked)
            {
                ToggleForegroundMenuItem.Checked = false;
                ChildTextBox.ForeColor = Color.Black;
            }
            else
            {
                ToggleForegroundMenuItem.Checked = true;
                ChildTextBox.ForeColor= Color.Blue;
            }

        }
    }
}
