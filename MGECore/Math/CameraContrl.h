#pragma once
#include "CameraBase.h"
namespace MagicGear
{
	class CameraContrl
	{
	public:
		CameraContrl(void)	
		{
			m_moveSpeed = 4096;
			m_zoomSpeed = 0.5f;
		}
		virtual ~CameraContrl(void)	{}

		virtual void onKeyDown(DWORD vk)	{}
		virtual void onLButtonDown(float x, float y)	{}
		virtual void onLButtonUp(void)	{}
		virtual void onRButtonDown(float x, float y)	{}
		virtual void onRButtonUp(void)	{}
		virtual void onMouseMove(float x, float y)	{}
		virtual void onMouseWheel(int delta)	{}

		void setMoveSpeed(float s)
		{
			m_moveSpeed = s;
		}
		void setZoomSpeed(float s)
		{
			m_zoomSpeed = s;
		}

	public:
		float		m_moveSpeed;
		float		m_zoomSpeed;
		CameraBase	m_camera;
	};
}//namespace MagicGear