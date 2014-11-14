// AvalonPToolsDlg.h : header file
//

#if !defined(AFX_AVALONPTOOLSDLG_H__497AF468_3F7E_4957_B263_8EF9269C0B32__INCLUDED_)
#define AFX_AVALONPTOOLSDLG_H__497AF468_3F7E_4957_B263_8EF9269C0B32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAvalonPToolsDlg dialog

class CAvalonPToolsDlg : public CDialog
{
// Construction
public:
	CAvalonPToolsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAvalonPToolsDlg)
	enum { IDD = IDD_AVALONPTOOLS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAvalonPToolsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAvalonPToolsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPrint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVALONPTOOLSDLG_H__497AF468_3F7E_4957_B263_8EF9269C0B32__INCLUDED_)
