#pragma once
#include "..\Terrain\TerrainMgr.h"
#include "..\EntityMgr\EntityMgr.h"
#include "..\Math\CameraTrackBallCtrl.h"
#include "..\Math\CameraDefaultCtrl.h"

namespace MagicGear
{
	/**	\class SceneEditor
		\brief a Facade Partten
	*/
	class SceneEditor
	{
	public:
		SceneEditor(void);
		~SceneEditor(void);

		void create(const char *szMapName);
		void destroy(HDResourceMgr* pResMgr);

		void loadFromFile(const char* szFileName);
		void saveToFile(const char* szFileName);

		void render(HDRenderer *pRenderer);

		TerrainMgr* getTerrainMgr()	{	return &m_terrainMgr; }
		EntityMgr* getEntityMgr()	{	return &m_entityMgr; }
		CameraContrl* getCameraTrackball()	{	return &m_cameraTrackball; }
		CameraContrl* getCameraDefault()	{	return &m_cameraDefault; }


		//! update terrain and entity on view changed
		void updateVisableObjects(void);
		void setDefaultCamera(void);
		
	private:
		void drawAxis(HDRenderer *pRenderer);
	private:
		TerrainMgr	m_terrainMgr;
		EntityMgr	m_entityMgr;

		int	m_viewWidth,
			m_viewHeight;

		CameraContrl		*m_curCameraCtrl;
		CameraTrackBallCtrl	m_cameraTrackball;
		CameraDefaultCtrl	m_cameraDefault;

		string	m_szMapName;
	};
}//namespace MagicGear