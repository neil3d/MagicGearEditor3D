#pragma once
#include "cameracontrl.h"

namespace MagicGear
{
	class CameraTrackBallCtrl : public CameraContrl
	{
	public:
		CameraTrackBallCtrl(void);
		virtual ~CameraTrackBallCtrl(void);

		virtual void onKeyDown(DWORD vk);
		virtual void onLButtonDown(float x, float y);
		virtual void onLButtonUp(void);
		virtual void onMouseMove(float x, float y);
		virtual void onMouseWheel(int delta);

		void setParam(const Vector3& lookAt, float dist, float yaw, float pitch, float roll)
		{
			m_lookAt = lookAt;
			m_dist = dist;
			D3DXQuaternionRotationYawPitchRoll(&m_rotate,yaw,pitch,roll);

			updateViewMat();
		}
	private:
		void updateViewMat();

	private:
		Vector3		m_eyePos;
		Vector3		m_lookAt;
		float		m_dist;
		Quaternion	m_rotate;
		Quaternion	m_lastRotate;

		//--
		bool		m_bDrag;
		Vector2		m_lastDragPt;
	};
}//namespace MagicGear