#pragma once

#ifndef SAFE_RELEASE
	#define SAFE_RELEASE(x) if(x) {x->Release();x=NULL;}
#endif

#ifndef SAFE_FREE
	#define SAFE_FREE(x) if(x) {free(x);x=NULL;}
#endif

#ifndef SAFE_DEL
	#define SAFE_DEL(x) if(x) {delete x;x=NULL;}
#endif

#ifndef SAFE_DELA
	#define SAFE_DELA(x) if(x) {delete[] x;x=NULL;}
#endif