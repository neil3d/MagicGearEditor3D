#include "StdAfx.h"
#include "CameraDefaultCtrl.h"

namespace MagicGear
{
	CameraDefaultCtrl::CameraDefaultCtrl(void) 
		: m_lookAt(0,0,0), m_lastDragPt(0,0)
	{
		m_dist = 500;
		m_yaw = 0;
		m_pitch = _DegToRad(45);
		m_roll = 0;

		m_bLeftDrag = m_bRightDrag = false;
	}

	CameraDefaultCtrl::~CameraDefaultCtrl(void)
	{
	}

	void CameraDefaultCtrl::updateViewMat()
	{
		D3DXMATRIX matR;
		D3DXMatrixRotationYawPitchRoll(&matR, m_yaw, m_pitch, m_roll);

		Vector3 vViewDir = Vector3(0,0,1);
		Vector3 vUp(0,1,0);

		vViewDir = vViewDir * matR;
		vUp = vUp * matR;

		m_eyePos = vViewDir*m_dist + m_lookAt;

		m_camera.setViewLookAt(m_eyePos, m_lookAt, vUp);
	}

	void CameraDefaultCtrl::onKeyDown(DWORD vk)
	{}

	void CameraDefaultCtrl::onLButtonDown(float x, float y)
	{
		m_bLeftDrag = true;
		m_lastDragPt.x = x;
		m_lastDragPt.y = y;
	}

	void CameraDefaultCtrl::onLButtonUp(void)
	{
		m_bLeftDrag = false;
	}

	void  CameraDefaultCtrl::onRButtonDown(float x, float y)
	{
		m_bRightDrag = true;
		m_lastDragPt.x = x;
		m_lastDragPt.y = y;
	}

	void  CameraDefaultCtrl::onRButtonUp(void)
	{
		m_bRightDrag = false;
	}

	void CameraDefaultCtrl::onMouseMove(float x, float y)
	{
		if(m_bLeftDrag)
		{
			Vector2 nowPt(x,y);
			Vector2 delta = nowPt - m_lastDragPt;

			m_yaw += delta.x*2;
			m_pitch += delta.y*2;

			updateViewMat();

			m_lastDragPt.x = x;
			m_lastDragPt.y = y;
		}
		else if(m_bRightDrag)
		{
			Vector3 vX(1, 0, 0);
			Vector3 vZ(0, 0, 1);

			Vector2 nowPt(x,y);
			Vector2 delta = nowPt - m_lastDragPt;


			delta *= m_moveSpeed;
			m_lookAt -= vX*delta.x;
			m_lookAt -= vZ*delta.y;

			updateViewMat();

			m_lastDragPt = nowPt;
		}
	}

	void CameraDefaultCtrl::onMouseWheel(int delta)
	{
		m_dist += delta*m_zoomSpeed;

		updateViewMat();
	}
}//namespace MagicGear