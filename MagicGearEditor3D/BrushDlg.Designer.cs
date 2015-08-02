namespace MagicGearEditor3D
{
    partial class BrushDlg
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
            this.groupBoxShape = new System.Windows.Forms.GroupBox();
            this.rbtnSquare = new System.Windows.Forms.RadioButton();
            this.rbtnCircle = new System.Windows.Forms.RadioButton();
            this.tbInner = new System.Windows.Forms.TrackBar();
            this.label1 = new System.Windows.Forms.Label();
            this.tbOuter = new System.Windows.Forms.TrackBar();
            this.label2 = new System.Windows.Forms.Label();
            this.tbStrength = new System.Windows.Forms.TrackBar();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.cmbLerpMode = new System.Windows.Forms.ComboBox();
            this.groupBoxShape.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tbInner)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbOuter)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbStrength)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBoxShape
            // 
            this.groupBoxShape.Controls.Add(this.rbtnSquare);
            this.groupBoxShape.Controls.Add(this.rbtnCircle);
            this.groupBoxShape.Location = new System.Drawing.Point(12, 12);
            this.groupBoxShape.Name = "groupBoxShape";
            this.groupBoxShape.Size = new System.Drawing.Size(155, 51);
            this.groupBoxShape.TabIndex = 0;
            this.groupBoxShape.TabStop = false;
            this.groupBoxShape.Text = "Shape";
            // 
            // rbtnSquare
            // 
            this.rbtnSquare.AutoSize = true;
            this.rbtnSquare.Location = new System.Drawing.Point(82, 21);
            this.rbtnSquare.Name = "rbtnSquare";
            this.rbtnSquare.Size = new System.Drawing.Size(59, 16);
            this.rbtnSquare.TabIndex = 0;
            this.rbtnSquare.TabStop = true;
            this.rbtnSquare.Text = "Square";
            this.rbtnSquare.UseVisualStyleBackColor = true;
            // 
            // rbtnCircle
            // 
            this.rbtnCircle.AutoSize = true;
            this.rbtnCircle.Checked = true;
            this.rbtnCircle.Location = new System.Drawing.Point(14, 21);
            this.rbtnCircle.Name = "rbtnCircle";
            this.rbtnCircle.Size = new System.Drawing.Size(59, 16);
            this.rbtnCircle.TabIndex = 0;
            this.rbtnCircle.TabStop = true;
            this.rbtnCircle.Text = "Circle";
            this.rbtnCircle.UseVisualStyleBackColor = true;
            // 
            // tbInner
            // 
            this.tbInner.Location = new System.Drawing.Point(99, 80);
            this.tbInner.Maximum = 255;
            this.tbInner.Minimum = 1;
            this.tbInner.Name = "tbInner";
            this.tbInner.Size = new System.Drawing.Size(207, 45);
            this.tbInner.TabIndex = 1;
            this.tbInner.TickFrequency = 8;
            this.tbInner.Value = 10;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 80);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 12);
            this.label1.TabIndex = 2;
            this.label1.Text = "Inner radius";
            // 
            // tbOuter
            // 
            this.tbOuter.Location = new System.Drawing.Point(99, 128);
            this.tbOuter.Maximum = 255;
            this.tbOuter.Minimum = 1;
            this.tbOuter.Name = "tbOuter";
            this.tbOuter.Size = new System.Drawing.Size(207, 45);
            this.tbOuter.TabIndex = 1;
            this.tbOuter.TickFrequency = 8;
            this.tbOuter.Value = 20;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 128);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(77, 12);
            this.label2.TabIndex = 2;
            this.label2.Text = "Outer radius";
            // 
            // tbStrength
            // 
            this.tbStrength.Location = new System.Drawing.Point(99, 176);
            this.tbStrength.Maximum = 255;
            this.tbStrength.Minimum = 1;
            this.tbStrength.Name = "tbStrength";
            this.tbStrength.Size = new System.Drawing.Size(207, 45);
            this.tbStrength.TabIndex = 1;
            this.tbStrength.TickFrequency = 8;
            this.tbStrength.Value = 40;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(13, 176);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 12);
            this.label3.TabIndex = 2;
            this.label3.Text = "Strength";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(189, 22);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(59, 12);
            this.label4.TabIndex = 1;
            this.label4.Text = "Lerp mode";
            // 
            // cmbLerpMode
            // 
            this.cmbLerpMode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbLerpMode.FormattingEnabled = true;
            this.cmbLerpMode.Items.AddRange(new object[] {
            "None",
            "Linear",
            "Cosine",
            "Quadratic"});
            this.cmbLerpMode.Location = new System.Drawing.Point(191, 43);
            this.cmbLerpMode.Name = "cmbLerpMode";
            this.cmbLerpMode.Size = new System.Drawing.Size(115, 20);
            this.cmbLerpMode.TabIndex = 2;
            // 
            // BrushDlg
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(318, 231);
            this.Controls.Add(this.cmbLerpMode);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbStrength);
            this.Controls.Add(this.tbOuter);
            this.Controls.Add(this.tbInner);
            this.Controls.Add(this.groupBoxShape);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.MaximizeBox = false;
            this.Name = "BrushDlg";
            this.ShowInTaskbar = false;
            this.Text = "Brush setting";
            this.groupBoxShape.ResumeLayout(false);
            this.groupBoxShape.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tbInner)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbOuter)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbStrength)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxShape;
        private System.Windows.Forms.RadioButton rbtnCircle;
        private System.Windows.Forms.RadioButton rbtnSquare;
        private System.Windows.Forms.TrackBar tbInner;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TrackBar tbOuter;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TrackBar tbStrength;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox cmbLerpMode;
    }
}