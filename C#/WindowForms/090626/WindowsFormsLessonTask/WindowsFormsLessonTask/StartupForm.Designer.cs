namespace WindowsFormsLessonTask
{
    partial class StartupForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnOpenGreen = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnOpenGreen
            // 
            this.btnOpenGreen.Location = new System.Drawing.Point(342, 167);
            this.btnOpenGreen.Name = "btnOpenGreen";
            this.btnOpenGreen.Size = new System.Drawing.Size(75, 23);
            this.btnOpenGreen.TabIndex = 0;
            this.btnOpenGreen.Text = "Green";
            this.btnOpenGreen.UseVisualStyleBackColor = true;
            this.btnOpenGreen.Click += new System.EventHandler(this.btnOpenGreen_Click);
            //
            // StartupForm
            //
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnOpenGreen);
            this.Name = "StartupForm";
            this.Text = "Main";
            this.Load += new System.EventHandler(this.StartupForm_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnOpenGreen;
    }
}