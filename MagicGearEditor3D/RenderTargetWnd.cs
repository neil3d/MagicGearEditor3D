using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace MagicGearEditor3D
{
    public partial class RenderTargetWnd : Control
    {
        private InputMessageDispatch m_dispatchInput;

        public RenderTargetWnd(InputMessageDispatch dispatchInput)
        {
            InitializeComponent();

            m_dispatchInput = dispatchInput;
        }

        protected override void WndProc(ref Message m)
        {
            m_dispatchInput.onInputMessage(ref m);
            base.WndProc(ref m);
        }

        protected override void OnPaint(PaintEventArgs pe)
        {
            // TODO: Add custom paint code here
            CoreAPI.mgRender();

            // Calling the base class OnPaint
            base.OnPaint(pe);
        }
    }
}
