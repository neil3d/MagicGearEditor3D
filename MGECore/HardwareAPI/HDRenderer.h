#pragma once

namespace MagicGear
{
	enum EPrimitiveType
	{
		EPM_PointList = 1,
		EPM_LineList = 2,
		EPM_LineStrip = 3,
		EPM_TriangleList = 4,
		EPM_TriangleStrip = 5,
		EPM_TriangleFan = 6,

		EPM_End
	};
	//----------------------------------------------------------------------
	class HDVertexDecl;
	class HDVertexBuffer;
	class HDIndexBuffer;

	class HDRenderer
	{
	public:
		HDRenderer(void)	{}
		virtual ~HDRenderer(void)	{}

		virtual void setVertexDecl(HDVertexDecl* pDecl) = 0;
		virtual void setVertexBuffer(int index, const HDVertexBuffer *pVB) = 0;
		virtual void setIndexBuffer(const HDIndexBuffer *pIB) = 0;

		virtual void drawPrimitive(EPrimitiveType type, int numPrimitive) = 0;
		virtual void drawIndexedPrimitive(EPrimitiveType type, int numVert, int numPrimitive) = 0;
	};
}//namespace MagicGear