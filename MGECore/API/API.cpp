#include "StdAfx.h"
#include "..\HardwareAPI\HDDevice.h"
#include "..\MGRoot.h"
#include "..\SceneEditor\SceneEditor.h"
using namespace MagicGear;

extern "C"
{
#define MG_API __declspec(dllexport)

	// root interface
	//---------------------------------------------------------------------
	MG_API void _cdecl mgCreateEngine(HWND hWnd, int clientW, int clientH)
	{
		tagDeviceCfg cfg;
		cfg.adapterID = 0;
		cfg.width = clientW;
		cfg.height = clientH;
		cfg.pixelFormat = EPF_X8R8G8B8;
		cfg.depthFormat = EDF_D24S8;
		cfg.hWnd = hWnd;

		MGRoot::getInst()->createDevice(cfg);
		MGRoot::getInst()->createSceneEditor();
	}

	MG_API void _cdecl mgDestroyEngine(void)
	{
		MGRoot::getInst()->destroy();
	}

	MG_API void _cdecl mgRender()
	{
		MGRoot::getInst()->render();
	}

	// scene editor interface
	//---------------------------------------------------------------------
	MG_API void _cdecl mgCreateMap(const char* szMapName, int terrainW, int terrainH, 
		int terrainBits, int terrainInit,
		float xScale, float yScale, float zScale)
	{
		SceneEditor *pEditor = MGRoot::getInst()->getSceneEditor();
		pEditor->create(szMapName);

		Vector3 hScale(xScale, yScale, zScale);
		pEditor->getTerrainMgr()->create(terrainW, terrainH, 
			terrainBits, terrainInit, hScale,
			MGRoot::getInst()->getHDResourceMgr());	

		pEditor->updateVisableObjects();
	}

	MG_API void _cdecl mgHeightmapNoise(int x, int y, int w, int h, int numOctaves, float amplitude, float frequency)
	{
		SceneEditor *pEditor = MGRoot::getInst()->getSceneEditor();
		pEditor->getTerrainMgr()->generateNoise(x, y, w, h, numOctaves, amplitude, frequency);
		pEditor->updateVisableObjects();
	}

	MG_API void _cdecl mgSetBrush(int shape, int lerpMode, int innerRadius, int outerRadius, int strength)
	{
	}

	// camera contrl
	//---------------------------------------------------------------------
	float _normalizeX(int x)
	{
		return  ( ( 2.0f * x ) / MGRoot::getInst()->getClientWidth()  ) - 1;
	}

	float _normalizeY(int y)
	{
		return  -( ( ( 2.0f * y ) / MGRoot::getInst()->getClientHeight() ) - 1 );
	}

	void _mgCameraContrlInput(CameraContrl *pCC, int msg, unsigned int wParam, unsigned int lParam)
	{
		bool changed = true;
		switch(msg)
		{
		case WM_KEYDOWN:
			pCC->onKeyDown((DWORD)wParam);
			break;
		case WM_LBUTTONDOWN:
			pCC->onLButtonDown(_normalizeX(GET_X_LPARAM(lParam)), _normalizeY(GET_Y_LPARAM(lParam))); 
			break;
		case WM_LBUTTONUP:
			pCC->onLButtonUp();
			break;
		case WM_RBUTTONDOWN:
			pCC->onRButtonDown(_normalizeX(GET_X_LPARAM(lParam)), _normalizeY(GET_Y_LPARAM(lParam))); 
			break;
		case WM_RBUTTONUP:
			pCC->onRButtonUp();
			break;
		case WM_MOUSEMOVE:
			pCC->onMouseMove(_normalizeX(GET_X_LPARAM(lParam)), _normalizeY(GET_Y_LPARAM(lParam)));
			break;
		case WM_MOUSEWHEEL:
			pCC->onMouseWheel(GET_WHEEL_DELTA_WPARAM(wParam));
			break;
		default:
			changed = false;
		}//endof switch

		if(changed)
		{
			SceneEditor *pEditor = MGRoot::getInst()->getSceneEditor();
			pEditor->updateVisableObjects();
		}
	}

	MG_API void _cdecl mgCameraTrackballInput(int msg, unsigned int wParam, unsigned int lParam)
	{
		CameraContrl *pCC = MGRoot::getInst()->getSceneEditor()->getCameraTrackball();
		_mgCameraContrlInput(pCC, msg, wParam, lParam);
	}

	MG_API void _cdecl mgCameraDefaultInput(int msg, unsigned int wParam, unsigned int lParam)
	{
		CameraContrl *pCC = MGRoot::getInst()->getSceneEditor()->getCameraDefault();
		_mgCameraContrlInput(pCC, msg, wParam, lParam);
	}
}//endof extern "C"