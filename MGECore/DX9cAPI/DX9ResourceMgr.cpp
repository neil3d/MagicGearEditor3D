#include "StdAfx.h"
#include ".\dx9resourcemgr.h"

namespace MagicGear
{
	DX9ResourceMgr::DX9ResourceMgr(void)
	{
		m_pD3D9Device = NULL;
	}

	DX9ResourceMgr::~DX9ResourceMgr(void)
	{
	}

	void DX9ResourceMgr::destroy(void)
	{
		DX9Texture::destroyFallbackTexture();
	}

	HDTexture* DX9ResourceMgr::createTexture(const char* szRefName)
	{
		string szNameLwr(szRefName);
		transform(szNameLwr.begin(), szNameLwr.end(), szNameLwr.begin(), tolower);

		// find in map
		map<string, DX9Texture*>::iterator iter = m_textureMap.find(szNameLwr);
		if(iter != m_textureMap.end())
		{
			DX9Texture* pTex = iter->second;
			pTex->addRef();
			return pTex;
		}

		// create new
		DX9Texture* pTex = new DX9Texture(szNameLwr.c_str());
		m_textureMap.insert(make_pair(szNameLwr, pTex));
		return pTex;
	}

	void DX9ResourceMgr::destroyTexture(HDTexture* pTexture)
	{
		string szRefName = pTexture->getRefName();
		bool bDel = pTexture->release();

		if(bDel)
		{
			// remove from map
			map<string, DX9Texture*>::iterator iter = m_textureMap.find(szRefName);
			if(iter != m_textureMap.end())
			{
				m_textureMap.erase(iter);
			}
			else
			{
				ASSERT(0 && "texture object not found in map");
			}
		}
	}

	void DX9ResourceMgr::onEvent(EEvent event, int param1, int param2)
	{
		for(list<HDEffect*>::iterator iter = m_effectList.begin();
			iter != m_effectList.end(); ++iter)
		{
			HDEffect *pEffect = (*iter);
			pEffect->onEvent(event, param1, param2);
		}

		for(list<HDFont*>::iterator iter = m_fontList.begin();
			iter != m_fontList.end(); ++iter)
		{
			HDFont *pFont = (*iter);
			pFont->onEvent(event, param1, param2);
		}
	}
}//namespace MagicGear