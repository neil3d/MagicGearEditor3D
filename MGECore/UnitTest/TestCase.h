#pragma once

#include "..\HardwareAPI\HDRenderer.h"
using namespace MagicGear;

class TestCase
{
public:
	TestCase(void)
	{
	}
	virtual ~TestCase(void)
	{
	}

	virtual void init()		{}
	virtual void run()		{}
	virtual void render(HDRenderer *pRenderer)	{}
};
