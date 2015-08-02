#pragma once
#include "..\HardwareAPI\HDResourceMgr.h"
#include "DX9Resource.h"

namespace MagicGear
{
	/**	\class DX9ResourceMgr 
	*/
	class DX9ResourceMgr : public HDResourceMgr
	{
	public:
		enum EEvent
		{
			EE_DeviceLost	= 1000,
			EE_DeviceReset
		};
	public:
		DX9ResourceMgr(void);
		virtual ~DX9ResourceMgr(void);

		virtual void destroy(void);

		virtual HDTexture* createTexture(const char* szRefName);
		virtual void destroyTexture(HDTexture* pTexture);

		virtual HDVertexBuffer* createVertexBuffer()
		{
			return new DX9VB;
		}

		virtual void destroyVertexBuffer(HDVertexBuffer *pVB)
		{
			delete pVB;
		}

		virtual HDVertexDecl* createVertexDecl()
		{
			return new DX9VertexDecl;
		}

		virtual void destroyVertexDecl(HDVertexDecl* pDecl)
		{
			delete pDecl;
		}

		virtual HDIndexBuffer* createIndexBuffer()
		{
			return new DX9IB;
		}

		virtual void destroyIndexBuffer(HDIndexBuffer* pIB)
		{
			delete pIB;
		}

		virtual HDEffect* createEffect()
		{
			DX9Effect* pNewEffect = new DX9Effect;
			m_effectList.push_back(pNewEffect);
			return pNewEffect;
		}

		virtual void destroyEffect(HDEffect* pEffect)
		{
			m_effectList.remove(pEffect);
			delete pEffect;
		}

		virtual HDFont* createFont()
		{
			DX9Font* pNewFont = new DX9Font;
			m_fontList.push_back(pNewFont);
			return pNewFont;
		}

		virtual void destroyFont(HDFont* pFont)
		{
			m_fontList.remove(pFont);
			delete pFont;
		}

		//--
		void init(IDirect3DDevice9 *pDevice)
		{
			m_pD3D9Device = pDevice;
			DX9Texture::createFallbackTexture(this);
		}

		void onEvent(EEvent event, int param1, int param2);

		IDirect3DDevice9* getDX9Device()	{	return m_pD3D9Device;}
	private:
		IDirect3DDevice9*	m_pD3D9Device;
		
		map<string, DX9Texture*>	m_textureMap;
		list<HDEffect*>				m_effectList;
		list<HDFont*>				m_fontList;
	};
}//namespace MagicGear