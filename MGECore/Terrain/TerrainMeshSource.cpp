#include "StdAfx.h"
#include ".\TerrainMeshSource.h"
#include "..\HardwareAPI\HDResource.h"
#include "..\HardwareAPI\HDResourceMgr.h"
#include "Perlin.h"

namespace MagicGear
{
	TerrainMeshSource::TerrainMeshSource(void)
	{
		m_vertDecl = NULL;
		m_vertBuffer = NULL;
		m_indexBuffer = NULL;
		m_curVBMapW = 0;
		m_curVBMapH = 0;
		m_pResMgr = NULL;
		m_numTriangles = 0;
	}

	TerrainMeshSource::~TerrainMeshSource(void)
	{
		destroy(m_pResMgr);
	}

	void TerrainMeshSource::create(int w, int h, int heightMapBits, int initVal, Vector3 mapScale, HDResourceMgr* pResMgr)
	{
		m_pResMgr = pResMgr;

		destroy(pResMgr);
		// -- 
		m_mapBits = heightMapBits;

		if(m_mapBits == 16)
			m_16bitHMap.create(w, h, initVal);
		else
		{
			ASSERT(m_mapBits == 8);
			m_8bitHMap.create(w, h, initVal);
		}

		m_mapScale = mapScale;

		// -- 
		m_vertDecl = pResMgr->createVertexDecl();
		m_vertDecl->beginBuild();
		m_vertDecl->addElement(0, 0, HDVertexDecl::ET_Float3, 0, HDVertexDecl::EU_Position, 0);
		m_vertDecl->addElement(0, 12, HDVertexDecl::ET_Float2, 0, HDVertexDecl::EU_Texcoord, 0);
		m_vertDecl->endBuild(pResMgr);

		m_vertBuffer = pResMgr->createVertexBuffer();

		m_indexBuffer = pResMgr->createIndexBuffer();
			
	}

	void TerrainMeshSource::destroy(HDResourceMgr* pResMgr)
	{
		//--
		m_8bitHMap.destroy();
		m_16bitHMap.destroy();

		// -- 
		if(m_vertDecl)
		{
			pResMgr->destroyVertexDecl(m_vertDecl);
			m_vertDecl = NULL;
		}

		if(m_vertBuffer)
		{
			pResMgr->destroyVertexBuffer(m_vertBuffer);
			m_vertBuffer = NULL;
		}
		m_curVBMapW = 0;
		m_curVBMapH = 0;

		if(m_indexBuffer)
		{
			pResMgr->destroyIndexBuffer(m_indexBuffer);
			m_indexBuffer = NULL;
		}
		m_numTriangles = 0;
	}

	template<typename T>
	void TerrainMeshSource::updateVertBufferT(RECT mapRect, HeightMap<T>* pHMap)
	{
		mapRectValid(mapRect, pHMap->getWidth(), pHMap->getHeight());

		// make sure vertex buffer alloc
		bool bNeedRealloc = false;
		int newW = mapRect.right - mapRect.left;
		if(m_curVBMapW != newW)
		{
			m_curVBMapW = newW;
			bNeedRealloc = true;
		}

		int newH = mapRect.bottom - mapRect.top;
		if(m_curVBMapH != newH)
		{
			m_curVBMapH = newH;
			bNeedRealloc = true;
		}

		if(bNeedRealloc)
			reallocVertices();

		// fill vert stream
		tagVertex *pVS = m_vertexStream.getVertices();
		int index = 0;
		float uStep = 1.0f/pHMap->getWidth();
		float vStep = 1.0f/pHMap->getHeight();
		for(int z=mapRect.top;z<mapRect.bottom;z++)
		{
			for(int x=mapRect.left;x<mapRect.right;x++)
			{
				pVS[index].pos.x = x*m_mapScale.x;
				pVS[index].pos.y = pHMap->getValue(x,z)*m_mapScale.y;
				pVS[index].pos.z = z*m_mapScale.z;

				pVS[index].uv.x = uStep*x;
				pVS[index].uv.y = vStep*z;

				index++;

			}
		}//endof for(z)

		// copy to hd vb
		m_vertBuffer->copyFromMemory((void*)pVS, m_vertexStream.getSizeInBytes());

		
	}

	void TerrainMeshSource::updateVertBuffer(RECT mapRect)
	{
		if(m_mapBits == 16)
		{	
			updateVertBufferT(mapRect, &m_16bitHMap);
		}
		else
		{
			ASSERT(m_mapBits == 8);
			updateVertBufferT(mapRect, &m_8bitHMap);
		}
	}

	int TerrainMeshSource::getHeightmapWidth(void)
	{
		return m_mapBits == 16 ? m_16bitHMap.getWidth() : m_8bitHMap.getWidth();
	}
	int TerrainMeshSource::getHeightmapHeight(void)
	{
		return m_mapBits == 16 ? m_16bitHMap.getHeight() : m_8bitHMap.getHeight();
	}

	void TerrainMeshSource::mapRectValid(RECT& rc, int w, int h)
	{
		if(rc.right == -1)
			rc.right = w;
		if(rc.bottom == -1)
			rc.bottom = h;

		// --
		if(rc.left < 0)
		{
			rc.right-=rc.left;
			rc.left=0;
		}
		if(rc.top < 0)
		{
			rc.bottom -= rc.top;
			rc.top = 0;
		}
		if(rc.right > w)
		{
			int offset = rc.right-w;
			rc.right -= offset;
			rc.left -= offset;
		}
		if(rc.bottom > h)
		{
			int offset = rc.bottom-h;
			rc.bottom -= offset;
			rc.top -=offset;
		}
	}

	void TerrainMeshSource::reallocVertices(void)
	{
		ASSERT(m_vertBuffer != NULL);

		// vertices
		int numVert = m_curVBMapH*m_curVBMapW;
		ASSERT(numVert > 0);
		
		m_vertexStream.alloc(numVert);

		m_vertBuffer->create(m_vertexStream.getSizeInBytes(), m_vertexStream.getStride(), m_pResMgr);

		// rebuild index buffer
		vector<WORD> memIB;
		int x,y;
		WORD indexGrid[9] = {0};
		for(y=0; y<m_curVBMapH-2; y+=2)
		{
			for(x=0; x<m_curVBMapW-2; x+=2)
			{
				indexGrid[0] = x + m_curVBMapW*y;
				indexGrid[1] = x+1 + m_curVBMapW*y;
				indexGrid[2] = x+2 + m_curVBMapW*y;

				indexGrid[3] = x + m_curVBMapW*(y+1);
				indexGrid[4] = x+1 + m_curVBMapW*(y+1);
				indexGrid[5] = x+2 + m_curVBMapW*(y+1);

				
				indexGrid[6] = x + m_curVBMapW*(y+2);
				indexGrid[7] = x+1 + m_curVBMapW*(y+2);
				indexGrid[8] = x+2 + m_curVBMapW*(y+2);

				memIB.push_back(indexGrid[4]);
				memIB.push_back(indexGrid[1]);
				memIB.push_back(indexGrid[2]);

				memIB.push_back(indexGrid[4]);
				memIB.push_back(indexGrid[2]);
				memIB.push_back(indexGrid[5]);

				memIB.push_back(indexGrid[4]);
				memIB.push_back(indexGrid[5]);
				memIB.push_back(indexGrid[8]);

				memIB.push_back(indexGrid[4]);
				memIB.push_back(indexGrid[8]);
				memIB.push_back(indexGrid[7]);

				memIB.push_back(indexGrid[4]);
				memIB.push_back(indexGrid[7]);
				memIB.push_back(indexGrid[6]);

				memIB.push_back(indexGrid[4]);
				memIB.push_back(indexGrid[6]);
				memIB.push_back(indexGrid[3]);

				memIB.push_back(indexGrid[4]);
				memIB.push_back(indexGrid[3]);
				memIB.push_back(indexGrid[0]);

				memIB.push_back(indexGrid[4]);
				memIB.push_back(indexGrid[0]);
				memIB.push_back(indexGrid[1]);
			}

			//
			m_numTriangles = (int)memIB.size()/3;
			int ibSize = (int)memIB.size()*sizeof(WORD);
			m_indexBuffer->create(ibSize, m_pResMgr);
			m_indexBuffer->copyFromMemory(&(memIB[0]), ibSize);
		}
	}

	void TerrainMeshSource::clipRect(RECT& rc)
	{
		if(rc.left < 0)
			rc.left = 0;
		if(rc.top < 0)
			rc.top = 0;
		if(rc.right > getHeightmapWidth())
			rc.right = getHeightmapWidth();
		if(rc.bottom > getHeightmapHeight())
			rc.bottom = getHeightmapHeight();
	}


	template<typename T>
	void copyNoiseToHeightmap(Perlin& pn, RECT rc, HeightMap<T>* pHMap, int tMax)
	{
		int x,y;
		float xStep = 1.0f/(rc.right-rc.left);
		float yStep = 1.0f/(rc.bottom-rc.top);

		//Perlin产生的值域在[-振幅,+振幅]之间
		//--缩放到0-255的区间
		float offset = pn.GetAmplitude();
		float range = pn.GetAmplitude()*2;

		for(y=rc.top; y<rc.bottom; y++)
		{
			for(x=rc.left; x<rc.right; x++)
			{
				float n = pn.Get(x*xStep, y*yStep);
				T tn = T((n+offset)/range*tMax);
				pHMap->setValue(x, y, tn);
			}
		}//endof for
	}

	void TerrainMeshSource::generateNoise(int x, int y, int w, int h, int numOctaves, float amplitude, float frequency)
	{
		if(w == -1)
			w = getHeightmapWidth();
		if(h == -1)
			h = getHeightmapHeight();

		RECT rc;
		rc.left = x;
		rc.right = x+w;
		rc.top = y;
		rc.bottom = y+h;

		clipRect(rc);

		//
		int cw = rc.right - rc.left;
		int ch = rc.bottom - rc.top;
		if(cw <=0
			|| ch <= 0)
			return;

		Perlin pn(numOctaves, frequency, amplitude, timeGetTime());

		if(m_mapBits == 16)
			copyNoiseToHeightmap(pn, rc, &m_16bitHMap, 65535);
		else
			copyNoiseToHeightmap(pn, rc, &m_8bitHMap, 255);
	}
}//namespace MagicGear