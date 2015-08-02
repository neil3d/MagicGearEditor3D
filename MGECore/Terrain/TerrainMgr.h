#pragma once
#include "..\Math\MathBaseDef.h"
#include "TerrainMeshSource.h"
#include "TerrainMaterialEdit.h"

namespace MagicGear
{
	class CameraBase;
	class HDRenderer;

	/**	\class TerrainMgr
		\brief Facade of terrain subsystem
	*/
	class TerrainMgr
	{
	public:
		TerrainMgr(void);
		~TerrainMgr(void);

		void create(int w, int h, int heightMapBits, int initVal, Vector3 hScale, HDResourceMgr* pResMgr);
		void generateNoise(int x, int y, int w, int h, int numOctaves, float amplitude, float frequency);

		void destroy(HDResourceMgr* pResMgr);
		void render(HDRenderer *pRenderer, CameraBase* pCamera);

		//!	recalculate vertex buffer and so on
		void updateMesh(int centerX, int centerZ, int halfW, int halfH);

	private:
		bool				m_bCreated;
		TerrainMeshSource	m_meshSource;
		TerrainMaterialEdit	m_mtlEdit;

	};
}//namespace MagicGear