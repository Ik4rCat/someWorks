using System;
using System.Windows.Forms;

namespace WindowsFormsLessonTask2
{
    public partial class SdiForm : Form
    {
        public SdiForm()
        {
            InitializeComponent();
        }

        private void SdiForm_Load(object sender, EventArgs e)
        {
            CenterCloseButton();
        }

        private void SdiForm_Resize(object sender, EventArgs e)
        {
            CenterCloseButton();
        }

        private void CenterCloseButton()
        {
            btnClose.Left = (this.ClientSize.Width  - btnClose.Width)  / 2;
            btnClose.Top  = (this.ClientSize.Height - btnClose.Height) / 2;
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
