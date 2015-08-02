#pragma once
#include "..\Util\SafeRelease.h"

namespace MagicGear
{
	template<typename VT>
	class VertexStream
	{
	public:
		VertexStream(void)
		{
			m_pVertices = NULL;
			m_numVert = 0;
		}
		~VertexStream(void)	
		{
			SAFE_DELA(m_pVertices);
		}

		void alloc(int numVert)
		{
			SAFE_DELA(m_pVertices);

			m_pVertices = new VT[numVert];
			m_numVert = numVert;

			memset(m_pVertices, 0, getSizeInBytes());
		}

		VT* getVertices()		{	return m_pVertices; }
		int getSizeInBytes()	{	return sizeof(VT)*m_numVert; }
		int getStride()			{	return sizeof(VT); }

	private:
		VT*	m_pVertices;
		int	m_numVert;

	};
}//namespace MagicGear