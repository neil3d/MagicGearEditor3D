#pragma once
#include "HardwareAPI\HDDevice.h"
#include "HardwareAPI\HDResourceMgr.h"

namespace MagicGear
{
	class SceneEditor;

	/**	\class MGRoot
		\brief a singleton contain top level golbal objects
	*/
	class MGRoot
	{
	private:
		MGRoot(void);
		~MGRoot(void);

	public:
		static MGRoot* getInst();

		//!	create device objects
		void createDevice(const tagDeviceCfg& cfg);
		//! create scene editor, device must created first
		void createSceneEditor();
		//! release all objects
		void destroy();

		//!	render
		bool render();

		int getClientWidth()				{	return m_deviceCfg.width; }
		int getClientHeight()				{	return m_deviceCfg.height; }
		HDResourceMgr* getHDResourceMgr()	{	return m_pDevice->getResourceMgr(); }
		SceneEditor* getSceneEditor()		{	return m_pSceneEditor;}

	private:
		void calculateFPS(void);
	private:
		tagDeviceCfg	m_deviceCfg;
		HDDevice		*m_pDevice;
		SceneEditor		*m_pSceneEditor;

		float	m_fps;

	};
}//namespace MagicGear