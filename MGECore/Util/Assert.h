
#ifndef ASSERT
	#include <assert.h>
	#ifdef _DEBUG
		#define ASSERT assert
	#else
		#define ASSERT	__noop
	#endif
#endif//#ifndef ASSERT