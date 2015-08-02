#include "StdAfx.h"
#include "DrawingUtil.h"
#include "..\HardwareAPI\HDRenderer.h"
#include "..\HardwareAPI\HDResourceMgr.h"

namespace MagicGear
{
	DrawingUtil::DrawingUtil(void)
	{
		m_pVB = NULL;
		m_pVDecl = NULL;
		m_pEffect = NULL;
		m_pFont = NULL;
	}

	DrawingUtil::~DrawingUtil(void)
	{
	}

	DrawingUtil* DrawingUtil::getInst()
	{
		static DrawingUtil g_drawingUtil;
		return &g_drawingUtil;
	}

	void DrawingUtil::create(HDResourceMgr *pResMgr)
	{
		// vertex buffer
		m_pVB = pResMgr->createVertexBuffer();
		m_pVB->create(sizeof(tagVertex)*NUM_VERT, sizeof(tagVertex), pResMgr);
		m_vs.alloc(NUM_VERT);

		// vert decl
		m_pVDecl = pResMgr->createVertexDecl();
		m_pVDecl->beginBuild();
		m_pVDecl->addElement(0, 0, HDVertexDecl::ET_Float3, 0, HDVertexDecl::EU_Position, 0);
		m_pVDecl->addElement(0, 12, HDVertexDecl::ET_DwordColor, 0, HDVertexDecl::EU_Color, 0);
		m_pVDecl->endBuild(pResMgr);

		// effect
		m_pEffect = pResMgr->createEffect();
		m_pEffect->loadFromFile("FXFiles\\DrawingUtil.fx", pResMgr);

		// font
		m_pFont = pResMgr->createFont();
		m_pFont->create(pResMgr, 14);
	}

	void DrawingUtil::destroy(HDResourceMgr *pResMgr)
	{
		if(m_pVB)
		{
			pResMgr->destroyVertexBuffer(m_pVB);
			m_pVB = NULL;
		}
		if(m_pVDecl)
		{
			pResMgr->destroyVertexDecl(m_pVDecl);
			m_pVDecl = NULL;
		}
		if(m_pEffect)
		{
			pResMgr->destroyEffect(m_pEffect);
			m_pEffect = NULL;
		}
		if(m_pFont)
		{
			pResMgr->destroyFont(m_pFont);
			m_pFont = NULL;
		}
	}

	void DrawingUtil::drawText(const char* szText, int x, int y, DWORD color)
	{
		m_pFont->drawText(szText, x, y, color);
	}

	void DrawingUtil::drawLineStrip(const Matrix4& matWorldViewPrj, const vector<Vector3>& posArray, DWORD color, HDRenderer *pRenderer)
	{
		ASSERT(posArray.size() > 0);
		ASSERT(posArray.size() < NUM_VERT);

		tagVertex *pVert = m_vs.getVertices();
		size_t i;
		for(i=0; i< posArray.size(); i++)
		{
			pVert[i].pos = posArray[i];
			pVert[i].color = color;
		}

		int numVert = (int)i;
		m_pVB->copyFromMemory(pVert, sizeof(tagVertex)*numVert);

		pRenderer->setVertexDecl(m_pVDecl);
		pRenderer->setVertexBuffer(0, m_pVB);

		m_pEffect->setMatrix4("matWorldViewPrj", matWorldViewPrj);
		m_pEffect->begin();
		m_pEffect->beginPass(0);
		pRenderer->drawPrimitive(EPM_LineStrip, numVert-1);
		m_pEffect->endPass();
		m_pEffect->end();
	}
}//namespace MagicGear