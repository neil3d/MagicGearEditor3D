#include "StdAfx.h"
#include "TerrainMaterialEdit.h"

namespace MagicGear
{
	TerrainMaterialEdit::TerrainMaterialEdit(void)
	{
	}

	TerrainMaterialEdit::~TerrainMaterialEdit(void)
	{
	}

	void TerrainMaterialEdit::create(HDResourceMgr* pResMgr)
	{
		m_mtl.loadFXFile("FXFiles\\Terrain.fx", pResMgr);
	}

	void TerrainMaterialEdit::destroy(HDResourceMgr* pResMgr)
	{
		m_mtl.destroy(pResMgr);
	}

}//namespace MagicGear