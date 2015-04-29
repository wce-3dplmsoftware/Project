
// projecTDlg.h : header file
//


#pragma once

#include "C:\Users\Project\Documents\Visual Studio 2010\Projects\Project_Dll\Project_Dll\MyClass.h"
#include "Process.h"
//#include "options.h"

// CprojecTDlg dialog
class CprojecTDlg : public CDialogEx
{
// Construction
public:
	CprojecTDlg(CWnd* pParent = NULL);	// standard constructor
	

// Dialog Data
	enum { IDD = IDD_PROJECT_DIALOG };
	//CString	m_edit;
	CButton *convert;
	CComboBox *ip;
	CComboBox *op;
	CButton *addImage;
	CButton *clearAll;
	CFileDialog *dlg;
	CString filepath;
	CListBox *imageList;
	CEdit *folder_name;
	CString foldername;
	int flag;
	CStringArray *filenames;
	CMyClass objt;
	

	//CProcess object;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton4();
};
