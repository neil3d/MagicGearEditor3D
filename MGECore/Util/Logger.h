#pragma once

namespace MagicGear
{
#define LOG g_logger.setSourceInfo(__FILE__, __LINE__, __FUNCTION__);g_logger.writeLog

	class Logger
	{
	public:
		Logger(void);
		~Logger(void);

		void setSourceInfo(const char* szFile, int line, const char* szFunction)
		{
			m_szFile = szFile;
			m_line = line;
			m_szFunction = szFunction;
		}

		void writeLog(const char* szFmt, ... );

	private:
		string	m_szFile;
		int		m_line;
		string	m_szFunction;
	};

	extern Logger	g_logger;
}//namespace MagicGear