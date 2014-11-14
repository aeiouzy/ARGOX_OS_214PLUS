// VC_6Dlg.h : header file
//

#if !defined(AFX_VC_6DLG_H__6016FCDA_9E23_4EDF_9931_EA7EA176ED58__INCLUDED_)
#define AFX_VC_6DLG_H__6016FCDA_9E23_4EDF_9931_EA7EA176ED58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVC_6Dlg dialog

class CVC_6Dlg : public CDialog
{
// Construction
public:
	CVC_6Dlg(CWnd* pParent = NULL);	// standard constructor
	~CVC_6Dlg();

// Dialog Data
	//{{AFX_DATA(CVC_6Dlg)
	enum { IDD = IDD_VC_6_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVC_6Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVC_6Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VC_6DLG_H__6016FCDA_9E23_4EDF_9931_EA7EA176ED58__INCLUDED_)
