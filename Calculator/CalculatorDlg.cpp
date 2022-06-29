
// CalculatorDlg.cpp: 实现文件
//
#include "pch.h"
#include "Compiler.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CALCULATOR, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_DEC, m_CStaticInputString);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	//////////////////////////////////////////////////////////////////////////
	//Digital Button
	ON_BN_CLICKED(IDC_BUTTON_NUM0, &CCalculatorDlg::OnBnClickedButtonNum0)
	ON_BN_CLICKED(IDC_BUTTON_NUM1, &CCalculatorDlg::OnBnClickedButtonNum1)
	ON_BN_CLICKED(IDC_BUTTON_NUM2, &CCalculatorDlg::OnBnClickedButtonNum2)
	ON_BN_CLICKED(IDC_BUTTON_NUM3, &CCalculatorDlg::OnBnClickedButtonNum3)
	ON_BN_CLICKED(IDC_BUTTON_NUM4, &CCalculatorDlg::OnBnClickedButtonNum4)
	ON_BN_CLICKED(IDC_BUTTON_NUM5, &CCalculatorDlg::OnBnClickedButtonNum5)
	ON_BN_CLICKED(IDC_BUTTON_NUM6, &CCalculatorDlg::OnBnClickedButtonNum6)
	ON_BN_CLICKED(IDC_BUTTON_NUM7, &CCalculatorDlg::OnBnClickedButtonNum7)
	ON_BN_CLICKED(IDC_BUTTON_NUM8, &CCalculatorDlg::OnBnClickedButtonNum8)
	ON_BN_CLICKED(IDC_BUTTON_NUM9, &CCalculatorDlg::OnBnClickedButtonNum9)
	ON_BN_CLICKED(IDC_BUTTON_LEFTBRACKET, &CCalculatorDlg::OnBnClickedButtonLeftBracket)
	ON_BN_CLICKED(IDC_BUTTON_RIGHTBRACKET, &CCalculatorDlg::OnBnClickedButtonRightBracket)
	//Operator Button
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLE, &CCalculatorDlg::OnBnClickedButtonMultiple)
	ON_BN_CLICKED(IDC_BUTTON_SUBSTRACT, &CCalculatorDlg::OnBnClickedButtonSubstract)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CCalculatorDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CCalculatorDlg::OnBnClickedButtonEqual)
	//Other
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CCalculatorDlg::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalculatorDlg::OnBnClickedButtonClear)

END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//////////////////////////////////////////////////////////////////////////
//Button Message Deal
void CCalculatorDlg::OnBnClickedButtonEqual()
{
	//ToCompile
	if (!m_InputString.GetLength())
	{
		MessageBox(_T("Please input a expression!"), _T("Tips"), 0);
	}
	else
	{
		Compiler compiler =  Compiler(m_InputString);
	}
}

void CCalculatorDlg::OnBnClickedButtonBack()
{
	if (m_InputString.GetLength() == 0) return;
	m_InputString.Delete(m_InputString.GetLength() - 1, 1);
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonClear()
{
	m_InputString = _T("");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonNum0()
{
	m_InputString += _T("0");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonNum1()
{
	m_InputString += _T("1");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonNum2()
{
	m_InputString += _T("2");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonNum3()
{
	m_InputString += _T("3");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonNum4()
{
	m_InputString += _T("4");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonNum5()
{
	m_InputString += _T("5");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonNum6()
{
	m_InputString += _T("6");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonNum7()
{
	m_InputString += _T("7");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonNum8()
{
	m_InputString += _T("8");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonNum9()
{
	m_InputString += _T("9");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonLeftBracket()
{
	m_InputString += _T("(");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonRightBracket()
{
	m_InputString += _T(")");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonDot()
{
	m_InputString += _T(".");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonDivide()
{
	m_InputString += _T("/");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonMultiple()
{
	m_InputString += _T("*");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonSubstract()
{
	m_InputString += _T("-");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}

void CCalculatorDlg::OnBnClickedButtonAdd()
{
	m_InputString += _T("+");
	m_CStaticInputString.SetWindowTextW(m_InputString);
}


