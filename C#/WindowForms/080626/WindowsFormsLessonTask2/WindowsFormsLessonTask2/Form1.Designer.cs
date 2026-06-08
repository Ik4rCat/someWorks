namespace WindowsFormsLessonTask2
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
            this.richTextBox = new System.Windows.Forms.RichTextBox();
            this.BoldButton = new System.Windows.Forms.Button();
            this.UnderLinedButton = new System.Windows.Forms.Button();
            this.InclinedButton = new System.Windows.Forms.Button();
            this.InTheCenterButton = new System.Windows.Forms.Button();
            this.SizeTextBox = new System.Windows.Forms.TextBox();
            this.SizeLabel = new System.Windows.Forms.Label();
            this.OpenButton = new System.Windows.Forms.Button();
            this.SaveButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // richTextBox
            // 
            this.richTextBox.Location = new System.Drawing.Point(12, 93);
            this.richTextBox.Name = "richTextBox";
            this.richTextBox.Size = new System.Drawing.Size(776, 314);
            this.richTextBox.TabIndex = 0;
            this.richTextBox.Text = "";
            this.richTextBox.TextChanged += new System.EventHandler(this.richTextBox_TextChanged);
            // 
            // BoldButton
            // 
            this.BoldButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.BoldButton.Location = new System.Drawing.Point(228, 12);
            this.BoldButton.Name = "BoldButton";
            this.BoldButton.Size = new System.Drawing.Size(75, 23);
            this.BoldButton.TabIndex = 1;
            this.BoldButton.Text = "Bold";
            this.BoldButton.UseVisualStyleBackColor = true;
            this.BoldButton.Click += new System.EventHandler(this.BoldButton_Click);
            // 
            // UnderLinedButton
            // 
            this.UnderLinedButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.UnderLinedButton.Location = new System.Drawing.Point(309, 12);
            this.UnderLinedButton.Name = "UnderLinedButton";
            this.UnderLinedButton.Size = new System.Drawing.Size(75, 23);
            this.UnderLinedButton.TabIndex = 2;
            this.UnderLinedButton.Text = "Underlinded";
            this.UnderLinedButton.UseVisualStyleBackColor = true;
            this.UnderLinedButton.Click += new System.EventHandler(this.UnderLinedButton_Click);
            // 
            // InclinedButton
            // 
            this.InclinedButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.InclinedButton.Location = new System.Drawing.Point(390, 12);
            this.InclinedButton.Name = "InclinedButton";
            this.InclinedButton.Size = new System.Drawing.Size(75, 23);
            this.InclinedButton.TabIndex = 3;
            this.InclinedButton.Text = "Inclined";
            this.InclinedButton.UseVisualStyleBackColor = true;
            this.InclinedButton.Click += new System.EventHandler(this.InclinedButton_Click);
            // 
            // InTheCenterButton
            // 
            this.InTheCenterButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.InTheCenterButton.Location = new System.Drawing.Point(471, 12);
            this.InTheCenterButton.Name = "InTheCenterButton";
            this.InTheCenterButton.Size = new System.Drawing.Size(75, 23);
            this.InTheCenterButton.TabIndex = 4;
            this.InTheCenterButton.Text = "In the center";
            this.InTheCenterButton.UseVisualStyleBackColor = true;
            this.InTheCenterButton.Click += new System.EventHandler(this.InTheCenterButton_Click);
            // 
            // SizeTextBox
            // 
            this.SizeTextBox.Location = new System.Drawing.Point(367, 56);
            this.SizeTextBox.Name = "SizeTextBox";
            this.SizeTextBox.Size = new System.Drawing.Size(100, 20);
            this.SizeTextBox.TabIndex = 5;
            this.SizeTextBox.TextChanged += new System.EventHandler(this.SizeTextBox_TextChanged);
            // 
            // SizeLabel
            // 
            this.SizeLabel.AutoSize = true;
            this.SizeLabel.Location = new System.Drawing.Point(334, 59);
            this.SizeLabel.Name = "SizeLabel";
            this.SizeLabel.Size = new System.Drawing.Size(27, 13);
            this.SizeLabel.TabIndex = 6;
            this.SizeLabel.Text = "Size";
            this.SizeLabel.Click += new System.EventHandler(this.SizeLabel_Click);
            // 
            // OpenButton
            // 
            this.OpenButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.OpenButton.Location = new System.Drawing.Point(309, 415);
            this.OpenButton.Name = "OpenButton";
            this.OpenButton.Size = new System.Drawing.Size(75, 23);
            this.OpenButton.TabIndex = 7;
            this.OpenButton.Text = "Open";
            this.OpenButton.UseVisualStyleBackColor = true;
            this.OpenButton.Click += new System.EventHandler(this.OpenButton_Click);
            // 
            // SaveButton
            // 
            this.SaveButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.SaveButton.Location = new System.Drawing.Point(390, 415);
            this.SaveButton.Name = "SaveButton";
            this.SaveButton.Size = new System.Drawing.Size(75, 23);
            this.SaveButton.TabIndex = 8;
            this.SaveButton.Text = "Save";
            this.SaveButton.UseVisualStyleBackColor = true;
            this.SaveButton.Click += new System.EventHandler(this.SaveButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.SaveButton);
            this.Controls.Add(this.OpenButton);
            this.Controls.Add(this.SizeLabel);
            this.Controls.Add(this.SizeTextBox);
            this.Controls.Add(this.InTheCenterButton);
            this.Controls.Add(this.InclinedButton);
            this.Controls.Add(this.UnderLinedButton);
            this.Controls.Add(this.BoldButton);
            this.Controls.Add(this.richTextBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox richTextBox;
        private System.Windows.Forms.Button BoldButton;
        private System.Windows.Forms.Button UnderLinedButton;
        private System.Windows.Forms.Button InclinedButton;
        private System.Windows.Forms.Button InTheCenterButton;
        private System.Windows.Forms.TextBox SizeTextBox;
        private System.Windows.Forms.Label SizeLabel;
        private System.Windows.Forms.Button OpenButton;
        private System.Windows.Forms.Button SaveButton;
    }
}

