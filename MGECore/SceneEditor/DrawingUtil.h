#pragma once
#include "..\Math\MathBaseDef.h"
#include "..\Mesh\VertexStream.h"

namespace MagicGear
{
	class HDResourceMgr;
	class HDRenderer;
	class HDVertexDecl;
	class HDVertexBuffer;
	class HDEffect;
	class HDFont;

	/**	\class DrawingUtil
		\brief some simple drawing functions
	*/
	class DrawingUtil
	{
		struct tagVertex
		{
			Vector3	pos;
			DWORD	color;
		};

		enum EConst
		{
			NUM_VERT = 256,
		};
	public:
		DrawingUtil(void);
		~DrawingUtil(void);

		static DrawingUtil* getInst();

		void create(HDResourceMgr *pResMgr);
		void destroy(HDResourceMgr *pResMgr);

		void drawText(const char* szText, int x, int y, DWORD color = 0xFFFFFFFF);
		void drawLineStrip(const Matrix4& matWorldViewPrj, const vector<Vector3>& posArray, DWORD color, HDRenderer *pRenderer);

	private:
		HDVertexBuffer	*m_pVB;
		HDVertexDecl	*m_pVDecl;
		HDEffect		*m_pEffect;

		HDFont			*m_pFont;
		VertexStream<tagVertex>	m_vs;
	};
}//namespace MagicGear