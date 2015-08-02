#pragma once
#include "CameraContrl.h"

namespace MagicGear
{
	class CameraDefaultCtrl : public CameraContrl
	{
	public:
		CameraDefaultCtrl(void);
		~CameraDefaultCtrl(void);

		virtual void onKeyDown(DWORD vk);
		virtual void onLButtonDown(float x, float y);
		virtual void onLButtonUp(void);
		virtual void onRButtonDown(float x, float y);
		virtual void onRButtonUp(void);
		virtual void onMouseMove(float x, float y);
		virtual void onMouseWheel(int delta);

		void setParam(const Vector3& lookAt, float dist, float yaw, float pitch, float roll)
		{
			m_lookAt = lookAt;
			m_dist = dist;
			m_yaw = yaw;
			m_pitch = pitch;
			m_roll = roll;

			updateViewMat();
		}
	private:
		void updateViewMat();

	private:
		Vector3		m_eyePos;
		Vector3		m_lookAt;
		float		m_dist;
		float		m_yaw;
		float		m_pitch;
		float		m_roll;

		bool		m_bLeftDrag;
		bool		m_bRightDrag;
		Vector2		m_lastDragPt;
	};
}//namespace MagicGear