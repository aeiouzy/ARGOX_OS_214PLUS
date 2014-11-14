// VC_6.h : main header file for the VC_6 application
//

#if !defined(AFX_VC_6_H__75F76716_A4DA_42B3_A247_47A840DE057E__INCLUDED_)
#define AFX_VC_6_H__75F76716_A4DA_42B3_A247_47A840DE057E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVC_6App:
// See VC_6.cpp for the implementation of this class
//

class CVC_6App : public CWinApp
{
public:
	CVC_6App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVC_6App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVC_6App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VC_6_H__75F76716_A4DA_42B3_A247_47A840DE057E__INCLUDED_)
