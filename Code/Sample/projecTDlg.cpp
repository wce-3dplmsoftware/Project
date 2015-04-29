
// projecTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "projecT.h"
#include "projecTDlg.h"
#include "afxdialogex.h"
#include "SecondDialog.h"
#include "Process.h"
#include "Shlwapi.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About


CString ipformat[]={L"jpg",L"bmp",L"png",L"wpg",L"cal",L"psd",L"dib",L"sct",L"pcx",L"dcx",L"xpm",L"ras",L"tga"};
CString opformat[]={L"jpg",L"bmp",L"png",L"psd",L"dib",L"pcx",L"dcx",L"xpm",L"ras",L"tga"};


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CprojecTDlg dialog




CprojecTDlg::CprojecTDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CprojecTDlg::IDD, pParent)
{
	//m_edit = _T("");
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CprojecTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(CprojecTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CprojecTDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &CprojecTDlg::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CprojecTDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CprojecTDlg::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CprojecTDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON1, &CprojecTDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &CprojecTDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON4, &CprojecTDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CprojecTDlg message handlers

BOOL CprojecTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.
	convert=(CButton*)GetDlgItem(IDC_BUTTON1);
	convert->EnableWindow(FALSE);
	ip=(CComboBox*)GetDlgItem(IDC_COMBO1);
	op=(CComboBox*)GetDlgItem(IDC_COMBO2);
	//op->EnableWindow(FALSE);
	addImage=(CButton*)GetDlgItem(IDC_BUTTON2);
	clearAll=(CButton*)GetDlgItem(IDC_BUTTON3);
	//addImage->EnableWindow(FALSE);
	//clearAll->EnableWindow(FALSE);
	imageList=(CListBox*)GetDlgItem(IDC_LIST1);
	folder_name=(CEdit*)GetDlgItem(IDC_EDIT1);
	folder_name->EnableWindow(FALSE);
	flag=0;
	CStringArray m_SelectedItemList;
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CprojecTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CprojecTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CprojecTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CprojecTDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	// CDialogEx::OnOK();
	CSecondDialog Dlg;

	Dlg.DoModal();

}


void CprojecTDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	 imageList->ResetContent();
	
}


void CprojecTDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	imageList->ResetContent();
	//op->EnableWindow(TRUE);
}


void CprojecTDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	dlg = new CFileDialog(TRUE, L"", NULL, NULL,L"Image Files (*."+ipformat[ip->GetCurSel()]+")|*."+ipformat[ip->GetCurSel()]+"|");
	dlg->m_ofn.lpstrTitle = L"Select an Input Image";
	//dlg->ModifyStyle(OFN_ALLOWMULTISELECT,0);
	
	dlg->GetOFN().Flags |= OFN_ALLOWMULTISELECT;
	//dlg->DoModal();
	
	
   if(dlg->DoModal()==IDOK)
   {
	 
      // get selected files
      POSITION pos = dlg->GetStartPosition();
      while(pos != NULL)
      {
         CString strFilePath = dlg->GetNextPathName(pos);
		 imageList->AddString(strFilePath);
         // ... do something with strFilePath.
      }
   }

	
	flag++;

	if(flag>=2)
		convert->EnableWindow(TRUE);
	//clearAll->EnableWindow(TRUE);
	
}



void CprojecTDlg::OnCbnSelchangeCombo2()
{
	//addImage->EnableWindow(TRUE);
	// TODO: Add your control notification handler code here
}


void CprojecTDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	//CProcess dlg;
	//dlg.DoModal();
	//Sleep(2000);
	//EndDialog(IDOK);
	//object.close->EnableWindow(TRUE);
	// int n;
	CString str;
	CString temp;
	//CString temp;
	CStringArray *ipImages;
	ipImages=new CStringArray[imageList->GetCount()];
	filenames=new CStringArray[imageList->GetCount()];
	for(int i=0;i<imageList->GetCount();i++)
	{
		str.GetBuffer(imageList->GetTextLen(i));
		imageList->GetText(i,str);
		imageList->GetText(i,temp);
		ipImages->Add(str);
		temp=temp.Mid(temp.ReverseFind('\\')+1);
		temp=temp.Left(temp.ReverseFind('.'));
		//temp=str.Right(str.ReverseFind('\\')+1);
		//AfxMessageBox(temp);
		//temp=temp.Left(str.ReverseFind('.'));
		//AfxMessageBox(temp);
		//temp=str.Mid(str.Find('.'));
		//temp=PathRemoveExtension(temp);
		//CString FileName = PathFindFileName( str ); 
		//AfxMessageBox(temp);
		filenames->Add(temp);
		str.ReleaseBuffer();
	}
	// AfxMessageBox(ipImages->GetAt(0));
	GetDlgItemText(IDC_EDIT1,foldername);
	
//	CString folder=objt.getFolder();
	CString ipf=ipformat[ip->GetCurSel()];
	CString opf=opformat[op->GetCurSel()];

	int i=1;
	i=objt.convertImage(ipf,opf,ipImages,foldername,filenames);
	//AfxMessageBox(folder);
	if(i==0)
		AfxMessageBox(L"Successful...!");
}


void CprojecTDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}

void CprojecTDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	CFolderPickerDialog *fldr=new CFolderPickerDialog();
	fldr->DoModal();
	foldername=fldr->GetFolderPath();
	folder_name->SetWindowText(foldername);


	flag++;
	if(flag>=2)
		convert->EnableWindow(FALSE);
	
}
