namespace WindowsFormsLessonTask3
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
            this.BorderStyleButton = new System.Windows.Forms.Button();
            this.ResizeButton = new System.Windows.Forms.Button();
            this.OpacityButton = new System.Windows.Forms.Button();
            this.OpenPart2Button = new System.Windows.Forms.Button();
            this.OpenPart3Button = new System.Windows.Forms.Button();
            this.OriginalViewButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // BorderStyleButton
            // 
            this.BorderStyleButton.Location = new System.Drawing.Point(12, 12);
            this.BorderStyleButton.Name = "BorderStyleButton";
            this.BorderStyleButton.Size = new System.Drawing.Size(75, 23);
            this.BorderStyleButton.TabIndex = 0;
            this.BorderStyleButton.Text = "Border Style";
            this.BorderStyleButton.UseVisualStyleBackColor = true;
            this.BorderStyleButton.Click += new System.EventHandler(this.BorderStyleButton_Click);
            // 
            // ResizeButton
            // 
            this.ResizeButton.Location = new System.Drawing.Point(12, 41);
            this.ResizeButton.Name = "ResizeButton";
            this.ResizeButton.Size = new System.Drawing.Size(75, 23);
            this.ResizeButton.TabIndex = 1;
            this.ResizeButton.Text = "Resize";
            this.ResizeButton.UseVisualStyleBackColor = true;
            this.ResizeButton.Click += new System.EventHandler(this.ResizeButton_Click);
            // 
            // OpacityButton
            // 
            this.OpacityButton.Location = new System.Drawing.Point(12, 70);
            this.OpacityButton.Name = "OpacityButton";
            this.OpacityButton.Size = new System.Drawing.Size(75, 23);
            this.OpacityButton.TabIndex = 2;
            this.OpacityButton.Text = "Opacity";
            this.OpacityButton.UseVisualStyleBackColor = true;
            this.OpacityButton.Click += new System.EventHandler(this.OpacityButton_Click);
            // 
            // OpenPart2Button
            // 
            this.OpenPart2Button.Location = new System.Drawing.Point(12, 99);
            this.OpenPart2Button.Name = "OpenPart2Button";
            this.OpenPart2Button.Size = new System.Drawing.Size(75, 23);
            this.OpenPart2Button.TabIndex = 3;
            this.OpenPart2Button.Text = "Open part 2";
            this.OpenPart2Button.UseVisualStyleBackColor = true;
            this.OpenPart2Button.Click += new System.EventHandler(this.OpenPart2Button_Click);
            // 
            // OpenPart3Button
            // 
            this.OpenPart3Button.Location = new System.Drawing.Point(12, 128);
            this.OpenPart3Button.Name = "OpenPart3Button";
            this.OpenPart3Button.Size = new System.Drawing.Size(75, 23);
            this.OpenPart3Button.TabIndex = 4;
            this.OpenPart3Button.Text = "Open part 3";
            this.OpenPart3Button.UseVisualStyleBackColor = true;
            this.OpenPart3Button.Click += new System.EventHandler(this.OpenPart3Button_Click);
            // 
            // OriginalViewButton
            // 
            this.OriginalViewButton.Location = new System.Drawing.Point(12, 157);
            this.OriginalViewButton.Name = "OriginalViewButton";
            this.OriginalViewButton.Size = new System.Drawing.Size(75, 23);
            this.OriginalViewButton.TabIndex = 5;
            this.OriginalViewButton.Text = "Original view";
            this.OriginalViewButton.UseVisualStyleBackColor = true;
            this.OriginalViewButton.Click += new System.EventHandler(this.OriginalViewButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(97, 190);
            this.Controls.Add(this.OriginalViewButton);
            this.Controls.Add(this.OpenPart3Button);
            this.Controls.Add(this.OpenPart2Button);
            this.Controls.Add(this.OpacityButton);
            this.Controls.Add(this.ResizeButton);
            this.Controls.Add(this.BorderStyleButton);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Location = new System.Drawing.Point(100, 200);
            this.Name = "Form1";
            this.Opacity = 0.75D;
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Trey Reserch";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button BorderStyleButton;
        private System.Windows.Forms.Button ResizeButton;
        private System.Windows.Forms.Button OpacityButton;
        private System.Windows.Forms.Button OpenPart2Button;
        private System.Windows.Forms.Button OpenPart3Button;
        private System.Windows.Forms.Button OriginalViewButton;
    }
}

