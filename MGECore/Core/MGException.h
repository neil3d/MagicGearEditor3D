#pragma once

namespace MagicGear
{
	/**	\class MGException
		\brief a base class for all exception MagicGear software
	*/
	class MGException
	{
	public:
		MGException(const char* szInfo);
		virtual ~MGException(void);

		const char* getInfo() const	{	return m_szInfo.c_str(); }
	
	protected:
		string	m_szInfo;
	};
}//namespace MagicGear