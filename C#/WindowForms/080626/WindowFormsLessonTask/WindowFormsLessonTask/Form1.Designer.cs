namespace WindowFormsLessonTask
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
            this.label1 = new System.Windows.Forms.Label();
            this.NameLabel = new System.Windows.Forms.Label();
            this.AdressLabel = new System.Windows.Forms.Label();
            this.OKButton = new System.Windows.Forms.Button();
            this.NameTextBox = new System.Windows.Forms.TextBox();
            this.AdressRichTextBox = new System.Windows.Forms.RichTextBox();
            this.HelpButton = new System.Windows.Forms.Button();
            this.IsProgrammerCheckBox = new System.Windows.Forms.CheckBox();
            this.SexGroupBox = new System.Windows.Forms.GroupBox();
            this.AgeLabel = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.ResultLabel = new System.Windows.Forms.Label();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.AdressvScrollBar = new System.Windows.Forms.VScrollBar();
            this.ResultvScrollBar = new System.Windows.Forms.VScrollBar();
            this.FemaleRadioButton = new System.Windows.Forms.RadioButton();
            this.MaleRadioButton = new System.Windows.Forms.RadioButton();
            this.SexGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(0, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(100, 23);
            this.label1.TabIndex = 0;
            // 
            // NameLabel
            // 
            this.NameLabel.AutoSize = true;
            this.NameLabel.Cursor = System.Windows.Forms.Cursors.Cross;
            this.NameLabel.Location = new System.Drawing.Point(32, 23);
            this.NameLabel.Name = "NameLabel";
            this.NameLabel.Size = new System.Drawing.Size(35, 13);
            this.NameLabel.TabIndex = 1;
            this.NameLabel.Text = "Name";
            this.NameLabel.Click += new System.EventHandler(this.NameLabel_Click);
            // 
            // AdressLabel
            // 
            this.AdressLabel.AutoSize = true;
            this.AdressLabel.Cursor = System.Windows.Forms.Cursors.Cross;
            this.AdressLabel.Location = new System.Drawing.Point(32, 55);
            this.AdressLabel.Name = "AdressLabel";
            this.AdressLabel.Size = new System.Drawing.Size(39, 13);
            this.AdressLabel.TabIndex = 2;
            this.AdressLabel.Text = "Adress";
            this.AdressLabel.Click += new System.EventHandler(this.AdressLabel_Click);
            // 
            // OKButton
            // 
            this.OKButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.OKButton.Location = new System.Drawing.Point(452, 25);
            this.OKButton.Name = "OKButton";
            this.OKButton.Size = new System.Drawing.Size(75, 23);
            this.OKButton.TabIndex = 3;
            this.OKButton.Text = "OK";
            this.OKButton.UseVisualStyleBackColor = true;
            this.OKButton.Click += new System.EventHandler(this.OKButton_Click);
            // 
            // NameTextBox
            // 
            this.NameTextBox.Location = new System.Drawing.Point(100, 25);
            this.NameTextBox.Name = "NameTextBox";
            this.NameTextBox.Size = new System.Drawing.Size(346, 20);
            this.NameTextBox.TabIndex = 4;
            this.NameTextBox.TextChanged += new System.EventHandler(this.NameTextBox_TextChanged);
            // 
            // AdressRichTextBox
            // 
            this.AdressRichTextBox.Location = new System.Drawing.Point(100, 55);
            this.AdressRichTextBox.Name = "AdressRichTextBox";
            this.AdressRichTextBox.Size = new System.Drawing.Size(346, 96);
            this.AdressRichTextBox.TabIndex = 6;
            this.AdressRichTextBox.Text = "";
            this.AdressRichTextBox.TextChanged += new System.EventHandler(this.AdressRichTextBox_TextChanged);
            // 
            // HelpButton
            // 
            this.HelpButton.Cursor = System.Windows.Forms.Cursors.Help;
            this.HelpButton.Location = new System.Drawing.Point(452, 55);
            this.HelpButton.Name = "HelpButton";
            this.HelpButton.Size = new System.Drawing.Size(75, 23);
            this.HelpButton.TabIndex = 7;
            this.HelpButton.Text = "Help";
            this.HelpButton.UseVisualStyleBackColor = true;
            this.HelpButton.Click += new System.EventHandler(this.HelpButton_Click);
            // 
            // IsProgrammerCheckBox
            // 
            this.IsProgrammerCheckBox.AutoSize = true;
            this.IsProgrammerCheckBox.Cursor = System.Windows.Forms.Cursors.Help;
            this.IsProgrammerCheckBox.Location = new System.Drawing.Point(35, 174);
            this.IsProgrammerCheckBox.Name = "IsProgrammerCheckBox";
            this.IsProgrammerCheckBox.Size = new System.Drawing.Size(82, 17);
            this.IsProgrammerCheckBox.TabIndex = 8;
            this.IsProgrammerCheckBox.Text = "Programmer";
            this.IsProgrammerCheckBox.UseVisualStyleBackColor = true;
            this.IsProgrammerCheckBox.CheckedChanged += new System.EventHandler(this.IsProgrammerCheckBox_CheckedChanged);
            // 
            // SexGroupBox
            // 
            this.SexGroupBox.Controls.Add(this.MaleRadioButton);
            this.SexGroupBox.Controls.Add(this.FemaleRadioButton);
            this.SexGroupBox.Location = new System.Drawing.Point(35, 209);
            this.SexGroupBox.Name = "SexGroupBox";
            this.SexGroupBox.Size = new System.Drawing.Size(492, 78);
            this.SexGroupBox.TabIndex = 9;
            this.SexGroupBox.TabStop = false;
            this.SexGroupBox.Text = "Gender";
            this.SexGroupBox.Enter += new System.EventHandler(this.SexGroupBox_Enter);
            // 
            // AgeLabel
            // 
            this.AgeLabel.AutoSize = true;
            this.AgeLabel.Cursor = System.Windows.Forms.Cursors.Cross;
            this.AgeLabel.Location = new System.Drawing.Point(35, 307);
            this.AgeLabel.Name = "AgeLabel";
            this.AgeLabel.Size = new System.Drawing.Size(26, 13);
            this.AgeLabel.TabIndex = 10;
            this.AgeLabel.Text = "Age";
            this.AgeLabel.Click += new System.EventHandler(this.AgeLabel_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(100, 307);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(346, 20);
            this.textBox1.TabIndex = 11;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // ResultLabel
            // 
            this.ResultLabel.AutoSize = true;
            this.ResultLabel.Cursor = System.Windows.Forms.Cursors.Cross;
            this.ResultLabel.Location = new System.Drawing.Point(36, 340);
            this.ResultLabel.Name = "ResultLabel";
            this.ResultLabel.Size = new System.Drawing.Size(37, 13);
            this.ResultLabel.TabIndex = 12;
            this.ResultLabel.Text = "Result";
            this.ResultLabel.Click += new System.EventHandler(this.ResultLabel_Click);
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(38, 367);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(408, 133);
            this.richTextBox1.TabIndex = 13;
            this.richTextBox1.Text = "";
            this.richTextBox1.TextChanged += new System.EventHandler(this.richTextBox1_TextChanged);
            // 
            // AdressvScrollBar
            // 
            this.AdressvScrollBar.Location = new System.Drawing.Point(430, 55);
            this.AdressvScrollBar.Name = "AdressvScrollBar";
            this.AdressvScrollBar.Size = new System.Drawing.Size(16, 96);
            this.AdressvScrollBar.TabIndex = 14;
            this.AdressvScrollBar.Scroll += new System.Windows.Forms.ScrollEventHandler(this.AdressvScrollBar_Scroll);
            // 
            // ResultvScrollBar
            // 
            this.ResultvScrollBar.Location = new System.Drawing.Point(430, 367);
            this.ResultvScrollBar.Name = "ResultvScrollBar";
            this.ResultvScrollBar.Size = new System.Drawing.Size(14, 133);
            this.ResultvScrollBar.TabIndex = 15;
            this.ResultvScrollBar.Scroll += new System.Windows.Forms.ScrollEventHandler(this.ResultvScrollBar_Scroll);
            // 
            // FemaleRadioButton
            // 
            this.FemaleRadioButton.AutoSize = true;
            this.FemaleRadioButton.Location = new System.Drawing.Point(144, 36);
            this.FemaleRadioButton.Name = "FemaleRadioButton";
            this.FemaleRadioButton.Size = new System.Drawing.Size(59, 17);
            this.FemaleRadioButton.TabIndex = 0;
            this.FemaleRadioButton.TabStop = true;
            this.FemaleRadioButton.Text = "Female";
            this.FemaleRadioButton.UseVisualStyleBackColor = true;
            this.FemaleRadioButton.CheckedChanged += new System.EventHandler(this.FemaleRadioButton_CheckedChanged);
            // 
            // MaleRadioButton
            // 
            this.MaleRadioButton.AutoSize = true;
            this.MaleRadioButton.Location = new System.Drawing.Point(292, 36);
            this.MaleRadioButton.Name = "MaleRadioButton";
            this.MaleRadioButton.Size = new System.Drawing.Size(48, 17);
            this.MaleRadioButton.TabIndex = 1;
            this.MaleRadioButton.TabStop = true;
            this.MaleRadioButton.Text = "Male";
            this.MaleRadioButton.UseVisualStyleBackColor = true;
            this.MaleRadioButton.CheckedChanged += new System.EventHandler(this.MaleRadioButton_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(555, 525);
            this.Controls.Add(this.ResultvScrollBar);
            this.Controls.Add(this.AdressvScrollBar);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.ResultLabel);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.AgeLabel);
            this.Controls.Add(this.SexGroupBox);
            this.Controls.Add(this.IsProgrammerCheckBox);
            this.Controls.Add(this.HelpButton);
            this.Controls.Add(this.AdressRichTextBox);
            this.Controls.Add(this.NameTextBox);
            this.Controls.Add(this.OKButton);
            this.Controls.Add(this.AdressLabel);
            this.Controls.Add(this.NameLabel);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.SexGroupBox.ResumeLayout(false);
            this.SexGroupBox.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label NameLabel;
        private System.Windows.Forms.Label AdressLabel;
        private System.Windows.Forms.Button OKButton;
        private System.Windows.Forms.TextBox NameTextBox;
        private System.Windows.Forms.RichTextBox AdressRichTextBox;
        private System.Windows.Forms.Button HelpButton;
        private System.Windows.Forms.CheckBox IsProgrammerCheckBox;
        private System.Windows.Forms.GroupBox SexGroupBox;
        private System.Windows.Forms.Label AgeLabel;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label ResultLabel;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.VScrollBar AdressvScrollBar;
        private System.Windows.Forms.VScrollBar ResultvScrollBar;
        private System.Windows.Forms.RadioButton MaleRadioButton;
        private System.Windows.Forms.RadioButton FemaleRadioButton;
    }
}

