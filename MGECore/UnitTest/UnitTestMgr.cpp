#include "StdAfx.h"
#include ".\unittestmgr.h"

#include "TestBasicDraw.h"

UnitTestMgr::UnitTestMgr(void)
{
}

UnitTestMgr::~UnitTestMgr(void)
{
}


void UnitTestMgr::create(void)
{
	m_testArray.push_back(new TestBasicDraw);
	
	for(size_t i=0; i<m_testArray.size(); i++)
	{
		m_testArray[i]->init();

		m_testArray[i]->run();
	}
}

void UnitTestMgr::destroy(void)
{
	for(size_t i=0; i<m_testArray.size(); i++)
	{
		delete m_testArray[i];
	}
	m_testArray.clear();
}

void UnitTestMgr::render(HDRenderer *pRenderer)
{
	for(size_t i=0; i<m_testArray.size(); i++)
	{
		m_testArray[i]->render(pRenderer);
	}
}