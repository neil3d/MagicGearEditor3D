#pragma once

#include <string>
using namespace std;

namespace MagicGear
{
	class Filename : public string
	{
	public:
		Filename(void)                                         { }
		Filename(const char* pFilename) : string(pFilename)    { }
		Filename(std::string strFilename) :string(strFilename) { }

		Filename getExtension(void);      // if filename is "/idv/code/file.cpp", it returns "cpp"
		Filename getPath(void);           // if filename is "/idv/code/file.cpp", it returns "/idv/code"
		Filename noExtension(void);       // if filename is "/idv/code/file.cpp", it returns "/idv/code/file"
		Filename noPath(void);            // if filename is "/idv/code/file.cpp", it returns "file.cpp"
	};


	///////////////////////////////////////////////////////////////////////  
	//  Filename::getExtension

	inline Filename Filename::getExtension(void)
	{
		string strExtension;

		int nLength = (int)length( );
		for (int i = nLength - 1; i > 0 && (*this)[i] != '/'; i--)
		{
			if ((*this)[i] == '.')
			{
				strExtension = string(c_str( ) + i + 1);
				break;
			}
		}

		return strExtension;
	}


	///////////////////////////////////////////////////////////////////////  
	//  Filename::getPath

	inline Filename Filename::getPath(void)
	{
		char szPath[1024];

		szPath[0] = '\0';
		int nLength = (int)length( );
		for (int i = nLength - 1; i >= 0; i--)
		{
			if ((*this)[i] == '/' ||
				(*this)[i] == '\\')
			{
				for (int j = 0; j < i + 1; j++)
					szPath[j] = (*this)[j];
				szPath[j] = '\0';
				break;
			}
		}

		return Filename(szPath);
	}


	///////////////////////////////////////////////////////////////////////  
	//  Filename::noExtension

	inline Filename Filename::noExtension(void)
	{
		char szExtension[1024];

		strcpy(szExtension, c_str( ));
		int nLength = (int)length( );
		for (int i = nLength - 1; i >= 0 && (*this)[i] != '/'; i--)
		{
			if ((*this)[i] == '.')
			{
				for (int j = 0; j < i; j++)
					szExtension[j] = (*this)[j];
				szExtension[j] = '\0';
				break;
			}
		}

		return szExtension;
	}


	///////////////////////////////////////////////////////////////////////  
	//  Filename::noPath

	inline Filename Filename::noPath(void)
	{
		char szPath[1024];

		strcpy(szPath, c_str( ));
		int nLength = (int)length( );
		for (int i = nLength - 1; i >= 0; i--)
		{
			if ((*this)[i] == '/' || (*this)[i] == '\\')
			{
				for (int j = i + 1, k = 0; j < nLength; j++, k++)
					szPath[k] = (*this)[j];
				szPath[k] = '\0';
				break;
			}
		}

		return string(szPath);
	}
}//namespace MagicGear