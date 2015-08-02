#pragma once
#include "..\Core\MGException.h"

namespace MagicGear
{
	class TerrainException : public MGException
	{
	public:
		TerrainException(const char* szInfo) : MGException(szInfo)	{}
		~TerrainException(void)	{}
	};
}//namespace MagicGear