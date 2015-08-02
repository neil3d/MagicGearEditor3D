#pragma once
#include "Heightmap.h"
#include "..\Mesh\Material.h"
#include "..\Math\CameraBase.h"

namespace MagicGear
{
	/**	\class TerrainMaterialEdit
		\brief manage effect, textures and alpha map update
	*/
	class TerrainMaterialEdit
	{
	public:
		enum EConst
		{
			SPLAT_PER_PASS = 4,
		};
		typedef HeightMap<BYTE> AlphaMap;

	public:
		TerrainMaterialEdit(void);
		~TerrainMaterialEdit(void);

		void create(HDResourceMgr* pResMgr);
		void destroy(HDResourceMgr* pResMgr);

		void beginRender(CameraBase* pCamera)
		{
			Matrix4 matWorldViewProj = pCamera->getView() * pCamera->getProject();
			m_mtl.getEffect()->setMatrix4("matWorldViewPrj", matWorldViewProj);

			int numPass = m_mtl.getEffect()->begin();
			ASSERT(numPass == 1);
			m_mtl.getEffect()->beginPass(0);
		}

		void endRender(void)
		{
			m_mtl.getEffect()->endPass();
			m_mtl.getEffect()->end();
		}

	private:
		Material	m_mtl;
	};
}//namespace MagicGear