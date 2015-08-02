using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace MagicGearEditor3D
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            int clientW = 800,
                clientH = 600;
            
            using (MainForm mainFrm = new MainForm(clientW, clientH))
            {
                CoreAPI.mgCreateEngine(mainFrm.getRenderTargetWnd(), clientW, clientH);
                mainFrm.Show();

                while (mainFrm.Created)
                {
                    CoreAPI.mgRender();
                    Application.DoEvents();
                }
            }//endof using

            CoreAPI.mgDestroyEngine();
        }//endo Main()
    }//endof class Program
}