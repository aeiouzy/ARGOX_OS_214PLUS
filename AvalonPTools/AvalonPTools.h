// AvalonPTools.h : main header file for the AVALONPTOOLS application
//

#if !defined(AFX_AVALONPTOOLS_H__AD8C44E0_5339_40C7_B4EE_479B54A9E4A3__INCLUDED_)
#define AFX_AVALONPTOOLS_H__AD8C44E0_5339_40C7_B4EE_479B54A9E4A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAvalonPToolsApp:
// See AvalonPTools.cpp for the implementation of this class
//

class CAvalonPToolsApp : public CWinApp
{
public:
	CAvalonPToolsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAvalonPToolsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAvalonPToolsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVALONPTOOLS_H__AD8C44E0_5339_40C7_B4EE_479B54A9E4A3__INCLUDED_)
