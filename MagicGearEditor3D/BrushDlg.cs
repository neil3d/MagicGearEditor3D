using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace MagicGearEditor3D
{
    public partial class BrushDlg : Form
    {
        public BrushDlg()
        {
            InitializeComponent();

            cmbLerpMode.SelectedIndex = 1;
        }

        private void UpdateBrush()
        {
            int shape = 0;
            if (rbtnSquare.Checked)
                shape = 1;

            int lerpMode = cmbLerpMode.SelectedIndex;

            int innerRadius = tbInner.Value;
            int outerRadius = tbOuter.Value;
            int strength = tbStrength.Value;

            CoreAPI.mgSetBrush(shape, lerpMode, innerRadius, outerRadius, strength);
        }
    }
}