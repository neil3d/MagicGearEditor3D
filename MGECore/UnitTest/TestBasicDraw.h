#pragma once
#include "testcase.h"
#include "..\MGRoot.h"
#include "..\HardwareAPI\HDRenderer.h"
#include "..\HardwareAPI\HDResourceMgr.h"
#include "..\Math\MathBaseDef.h"
using namespace MagicGear;

class TestBasicDraw : public TestCase
{
	struct tagVertex
	{
		Vector3	pos;
		DWORD	color;
		Vector2 uv;
	};
public:
	TestBasicDraw(void)
	{
		m_pTexture = NULL;
		m_pVB = NULL;
		m_pVDecl = NULL;
		m_pEffect = NULL;
		m_pIB = NULL;
	}

	virtual ~TestBasicDraw(void)
	{
		HDResourceMgr* pResMgr = MGRoot::getInst()->getHDResourceMgr();
		if(m_pTexture)
		{
			pResMgr->destroyTexture(m_pTexture);
			m_pTexture = NULL;
		}
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
		if(m_pIB)
		{
			pResMgr->destroyIndexBuffer(m_pIB);
			m_pIB = NULL;
		}
	}

	virtual void render(HDRenderer *pRenderer)
	{
		pRenderer->setVertexDecl(m_pVDecl);
		pRenderer->setVertexBuffer(0, m_pVB);
		pRenderer->setIndexBuffer(m_pIB);

		m_pEffect->setTexture("texDiffuse", m_pTexture);
		int numPass = m_pEffect->begin();
		for(int i=0;i<numPass;i++)
		{
			m_pEffect->beginPass(i);
			pRenderer->drawIndexedPrimitive(EPM_TriangleList, m_pVB->getNumVertex(), 2);
			m_pEffect->endPass();
		}
		m_pEffect->end();
	}

	virtual void init()		
	{
		HDResourceMgr* pResMgr = MGRoot::getInst()->getHDResourceMgr();

		// load texture
		m_pTexture = pResMgr->createTexture("Media\\test.tga");
		m_pTexture->loadFromFile(NULL, 1, pResMgr);

		// make vertex buffer
		m_pVB = pResMgr->createVertexBuffer();
		m_pVB->create(sizeof(tagVertex)*4, sizeof(tagVertex), pResMgr);

		tagVertex quadVert[4];
		quadVert[0].pos = Vector3(-0.5f,	0.5f,	0);
		quadVert[1].pos = Vector3(0.5f,	0.5f,	0);
		quadVert[2].pos = Vector3(0.5f,	-0.5f,	0);
		quadVert[3].pos = Vector3(-0.5f,	-0.5f,	0);
		
		quadVert[0].color = 0xFF0000FF;
		quadVert[1].color = 0xFF00FF00;
		quadVert[2].color = 0xFF0FF000;
		quadVert[3].color = 0xFFFF0000;

		quadVert[0].uv = Vector2(0,0);
		quadVert[1].uv = Vector2(1,0);
		quadVert[2].uv = Vector2(1,1);
		quadVert[3].uv = Vector2(0,1);

		m_pVB->copyFromMemory(quadVert, sizeof(quadVert));

		m_pVDecl = pResMgr->createVertexDecl();
		m_pVDecl->beginBuild();
		m_pVDecl->addElement(0, 0, HDVertexDecl::ET_Float3, 0, HDVertexDecl::EU_Position, 0);
		m_pVDecl->addElement(0, 12, HDVertexDecl::ET_DwordColor, 0, HDVertexDecl::EU_Color, 0);
		m_pVDecl->addElement(0, 16, HDVertexDecl::ET_Float2, 0, HDVertexDecl::EU_Texcoord, 0);
		m_pVDecl->endBuild(pResMgr);

		// index buffer
		m_pIB = pResMgr->createIndexBuffer();
		m_pIB->create(sizeof(WORD)*6, pResMgr);
		WORD indexArray[6];
		indexArray[0] = 0;
		indexArray[1] = 1;
		indexArray[2] = 2;

		indexArray[3] = 2;
		indexArray[4] = 3;
		indexArray[5] = 0;

		m_pIB->copyFromMemory(indexArray, sizeof(indexArray));

		// effect
		m_pEffect = pResMgr->createEffect();
		m_pEffect->loadFromFile("FXFiles\\BasicDraw_PCT.fx", pResMgr);
	}

private:
	HDTexture		*m_pTexture;
	HDVertexBuffer	*m_pVB;
	HDIndexBuffer	*m_pIB;
	HDVertexDecl	*m_pVDecl;
	HDEffect		*m_pEffect;
};
