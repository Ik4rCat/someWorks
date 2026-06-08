namespace WindowFormsLessonTaskPT3
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.listView1 = new System.Windows.Forms.ListView();
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.TreeAddButton = new System.Windows.Forms.Button();
            this.ListAddButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // listView1
            // 
            this.listView1.HideSelection = false;
            this.listView1.Location = new System.Drawing.Point(13, 13);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(231, 314);
            this.listView1.TabIndex = 0;
            this.listView1.UseCompatibleStateImageBehavior = false;
            // 
            // treeView1
            // 
            this.treeView1.Location = new System.Drawing.Point(262, 13);
            this.treeView1.Name = "treeView1";
            this.treeView1.Size = new System.Drawing.Size(237, 314);
            this.treeView1.TabIndex = 1;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(202, 355);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 2;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // TreeAddButton
            // 
            this.TreeAddButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.TreeAddButton.Location = new System.Drawing.Point(352, 353);
            this.TreeAddButton.Name = "TreeAddButton";
            this.TreeAddButton.Size = new System.Drawing.Size(75, 23);
            this.TreeAddButton.TabIndex = 3;
            this.TreeAddButton.Text = "Add to tree";
            this.TreeAddButton.UseVisualStyleBackColor = true;
            this.TreeAddButton.Click += new System.EventHandler(this.TreeAddButton_Click);
            // 
            // ListAddButton
            // 
            this.ListAddButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ListAddButton.Location = new System.Drawing.Point(85, 352);
            this.ListAddButton.Name = "ListAddButton";
            this.ListAddButton.Size = new System.Drawing.Size(75, 23);
            this.ListAddButton.TabIndex = 4;
            this.ListAddButton.Text = "Add to list";
            this.ListAddButton.UseVisualStyleBackColor = true;
            this.ListAddButton.Click += new System.EventHandler(this.ListAddButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(511, 412);
            this.Controls.Add(this.ListAddButton);
            this.Controls.Add(this.TreeAddButton);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.treeView1);
            this.Controls.Add(this.listView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button TreeAddButton;
        private System.Windows.Forms.Button ListAddButton;
    }
}

