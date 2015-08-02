#include "StdAfx.h"
#include "CameraBase.h"

namespace MagicGear
{
	CameraBase::CameraBase(void)	
	{
		matLoadIdentity(m_matPrj);
		matLoadIdentity(m_matInvPrj);
		matLoadIdentity(m_matView);
		matLoadIdentity(m_matInvView);

		m_viewPortW = m_viewPortH =1;
	}
	
	CameraBase::~CameraBase(void)	
	{
	}

	Vector2 CameraBase::normalizeScreen(int x, int y)
	{
		return Vector2(x/(m_viewPortW*0.5f)-1.0f,
			1.0f-y/(m_viewPortH*0.5f));
	}

	Vector3 CameraBase::worldToScreenF(const Vector3& wpt) const
	{
		Vector4 trans(wpt.x,wpt.y,wpt.z,1.0f);

		D3DXVec4Transform(&trans,&trans,&m_matView);
		D3DXVec4Transform(&trans,&trans,&m_matPrj);
		trans /= trans.w;

		return Vector3(trans.x,trans.y,trans.z);
	}

	POINT CameraBase::worldToScreen(const Vector3& wpt) const
	{
		Vector3 trans = worldToScreenF(wpt);

		POINT ret;
		ret.x = LONG((trans.x+1.0f)*0.5f*float(m_viewPortW));
		ret.y = LONG(-(trans.y-1.0f)*0.5f*float(m_viewPortH));
		return ret;
	}

	void CameraBase::getViewSizeOnNearPlane(float& halfW,float& halfH) const
	{
		float aspect=(float)m_viewPortW/m_viewPortH;

		halfW=tanf(m_fFov*0.5f)*m_fZNear*aspect;
		halfH=halfW/aspect;
	}

	Vector3 CameraBase::screenToWorld(int screenX, int screenY) const
	{
		float hw,hh;
		getViewSizeOnNearPlane(hw,hh);

		Vector3 r(screenX/(m_viewPortW*0.5f)-1.0f,
			1.0f-screenY/(m_viewPortW*0.5f),m_fZNear);

		r.x*=hw;
		r.y*=hh;
		Vector4 ret;
		D3DXVec3Transform(&ret,&r,&m_matInvView);

		return Vector3(ret.x,ret.y,ret.z);
	}

	void CameraBase::getMouseRay(int cursorX, int cursorY, Ray& out) const
	{
		out.origin = screenToWorld(cursorX,cursorY);
		out.dir = out.origin-m_eyePos;	//从From点出发,指向"鼠标所指向的点"的方向
		D3DXVec3Normalize(&out.dir,&out.dir);

		out.origin += out.dir*m_fZNear;//进行near剪裁
	}
}//namespace MagicGear