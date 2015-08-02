#include "StdAfx.h"
#include ".\dx9renderer.h"
#include "DX9Resource.h"

namespace MagicGear
{
	DX9Renderer::DX9Renderer(void)
	{
		m_pD3D9Device = NULL;
	}

	DX9Renderer::~DX9Renderer(void)
	{
	}

	void DX9Renderer::setVertexDecl(HDVertexDecl* pDecl)
	{
		DX9VertexDecl* pDX9 = (DX9VertexDecl*)pDecl;
		HRESULT hr = m_pD3D9Device->SetVertexDeclaration(pDX9->getDX9());
	}

	void DX9Renderer::setVertexBuffer(int index, const HDVertexBuffer *pVB)
	{
		DX9VB* pDX9 = (DX9VB*)pVB;
		HRESULT hr = m_pD3D9Device->SetStreamSource(index, pDX9->getDX9(), 0, pVB->getStride());
	}

	void DX9Renderer::setIndexBuffer(const HDIndexBuffer *pIB)
	{
		DX9IB* pDX9 = (DX9IB*)pIB;
		HRESULT hr = m_pD3D9Device->SetIndices(pDX9->getDX9());
	}

	void DX9Renderer::drawPrimitive(EPrimitiveType type, int numPrimitive)
	{
		HRESULT hr = m_pD3D9Device->DrawPrimitive((D3DPRIMITIVETYPE)type,0,numPrimitive);
	}

	void DX9Renderer::drawIndexedPrimitive(EPrimitiveType type, int numVert, int numPrimitive)
	{
		HRESULT hr = m_pD3D9Device->DrawIndexedPrimitive((D3DPRIMITIVETYPE)type,
			0,	// BaseVertexIndex
			0,	// MinIndex
			numVert,
			0,	// StartIndex
			numPrimitive);
	}
}//namespace MagicGear