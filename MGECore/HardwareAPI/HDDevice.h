#pragma once
#include "..\Core\MGException.h"

namespace MagicGear
{
	enum EPixelFormat
	{
		EPF_R5G6B5,
		EPF_R8G8B8,
		EPF_A1R5G5B5,
		EPF_A8R8G8B8,
		EPF_X8R8G8B8,

		EPF_End
	};

	enum EDepthFormat
	{
		EDF_D16,
		EDF_D15S1,

		EDF_D24S8,
		EDF_D24X8,
		EDF_D24X4S4,
		EDF_D24FS8,

		EDF_D32,

		EDF_End
	};

	//---------------------------------------------------------------
	struct tagDeviceCfg
	{
		UINT			adapterID;
		UINT			width,
						height;
		EPixelFormat	pixelFormat;
		EDepthFormat	depthFormat;
		HWND			hWnd;
	};
	//---------------------------------------------------------------
	class HDRenderer;
	class HDResourceMgr;

	class HDDevice
	{
	public:
		HDDevice(void)	{}
		virtual ~HDDevice(void)	{}

		virtual void create(const tagDeviceCfg& cfg) = 0;
		virtual void destroy() = 0;

		virtual void setClearColor(DWORD color) = 0;

		// handle device lost
		virtual bool beginRender(void) = 0;
		virtual void endRender(void) = 0;

		virtual HDRenderer *getRenderer() = 0;
		virtual HDResourceMgr *getResourceMgr() = 0;
	};

	//---------------------------------------------------------------
	class HDAPIException : public MGException
	{
	public:
		HDAPIException(const char* szInfo) : MGException(szInfo)	{}
		virtual ~HDAPIException(void)	{}
	};
}//namespace MagicGear