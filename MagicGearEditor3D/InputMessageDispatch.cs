using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace MagicGearEditor3D
{
    public class InputMessageDispatch
    {
        public InputMessageDispatch()
        { 
        }

        public void onInputMessage(ref Message m)
        {
            unchecked
            {            
                CoreAPI.mgCameraDefaultInput(m.Msg, (uint)m.WParam, (uint)m.LParam);
            }
        }
    }//endof class
}
