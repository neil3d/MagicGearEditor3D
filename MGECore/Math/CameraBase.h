#pragma once
#include "MathBaseDef.h"
#include "Ray.h"

namespace MagicGear
{
	class CameraBase
	{
	public:
		CameraBase(void);
		virtual ~CameraBase(void);

		// basic
		void setPerspective(float fov, int viewPortW, int viewPortH, float znear, float zFar)
		{
			m_viewPortW = viewPortW;
			m_viewPortH = viewPortH;

			float aspect = float(viewPortW)/viewPortH;
			D3DXMatrixPerspectiveFovLH(&m_matPrj, fov, aspect, znear, zFar);
			D3DXMatrixInverse(&m_matInvPrj,NULL,&m_matPrj);

			m_fFov = fov;
			m_fZNear = znear;
			m_fZFar = zFar;
		}

		void setViewLookAt(const Vector3& eyePos, const Vector3& lookAt, const Vector3& up)
		{
			D3DXMatrixLookAtLH(&m_matView, &eyePos, &lookAt, &up);
			D3DXMatrixInverse(&m_matInvView,NULL,&m_matView);

			m_eyePos = eyePos;
		}

		int getViewPortWidth()			{	return m_viewPortW;}
		int getViewPortHeight()			{	return m_viewPortH;}
		const Matrix4& getProject()		{	return m_matPrj;}
		const Matrix4& getView()		{	return m_matView;}

		// transform
		Vector2 normalizeScreen(int x, int y);
		POINT	worldToScreen(const Vector3& wpt) const;
		Vector3	worldToScreenF(const Vector3& wpt) const;
		Vector3 screenToWorld(int screenX, int screenY) const;
		void getMouseRay(int cursorX, int cursorY, Ray& out) const;

	protected:
		void getViewSizeOnNearPlane(float& halfW,float& halfH) const;
	private:
		Matrix4 m_matPrj;
		Matrix4 m_matInvPrj;
		Matrix4 m_matView;
		Matrix4	m_matInvView;

		float	m_fFov;
		float	m_fZNear;
		float	m_fZFar;

		int		m_viewPortW,
				m_viewPortH;

		Vector3	m_eyePos;
	};
}//namespace MagicGear