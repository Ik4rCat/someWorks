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
            this.MainMenuStrip = this.menuStrip1;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void mdiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ChildForm childForm = new ChildForm();
            childForm.MdiParent = this;
            childForm.Show();
        }

        private void sdiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SdiForm sdiForm = new SdiForm();
            sdiForm.Show();
        }
    }
}
