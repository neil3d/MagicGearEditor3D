#include "StdAfx.h"
#include ".\mgrtti.h"

namespace MagicGear
{
	RTTInfo	RTTIObj::m_classRTTIObj("RTTIObj",NULL,NULL);

	RTTIObj::RTTIObj(void)
	{
	}

	RTTIObj::~RTTIObj(void)
	{
	}

	RTTInfo* RTTIObj::getRTTInfo() const
	{
		return &m_classRTTIObj;
	}

	const char* RTTIObj::getClassName()
	{
		return getRTTInfo()->m_szClassName;
	}

	bool RTTIObj::isKindOf(const char* szClassName) const
	{
		RTTInfo *pInfo = const_cast<RTTInfo*>(getRTTInfo());
		return pInfo->isKindOf(szClassName);
	}

	bool RTTIObj::isStaticClass(const char* szClassName) const
	{
		RTTInfo *pInfo = const_cast<RTTInfo*>(getRTTInfo());
		if(pInfo == NULL)
			return false;
		return strcmp(szClassName,pInfo->m_szClassName) == 0;
	}


	bool RTTIObj::isKindOf(const RTTInfo *pInfo) const
	{
		RTTInfo *pMyInfo = const_cast<RTTInfo*>(getRTTInfo());
		return pMyInfo->isKindOf(pInfo);
	}

	bool RTTIObj::isStaticClass(const RTTInfo *pInfo) const
	{
		if(pInfo == NULL)
			return false;

		return pInfo == getRTTInfo();
	}

	// class RTTInfo
	//----------------------------------------------------------------------------
	RTTInfo::RTTInfo(const char* szClassName,RTTInfo *pSuperClass,FuncCreateObj *pFunc)
		: m_szClassName(szClassName),
		m_pSuperClass(pSuperClass),
		m_pfnCreateObj(pFunc)

	{
		RTTFactory::getInst()->addRuntimeClass(this);
	}

	RTTInfo::~RTTInfo(void)
	{
	}

	bool RTTInfo::isKindOf(const RTTInfo *pInfo)
	{
		if(pInfo == NULL)
			return false;

		RTTInfo *pInfoIter = this;
		while(pInfoIter!=NULL)
		{
			if(pInfoIter == pInfo)
				return true;
			else
				pInfoIter = pInfoIter->m_pSuperClass;
		}

		return false;
	}

	bool RTTInfo::isKindOf(const char* szClassName)
	{
		if(szClassName == NULL)
			return false;

		RTTInfo *pInfoIter = this;
		while(pInfoIter!=NULL)
		{
			if(strcmp(szClassName,pInfoIter->m_szClassName) == 0)
				return true;
			else
				pInfoIter = pInfoIter->m_pSuperClass;
		}
		return false;
	}

	// class RTTFactory
	//----------------------------------------------------------------------------
	typedef map<string,const RTTInfo*>RTTIMap;
	class RTTFactory::Member
	{
	public:
		RTTIMap					m_rttiMap;	//save to map, for fast finding
		vector<const RTTInfo*>	m_rttiArray;//vector for radom access

		Member()
		{}
		~Member()
		{}
	};

	RTTFactory::RTTFactory()
	{
		m_p = new Member;
	}

	RTTFactory::~RTTFactory()
	{
		delete m_p;
	}

	RTTIObj	*RTTFactory::createObj(const char* szClassName)
	{
		RTTIMap::iterator iter = m_p->m_rttiMap.find(szClassName);

		if(iter == m_p->m_rttiMap.end())
		{
			OutputDebugString(szClassName);
			OutputDebugString(" : class not found.\r\n");
			return NULL;
		}

		const RTTInfo *pInfo = (*iter).second;
		if(pInfo->m_pfnCreateObj == NULL)
		{
			OutputDebugString(szClassName);
			OutputDebugString(" : class runtime create func not defined.\r\n");
			return NULL;
		}

		return pInfo->m_pfnCreateObj();
	}

	RTTFactory *RTTFactory::getInst()
	{
		static RTTFactory g_rtcFactory;
		return &g_rtcFactory;
	}

	void	RTTFactory::addRuntimeClass(const RTTInfo *pInfo)
	{
		if(pInfo == NULL)
			return;

#ifdef _DEBUG
		RTTIMap::iterator iter = m_p->m_rttiMap.find(pInfo->m_szClassName);
		ASSERT(iter == m_p->m_rttiMap.end());
#endif

		m_p->m_rttiMap[pInfo->m_szClassName] = pInfo;
		m_p->m_rttiArray.push_back(pInfo);
	}

	unsigned int RTTFactory::getNumClass() const
	{
		return (unsigned int)m_p->m_rttiArray.size();
	}

	const RTTInfo *RTTFactory::getClass(unsigned int i) const
	{
		ASSERT(i < getNumClass());
		return m_p->m_rttiArray[i];
	}
}//namespace MagicGear