#include "StdAfx.h"
#include "CameraTrackBallCtrl.h"
#include "SGITrackBall.h"
#include "..\MGRoot.h"

namespace MagicGear
{
	CameraTrackBallCtrl::CameraTrackBallCtrl(void)
	{
		m_lookAt = Vector3(0,0,0);
		m_dist = 400;
		D3DXQuaternionRotationYawPitchRoll(&m_rotate,0,0,0);
	}

	CameraTrackBallCtrl::~CameraTrackBallCtrl(void)
	{
	}

	void CameraTrackBallCtrl::updateViewMat()
	{
		D3DXMATRIX matR;
		D3DXMatrixRotationQuaternion(&matR,&m_rotate);

		Vector3 vViewDir = Vector3(0,0,1);
		Vector3 vUp(0,1,0);

		vViewDir = vViewDir * matR;
		vUp = vUp * matR;

		m_eyePos = vViewDir*m_dist + m_lookAt;

		m_camera.setViewLookAt(m_eyePos, m_lookAt, vUp);
	}


	void CameraTrackBallCtrl::onKeyDown(DWORD vk)
	{
		const Matrix4& matView = m_camera.getView();
		Vector3 vX(matView._11,matView._21,matView._31);
		Vector3 vY(matView._12,matView._22,matView._32);
		Vector3 vZ(matView._13,matView._23,matView._33);

		float s = m_moveSpeed;
		switch(vk)
		{
		case 'W':
			m_lookAt += vZ*s;
			break;
		case 'S':
			m_lookAt -= vZ*s;
			break;
		case 'A':
			m_lookAt += vX*s;
			break;
		case 'D':
			m_lookAt -= vX*s;
			break;
		case 'Z':
			m_lookAt += vY*s;
			break;
		case 'X':
			m_lookAt -= vY*s;
			break;
		default:
			break;
		}

		updateViewMat();
	}

	void CameraTrackBallCtrl::onLButtonDown(float x,float y)
	{
		m_bDrag = true;
		m_lastDragPt.x = x;
		m_lastDragPt.y = y;

		trackball((float*)m_lastRotate,0,0,0,0);
	}

	void CameraTrackBallCtrl::onLButtonUp(void)
	{
		m_bDrag = false;
	}

	void CameraTrackBallCtrl::onMouseMove(float x,float y)
	{
		if(m_bDrag)
		{
			Vector2 lastPt = m_lastDragPt;
			Vector2 nowPt(x, y);

			trackball((float*)&m_lastRotate,lastPt.x,lastPt.y,nowPt.x,nowPt.y);

			m_lastDragPt.x = x;
			m_lastDragPt.y = y;

			add_quats((float*)&m_lastRotate,(float*)&m_rotate,(float*)&m_rotate);

			updateViewMat();
		}
	}

	void CameraTrackBallCtrl::onMouseWheel(int delta)
	{
		m_dist += delta*m_zoomSpeed;

		updateViewMat();
	}
}//namespace MagicGear