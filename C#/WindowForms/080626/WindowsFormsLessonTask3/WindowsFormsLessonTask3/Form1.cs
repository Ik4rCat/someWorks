using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsLessonTask3
{
    public partial class Form1 : Form
    {

        FormBorderStyle startBorder;
        private int startWidth;
        private int startHeight;
        private double startOpacity;

        public Form1()
        {
            InitializeComponent();

            
            startBorder = this.FormBorderStyle;
            startWidth = this.Width;
            startHeight = this.Height;
            startOpacity = this.Opacity;
        }

        private void BorderStyleButton_Click(object sender, EventArgs e)
        {
            if (this.FormBorderStyle == FormBorderStyle.Fixed3D) { this.FormBorderStyle = FormBorderStyle.None; }
            else { this.FormBorderStyle = FormBorderStyle.Fixed3D; }
        }

        private void ResizeButton_Click(object sender, EventArgs e)
        {
            this.Width += 100;
            this.Height += 50;
        }

        private void OpacityButton_Click(object sender, EventArgs e)
        {
            this.Opacity -= 0.1;
            if (this.Opacity < 0.2) this.Opacity = 1;
        }

        private void OpenPart2Button_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.Show();
        }

        private void OpenPart3Button_Click(object sender, EventArgs e)
        {
            Form3 f3 = new Form3();
            f3.Show();
        }

        private void OriginalViewButton_Click(object sender, EventArgs e)
        {
            this.FormBorderStyle = startBorder;
            this.Width = Width;
            this.Height = Height;
            this.Opacity = startOpacity;
        }
    }
}
