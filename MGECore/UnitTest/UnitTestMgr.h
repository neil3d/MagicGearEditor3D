#pragma once
#include "..\HardwareAPI\HDRenderer.h"
using namespace MagicGear;

class TestCase;

class UnitTestMgr
{
public:
	UnitTestMgr(void);
	~UnitTestMgr(void);

	void create(void);
	void destroy(void);

	void render(HDRenderer *pRenderer);

private:
	vector<TestCase*>	m_testArray;
};
