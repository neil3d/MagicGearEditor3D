#pragma once
#include "Heightmap.h"
#include "..\Mesh\VertexStream.h"
#include "..\Math\MathBaseDef.h"

namespace MagicGear
{
	class HDVertexDecl;
	class HDVertexBuffer;
	class HDIndexBuffer;
	class HDResourceMgr;

	/**	\class TerrainMeshSource
		\brief manage height filed and VertexBuffer
	*/
	class TerrainMeshSource
	{
		struct tagVertex
		{
			Vector3	pos;
			Vector2	uv;
		};
	public:
		TerrainMeshSource(void);
		~TerrainMeshSource(void);

		void create(int w, int h, int heightMapBits, int initVal, Vector3 mapScale, HDResourceMgr* pResMgr);
		void destroy(HDResourceMgr* pResMgr);

		//!	make noise on rect of heightmap
		void generateNoise(int x, int y, int w, int h, int numOctaves, float amplitude, float frequency);


		// -- vertex buffer
		void updateVertBuffer(RECT mapRect);
		HDVertexDecl* getVertDecl(void)		{	return m_vertDecl;}
		HDVertexBuffer* getVertBuffer(void)	{	return m_vertBuffer; }
		HDIndexBuffer* getIndexBuffer(void)	{	return m_indexBuffer; }
		int getNumTriangles(void)	{	return m_numTriangles; }

	private:
		void mapRectValid(RECT& rc, int w, int h);
		template<typename T>
		void updateVertBufferT(RECT mapRect, HeightMap<T>* pHMap);
		void reallocVertices(void);

		int getHeightmapWidth(void);
		int getHeightmapHeight(void);
		void clipRect(RECT& rc);

	private:
		HDResourceMgr			*m_pResMgr;
		VertexStream<tagVertex>	m_vertexStream;
		HDVertexDecl			*m_vertDecl;
		HDVertexBuffer			*m_vertBuffer;
		int						m_curVBMapW,
								m_curVBMapH;
		HDIndexBuffer			*m_indexBuffer;
		int						m_numTriangles;


		int						m_mapBits;
		HeightMap<BYTE>			m_8bitHMap;
		HeightMap<WORD>			m_16bitHMap;
		Vector3					m_mapScale;
	};
}//namespace MagicGear