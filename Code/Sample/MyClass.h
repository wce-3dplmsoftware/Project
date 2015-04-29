// MyClass.h: interface for the CMyClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCLASS_H__1FAFEE60_88D6_11D6_89D7_00010302158B__INCLUDED_)
#define AFX_MYCLASS_H__1FAFEE60_88D6_11D6_89D7_00010302158B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyClass  
{
public:
	__declspec(dllexport) int CMyClass::getValues();
	__declspec(dllexport) int CMyClass::getCType();
	__declspec(dllexport) int CMyClass::getCSize();
	__declspec(dllexport) void CMyClass::setValues(int a,int b,int c);
	__declspec(dllexport) CString CMyClass::getFolder();
	__declspec(dllexport) int CMyClass :: convertImage(CString ip,CString op,CStringArray *ipImg,CString folder,CStringArray *filenames);
	__declspec(dllexport) CMyClass();
	__declspec(dllexport) virtual ~CMyClass();
	struct getval{
		int choice;
		int ctype;
		int csize;
		CString copfolder;
	}obj;

};

#endif // !defined(AFX_MYCLASS_H__1FAFEE60_88D6_11D6_89D7_00010302158B__INCLUDED_)
