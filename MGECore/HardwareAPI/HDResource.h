#pragma once
#include "..\Math\MathBaseDef.h"

namespace MagicGear
{
	class HDResourceMgr;

	/**	\class Resource
		\brief resource base class
		\remarks reference by name; device lost interface
	*/
	class Resource
	{
	public:
		Resource(const char* szRefName)
		{
			m_refCount = 1;
			m_szRefName = szRefName;
		}
		virtual ~Resource(void)	{}

		void addRef(void)	{	m_refCount++; }

		//!	return true if deleted
		bool release(void)
		{
			m_refCount--;

			if(m_refCount <= 0)
			{
				delete this;
				return true;
			}
			else
				return false;
		}

		// device lost issue
		virtual void onEvent(int event, int param1, int param2)
		{}

		const char* getRefName() const	{	return m_szRefName.c_str(); }
	private:
		int		m_refCount;
		string	m_szRefName;
	};

	class HDVertexDecl
	{
	public:
		enum EType	// exactly same as dx9
		{
			ET_Float1 = 0,
			ET_Float2 = 1,
			ET_Float3 = 2,
			ET_Float4 = 3,
			ET_DwordColor = 4,
			ET_Ubyte4 = 5,
			ET_Short2 = 6,
			ET_Short4 = 7,
			ET_Ubyte4n = 8,
			ET_Short2n = 9,
			ET_Short4n = 10,
			ET_Ushort2n = 11,
			ET_Ushort4n = 12,
			ET_Udec3 = 13,
			ET_Dec3n = 14,
			ET_Float16_2 = 15,
			ET_Float16_4 = 16,
			ET_Unused = 17
		};

		enum EUsage
		{
			EU_Position = 0,
			EU_BlendWeight = 1,
			EU_BlendIndices = 2,
			EU_Normal = 3,
			EU_Psize = 4,
			EU_Texcoord = 5,
			EU_Tangent = 6,
			EU_Binormal = 7,
			EU_Tessfactor = 8,
			EU_Positiont = 9,
			EU_Color = 10,
			EU_Fog = 11,
			EU_Depth = 12,
			EU_Sample = 13
		};

		enum EMothod
		{
			EM_Default = 0,
			EM_Partialu = 1,
			EM_Partialv = 2,
			EM_CrossUV = 3,
			EM_UV = 4,
			EM_Lookup = 5,
			EM_LookupPresampled = 6
		};
	public:
		HDVertexDecl(void)	{}
		virtual ~HDVertexDecl(void)	{}

		virtual void beginBuild(void) = 0;
		virtual void addElement(int stream, int offset, EType type,  int method, EUsage usage, int usageIndex) = 0;
		virtual void endBuild(HDResourceMgr *pMgr) = 0;
	};

	class HDVertexBuffer : public Resource
	{
	public:
		HDVertexBuffer(void) : Resource("NONE")	{}
		virtual ~HDVertexBuffer(void)			{}

		virtual void create(int sizeInBytes, int stride, HDResourceMgr *pMgr) = 0;
		virtual void destroy(void) = 0;
		virtual void copyFromMemory(void* pBuffer, int bufSize) = 0;
		virtual int getStride() const = 0;
		virtual int getNumVertex() const = 0;
	};

	class HDIndexBuffer : public Resource
	{
	public:
		HDIndexBuffer(void) : Resource("NONE")
		{}
		virtual ~HDIndexBuffer(void)
		{}

		virtual void create(int sizeInBytes, HDResourceMgr *pMgr) = 0;
		virtual void destroy(void) = 0;
		virtual void copyFromMemory(void* pBuffer, int bufSize) = 0;
	};

	class HDTexture : public Resource
	{
	public:
		HDTexture(const char* szRefName) : Resource(szRefName)
		{}
		virtual ~HDTexture(void)
		{}

		virtual void loadFromFile(const char* szPath, int numMipLevels, HDResourceMgr *pMgr) = 0;
		virtual void writeToFile(const char* szPath) = 0;
		virtual void destroy() = 0;
	};

	class HDEffect : public Resource
	{
	public:
		HDEffect(void) : Resource("NONE")
		{}
		virtual ~HDEffect(void)
		{}

		virtual void loadFromFile(const char* szPath, HDResourceMgr *pMgr) = 0;
		virtual void destroy() = 0;

		virtual int begin() = 0;
		virtual void beginPass(int index) = 0;
		virtual void endPass() = 0;
		virtual void end() = 0;

		virtual void setTexture(const char* szName, HDTexture* pTexture) = 0;
		virtual void setMatrix4(const char* szName, const Matrix4& mat) = 0;
	};

	class HDFont : public Resource
	{
	public:
		HDFont(void) : Resource("NONE")	{}
		virtual ~HDFont(void)	{}

		virtual void create(HDResourceMgr *pMgr, int size, int weight = 400, const char* szFaceName = "", bool bItalic = false) = 0;
		virtual void destroy() = 0;
		virtual void drawText(const char* szText, int x, int y, DWORD color = 0xFFFFFFFF) = 0;
	};

}//namespace MagicGear