using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsLessonTask
{
    public partial class GreenPeaceForm : Form
    {
        public GreenPeaceForm()
        {
            InitializeComponent();
        }

        private void GreenPeaceForm_Load(object sender, EventArgs e)
        {
            GraphicsPath myPath = new GraphicsPath();
            Point[] points =
            {
            new Point(Width / 2, 0),
            new Point(Width,     Height / 2),
            new Point(Width / 2, Height),
            new Point(0,         Height / 2)
        };
            myPath.AddPolygon(points);
            this.Region = new Region(myPath);

            btnClose.Left = (this.Width - btnClose.Width) / 2;
            btnClose.Top = (this.Height - btnClose.Height) / 2;
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
