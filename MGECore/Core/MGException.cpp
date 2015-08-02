#include "StdAfx.h"
#include ".\mgexception.h"

namespace MagicGear
{
	MGException::MGException(const char* szInfo) : m_szInfo(szInfo)
	{
	}

	MGException::~MGException(void)
	{
	}
}//namespace MagicGear