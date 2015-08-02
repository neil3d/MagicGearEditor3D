#include "StdAfx.h"
#include ".\dx9device.h"
#include "..\Util\SafeRelease.h"
#include "..\Util\Logger.h"

namespace MagicGear
{
	DX9Device::DX9Device(void)
	{
		m_pD3D9 = NULL;
		m_pD3D9Device = NULL;
		m_clearColor = 0;
		m_bLost = false;
	}

	DX9Device::~DX9Device(void)
	{
		destroy();
	}

	void DX9Device::create(const tagDeviceCfg& cfg)
	{
		HRESULT hr;
		// create D3D9 object
		m_pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);
		if(m_pD3D9 == NULL)
			throw HDAPIException("D3D9 object create filed!");

		// select flags
		DWORD behaviorFlags = 0;
		D3DCAPS9 caps;
		hr = m_pD3D9->GetDeviceCaps(cfg.adapterID, D3DDEVTYPE_HAL, &caps);

		behaviorFlags |= D3DCREATE_HARDWARE_VERTEXPROCESSING;

		D3DPRESENT_PARAMETERS ppm;
		memset(&ppm, 0, sizeof(D3DPRESENT_PARAMETERS));
		
		ppm.BackBufferWidth = cfg.width;
		ppm.BackBufferHeight = cfg.height;
		ppm.BackBufferFormat = PixelFormat2DX(cfg.pixelFormat);
		ppm.BackBufferCount = 1;
		ppm.MultiSampleType = D3DMULTISAMPLE_NONE;
		ppm.MultiSampleQuality = 0;
		ppm.SwapEffect = D3DSWAPEFFECT_COPY;
		ppm.hDeviceWindow = cfg.hWnd;
		ppm.Windowed = TRUE;
		ppm.EnableAutoDepthStencil = TRUE;
		ppm.AutoDepthStencilFormat = DepthFormat2DX(cfg.depthFormat);
		ppm.Flags = 0;
		ppm.FullScreen_RefreshRateInHz = 0;
		ppm.PresentationInterval = D3DPRESENT_DONOTWAIT;

		D3DDEVTYPE devType = D3DDEVTYPE_HAL;
#ifdef SHADER_DEBUG
		devType = D3DDEVTYPE_REF;
#endif
		// call create
		hr = m_pD3D9->CreateDevice(cfg.adapterID,
			devType,
			cfg.hWnd,
			behaviorFlags,
			&ppm,&m_pD3D9Device);
		if(FAILED(hr))
		{
			LOG("CreateDevice() Failed, error = %s", DXGetErrorString9(hr));
			throw HDAPIException("D3D9 device create filed!");
		}

		// save it for device reset
		m_d3dPPM = ppm;

		// init subsystems
		m_renderer.init(m_pD3D9Device);
		m_resourceMgr.init(m_pD3D9Device);

	}

	void DX9Device::destroy()
	{
		m_resourceMgr.destroy();
		//--
		SAFE_RELEASE(m_pD3D9);
		SAFE_RELEASE(m_pD3D9Device);
	}

	bool DX9Device::beginRender(void)
	{
		bool bOK = !m_bLost;
		if(m_bLost)
		{
			bOK = handleDeviceLost();
		}

		if(bOK)
		{
			HRESULT hr;
			hr = m_pD3D9Device->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER,
				m_clearColor,1,0);

			hr = m_pD3D9Device->BeginScene();

			return SUCCEEDED(hr);
		}
		else
			return false;
	}

	void DX9Device::endRender(void)
	{
		HRESULT hr;
		hr = m_pD3D9Device->EndScene();
		hr = m_pD3D9Device->Present(NULL, NULL, NULL, NULL);
		if(hr == D3DERR_DEVICELOST)
		{
			m_bLost = true;

			//release all video memory resource
			m_resourceMgr.onEvent(DX9ResourceMgr::EE_DeviceLost, 0, 0);
		}
	}

	bool DX9Device::handleDeviceLost(void)
	{
		HRESULT hr;
		if( FAILED( hr = m_pD3D9Device->TestCooperativeLevel() ) )
		{
			if( hr == D3DERR_DEVICELOST )
				return false;
			if( hr == D3DERR_DEVICENOTRESET )
			{
				hr = m_pD3D9Device->Reset( &m_d3dPPM );
				if(FAILED(hr))
					throw HDAPIException("D3D9 device reset filed!");

				//re-create all video memory resource
				m_resourceMgr.onEvent(DX9ResourceMgr::EE_DeviceReset, 0, 0);

			}//endof if(can reset)
		}//endof if(failed)

		m_bLost = false;
		return true;
	}
}//namespace MagicGear