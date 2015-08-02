#pragma once
#include "..\HardwareAPI\HDRenderer.h"

namespace MagicGear
{
	class DX9Renderer : public HDRenderer
	{
	public:
		DX9Renderer(void);
		virtual ~DX9Renderer(void);

		void init(IDirect3DDevice9 *pDevice)
		{
			m_pD3D9Device = pDevice;
		}

		virtual void setVertexDecl(HDVertexDecl* pDecl);
		virtual void setVertexBuffer(int index, const HDVertexBuffer *pVB);
		virtual void setIndexBuffer(const HDIndexBuffer *pIB);

		virtual void drawPrimitive(EPrimitiveType type, int numPrimitive);
		virtual void drawIndexedPrimitive(EPrimitiveType type, int numVert, int numPrimitive);

	private:
		IDirect3DDevice9*	m_pD3D9Device;
	};
}//namespace MagicGear