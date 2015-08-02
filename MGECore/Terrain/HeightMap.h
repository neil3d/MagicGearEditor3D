#pragma once
#include "..\Util\Logger.h"
#include "..\Util\SafeRelease.h"
#include "TerrainException.h"

namespace MagicGear
{
	/**	\class HeightMap
		\brief height map data, image import/export
	*/
	template<typename T>
	class HeightMap
	{
	public:
		HeightMap(void)
		{
			m_pData = NULL;
			m_width = m_height = 0;
		}
		~HeightMap(void)
		{
			destroy();
		}

		//!	alloc memory, init members
		void create(int w, int h, int initVal)
		{
			ASSERT(w>0 && h>0);
			// free old data
			destroy();

			// 
			m_width = w;
			m_height = h;

			// alloc
			int bufSize = getDataSize();
			m_pData = (T*)malloc(bufSize);
			if(m_pData == NULL)
			{
				LOG("height map alloc failed ,w = %d, h = %d", w, h);
				throw TerrainException("height map create failed.");
			}
			memset(m_pData, initVal, bufSize);
		}

		//! destroy
		void destroy()
		{
			SAFE_FREE(m_pData);
			m_width = m_height = 0;
		}

		int getWidth() const	{	return m_width; }
		int getHeight() const	{	return m_height;}
		int getDataSize() const	{	return m_width*m_height*sizeof(T);}
		void* getRawData() const{	return m_pData; }
		
		inline bool isValidIndex(int x,int y) const
		{ 
			return x>=0 && y>=0 && x<m_width && y<m_height; 
		}

		inline int getIndex(int x, int y) const
		{
			return y*m_width + x;
		}

		inline T getValue(int x, int y) const
		{
			ASSERT(isValidIndex(x, y));
			return m_pData[getIndex(x, y)];
		}

		inline void setValue(int x, int y, T val)
		{
			ASSERT(isValidIndex(x, y));
			m_pData[getIndex(x, y)] = val;
		}

	private:
		T*		m_pData;
		int		m_width,
				m_height;

	private:// non-copyable
		HeightMap( const HeightMap& );
		const HeightMap& operator=( const HeightMap& );
	};
}//namespace MagicGear