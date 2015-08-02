#include "StdAfx.h"
#include ".\dx9resource.h"
#include "DX9ResourceMgr.h"
#include "..\Util\Logger.h"
#include "..\Util\SafeRelease.h"
#include "..\HardwareAPI\HDDevice.h"

namespace MagicGear
{
	// DX9Texture
	//-----------------------------------------------------------------------------------------
	IDirect3DTexture9* DX9Texture::s_fallbackTexture = NULL;

	DX9Texture::DX9Texture(const char* szRefName) : HDTexture(szRefName)
	{
		m_texture = 0;
	}

	DX9Texture::~DX9Texture(void)
	{}

	void DX9Texture::loadFromFile(const char* szPath, int numMipLevels, HDResourceMgr *pMgr)
	{
		// szPath can be null
		ASSERT(pMgr);

		destroy();

		//--
		string szSafePath;
		if(szPath)
			szSafePath = szPath;
		else
			szSafePath = getRefName();

		DX9ResourceMgr* pDX9Mgr = (DX9ResourceMgr*)pMgr;
		IDirect3DDevice9* pDev = pDX9Mgr->getDX9Device();
		HRESULT hr;

		D3DXIMAGE_INFO imgInfo;
		hr = D3DXCreateTextureFromFileEx(pDev,
			szSafePath.c_str(),
			D3DX_DEFAULT,	// width
			D3DX_DEFAULT,	// height
			numMipLevels,
			0,	// usage
			D3DFMT_UNKNOWN,	// format,
			D3DPOOL_MANAGED,// pool
			D3DX_DEFAULT,	// filter
			D3DX_DEFAULT,	// mip filter
			0,	// color key
			&imgInfo,
			NULL,//palette 
			&m_texture);

		if(FAILED(hr))
		{
			LOG("texture load failed, path = %s, error = %s.\r\n", szSafePath.c_str(), DXGetErrorString9(hr));
			m_texture = s_fallbackTexture;

			throw HDAPIException("texture file load failed.");
		}

	}

	void DX9Texture::writeToFile(const char* szPath)
	{
		
	}

	void DX9Texture::destroy()
	{
		if(m_texture != s_fallbackTexture)
		{
			SAFE_RELEASE(m_texture);
		}
	}

	void DX9Texture::createFallbackTexture(HDResourceMgr *pMgr)
	{
		ASSERT(pMgr);

		DX9ResourceMgr* pDX9Mgr = (DX9ResourceMgr*)pMgr;
		IDirect3DDevice9* pDev = pDX9Mgr->getDX9Device();
		HRESULT hr;

		const int SIZE = 128;

		hr = pDev->CreateTexture(SIZE, SIZE, 1, 0, 
			D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, &s_fallbackTexture, NULL);
		if(FAILED(hr))
		{
			LOG("fallback texture create failed");
			return;
		}

		D3DLOCKED_RECT lockRect;
		hr = s_fallbackTexture->LockRect(0, &lockRect, NULL, 0);
		if(SUCCEEDED(hr))
		{
			D3DCOLOR fallColor[2];
			fallColor[0] = D3DCOLOR_ARGB(255,5,250,250);
			fallColor[1] = D3DCOLOR_ARGB(255,5,0,5);

			D3DCOLOR *pPixel = (D3DCOLOR *)lockRect.pBits;
			for(int y=0; y<SIZE; y++)
			{
				for(int x=0; x<SIZE; x++)
				{
					int sel = (x/16)%2+(y/16+1)%2;
					pPixel[y*SIZE+x] = fallColor[sel%2];
				}
			}
			hr = s_fallbackTexture->UnlockRect(0);
		}//endof if
	}

	void DX9Texture::destroyFallbackTexture()
	{
		SAFE_RELEASE(s_fallbackTexture);
	}

	// DX9VB
	//-----------------------------------------------------------------------------------------
	DX9VB::DX9VB(void)
	{
		m_sizeInBytes = 0;
		m_stride = 0;
		m_pVB = NULL;
	}

	DX9VB::~DX9VB(void)
	{
		destroy();
	}

	void DX9VB::create(int sizeInBytes, int stride, HDResourceMgr *pMgr)
	{
		ASSERT(sizeInBytes > 0);
		ASSERT(stride > 0);
		ASSERT(pMgr);

		destroy();

		//
		DX9ResourceMgr* pDX9Mgr = (DX9ResourceMgr*)pMgr;
		IDirect3DDevice9* pDev = pDX9Mgr->getDX9Device();
		HRESULT hr;

		hr = pDev->CreateVertexBuffer(sizeInBytes,
			D3DUSAGE_WRITEONLY,	// usage
			0,	// FVF
			D3DPOOL_MANAGED,
			&m_pVB, NULL);

		if(FAILED(hr))
		{
			LOG("vertex buffer create failed, size = %d\r\n", sizeInBytes);
			throw HDAPIException("vertex buffer create failed.");
		}

		//
		m_sizeInBytes = sizeInBytes;
		m_stride = stride;
	}

	void DX9VB::destroy()
	{
		SAFE_RELEASE(m_pVB);
	}

	void DX9VB::copyFromMemory(void* pBuffer, int bufSize)
	{
		ASSERT(m_pVB);
		ASSERT(pBuffer);
		ASSERT(bufSize <= m_sizeInBytes);

		void* pData = NULL;
		HRESULT hr = m_pVB->Lock(0, bufSize, &pData, 0);
		if(SUCCEEDED(hr))
		{
			memcpy(pData, pBuffer, bufSize);
			hr = m_pVB->Unlock();
			ASSERT(SUCCEEDED(hr));
		}
		else
		{
			throw HDAPIException("vertex buffer lock failed.");
		}
	}

	// DX9VertexDecl
	//-----------------------------------------------------------------------------------------
	DX9VertexDecl::DX9VertexDecl(void)
	{
		m_pDecl = NULL;
	}
	DX9VertexDecl::~DX9VertexDecl(void)
	{
		destroy();
	}

	void DX9VertexDecl::beginBuild(void)
	{
		destroy();
		m_elementArray.clear();
	}

	void DX9VertexDecl::addElement(int stream, int offset, EType type,  int method, EUsage usage, int usageIndex)
	{
		D3DVERTEXELEMENT9 em;
		em.Stream = stream;
		em.Offset = offset;
		em.Type = type;
		em.Method = method;
		em.Usage = usage;
		em.UsageIndex = usageIndex;

		m_elementArray.push_back(em);
	}

	void DX9VertexDecl::endBuild(HDResourceMgr *pMgr)
	{
		ASSERT(pMgr);
		ASSERT(m_elementArray.size() > 0);

		// --
		D3DVERTEXELEMENT9 em = D3DDECL_END();
		m_elementArray.push_back(em);

		// --
		DX9ResourceMgr* pDX9Mgr = (DX9ResourceMgr*)pMgr;
		IDirect3DDevice9* pDev = pDX9Mgr->getDX9Device();
		HRESULT hr;


		hr = pDev->CreateVertexDeclaration(&m_elementArray[0], &m_pDecl);
		if(FAILED(hr))
		{
			throw HDAPIException("vertex declaration created failed.");
		}

	}

	void DX9VertexDecl::destroy()
	{
		SAFE_RELEASE(m_pDecl);
		m_elementArray.clear();
	}

	// DX9Effect
	//-----------------------------------------------------------------------------------------
	DX9Effect::DX9Effect(void)
	{
		m_pEffect = NULL;
	}

	DX9Effect::~DX9Effect(void)
	{
		destroy();
	}

	void DX9Effect::loadFromFile(const char* szPath, HDResourceMgr *pMgr)
	{
		ASSERT(szPath);
		ASSERT(pMgr);

		destroy();

		//
		DX9ResourceMgr* pDX9Mgr = (DX9ResourceMgr*)pMgr;
		IDirect3DDevice9* pDev = pDX9Mgr->getDX9Device();
		HRESULT hr;

		ID3DXEffect *pEffect = NULL;

		DWORD dwFlag = 0;
#ifdef SHADER_DEBUG
		dwFlag = D3DXSHADER_DEBUG | D3DXSHADER_NO_PRESHADER |D3DXSHADER_SKIPOPTIMIZATION;
#endif

		ID3DXBuffer *pError = NULL;
		hr = D3DXCreateEffectFromFile(pDev,
			szPath,
			NULL,NULL,
			dwFlag,
			NULL,
			&pEffect,&pError);
		if(FAILED(hr))
		{
			if(pError)
			{
				const char* szError = (const char*)pError->GetBufferPointer();
				LOG(szError);
			}
			throw HDAPIException("Effect load failed.");
		}

		m_pEffect = pEffect;
	}

	void DX9Effect::destroy()
	{
		SAFE_RELEASE(m_pEffect);
	}

	int DX9Effect::begin()
	{
		UINT numPass = 0;
		HRESULT hr = m_pEffect->Begin(&numPass, 0);
		ASSERT(SUCCEEDED(hr));

		return numPass;
	}

	void DX9Effect::beginPass(int index)
	{
		HRESULT hr = m_pEffect->BeginPass(index);
		ASSERT(SUCCEEDED(hr));
	}

	void DX9Effect::endPass()
	{
		HRESULT hr = m_pEffect->EndPass();
		ASSERT(SUCCEEDED(hr));
	}

	void DX9Effect::end()
	{
		HRESULT hr = m_pEffect->End();
		ASSERT(SUCCEEDED(hr));
	}

	void DX9Effect::setTexture(const char* szName, HDTexture* pTexture)
	{
		DX9Texture *pDX9 = (DX9Texture *)pTexture;
		HRESULT hr = m_pEffect->SetTexture(szName, pDX9->getDX9());
		ASSERT(SUCCEEDED(hr));
	}

	void DX9Effect::setMatrix4(const char* szName, const Matrix4& mat)
	{
		HRESULT hr = m_pEffect->SetMatrix(szName, &mat);
		ASSERT(SUCCEEDED(hr));
	}

	void DX9Effect::onEvent(int event, int param1, int param2)
	{
		switch(event)
		{
		case DX9ResourceMgr::EE_DeviceLost:
			{
				HRESULT hr = m_pEffect->OnLostDevice();
				break;
			}
		case DX9ResourceMgr::EE_DeviceReset:
			{
				HRESULT hr = m_pEffect->OnResetDevice();
				break;
			}
		}
	}

	// DX9IB
	//-----------------------------------------------------------------------------------------
	DX9IB::DX9IB(void)
	{
		m_pIB = NULL;
		m_sizeInBytes = 0;
	}

	DX9IB::~DX9IB(void)
	{
		destroy();
	}

	void DX9IB::create(int sizeInBytes, HDResourceMgr *pMgr)
	{
		ASSERT(sizeInBytes > 0);
		ASSERT(pMgr);

		destroy();

		//
		DX9ResourceMgr* pDX9Mgr = (DX9ResourceMgr*)pMgr;
		IDirect3DDevice9* pDev = pDX9Mgr->getDX9Device();
		HRESULT hr;

		hr = pDev->CreateIndexBuffer(sizeInBytes,
			D3DUSAGE_WRITEONLY, // usage
			D3DFMT_INDEX16,
			D3DPOOL_MANAGED,
			&m_pIB, NULL);

		if(FAILED(hr))
		{
			LOG("index buffer create failed, size = %d\r\n", sizeInBytes);
			throw HDAPIException("index buffer create failed.");
		}

		m_sizeInBytes = sizeInBytes;

	}

	void DX9IB::destroy(void)
	{
		SAFE_RELEASE(m_pIB);
	}

	void DX9IB::copyFromMemory(void* pBuffer, int bufSize)
	{
		ASSERT(m_pIB);
		ASSERT(pBuffer);
		ASSERT(bufSize <= m_sizeInBytes);

		void* pData = NULL;
		HRESULT hr = m_pIB->Lock(0, bufSize, &pData, 0);
		if(SUCCEEDED(hr))
		{
			memcpy(pData, pBuffer, bufSize);
			hr = m_pIB->Unlock();
			ASSERT(SUCCEEDED(hr));
		}
		else
		{
			throw HDAPIException("index buffer lock failed.");
		}
	}

	//-----------------------------------------------------------------------------------------
	DX9Font::DX9Font()
	{
		m_pD3DFont = NULL;
		m_fontSize = 0;
	}

	DX9Font::~DX9Font()
	{
		destroy();
	}

	void DX9Font::create(HDResourceMgr *pMgr, int size, int weight, const char* szFaceName, bool bItalic)
	{
		destroy();

		//--
		DX9ResourceMgr* pDX9Mgr = (DX9ResourceMgr*)pMgr;
		IDirect3DDevice9* pDev = pDX9Mgr->getDX9Device();
		
		D3DXFONT_DESC font;
		memset(&font,0,sizeof(font));
		font.Height = size;
		font.Width = 0;
		font.Weight= weight;
		font.MipLevels = D3DX_DEFAULT;
		font.Italic = bItalic;
		font.CharSet = DEFAULT_CHARSET;
		font.OutputPrecision = OUT_DEFAULT_PRECIS;
		font.Quality = DEFAULT_QUALITY;
		font.PitchAndFamily = DEFAULT_PITCH;
		strcpy( font.FaceName, szFaceName);

		HRESULT hr=D3DXCreateFontIndirect(pDev,
			&font,
			&m_pD3DFont);

		if(FAILED(hr))
		{
			LOG("Font create failed, size = %d\r\n", size);
			throw HDAPIException("font create failed.");
		}

		m_fontSize = size;
	}

	void DX9Font::destroy()
	{
		SAFE_RELEASE(m_pD3DFont);
	}

	void DX9Font::drawText(const char* szText, int x, int y, DWORD color)
	{
		int len = (int)strlen(szText);

		RECT rc;
		rc.left = x;
		rc.top = y;
		rc.right = x+len*m_fontSize;
		rc.bottom = y+m_fontSize;

		int offset = m_pD3DFont->DrawText(NULL, szText, len, &rc, DT_TOP|DT_LEFT, color);
	}

	void DX9Font::onEvent(int event, int param1, int param2)
	{
		switch(event)
		{
		case DX9ResourceMgr::EE_DeviceLost:
			{
				HRESULT hr = m_pD3DFont->OnLostDevice();
				break;
			}
		case DX9ResourceMgr::EE_DeviceReset:
			{
				HRESULT hr = m_pD3DFont->OnResetDevice();
				break;
			}
		}
	}
}//namespace MagicGear