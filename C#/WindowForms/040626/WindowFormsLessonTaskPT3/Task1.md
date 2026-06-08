code:

Form1.cs
```
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowFormsLessonTaskPT3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void ListAddButton_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(textBox1.Text))
            {
                MessageBox.Show("Write text");
                return;
            }

            listView1.Items.Add(textBox1.Text);
            textBox1.Clear();
        }

        private void TreeAddButton_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(textBox1.Text))
            {
                MessageBox.Show("Write text");
                return;
            }

            if (treeView1.SelectedNode == null)
            {
                treeView1.Nodes.Add(textBox1.Text);
            }
            else
            {
                treeView1.SelectedNode.Nodes.Add(textBox1.Text);
                treeView1.SelectedNode.Expand();
            }

            textBox1.Clear();

        }
    }
}

```


results:

