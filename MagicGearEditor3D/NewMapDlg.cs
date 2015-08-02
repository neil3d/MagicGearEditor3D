using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace MagicGearEditor3D
{
    public partial class NewMapDlg : Form
    {
        public enum EInitType
        {
            Value,
            Noise
        }

        public NewMapDlg()
        {
            InitializeComponent();
            
            this.cmbBits.SelectedIndex = 0;
            btnAlphaAsHeightChanged(this, null);
        }

        public string GetMapName()
        {
            return textName.Text;
        }

        public int GetHMapWidth()
        {
            return int.Parse(textWidth.Text);
        }

        public int GetHMapHeight()
        {
            return int.Parse(textHeight.Text);
        }

        public float GetHMapXScale()
        {
            return float.Parse(textXScale.Text);
        }

        public float GetHMapYScale()
        {
            return float.Parse(textYScale.Text);
        }

        public float GetHMapZScale()
        {
            return float.Parse(textZScale.Text);
        }

        public int GetHMapBits()
        {
            if (cmbBits.SelectedIndex == 0)
                return 8;
            else
                return 16;
        }

        public int GetInitValue()
        {
            if (GetInitType() == EInitType.Value)
                return int.Parse(textInit.Text);
            else
                return 0;
        }

        public EInitType GetInitType()
        {
            if (rbtnInitNoise.Checked)
                return EInitType.Noise;
            else
                return EInitType.Value;
        }

        public float GetNoiseFrequency()
        {
            return float.Parse(textInit.Text);
        }

        public int GetNoiseOctaves()
        {
            return int.Parse(textOctaves.Text);
        }

        public float GetNoiseAmplitude()
        {
            return float.Parse(textAmplitude.Text);
        }

        private void rbtnInitNoise_CheckedChanged(object sender, EventArgs e)
        {
            textAmplitude.Show();
            textOctaves.Show();

            labelAmplitude.Show();
            labelOctaves.Show();

            textInit.Text = "4.0";
            lbInitType.Text = "Frequency";
        }

        private void rbtnInitValue_CheckedChanged(object sender, EventArgs e)
        {
            textAmplitude.Hide();
            textOctaves.Hide();

            labelAmplitude.Hide();
            labelOctaves.Hide();

            textInit.Text = "0";
            lbInitType.Text = "Value";
        }

        private void btnAlphaAsHeightChanged(object sender, EventArgs e)
        {
            bool bChecked = btnAsHeightmap.Checked;

            tbAlphamapW.Enabled = !bChecked;
            tbAlphamapH.Enabled = !bChecked;
        }

        private void heightmapWidthChanged(object sender, EventArgs e)
        {
            if (btnAsHeightmap.Checked)
                tbAlphamapW.Text = textWidth.Text;
        }

        private void heightmapHeightChanged(object sender, EventArgs e)
        {
            if (btnAsHeightmap.Checked)
                tbAlphamapH.Text = textHeight.Text;
        }
    }
}