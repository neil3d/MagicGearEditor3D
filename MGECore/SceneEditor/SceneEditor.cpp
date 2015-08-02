#include "StdAfx.h"
#include ".\sceneeditor.h"
#include "..\MGRoot.h"
#include "DrawingUtil.h"

namespace MagicGear
{
	SceneEditor::SceneEditor(void)
	{
		m_curCameraCtrl = &m_cameraDefault;
		m_viewWidth = m_viewHeight = 128;

		setDefaultCamera();
	}

	SceneEditor::~SceneEditor(void)
	{
	}

	void SceneEditor::create(const char *szMapName)
	{
		m_szMapName = szMapName;
		setDefaultCamera();
	}

	void SceneEditor::render(HDRenderer *pRenderer)
	{
		m_terrainMgr.render(pRenderer, &m_curCameraCtrl->m_camera);
		drawAxis(pRenderer);
	}

	void SceneEditor::destroy(HDResourceMgr* pResMgr)
	{
		m_terrainMgr.destroy(pResMgr);
	}

	void SceneEditor::loadFromFile(const char* szFileName)
	{}

	void SceneEditor::saveToFile(const char* szFileName)
	{}

	void SceneEditor::setDefaultCamera(void)
	{
		const int numCamera = 2;
		CameraBase *pCamera[numCamera]={0};
		pCamera[0] = &m_cameraTrackball.m_camera;
		pCamera[1] = &m_cameraDefault.m_camera;

		int clientW = MGRoot::getInst()->getClientWidth();
		int clientH = MGRoot::getInst()->getClientHeight();
		for(int i=0; i< numCamera; i++)
		{
			pCamera[i]->setPerspective(_DegToRad(45), clientW, clientH, 20, 20000);		
		}

		Vector3 lookAt(500,0,500);
		float dist = 600;
		float yaw = _DegToRad(270);
		float pitch = _DegToRad(-60);
		float roll = 0;

		m_cameraDefault.setParam(lookAt, dist, yaw, pitch, roll);
		m_cameraTrackball.setParam(lookAt, dist, yaw, pitch, roll);
	}

	void SceneEditor::updateVisableObjects(void)
	{
		// get center from camera
		int centerX = m_viewWidth/2,
			centerZ = m_viewHeight/2;

		// make heightmap rect
		m_terrainMgr.updateMesh(centerX, centerZ, m_viewWidth/2, m_viewHeight/2);
	}

	void SceneEditor::drawAxis(HDRenderer *pRenderer)
	{
		CameraBase *pCamera = &m_curCameraCtrl->m_camera;

		Matrix4 matWorldViewPrj = pCamera->getView() * pCamera->getProject();

		const Matrix4& matView = pCamera->getView();
		Vector3 cZ(matView._13,matView._23,matView._33);

		Vector3 vX(1,0,0);
		Vector3 vY(0,1,0);
		Vector3 vZ(0,0,1);

		POINT pt = {pCamera->getViewPortWidth()-10
			,pCamera->getViewPortHeight()};

		Vector3 wpt = pCamera->screenToWorld(pt.x, pt.y);
		wpt += cZ*1;
		const float len = 2;

		Vector3 tmp = wpt+vX*len;

		vector<Vector3> ptArray;
		
		ptArray.push_back(wpt);
		ptArray.push_back(tmp);
		DrawingUtil::getInst()->drawLineStrip(matWorldViewPrj, ptArray, 0xFFFF0000, pRenderer);

		tmp = wpt+vY*len;
		ptArray.clear();
		ptArray.push_back(wpt);
		ptArray.push_back(tmp);
		DrawingUtil::getInst()->drawLineStrip(matWorldViewPrj, ptArray, 0xFF00FF00, pRenderer);

		tmp = wpt+vZ*len;
		ptArray.clear();
		ptArray.push_back(wpt);
		ptArray.push_back(tmp);
		DrawingUtil::getInst()->drawLineStrip(matWorldViewPrj, ptArray, 0xFF0000FF, pRenderer);
	}
}//namespace MagicGear