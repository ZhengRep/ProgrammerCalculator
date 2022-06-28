
// CalculatorDlg.h: 头文件
//

#pragma once


// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CALCULATOR };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////
public:
	//Number
	afx_msg void OnBnClickedButtonNum0();
	afx_msg void OnBnClickedButtonNum1();
	afx_msg void OnBnClickedButtonNum2();
	afx_msg void OnBnClickedButtonNum3();
	afx_msg void OnBnClickedButtonNum4();
	afx_msg void OnBnClickedButtonNum5();
	afx_msg void OnBnClickedButtonNum6();
	afx_msg void OnBnClickedButtonNum7();
	afx_msg void OnBnClickedButtonNum8();
	afx_msg void OnBnClickedButtonNum9();
	afx_msg void OnBnClickedButtonLeftBracket();
	afx_msg void OnBnClickedButtonRightBracket();
	afx_msg void OnBnClickedButtonDot();
	//Operator
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonMultiple();
	afx_msg void OnBnClickedButtonSubstract();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonEqual();
	//Other
	afx_msg void OnBnClickedButtonBack();
	afx_msg void OnBnClickedButtonClear();



	CStatic				m_CStaticInputString;
	CString				m_InputString;
};
