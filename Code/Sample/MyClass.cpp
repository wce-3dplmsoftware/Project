// MyClass.cpp: implementation of the CMyClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Project_Dll.h"
#include "MyClass.h"
#include <Magick++.h>
#include "magick\exception.h"
#include "magick\magick-type.h"
#include <iostream>
//#include "afxdialogex.h"
//#include "Resource.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Magick;
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyClass::CMyClass()
{

}

CMyClass::~CMyClass()
{

}


int CMyClass::getValues()
{
	return obj.choice;
}

int CMyClass::getCType()
{
	return obj.ctype;
}

int CMyClass::getCSize()
{
	return obj.csize;
}

CString CMyClass::getFolder()
{
	return obj.copfolder;
}

void CMyClass::setValues(int a,int b,int c)
{
	obj.choice=a;
	obj.ctype=b;
	obj.csize=c;
	//obj.copfolder=str;
}

int CMyClass :: convertImage(CString ip,CString op,CStringArray *ipImg,CString opfolder,CStringArray *filenames)
{
	InitializeMagick("");

	for(int i=0;i<ipImg->GetCount();i++)
	{
	CT2CA pszConvertedAnsiString (ipImg->GetAt(i));
	std::string str (pszConvertedAnsiString);
	//CT2CA pszConvertedAnsiString21 (filenames->GetAt(i));
	//std::string str21 (pszConvertedAnsiString21);
	// Read GIF file from disk 
	Image image(str);
	// Write to BLOB in JPEG format 
	//CT2CA pszConvertedAnsiString1 ();
	//std::string str1 (pszConvertedAnsiString1);
	//image.magick( str1 ); // Set JPEG output format
	AfxMessageBox(opfolder);
	CString str12;
	str12.Format(_T("%s\\%s.%s"),opfolder,filenames->GetAt(i),op);
	CT2CA pszConvertedAnsiString1 (str12);
	std::string str1 (pszConvertedAnsiString1);
	//image.type( BilevelType );
	//image.compressType(RLECompression);
	image.write(str1);
	}

	//Image img("horse.jpg");
	//img.write("horse.dib");

	return 0;
}
