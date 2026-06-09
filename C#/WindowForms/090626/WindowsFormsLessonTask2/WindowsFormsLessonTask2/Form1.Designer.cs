namespace WindowsFormsLessonTask2
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mdiToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.sdiToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            //
            // menuStrip1
            //
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            //
            // newToolStripMenuItem
            //
            this.newToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mdiToolStripMenuItem,
            this.sdiToolStripMenuItem});
            this.newToolStripMenuItem.Name = "newToolStripMenuItem";
            this.newToolStripMenuItem.Size = new System.Drawing.Size(43, 20);
            this.newToolStripMenuItem.Text = "New";
            //
            // mdiToolStripMenuItem
            //
            this.mdiToolStripMenuItem.Name = "mdiToolStripMenuItem";
            this.mdiToolStripMenuItem.Size = new System.Drawing.Size(100, 22);
            this.mdiToolStripMenuItem.Text = "MDI";
            this.mdiToolStripMenuItem.Click += new System.EventHandler(this.mdiToolStripMenuItem_Click);
            //
            // sdiToolStripMenuItem
            //
            this.sdiToolStripMenuItem.Name = "sdiToolStripMenuItem";
            this.sdiToolStripMenuItem.Size = new System.Drawing.Size(100, 22);
            this.sdiToolStripMenuItem.Text = "SDI";
            this.sdiToolStripMenuItem.Click += new System.EventHandler(this.sdiToolStripMenuItem_Click);
            //
            // Form1
            //
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.Name = "Form1";
            this.Text = "MDI Form";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mdiToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem sdiToolStripMenuItem;
    }
}
