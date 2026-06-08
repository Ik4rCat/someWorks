using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsLessonTask2PT3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            listView.View = View.List;
        }

        private void AddTask_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(textBox.Text))
            {
                MessageBox.Show("You can't add empty task");
                return;
            }

            listView.Items.Add(textBox.Text);
            textBox.Clear();
            UpdateCount();
        }

        private void DeleteTask_Click(object sender, EventArgs e)
        {
            if(listView.SelectedItems.Count == 0)
            {
                MessageBox.Show("Choice any tasks for delete");
                return;
            }

            listView.SelectedItems[0].Remove();
            UpdateCount();

        }

        private void ClearList_Click(object sender, EventArgs e)
        {
            listView.Items.Clear();
            UpdateCount();
        }


        private void UpdateCount()
        {
            TasksCountlabel.Text = "Items in task list: " + listView.Items.Count;
        }

    }
}
