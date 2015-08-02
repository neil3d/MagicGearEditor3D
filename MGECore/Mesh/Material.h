#pragma once
#include "..\HardwareAPI\HDResource.h"
#include "..\HardwareAPI\HDResourceMgr.h"

namespace MagicGear
{
	class Material
	{
	public:
		Material(void)	
		{
			m_pEffect = NULL;
		}
		virtual ~Material(void)
		{
			ASSERT(m_pEffect == NULL);
		}

		void loadFXFile(const char* szPath, HDResourceMgr* pResMgr)
		{
			destroy(pResMgr);
			
			//--
			m_pEffect = pResMgr->createEffect();
			m_pEffect->loadFromFile(szPath, pResMgr);
		}

		void destroy(HDResourceMgr* pResMgr)
		{
			if(m_pEffect)
			{
				pResMgr->destroyEffect(m_pEffect);
				m_pEffect = NULL;
			}
		}

		HDEffect* getEffect()	{	return m_pEffect; }
	protected:
		HDEffect	*m_pEffect;
	};
}//namespace MagicGear