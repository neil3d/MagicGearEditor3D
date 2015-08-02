#include "StdAfx.h"
#include ".\logger.h"

namespace MagicGear
{
	Logger	g_logger;
	const char* const _LOG_FILE_FULL_PATH = "log.txt";

	Logger::Logger(void)
	{
		char szMdlName[512] = {0};
		::GetModuleFileName(NULL,szMdlName,sizeof(szMdlName));
		char szDate[128] = {0};
		_strdate(szDate);
		char szTime[128] = {0};
		_strtime(szTime);

		//clear file
		FILE *fp=fopen(_LOG_FILE_FULL_PATH,"wt");
		if(fp)
			fclose(fp);

		//
		writeLog("[%s log begin at %s,%s]\r\n\r\n", szMdlName, szDate, szTime);
	}

	Logger::~Logger(void)
	{
		char szDate[128] = {0};
		_strdate(szDate);
		char szTime[128] = {0};
		_strtime(szTime);

		writeLog("[log end at %s,%s]\r\n", szDate, szTime);
	}

	void Logger::writeLog(const char* szFmt, ... )
	{
		static char buf[4096] = {0};
		va_list argptr;
		
		va_start(argptr, szFmt);
		vsprintf(buf, szFmt, argptr);
		va_end(argptr);
		
		FILE *fp=fopen(_LOG_FILE_FULL_PATH,"at");
		if(fp)
		{
			// write source info
			if(!m_szFile.empty())
			{
				fprintf(fp, "%s : %d ", m_szFile.c_str(), m_line);
				m_szFile.clear();
			}
			if(!m_szFunction.empty())
			{
				fprintf(fp, "( %s ) ", m_szFunction.c_str());
				m_szFunction.clear();
			}

			// write log txt
			fprintf(fp,buf);
			fclose(fp);
		}
	}
}//namespace MagicGear