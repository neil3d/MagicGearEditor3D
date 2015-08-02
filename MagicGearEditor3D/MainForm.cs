using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace MagicGearEditor3D
{
    public partial class MainForm : Form
    {
        private HeightmapToolsDlg m_heightMapToolsDlg;
        private BrushDlg m_brushDlg;
        private InputMessageDispatch m_dispatchInput;
        private RenderTargetWnd m_renderTargetWnd;
        
        public MainForm(int clientW, int clientH)
        {
            InitializeComponent();
            
            m_dispatchInput = new InputMessageDispatch();

            // adjust render target window
            int adjustH = clientH 
                + mainToolBar.Height 
                + mainStatus.Height
                + menuMain.Height;

            this.ClientSize = new Size(clientW, adjustH);

            m_renderTargetWnd = new RenderTargetWnd(m_dispatchInput);
            m_renderTargetWnd.Parent = this;
            m_renderTargetWnd.Location = new Point(0, mainToolBar.Height + menuMain.Height);
            m_renderTargetWnd.Name = "RenderTargetWnd";
            m_renderTargetWnd.Size = new Size(clientW, clientH);
            m_renderTargetWnd.TabIndex = 9;
            m_renderTargetWnd.Visible = true;
            
            // create tools dialogs
            m_heightMapToolsDlg = new HeightmapToolsDlg();
            m_heightMapToolsDlg.Show();

            m_brushDlg = new BrushDlg();         
            m_brushDlg.Show();      
        }

        public IntPtr getRenderTargetWnd()
        {
            return m_renderTargetWnd.Handle;
        }       

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (AboutBox aboutBox = new AboutBox())
            {
                aboutBox.ShowDialog(this);
            }

        }

        private void newMapToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (NewMapDlg newMapDlg = new NewMapDlg())
            {
                if (newMapDlg.ShowDialog(this) == DialogResult.OK)
                {
                    int w = newMapDlg.GetHMapWidth();
                    int h = newMapDlg.GetHMapHeight();
                    float xScale = newMapDlg.GetHMapXScale();
                    float yScale = newMapDlg.GetHMapYScale();
                    float zScale = newMapDlg.GetHMapZScale();
                    int bits = newMapDlg.GetHMapBits();
                    int initVal = newMapDlg.GetInitValue();

                    CoreAPI.mgCreateMap(newMapDlg.GetMapName(),
                        w, h,
                        bits, initVal,
                        xScale, yScale, zScale);

                    if (newMapDlg.GetInitType() == NewMapDlg.EInitType.Noise)
                    {
                        CoreAPI.mgHeightmapNoise(0, 0, -1, -1,
                            newMapDlg.GetNoiseOctaves(),
                            newMapDlg.GetNoiseAmplitude(),
                            newMapDlg.GetNoiseFrequency());
                    }
                }//endof if(OK)
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}