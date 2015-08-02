#pragma once

#include "HDResource.h"

namespace MagicGear
{
	class HDResourceMgr
	{
	public:
		HDResourceMgr(void)	{}
		virtual ~HDResourceMgr(void)	{}

		virtual void destroy(void) = 0;

		virtual HDTexture* createTexture(const char* szRefName) =0;
		virtual void destroyTexture(HDTexture* pTexture) = 0;

		virtual HDVertexBuffer* createVertexBuffer() = 0;
		virtual void destroyVertexBuffer(HDVertexBuffer *pVB) = 0;
		virtual HDVertexDecl* createVertexDecl() = 0;
		virtual void destroyVertexDecl(HDVertexDecl* pDecl) =0;

		virtual HDIndexBuffer* createIndexBuffer() = 0;
		virtual void destroyIndexBuffer(HDIndexBuffer* pIB) = 0;

		virtual HDEffect* createEffect() = 0;
		virtual void destroyEffect(HDEffect* pEffect) =0;

		virtual HDFont* createFont() = 0;
		virtual void destroyFont(HDFont* pFont) = 0;
	};
}//namespace MagicGear