#pragma once
#include "..\hardwareapi\hddevice.h"
#include "DX9Renderer.h"
#include "DX9ResourceMgr.h"

namespace MagicGear
{
	
	//--------------------------------------------------------------------------
	class DX9Device : public HDDevice
	{
	public:
		DX9Device(void);
		virtual ~DX9Device(void);

		virtual void create(const tagDeviceCfg& cfg);
		virtual void destroy();

		void setClearColor(DWORD color)	{	m_clearColor = color; }

		virtual bool beginRender(void);
		virtual void endRender(void);

		virtual HDRenderer *getRenderer()			{	return &m_renderer; }
		virtual HDResourceMgr *getResourceMgr()		{	return &m_resourceMgr;}

	private:
		bool handleDeviceLost(void);
	private:
		IDirect3D9*			m_pD3D9;
		IDirect3DDevice9*	m_pD3D9Device;

		DWORD				m_clearColor;
		bool				m_bLost;

		DX9Renderer			m_renderer;
		DX9ResourceMgr		m_resourceMgr;
		D3DPRESENT_PARAMETERS m_d3dPPM;
	};

	// pixel format
	//--------------------------------------------------------------------------
	inline EPixelFormat DXFMT2PixelFormatD(D3DFORMAT fmt)
	{
		switch(fmt)
		{
		case D3DFMT_R5G6B5:		return EPF_R5G6B5;
		case D3DFMT_R8G8B8:		return EPF_R8G8B8;
		case D3DFMT_A1R5G5B5:	return EPF_A1R5G5B5;
		case D3DFMT_A8R8G8B8:	return EPF_A8R8G8B8;
		case D3DFMT_X8R8G8B8:	return EPF_X8R8G8B8;
		}
		return EPF_End;
	}
	inline D3DFORMAT PixelFormat2DX(EPixelFormat pf)
	{
		switch(pf)
		{
		case EPF_R5G6B5:	return D3DFMT_R5G6B5;
		case EPF_R8G8B8:	return D3DFMT_R8G8B8;
		case EPF_A1R5G5B5:	return D3DFMT_A1R5G5B5;
		case EPF_A8R8G8B8:	return D3DFMT_A8R8G8B8;
		case EPF_X8R8G8B8:	return D3DFMT_X8R8G8B8;
		}
		return D3DFMT_FORCE_DWORD;
	}


	// depth/stencil format
	//--------------------------------------------------------------------------
	inline D3DFORMAT DepthFormat2DX(EDepthFormat zf)
	{
		switch(zf)
		{
		case EDF_D16:		return D3DFMT_D16;
		case EDF_D15S1:		return D3DFMT_D15S1;
		case EDF_D24S8:		return D3DFMT_D24S8;
		case EDF_D24X8:		return D3DFMT_D24X8;
		case EDF_D24X4S4:	return D3DFMT_D24X4S4;
		case EDF_D24FS8:	return D3DFMT_D24FS8;
		case EDF_D32:		return D3DFMT_D32;
		}

		return D3DFMT_FORCE_DWORD;
	}
	inline EDepthFormat DXFMT2DepthFormat(D3DFORMAT fmt)
	{
		switch(fmt)
		{
		case D3DFMT_D16:		return EDF_D16;		
		case D3DFMT_D15S1:		return EDF_D15S1;		
		case D3DFMT_D24S8:		return EDF_D24S8;		
		case D3DFMT_D24X8:		return EDF_D24X8;		
		case D3DFMT_D24X4S4:	return EDF_D24X4S4;	
		case D3DFMT_D24FS8:		return EDF_D24FS8;	
		case D3DFMT_D32:		return EDF_D32;		
		}

		return EDF_End;
	}
}//namespace MagicGear