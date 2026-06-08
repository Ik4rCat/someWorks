namespace WindowsFormsLessonTask2PT3
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
            this.listView = new System.Windows.Forms.ListView();
            this.AddTask = new System.Windows.Forms.Button();
            this.DeleteTask = new System.Windows.Forms.Button();
            this.ClearList = new System.Windows.Forms.Button();
            this.TasksCountlabel = new System.Windows.Forms.Label();
            this.textBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // listView
            // 
            this.listView.Cursor = System.Windows.Forms.Cursors.Cross;
            this.listView.HideSelection = false;
            this.listView.Location = new System.Drawing.Point(12, 12);
            this.listView.Name = "listView";
            this.listView.Size = new System.Drawing.Size(378, 260);
            this.listView.TabIndex = 0;
            this.listView.UseCompatibleStateImageBehavior = false;
            // 
            // AddTask
            // 
            this.AddTask.Cursor = System.Windows.Forms.Cursors.Hand;
            this.AddTask.Location = new System.Drawing.Point(12, 327);
            this.AddTask.Name = "AddTask";
            this.AddTask.Size = new System.Drawing.Size(174, 25);
            this.AddTask.TabIndex = 1;
            this.AddTask.Text = "Add task";
            this.AddTask.UseVisualStyleBackColor = true;
            this.AddTask.Click += new System.EventHandler(this.AddTask_Click);
            // 
            // DeleteTask
            // 
            this.DeleteTask.Cursor = System.Windows.Forms.Cursors.Hand;
            this.DeleteTask.Location = new System.Drawing.Point(216, 327);
            this.DeleteTask.Name = "DeleteTask";
            this.DeleteTask.Size = new System.Drawing.Size(174, 25);
            this.DeleteTask.TabIndex = 2;
            this.DeleteTask.Text = "Delete task";
            this.DeleteTask.UseVisualStyleBackColor = true;
            this.DeleteTask.Click += new System.EventHandler(this.DeleteTask_Click);
            // 
            // ClearList
            // 
            this.ClearList.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ClearList.Location = new System.Drawing.Point(115, 368);
            this.ClearList.Name = "ClearList";
            this.ClearList.Size = new System.Drawing.Size(174, 23);
            this.ClearList.TabIndex = 3;
            this.ClearList.Text = "Clear list";
            this.ClearList.UseVisualStyleBackColor = true;
            this.ClearList.Click += new System.EventHandler(this.ClearList_Click);
            // 
            // TasksCountlabel
            // 
            this.TasksCountlabel.AutoSize = true;
            this.TasksCountlabel.Cursor = System.Windows.Forms.Cursors.Help;
            this.TasksCountlabel.Location = new System.Drawing.Point(12, 291);
            this.TasksCountlabel.Name = "TasksCountlabel";
            this.TasksCountlabel.Size = new System.Drawing.Size(96, 13);
            this.TasksCountlabel.TabIndex = 4;
            this.TasksCountlabel.Text = " Items in task list: 0";
            // 
            // textBox
            // 
            this.textBox.Location = new System.Drawing.Point(170, 288);
            this.textBox.Name = "textBox";
            this.textBox.Size = new System.Drawing.Size(198, 20);
            this.textBox.TabIndex = 5;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(402, 403);
            this.Controls.Add(this.textBox);
            this.Controls.Add(this.TasksCountlabel);
            this.Controls.Add(this.ClearList);
            this.Controls.Add(this.DeleteTask);
            this.Controls.Add(this.AddTask);
            this.Controls.Add(this.listView);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView listView;
        private System.Windows.Forms.Button AddTask;
        private System.Windows.Forms.Button DeleteTask;
        private System.Windows.Forms.Button ClearList;
        private System.Windows.Forms.Label TasksCountlabel;
        private System.Windows.Forms.TextBox textBox;
    }
}

