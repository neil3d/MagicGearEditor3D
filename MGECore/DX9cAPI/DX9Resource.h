#pragma once
#include "..\HardwareAPI\HDResource.h"

namespace MagicGear
{
	//-----------------------------------------------------------------------------------------
	/**	\class DX9Texture 
	*/
	class DX9Texture : public HDTexture
	{
	public:
		DX9Texture(const char* szRefName);
		virtual ~DX9Texture(void);

		virtual void loadFromFile(const char* szPath, int numMipLevels, HDResourceMgr *pMgr);
		virtual void writeToFile(const char* szPath);
		virtual void destroy();

		IDirect3DTexture9* getDX9()	{	return m_texture;}
	private:
		IDirect3DTexture9*	m_texture;
	
		//--
	public:
		static void createFallbackTexture(HDResourceMgr *pMgr);
		static void destroyFallbackTexture();
	private:
		static IDirect3DTexture9*	s_fallbackTexture;
	};

	//-----------------------------------------------------------------------------------------
	/**	\class DX9VB 
	*/
	class DX9VB : public HDVertexBuffer
	{
	public:
		DX9VB(void);
		virtual ~DX9VB(void);

		virtual void create(int sizeInBytes, int stride, HDResourceMgr *pMgr);
		virtual void destroy(void);
		virtual void copyFromMemory(void* pBuffer, int bufSize);
		virtual int getStride() const		{	return m_stride;	}
		virtual int getNumVertex() const	{	return m_sizeInBytes/m_stride; }

		IDirect3DVertexBuffer9* getDX9()	{	return m_pVB;}

	private:
		IDirect3DVertexBuffer9*	m_pVB;
		int						m_stride;
		int						m_sizeInBytes;
	};

	//-----------------------------------------------------------------------------------------
	/**	\class DX9VertexDecl 
	*/
	class DX9VertexDecl : public HDVertexDecl
	{
	public:
		DX9VertexDecl(void);
		virtual ~DX9VertexDecl(void);

		virtual void beginBuild(void);
		virtual void addElement(int stream, int offset, EType type,  int method, EUsage usage, int usageIndex);
		virtual void endBuild(HDResourceMgr *pMgr);
		virtual void destroy();

		IDirect3DVertexDeclaration9* getDX9()	{	return m_pDecl;}
	private:
		vector<D3DVERTEXELEMENT9>		m_elementArray;
		IDirect3DVertexDeclaration9*	m_pDecl;
	};

	//-----------------------------------------------------------------------------------------
	/**	\class DX9Effect
	*/
	class DX9Effect : public HDEffect
	{
	public:
		DX9Effect(void);
		virtual ~DX9Effect(void);

		virtual void loadFromFile(const char* szPath, HDResourceMgr *pMgr);
		virtual void destroy();

		virtual int begin();
		virtual void beginPass(int index);
		virtual void endPass();
		virtual void end();

		virtual void setTexture(const char* szName, HDTexture* pTexture);
		virtual void setMatrix4(const char* szName, const Matrix4& mat);

		virtual void onEvent(int event, int param1, int param2);

	private:
		ID3DXEffect	*m_pEffect;
	};

	//-----------------------------------------------------------------------------------------
	/**	\class DX9IB
	*/
	class DX9IB : public HDIndexBuffer
	{
	public:
		DX9IB(void);
		virtual ~DX9IB(void);

		virtual void create(int sizeInBytes, HDResourceMgr *pMgr);
		virtual void destroy(void);
		virtual void copyFromMemory(void* pBuffer, int bufSize);

		IDirect3DIndexBuffer9* getDX9(void)	{	return m_pIB;}
	private:
		IDirect3DIndexBuffer9*	m_pIB;
		int						m_sizeInBytes;
	};

	//-----------------------------------------------------------------------------------------
	/**	\class DX9Font 
	*/
	class DX9Font : public HDFont
	{
	public:
		DX9Font();
		virtual ~DX9Font();

		virtual void create(HDResourceMgr *pMgr, int size, int weight = 400, const char* szFaceName = "", bool bItalic = false);
		virtual void destroy();
		virtual void drawText(const char* szText, int x, int y, DWORD color = 0xFFFFFFFF);

		virtual void onEvent(int event, int param1, int param2);

	private:
		ID3DXFont	*m_pD3DFont;
		int			m_fontSize;
	};
}//namespace MagicGear