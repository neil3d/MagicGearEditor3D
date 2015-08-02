#include "StdAfx.h"
#include ".\mgroot.h"
#include "SceneEditor\SceneEditor.h"
#include "DX9CAPI\DX9Device.h"
#include "Util\SafeRelease.h"
#include "SceneEditor\DrawingUtil.h"

//#define RUN_UNIT_TEST
#ifdef RUN_UNIT_TEST
#include "UnitTest\UnitTestMgr.h"
UnitTestMgr	g_testMgr;
#endif

namespace MagicGear
{
	MGRoot::MGRoot(void)
	{
		m_pDevice = NULL;
		m_pSceneEditor = NULL;
	}

	MGRoot::~MGRoot(void)
	{
	}

	MGRoot* MGRoot::getInst()
	{
		static MGRoot g_root;
		return &g_root;
	}

	void MGRoot::createDevice(const tagDeviceCfg& cfg)
	{
		m_deviceCfg = cfg;
		m_pDevice = new DX9Device;
		m_pDevice->create(cfg);

		// -
		DrawingUtil::getInst()->create(m_pDevice->getResourceMgr());
	}

	void MGRoot::createSceneEditor()
	{
		m_pSceneEditor = new SceneEditor;

#ifdef RUN_UNIT_TEST
		g_testMgr.create();
#endif
	}

	bool MGRoot::render()
	{
		if(m_pDevice->beginRender())
		{
			m_pSceneEditor->render(m_pDevice->getRenderer());

#ifdef RUN_UNIT_TEST
			g_testMgr.render(m_pDevice->getRenderer());
#endif

			//show fps
			calculateFPS();
			char szTmp[64] = {0};
			sprintf(szTmp, "FPS : %.2f", m_fps);
			DrawingUtil::getInst()->drawText(szTmp, 2, 2);

			m_pDevice->endRender();
			return true;
		}
		else
		{
			return false;
		}
	}

	void MGRoot::destroy()
	{
#ifdef RUN_UNIT_TEST
		g_testMgr.destroy();
#endif
		if(m_pSceneEditor)
			m_pSceneEditor->destroy(getHDResourceMgr());

		DrawingUtil::getInst()->destroy(m_pDevice->getResourceMgr());

		SAFE_DEL(m_pSceneEditor);
		SAFE_DEL(m_pDevice);
	}

	void MGRoot::calculateFPS(void)
	{
		static DWORD lastTime = timeGetTime();
		static float c=0;

		if(c < 10)
		{
			c += 1.0f;
		}
		else
		{
			float totalTime = (timeGetTime() - lastTime)*0.001f;
			lastTime = timeGetTime();

			m_fps = c/totalTime;			
		}
	}
}//namespace MagicGear