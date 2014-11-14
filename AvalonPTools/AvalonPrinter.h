// AvalonPrinter.h: interface for the CAvalonPrinter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AVALONPRINTER_H__1762D36E_43B4_40F7_8388_487B0B370420__INCLUDED_)
#define AFX_AVALONPRINTER_H__1762D36E_43B4_40F7_8388_487B0B370420__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAvalonPrinter  
{
public:
	int PrintDNA(CString dna);
	CAvalonPrinter();
	virtual ~CAvalonPrinter();

};

#endif // !defined(AFX_AVALONPRINTER_H__1762D36E_43B4_40F7_8388_487B0B370420__INCLUDED_)
