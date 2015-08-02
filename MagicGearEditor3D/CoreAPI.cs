using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace MagicGearEditor3D
{
    public static class CoreAPI
    {
        const string m_szDLLName = "MGECore.dll";

        // engine
        [DllImport(m_szDLLName)]
        public static extern void mgCreateEngine(IntPtr hWnd, int clientW, int clientH);

        [DllImport(m_szDLLName)]
        public static extern void mgDestroyEngine();

        [DllImport(m_szDLLName)]
        public static extern void mgRender();

        // map editor
        [DllImport(m_szDLLName)]
        public static extern void mgCreateMap(string szMapName,
            int terrainW, int terrainH,
            int terrainBits, int terrainInit,
            float xScale, float yScale, float zScale);

        [DllImport(m_szDLLName)]
        public static extern void mgHeightmapNoise(int x, int y, int w, int h,
            int numOctaves, float amplitude, float frequency);

        [DllImport(m_szDLLName)]
        public static extern void mgSetBrush(int shape, int lerpMode, int innerRadius, int outerRadius, int strength);

        // camera control
        [DllImport(m_szDLLName)]
        public static extern void mgCameraTrackballInput(int msg, uint wParam, uint lParam);
        
        [DllImport(m_szDLLName)]
        public static extern void mgCameraDefaultInput(int msg, uint wParam, uint lParam);
                
    }
}
