// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows XP or later.
#define WINVER 0x0501		// Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 6.0 or later.
#define _WIN32_IE 0x0600	// Change this to the appropriate value to target other versions of IE.
#endif

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>



// TODO: reference additional headers your program requires here
#include <windowsx.h>
#include <Mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#include <time.h>
#include <stdio.h>


// STL
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

// DirectX 9
//#define D3D_DEBUG_INFO

#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")
#include <d3dx9math.h>
#pragma comment(lib,"d3dx9.lib")
#include <dxerr9.h>
#pragma comment(lib,"dxerr9.lib")
#include <d3d9types.h>

#include "MGConfig.h"
#include "util\Assert.h"