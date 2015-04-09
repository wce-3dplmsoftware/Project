
// sampleDlg.cpp : implementation file

#include "stdafx.h"
#include "sample.h"
#include "sampleDlg.h"
#include "afxdialogex.h"
#include <Magick++.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Magick;
using namespace std;

CString title1[]={L"jpg",L"bmp",L"png",L"wpg",L"cal",L"psd",L"dib",L"sct",L"pcx",L"dcx",L"xpm",L"ras",L"tga"};
CString title[]={L"jpg",L"bmp",L"png",L"wpg",L"cal",L"psd",L"dib",L"pcx",L"dcx",L"xpm",L"ras",L"tga"};


// CAboutDlg dialog used for App About

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


// CsampleDlg dialog
CsampleDlg::CsampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CsampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CsampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CsampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CsampleDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CsampleDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CsampleDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK1, &CsampleDlg::OnBnClickedCheck1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CsampleDlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CsampleDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON3, &CsampleDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CsampleDlg message handlers
BOOL CsampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Add "About..." menu item to system menu.
	name=(CEdit*)GetDlgItem(IDC_EDIT1);
	folder_name=(CEdit*)GetDlgItem(IDC_EDIT2);
	ip=(CComboBox*)GetDlgItem(IDC_COMBO1);
	op=(CComboBox*)GetDlgItem(IDC_COMBO2);
	ckb=GetDlgItem(IDC_CHECK1);
	browse=(CButton*)GetDlgItem(IDC_BUTTON1);
	btn=(CButton*)GetDlgItem(IDC_BUTTON2);
	ok=(CButton*)GetDlgItem(IDOK);
	ok->EnableWindow(false);
	browse->EnableWindow(false);
	btn->EnableWindow(false);
	op->EnableWindow(false);
	ckb->EnableWindow(false);
	flag=false;

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

void CsampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CsampleDlg::OnPaint()
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
HCURSOR CsampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CsampleDlg::OnBnClickedOk()
{	
	InitializeMagick("");

	CT2CA pszConvertedAnsiString (fld);
	std::string str (pszConvertedAnsiString);
	 
	Image image(str);
	
	CT2CA pszConvertedAnsiString1 (foldername+"\\success."+title[op->GetCurSel()]);
	std::string str1 (pszConvertedAnsiString1);
	
	image.write( str1 );
}


void CsampleDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	btn->EnableWindow(true);
	ckb->EnableWindow(true);
	dlg = new CFileDialog(TRUE, L"", NULL, NULL,L"Image Files (*."+title1[ip->GetCurSel()]+")|*."+title1[ip->GetCurSel()]+"|");
	dlg->m_ofn.lpstrTitle = L"Select an Input Image";
	dlg->DoModal();
	fld=dlg->GetPathName();
	name->SetWindowText(fld);
	
}


void CsampleDlg::OnBnClickedButton2()
{
	//Browse and Select Output folder
	CFolderPickerDialog *fldr=new CFolderPickerDialog();
	fldr->DoModal();
	foldername=fldr->GetFolderPath();
	folder_name->SetWindowText(foldername);
	ok->EnableWindow(true);
	flag=true;
}


void CsampleDlg::OnBnClickedCheck1()
{
	 
	 if(btn->IsWindowVisible())
	 {
		 btn->ShowWindow(SW_HIDE);
		 folder_name->ShowWindow(SW_HIDE);
		 ok->EnableWindow(true);
	 }
	 else
	 {
		btn->ShowWindow(SW_SHOW);
		folder_name->ShowWindow(SW_SHOW);
		folder_name->SetWindowText(foldername);
		if(flag==false)
			ok->EnableWindow(false);
		else
			ok->EnableWindow(true);
	 }
}

void CsampleDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	op->EnableWindow(true);
}


void CsampleDlg::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
	browse->EnableWindow(true);
}

void CsampleDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
Image image("test.jpg");
int w = image.columns();
int h = image.rows();

//pixel cache for the entire image
PixelPacket *pixels = image.getPixels(0, 0, w, h);

//access single pixels like a vector
int row = 0;
int column = 0;
Color color = pixels[w * row + column];


//pixels[0] = Color(255, 0, 0);
//pixels[200] = Color(255, 0, 0);
//pixels[159990] = Color(255, 0, 0);
image.syncPixels();

for(row=5; row<10; row++){
  for(column=4; column<6; column++){
    Color color = pixels[w * row + column];
	int a=color.redQuantum()/255;
	int b=color.greenQuantum()/255;
	int c=color.blueQuantum()/255;
	CString t;
	t.Format(_T("%d,%d,%d"), a,b,c);
	AfxMessageBox(t);
	//MessageBox(L""+a,L"Image");
    }
}
Pixels view(image);
*(view.get(1,1,1,1))=Color("white");
view.sync();

image.write("test_modified.jpg");
}
