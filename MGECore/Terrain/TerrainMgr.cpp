#include "StdAfx.h"
#include ".\terrainmgr.h"
#include "..\Math\CameraBase.h"
#include "..\HardwareAPI\HDRenderer.h"

namespace MagicGear
{
	TerrainMgr::TerrainMgr(void)
	{
		m_bCreated = false;
	}

	TerrainMgr::~TerrainMgr(void)
	{
	}

	void TerrainMgr::create(int w, int h, int heightMapBits, int initVal, Vector3 hScale, HDResourceMgr* pResMgr)
	{
		destroy(pResMgr);

		m_meshSource.create(w, h, heightMapBits, initVal, hScale, pResMgr);
		m_mtlEdit.create(pResMgr);

		m_bCreated = true;
	}

	void TerrainMgr::generateNoise(int x, int y, int w, int h, int numOctaves, float amplitude, float frequency)
	{
		if(m_bCreated)
		{
			m_meshSource.generateNoise(x,y,w,h, numOctaves, amplitude, frequency);
		}
		else
		{
			// todo report error
		}
	}

	void TerrainMgr::updateMesh(int centerX, int centerZ, int halfW, int halfH)
	{
		if(m_bCreated)
		{
			const int MAX_HALF_SIZE = 128;
			if(halfW > MAX_HALF_SIZE)
				halfW = MAX_HALF_SIZE;
			if(halfH > MAX_HALF_SIZE)
				halfH = MAX_HALF_SIZE;

			RECT rc;
			rc.left = centerX - halfW;
			rc.right = centerX + halfW;
			rc.top = centerZ - halfH;
			rc.bottom = centerZ + halfH;
			m_meshSource.updateVertBuffer(rc);
		}
	}

	void TerrainMgr::destroy(HDResourceMgr* pResMgr)
	{
		m_bCreated = false;
		m_meshSource.destroy(pResMgr);
		m_mtlEdit.destroy(pResMgr);
	}

	void TerrainMgr::render(HDRenderer *pRenderer, CameraBase* pCamera)
	{
		if(!m_bCreated)
			return;

		pRenderer->setVertexDecl(m_meshSource.getVertDecl());
		pRenderer->setVertexBuffer(0, m_meshSource.getVertBuffer());
		pRenderer->setIndexBuffer(m_meshSource.getIndexBuffer());

		m_mtlEdit.beginRender(pCamera);
		pRenderer->drawIndexedPrimitive(EPM_TriangleList, m_meshSource.getVertBuffer()->getNumVertex(),
			m_meshSource.getNumTriangles());
		m_mtlEdit.endRender();
	}
}//namespace MagicGear