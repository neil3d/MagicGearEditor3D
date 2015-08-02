namespace MagicGearEditor3D
{
    partial class NewMapDlg
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
            this.btnOK = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.hmapProperty = new System.Windows.Forms.GroupBox();
            this.cmbBits = new System.Windows.Forms.ComboBox();
            this.textYScale = new System.Windows.Forms.TextBox();
            this.textHeight = new System.Windows.Forms.TextBox();
            this.textZScale = new System.Windows.Forms.TextBox();
            this.textXScale = new System.Windows.Forms.TextBox();
            this.textWidth = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.hmapInit = new System.Windows.Forms.GroupBox();
            this.rbtnInitNoise = new System.Windows.Forms.RadioButton();
            this.rbtnInitValue = new System.Windows.Forms.RadioButton();
            this.textAmplitude = new System.Windows.Forms.TextBox();
            this.labelAmplitude = new System.Windows.Forms.Label();
            this.textOctaves = new System.Windows.Forms.TextBox();
            this.labelOctaves = new System.Windows.Forms.Label();
            this.textInit = new System.Windows.Forms.TextBox();
            this.lbInitType = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.textName = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnAsHeightmap = new System.Windows.Forms.CheckBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.tbAlphamapW = new System.Windows.Forms.TextBox();
            this.tbAlphamapH = new System.Windows.Forms.TextBox();
            this.hmapProperty.SuspendLayout();
            this.hmapInit.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnOK
            // 
            this.btnOK.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnOK.Location = new System.Drawing.Point(99, 359);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(75, 23);
            this.btnOK.TabIndex = 2;
            this.btnOK.Text = "OK";
            this.btnOK.UseVisualStyleBackColor = true;
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(222, 359);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 3;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // hmapProperty
            // 
            this.hmapProperty.Controls.Add(this.cmbBits);
            this.hmapProperty.Controls.Add(this.textYScale);
            this.hmapProperty.Controls.Add(this.textHeight);
            this.hmapProperty.Controls.Add(this.textZScale);
            this.hmapProperty.Controls.Add(this.textXScale);
            this.hmapProperty.Controls.Add(this.textWidth);
            this.hmapProperty.Controls.Add(this.label2);
            this.hmapProperty.Controls.Add(this.label6);
            this.hmapProperty.Controls.Add(this.label4);
            this.hmapProperty.Controls.Add(this.label5);
            this.hmapProperty.Controls.Add(this.label3);
            this.hmapProperty.Controls.Add(this.label1);
            this.hmapProperty.Location = new System.Drawing.Point(12, 51);
            this.hmapProperty.Name = "hmapProperty";
            this.hmapProperty.Size = new System.Drawing.Size(371, 109);
            this.hmapProperty.TabIndex = 1;
            this.hmapProperty.TabStop = false;
            this.hmapProperty.Text = "Height map property";
            // 
            // cmbBits
            // 
            this.cmbBits.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbBits.FormattingEnabled = true;
            this.cmbBits.Items.AddRange(new object[] {
            "8Bits",
            "16Bits"});
            this.cmbBits.Location = new System.Drawing.Point(268, 81);
            this.cmbBits.Name = "cmbBits";
            this.cmbBits.Size = new System.Drawing.Size(89, 20);
            this.cmbBits.TabIndex = 5;
            // 
            // textYScale
            // 
            this.textYScale.Location = new System.Drawing.Point(268, 54);
            this.textYScale.Name = "textYScale";
            this.textYScale.Size = new System.Drawing.Size(89, 21);
            this.textYScale.TabIndex = 3;
            this.textYScale.Text = "10";
            // 
            // textHeight
            // 
            this.textHeight.Location = new System.Drawing.Point(268, 28);
            this.textHeight.Name = "textHeight";
            this.textHeight.Size = new System.Drawing.Size(89, 21);
            this.textHeight.TabIndex = 1;
            this.textHeight.Text = "128";
            this.textHeight.TextChanged += new System.EventHandler(this.heightmapHeightChanged);
            // 
            // textZScale
            // 
            this.textZScale.Location = new System.Drawing.Point(83, 80);
            this.textZScale.Name = "textZScale";
            this.textZScale.Size = new System.Drawing.Size(89, 21);
            this.textZScale.TabIndex = 4;
            this.textZScale.Text = "50";
            // 
            // textXScale
            // 
            this.textXScale.Location = new System.Drawing.Point(83, 54);
            this.textXScale.Name = "textXScale";
            this.textXScale.Size = new System.Drawing.Size(89, 21);
            this.textXScale.TabIndex = 2;
            this.textXScale.Text = "50";
            // 
            // textWidth
            // 
            this.textWidth.Location = new System.Drawing.Point(83, 28);
            this.textWidth.Name = "textWidth";
            this.textWidth.Size = new System.Drawing.Size(89, 21);
            this.textWidth.TabIndex = 0;
            this.textWidth.Text = "128";
            this.textWidth.TextChanged += new System.EventHandler(this.heightmapWidthChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.label2.Location = new System.Drawing.Point(211, 28);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(41, 12);
            this.label2.TabIndex = 0;
            this.label2.Text = "Height";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.label6.Location = new System.Drawing.Point(211, 80);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(29, 12);
            this.label6.TabIndex = 0;
            this.label6.Text = "Bits";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.label4.Location = new System.Drawing.Point(211, 54);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(47, 12);
            this.label4.TabIndex = 0;
            this.label4.Text = "Y Scale";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.label5.Location = new System.Drawing.Point(27, 80);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(47, 12);
            this.label5.TabIndex = 0;
            this.label5.Text = "Z Scale";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.label3.Location = new System.Drawing.Point(27, 54);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(47, 12);
            this.label3.TabIndex = 0;
            this.label3.Text = "X Scale";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.label1.Location = new System.Drawing.Point(27, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "Width";
            // 
            // hmapInit
            // 
            this.hmapInit.Controls.Add(this.rbtnInitNoise);
            this.hmapInit.Controls.Add(this.rbtnInitValue);
            this.hmapInit.Controls.Add(this.textAmplitude);
            this.hmapInit.Controls.Add(this.labelAmplitude);
            this.hmapInit.Controls.Add(this.textOctaves);
            this.hmapInit.Controls.Add(this.labelOctaves);
            this.hmapInit.Controls.Add(this.textInit);
            this.hmapInit.Controls.Add(this.lbInitType);
            this.hmapInit.Location = new System.Drawing.Point(13, 255);
            this.hmapInit.Name = "hmapInit";
            this.hmapInit.Size = new System.Drawing.Size(371, 98);
            this.hmapInit.TabIndex = 2;
            this.hmapInit.TabStop = false;
            this.hmapInit.Text = "Height map init";
            // 
            // rbtnInitNoise
            // 
            this.rbtnInitNoise.AutoSize = true;
            this.rbtnInitNoise.Location = new System.Drawing.Point(213, 21);
            this.rbtnInitNoise.Name = "rbtnInitNoise";
            this.rbtnInitNoise.Size = new System.Drawing.Size(53, 16);
            this.rbtnInitNoise.TabIndex = 1;
            this.rbtnInitNoise.Text = "noise";
            this.rbtnInitNoise.UseVisualStyleBackColor = true;
            this.rbtnInitNoise.CheckedChanged += new System.EventHandler(this.rbtnInitNoise_CheckedChanged);
            // 
            // rbtnInitValue
            // 
            this.rbtnInitValue.AutoSize = true;
            this.rbtnInitValue.Checked = true;
            this.rbtnInitValue.Location = new System.Drawing.Point(26, 21);
            this.rbtnInitValue.Name = "rbtnInitValue";
            this.rbtnInitValue.Size = new System.Drawing.Size(53, 16);
            this.rbtnInitValue.TabIndex = 0;
            this.rbtnInitValue.TabStop = true;
            this.rbtnInitValue.Text = "value";
            this.rbtnInitValue.UseVisualStyleBackColor = true;
            this.rbtnInitValue.CheckedChanged += new System.EventHandler(this.rbtnInitValue_CheckedChanged);
            // 
            // textAmplitude
            // 
            this.textAmplitude.Location = new System.Drawing.Point(314, 51);
            this.textAmplitude.Name = "textAmplitude";
            this.textAmplitude.Size = new System.Drawing.Size(43, 21);
            this.textAmplitude.TabIndex = 2;
            this.textAmplitude.Text = "20";
            this.textAmplitude.Visible = false;
            // 
            // labelAmplitude
            // 
            this.labelAmplitude.AutoSize = true;
            this.labelAmplitude.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.labelAmplitude.Location = new System.Drawing.Point(253, 53);
            this.labelAmplitude.Name = "labelAmplitude";
            this.labelAmplitude.Size = new System.Drawing.Size(59, 12);
            this.labelAmplitude.TabIndex = 3;
            this.labelAmplitude.Text = "Amplitude";
            this.labelAmplitude.Visible = false;
            // 
            // textOctaves
            // 
            this.textOctaves.Location = new System.Drawing.Point(197, 51);
            this.textOctaves.Name = "textOctaves";
            this.textOctaves.Size = new System.Drawing.Size(43, 21);
            this.textOctaves.TabIndex = 2;
            this.textOctaves.Text = "8";
            this.textOctaves.Visible = false;
            // 
            // labelOctaves
            // 
            this.labelOctaves.AutoSize = true;
            this.labelOctaves.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.labelOctaves.Location = new System.Drawing.Point(141, 54);
            this.labelOctaves.Name = "labelOctaves";
            this.labelOctaves.Size = new System.Drawing.Size(47, 12);
            this.labelOctaves.TabIndex = 3;
            this.labelOctaves.Text = "Octaves";
            this.labelOctaves.Visible = false;
            // 
            // textInit
            // 
            this.textInit.Location = new System.Drawing.Point(83, 51);
            this.textInit.Name = "textInit";
            this.textInit.Size = new System.Drawing.Size(43, 21);
            this.textInit.TabIndex = 2;
            this.textInit.Text = "0";
            // 
            // lbInitType
            // 
            this.lbInitType.AutoSize = true;
            this.lbInitType.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.lbInitType.Location = new System.Drawing.Point(21, 54);
            this.lbInitType.Name = "lbInitType";
            this.lbInitType.Size = new System.Drawing.Size(35, 12);
            this.lbInitType.TabIndex = 3;
            this.lbInitType.Text = "Value";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.label7.Location = new System.Drawing.Point(39, 24);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(53, 12);
            this.label7.TabIndex = 0;
            this.label7.Text = "Map Name";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // textName
            // 
            this.textName.Location = new System.Drawing.Point(95, 24);
            this.textName.Name = "textName";
            this.textName.Size = new System.Drawing.Size(175, 21);
            this.textName.TabIndex = 0;
            this.textName.Text = "MyMap";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnAsHeightmap);
            this.groupBox1.Controls.Add(this.tbAlphamapH);
            this.groupBox1.Controls.Add(this.label8);
            this.groupBox1.Controls.Add(this.label9);
            this.groupBox1.Controls.Add(this.tbAlphamapW);
            this.groupBox1.Location = new System.Drawing.Point(13, 166);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(370, 83);
            this.groupBox1.TabIndex = 4;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Alpha map resolution";
            // 
            // btnAsHeightmap
            // 
            this.btnAsHeightmap.AutoSize = true;
            this.btnAsHeightmap.Checked = true;
            this.btnAsHeightmap.CheckState = System.Windows.Forms.CheckState.Checked;
            this.btnAsHeightmap.Location = new System.Drawing.Point(28, 21);
            this.btnAsHeightmap.Name = "btnAsHeightmap";
            this.btnAsHeightmap.Size = new System.Drawing.Size(126, 16);
            this.btnAsHeightmap.TabIndex = 0;
            this.btnAsHeightmap.Text = "Same as heightmap";
            this.btnAsHeightmap.UseVisualStyleBackColor = true;
            this.btnAsHeightmap.CheckedChanged += new System.EventHandler(this.btnAlphaAsHeightChanged);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.label8.Location = new System.Drawing.Point(26, 51);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(35, 12);
            this.label8.TabIndex = 0;
            this.label8.Text = "Width";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.label9.Location = new System.Drawing.Point(210, 51);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(41, 12);
            this.label9.TabIndex = 0;
            this.label9.Text = "Height";
            // 
            // tbAlphamapW
            // 
            this.tbAlphamapW.Location = new System.Drawing.Point(82, 51);
            this.tbAlphamapW.Name = "tbAlphamapW";
            this.tbAlphamapW.Size = new System.Drawing.Size(89, 21);
            this.tbAlphamapW.TabIndex = 0;
            this.tbAlphamapW.Text = "128";
            // 
            // tbAlphamapH
            // 
            this.tbAlphamapH.Location = new System.Drawing.Point(267, 51);
            this.tbAlphamapH.Name = "tbAlphamapH";
            this.tbAlphamapH.Size = new System.Drawing.Size(89, 21);
            this.tbAlphamapH.TabIndex = 1;
            this.tbAlphamapH.Text = "128";
            // 
            // NewMapDlg
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(396, 392);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.hmapInit);
            this.Controls.Add(this.hmapProperty);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnOK);
            this.Controls.Add(this.textName);
            this.Controls.Add(this.label7);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.Name = "NewMapDlg";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Create a new map ...";
            this.hmapProperty.ResumeLayout(false);
            this.hmapProperty.PerformLayout();
            this.hmapInit.ResumeLayout(false);
            this.hmapInit.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.GroupBox hmapProperty;
        private System.Windows.Forms.GroupBox hmapInit;
        private System.Windows.Forms.RadioButton rbtnInitNoise;
        private System.Windows.Forms.RadioButton rbtnInitValue;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textYScale;
        private System.Windows.Forms.TextBox textHeight;
        private System.Windows.Forms.TextBox textZScale;
        private System.Windows.Forms.TextBox textXScale;
        private System.Windows.Forms.TextBox textWidth;
        private System.Windows.Forms.TextBox textInit;
        private System.Windows.Forms.Label lbInitType;
        private System.Windows.Forms.ComboBox cmbBits;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox textName;
        private System.Windows.Forms.TextBox textAmplitude;
        private System.Windows.Forms.Label labelAmplitude;
        private System.Windows.Forms.TextBox textOctaves;
        private System.Windows.Forms.Label labelOctaves;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.CheckBox btnAsHeightmap;
        private System.Windows.Forms.TextBox tbAlphamapH;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox tbAlphamapW;
    }
}