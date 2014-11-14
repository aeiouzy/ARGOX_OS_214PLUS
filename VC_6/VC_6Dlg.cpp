// VC_6Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "VC_6.h"
#include "VC_6Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const char szSavePath[] = "C:\\Argox";
const char szSaveFile[] = "C:\\Argox\\PPLA_Example.Prn";
const char sznop1[]     = "nop_front\r\n";
const char sznop2[]     = "nop_middle\r\n";
// PPLADLL Function Declaration start
HINSTANCE hPPLA;
typedef int   (_stdcall *pfnA_Bar2d_Maxi)(int x, int y, int primary, int secondary, int country,
						 int service, char mode, int numeric, LPCTSTR data);
typedef int   (_stdcall *pfnA_Bar2d_Maxi_Ori)(int x, int y, int ori, int primary, int secondary,
						 int country, int service, char mode, int numeric, LPCTSTR data);
typedef int   (_stdcall *pfnA_Bar2d_PDF417)(int x, int y, int narrow, int width, char normal,
						 int security, int aspect, int row, int column, char mode, int numeric,
						 LPCTSTR data);
typedef int   (_stdcall *pfnA_Bar2d_PDF417_Ori)(int x, int y, int ori, int narrow, int width,
						 char normal, int security, int aspect, int row, int column, char mode,
						 int numeric, LPCTSTR data);
typedef int   (_stdcall *pfnA_Bar2d_DataMatrix)(int x, int y, int rotation, int hor_mul,
						 int ver_mul, int ECC, int data_format, int num_rows, int num_col,
						 char mode, int numeric, LPCTSTR data);
typedef void  (_stdcall *pfnA_Clear_Memory)(void);
typedef void  (_stdcall *pfnA_ClosePrn)(void);
typedef int   (_stdcall *pfnA_CreatePrn)(int selection, LPCTSTR filename);
typedef int   (_stdcall *pfnA_Del_Graphic)(int mem_mode, char graphic[10]);
typedef int   (_stdcall *pfnA_Draw_Box)(char mode, int x, int y, int width, int height, int top,
						 int side);
typedef int   (_stdcall *pfnA_Draw_Line)(char mode, int x, int y, int width, int height);
typedef void  (_stdcall *pfnA_Feed_Label)(void);
typedef char* (_stdcall *pfnA_Get_DLL_Version)(int nShowMessage);
typedef int   (_stdcall *pfnA_Get_DLL_VersionA)(int nShowMessage);
typedef int   (_stdcall *pfnA_Get_Graphic)(int x, int y, int mem_mode, char format, LPCTSTR filename);
typedef int   (_stdcall *pfnA_Get_Graphic_ColorBMP)(int x, int y, int mem_mode, char format,
						 LPCTSTR filename);
typedef int   (_stdcall *pfnA_Get_Graphic_ColorBMPEx)(int x, int y, int nWidth, int nHeight,
						 int rotate, int mem_mode,char format, LPCTSTR id_name, LPCTSTR filename);
typedef int   (_stdcall *pfnA_Get_Graphic_ColorBMP_HBitmap)(int x, int y, int nWidth, int nHeight,
						 int rotate, int mem_mode,char format, LPCTSTR id_name, HBITMAP hbm);
typedef int   (_stdcall *pfnA_Initial_Setting)(int Type, LPCTSTR Source);
typedef int   (_stdcall *pfnA_WriteData)(int IsImmediate, LPCTSTR pbuf, DWORD length);
typedef int   (_stdcall *pfnA_ReadData)(LPTSTR pbuf, DWORD length, DWORD dwTimeoutms);
typedef int   (_stdcall *pfnA_Load_Graphic)(int x, int y, char graphic_name[10]);
typedef int   (_stdcall *pfnA_Open_ChineseFont)(char* path);
typedef int   (_stdcall *pfnA_Print_Form)(int width, int height, int copies, int amount,
						 LPTSTR form_name);
typedef int   (_stdcall *pfnA_Print_Out)(int width, int height, int copies, int amount);
typedef int   (_stdcall *pfnA_Prn_Barcode)(int x, int y, int ori, char type, int narrow, int width,
						 int height, char mode, int numeric, LPTSTR data);
typedef int   (_stdcall *pfnA_Prn_Text)(int x, int y, int ori, int font, int type, int hor_factor,
						 int ver_factor, char mode, int numeric, LPCTSTR data);
typedef int   (_stdcall *pfnA_Prn_Text_Chinese)(int x, int y, int fonttype, LPCTSTR id_name,
						 LPCTSTR data, int mem_mode);
typedef int   (_stdcall *pfnA_Prn_Text_TrueType)(int x, int y, int FSize, LPCTSTR FType, int Fspin,
						 int FWeight, int FItalic, int FUnline, int FStrikeOut, LPCTSTR id_name,
						 LPCTSTR data, int mem_mode);
typedef int   (_stdcall *pfnA_Prn_Text_TrueType_W)(int x, int y, int FHeight, int FWidth,
						 LPCTSTR FType, int Fspin, int FWeight, int FItalic, int FUnline,
						 int FStrikeOut, LPCTSTR id_name, LPCTSTR data, int mem_mode);
typedef int   (_stdcall *pfnA_Set_Backfeed)(int back);
typedef int   (_stdcall *pfnA_Set_BMPSave)(int nSave, char* pstrBMPFName);
typedef int   (_stdcall *pfnA_Set_Cutting)(int cutting);
typedef int   (_stdcall *pfnA_Set_Darkness)(int heat);
typedef int   (_stdcall *pfnA_Set_DebugDialog)(int nEnable);
typedef int   (_stdcall *pfnA_Set_Feed)(char rate);
typedef int   (_stdcall *pfnA_Set_Form)(LPCTSTR formfile, LPCTSTR form_name, int mem_mode);
typedef int   (_stdcall *pfnA_Set_Margin)(int position, int margin);
typedef int   (_stdcall *pfnA_Set_Prncomport)(int baud, int parity, int data, int stop);
typedef int   (_stdcall *pfnA_Set_Prncomport_PC)(int nBaudRate, int nByteSize, int nParity,
						 int nStopBits, int nDsr, int nCts, int nXonXoff);
typedef int   (_stdcall *pfnA_Set_Sensor_Mode)(char type, int continuous);
typedef int   (_stdcall *pfnA_Set_Speed)(char speed);
typedef int   (_stdcall *pfnA_Set_Syssetting)(int transfer, int cut_peel, int length, int zero,
						 int pause);
typedef int   (_stdcall *pfnA_Set_Unit)(char unit);
typedef int   (_stdcall *pfnA_Set_Gap)(int gap);
typedef int   (_stdcall *pfnA_Set_Logic)(int logic);
typedef int   (_stdcall *pfnA_Set_ProcessDlg)(int nShow);
typedef int   (_stdcall *pfnA_Set_ErrorDlg)(int nShow);
typedef int   (_stdcall *pfnA_Set_LabelVer)(int centiInch);
typedef int   (_stdcall *pfnA_GetUSBBufferLen)(void);
typedef int   (_stdcall *pfnA_EnumUSB)(char *buf);
typedef int   (_stdcall *pfnA_CreateUSBPort)(int nPort);
typedef int   (_stdcall *pfnA_CreatePort)(int nPortType, int nPort, LPCTSTR filename);
typedef void  (_stdcall *pfnA_Clear_MemoryEx)(int nMode);
typedef void  (_stdcall *pfnA_Set_Mirror)(void);
typedef int   (_stdcall *pfnA_Bar2d_RSS)(int x, int y, int ori, int ratio, int height, char rtype,
						 int mult, int seg, LPCTSTR data1, LPCTSTR data2);
typedef int   (_stdcall *pfnA_Bar2d_QR_M)(int x, int y, int ori, char mult, int value, int model,
						 char error, int mask, char dinput, char mode, int numeric, LPCTSTR data);
typedef int   (_stdcall *pfnA_Bar2d_QR_A)(int x, int y, int ori, char mult, int value, char mode,
						 int numeric, LPCTSTR data);
typedef int   (_stdcall *pfnA_GetNetPrinterBufferLen)(void);
typedef int   (_stdcall *pfnA_EnumNetPrinter)(char *buf);
typedef int   (_stdcall *pfnA_CreateNetPort)(int nPort);
typedef int   (_stdcall *pfnA_Prn_Text_TrueType_Uni)(int x, int y, int FSize, LPCTSTR FType,
						 int Fspin, int FWeight, int FItalic, int FUnline, int FStrikeOut,
						 LPCTSTR id_name, LPCWSTR data, int format, int mem_mode);
typedef int   (_stdcall *pfnA_Prn_Text_TrueType_UniB)(int x, int y, int FSize, LPCTSTR FType, 
						 int Fspin, int FWeight, int FItalic, int FUnline, int FStrikeOut,
						 LPCTSTR id_name, LPCTSTR data, int format, int mem_mode);
typedef int   (_stdcall *pfnA_GetUSBDeviceInfo)(int nPort, char *pDeviceName, int *pDeviceNameLen,
						 char *pDevicePath, int *pDevicePathLen);
typedef int   (_stdcall *pfnA_Set_EncryptionKey)(char encryptionKey[16]);
typedef int   (_stdcall *pfnA_Check_EncryptionKey)(char decodeKey[8], char encryptionKey[16], 
						 DWORD dwTimeoutms);

pfnA_Bar2d_Maxi				A_Bar2d_Maxi			= NULL;
pfnA_Bar2d_Maxi_Ori			A_Bar2d_Maxi_Ori		= NULL;
pfnA_Bar2d_PDF417			A_Bar2d_PDF417			= NULL;
pfnA_Bar2d_PDF417_Ori		A_Bar2d_PDF417_Ori		= NULL;
pfnA_Bar2d_DataMatrix		A_Bar2d_DataMatrix		= NULL;
pfnA_Clear_Memory			A_Clear_Memory			= NULL;
pfnA_ClosePrn				A_ClosePrn				= NULL;
pfnA_CreatePrn				A_CreatePrn				= NULL;
pfnA_Del_Graphic			A_Del_Graphic			= NULL;
pfnA_Draw_Box				A_Draw_Box				= NULL; 
pfnA_Draw_Line				A_Draw_Line				= NULL;
pfnA_Feed_Label				A_Feed_Label			= NULL;
pfnA_Get_DLL_Version		A_Get_DLL_Version		= NULL;
pfnA_Get_DLL_VersionA		A_Get_DLL_VersionA		= NULL;
pfnA_Get_Graphic			A_Get_Graphic			= NULL;
pfnA_Get_Graphic_ColorBMP	A_Get_Graphic_ColorBMP	= NULL;
pfnA_Get_Graphic_ColorBMPEx	A_Get_Graphic_ColorBMPEx	= NULL;
pfnA_Get_Graphic_ColorBMP_HBitmap	A_Get_Graphic_ColorBMP_HBitmap	= NULL;
pfnA_Initial_Setting		A_Initial_Setting		= NULL;
pfnA_WriteData				A_WriteData				= NULL;
pfnA_ReadData				A_ReadData				= NULL;
pfnA_Load_Graphic			A_Load_Graphic			= NULL;
pfnA_Open_ChineseFont		A_Open_ChineseFont		= NULL;
pfnA_Print_Form				A_Print_Form			= NULL;
pfnA_Print_Out				A_Print_Out				= NULL;
pfnA_Prn_Barcode			A_Prn_Barcode			= NULL;
pfnA_Prn_Text				A_Prn_Text				= NULL;
pfnA_Prn_Text_Chinese		A_Prn_Text_Chinese		= NULL;
pfnA_Prn_Text_TrueType		A_Prn_Text_TrueType		= NULL;
pfnA_Prn_Text_TrueType_W	A_Prn_Text_TrueType_W	= NULL;
pfnA_Set_Backfeed			A_Set_Backfeed			= NULL;
pfnA_Set_BMPSave			A_Set_BMPSave			= NULL;
pfnA_Set_Cutting			A_Set_Cutting			= NULL;
pfnA_Set_Darkness			A_Set_Darkness			= NULL;
pfnA_Set_DebugDialog		A_Set_DebugDialog		= NULL;
pfnA_Set_Feed				A_Set_Feed				= NULL;
pfnA_Set_Form				A_Set_Form				= NULL;
pfnA_Set_Margin				A_Set_Margin			= NULL;
pfnA_Set_Prncomport			A_Set_Prncomport		= NULL;
pfnA_Set_Prncomport_PC		A_Set_Prncomport_PC		= NULL;
pfnA_Set_Sensor_Mode		A_Set_Sensor_Mode		= NULL;
pfnA_Set_Speed				A_Set_Speed				= NULL;
pfnA_Set_Syssetting			A_Set_Syssetting		= NULL;
pfnA_Set_Unit				A_Set_Unit				= NULL;
pfnA_Set_Gap				A_Set_Gap				= NULL;
pfnA_Set_Logic				A_Set_Logic				= NULL;
pfnA_Set_ProcessDlg			A_Set_ProcessDlg		= NULL;
pfnA_Set_ErrorDlg			A_Set_ErrorDlg		= NULL;
pfnA_Set_LabelVer			A_Set_LabelVer			= NULL;
pfnA_GetUSBBufferLen		A_GetUSBBufferLen		= NULL;
pfnA_EnumUSB				A_EnumUSB				= NULL;
pfnA_CreateUSBPort			A_CreateUSBPort			= NULL;
pfnA_CreatePort				A_CreatePort			= NULL;
pfnA_Clear_MemoryEx			A_Clear_MemoryEx		= NULL;
pfnA_Set_Mirror				A_Set_Mirror			= NULL;
pfnA_Bar2d_RSS				A_Bar2d_RSS				= NULL;
pfnA_Bar2d_QR_M				A_Bar2d_QR_M			= NULL;
pfnA_Bar2d_QR_A				A_Bar2d_QR_A			= NULL;
pfnA_GetUSBBufferLen		A_GetNetPrinterBufferLen= NULL;
pfnA_EnumUSB				A_EnumNetPrinter		= NULL;
pfnA_CreateUSBPort			A_CreateNetPort			= NULL;
pfnA_Prn_Text_TrueType_Uni	A_Prn_Text_TrueType_Uni = NULL;
pfnA_Prn_Text_TrueType_UniB	A_Prn_Text_TrueType_UniB= NULL;
pfnA_GetUSBDeviceInfo		A_GetUSBDeviceInfo		= NULL;
pfnA_Set_EncryptionKey		A_Set_EncryptionKey		= NULL;
pfnA_Check_EncryptionKey	A_Check_EncryptionKey	= NULL;
// PPLADLL Function Declaration end

/////////////////////////////////////////////////////////////////////////////
// CVC_6Dlg dialog

CVC_6Dlg::CVC_6Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVC_6Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVC_6Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	// Load Library start
	VERIFY(hPPLA = ::LoadLibrary("WINPPLA.DLL"));
	VERIFY(A_Bar2d_Maxi = (pfnA_Bar2d_Maxi) ::GetProcAddress(hPPLA,"A_Bar2d_Maxi"));
	VERIFY(A_Bar2d_Maxi_Ori = (pfnA_Bar2d_Maxi_Ori) ::GetProcAddress(hPPLA,"A_Bar2d_Maxi_Ori"));
	VERIFY(A_Bar2d_PDF417 = (pfnA_Bar2d_PDF417) ::GetProcAddress(hPPLA,"A_Bar2d_PDF417"));
	VERIFY(A_Bar2d_PDF417_Ori = (pfnA_Bar2d_PDF417_Ori) ::GetProcAddress(hPPLA,"A_Bar2d_PDF417_Ori"));
	VERIFY(A_Bar2d_DataMatrix = (pfnA_Bar2d_DataMatrix) ::GetProcAddress(hPPLA,"A_Bar2d_DataMatrix"));
	VERIFY(A_Clear_Memory = (pfnA_Clear_Memory) ::GetProcAddress(hPPLA,"A_Clear_Memory"));
	VERIFY(A_ClosePrn = (pfnA_ClosePrn) ::GetProcAddress(hPPLA,"A_ClosePrn"));
	VERIFY(A_CreatePrn = (pfnA_CreatePrn) ::GetProcAddress(hPPLA,"A_CreatePrn"));
	VERIFY(A_Del_Graphic = (pfnA_Del_Graphic) ::GetProcAddress(hPPLA,"A_Del_Graphic"));
	VERIFY(A_Draw_Box = (pfnA_Draw_Box) ::GetProcAddress(hPPLA,"A_Draw_Box"));
	VERIFY(A_Draw_Line = (pfnA_Draw_Line) ::GetProcAddress(hPPLA,"A_Draw_Line"));
	VERIFY(A_Feed_Label = (pfnA_Feed_Label) ::GetProcAddress(hPPLA,"A_Feed_Label"));
	VERIFY(A_Get_DLL_Version = (pfnA_Get_DLL_Version) ::GetProcAddress(hPPLA,"A_Get_DLL_Version"));
	VERIFY(A_Get_DLL_VersionA = (pfnA_Get_DLL_VersionA) ::GetProcAddress(hPPLA,"A_Get_DLL_VersionA"));
	VERIFY(A_Get_Graphic = (pfnA_Get_Graphic) ::GetProcAddress(hPPLA,"A_Get_Graphic"));
	VERIFY(A_Get_Graphic_ColorBMP = (pfnA_Get_Graphic_ColorBMP) ::GetProcAddress(hPPLA,"A_Get_Graphic_ColorBMP"));
	VERIFY(A_Get_Graphic_ColorBMPEx = (pfnA_Get_Graphic_ColorBMPEx) ::GetProcAddress(hPPLA,"A_Get_Graphic_ColorBMPEx"));
	VERIFY(A_Get_Graphic_ColorBMP_HBitmap = (pfnA_Get_Graphic_ColorBMP_HBitmap) ::GetProcAddress(hPPLA,"A_Get_Graphic_ColorBMP_HBitmap"));
	VERIFY(A_Initial_Setting = (pfnA_Initial_Setting) ::GetProcAddress(hPPLA,"A_Initial_Setting"));
	VERIFY(A_WriteData = (pfnA_WriteData) ::GetProcAddress(hPPLA,"A_WriteData"));
	VERIFY(A_ReadData = (pfnA_ReadData) ::GetProcAddress(hPPLA,"A_ReadData"));
	VERIFY(A_Load_Graphic = (pfnA_Load_Graphic) ::GetProcAddress(hPPLA,"A_Load_Graphic"));
	VERIFY(A_Open_ChineseFont = (pfnA_Open_ChineseFont) ::GetProcAddress(hPPLA,"A_Open_ChineseFont"));
	VERIFY(A_Print_Form = (pfnA_Print_Form) ::GetProcAddress(hPPLA,"A_Print_Form"));
	VERIFY(A_Print_Out = (pfnA_Print_Out) ::GetProcAddress(hPPLA,"A_Print_Out"));
	VERIFY(A_Prn_Barcode = (pfnA_Prn_Barcode) ::GetProcAddress(hPPLA,"A_Prn_Barcode"));
	VERIFY(A_Prn_Text = (pfnA_Prn_Text) ::GetProcAddress(hPPLA,"A_Prn_Text"));
	VERIFY(A_Prn_Text_Chinese = (pfnA_Prn_Text_Chinese) ::GetProcAddress(hPPLA,"A_Prn_Text_Chinese"));
	VERIFY(A_Prn_Text_TrueType = (pfnA_Prn_Text_TrueType) ::GetProcAddress(hPPLA,"A_Prn_Text_TrueType"));
	VERIFY(A_Prn_Text_TrueType_W = (pfnA_Prn_Text_TrueType_W) ::GetProcAddress(hPPLA,"A_Prn_Text_TrueType_W"));
	VERIFY(A_Set_Backfeed = (pfnA_Set_Backfeed) ::GetProcAddress(hPPLA,"A_Set_Backfeed"));
	VERIFY(A_Set_BMPSave = (pfnA_Set_BMPSave) ::GetProcAddress(hPPLA,"A_Set_BMPSave"));
	VERIFY(A_Set_Cutting = (pfnA_Set_Cutting) ::GetProcAddress(hPPLA,"A_Set_Cutting"));
	VERIFY(A_Set_Darkness = (pfnA_Set_Darkness) ::GetProcAddress(hPPLA,"A_Set_Darkness"));
	VERIFY(A_Set_DebugDialog = (pfnA_Set_DebugDialog) ::GetProcAddress(hPPLA,"A_Set_DebugDialog"));
	VERIFY(A_Set_Feed = (pfnA_Set_Feed) ::GetProcAddress(hPPLA,"A_Set_Feed"));
	VERIFY(A_Set_Form = (pfnA_Set_Form) ::GetProcAddress(hPPLA,"A_Set_Form"));
	VERIFY(A_Set_Margin = (pfnA_Set_Margin) ::GetProcAddress(hPPLA,"A_Set_Margin"));
	VERIFY(A_Set_Prncomport = (pfnA_Set_Prncomport) ::GetProcAddress(hPPLA,"A_Set_Prncomport"));
	VERIFY(A_Set_Prncomport_PC = (pfnA_Set_Prncomport_PC) ::GetProcAddress(hPPLA,"A_Set_Prncomport_PC"));
	VERIFY(A_Set_Sensor_Mode = (pfnA_Set_Sensor_Mode) ::GetProcAddress(hPPLA,"A_Set_Sensor_Mode"));
	VERIFY(A_Set_Speed = (pfnA_Set_Speed) ::GetProcAddress(hPPLA,"A_Set_Speed"));
	VERIFY(A_Set_Syssetting = (pfnA_Set_Syssetting) ::GetProcAddress(hPPLA,"A_Set_Syssetting"));
	VERIFY(A_Set_Unit = (pfnA_Set_Unit) ::GetProcAddress(hPPLA,"A_Set_Unit"));
	VERIFY(A_Set_Gap = (pfnA_Set_Gap) ::GetProcAddress(hPPLA,"A_Set_Gap"));
	VERIFY(A_Set_Logic = (pfnA_Set_Logic) ::GetProcAddress(hPPLA,"A_Set_Logic"));
	VERIFY(A_Set_ProcessDlg = (pfnA_Set_ProcessDlg) ::GetProcAddress(hPPLA,"A_Set_ProcessDlg"));
	//VERIFY(A_SetErrorDlg = (pfnA_Set_ErrorDlg) ::GetProcAddress(hPPLA,"A_Set_ErrorDlg"));
	VERIFY(A_Set_LabelVer = (pfnA_Set_LabelVer) ::GetProcAddress(hPPLA,"A_Set_LabelVer"));
	VERIFY(A_GetUSBBufferLen = (pfnA_GetUSBBufferLen) ::GetProcAddress(hPPLA,"A_GetUSBBufferLen"));
	VERIFY(A_EnumUSB = (pfnA_EnumUSB) ::GetProcAddress(hPPLA,"A_EnumUSB"));
	VERIFY(A_CreateUSBPort = (pfnA_CreateUSBPort) ::GetProcAddress(hPPLA,"A_CreateUSBPort"));
	VERIFY(A_CreatePort = (pfnA_CreatePort) ::GetProcAddress(hPPLA, "A_CreatePort"));
	VERIFY(A_Clear_MemoryEx = (pfnA_Clear_MemoryEx) ::GetProcAddress(hPPLA,"A_Clear_MemoryEx"));
	VERIFY(A_Set_Mirror = (pfnA_Set_Mirror) ::GetProcAddress(hPPLA,"A_Set_Mirror"));
	VERIFY(A_Bar2d_RSS = (pfnA_Bar2d_RSS) ::GetProcAddress(hPPLA,"A_Bar2d_RSS"));
	VERIFY(A_Bar2d_QR_M = (pfnA_Bar2d_QR_M) ::GetProcAddress(hPPLA,"A_Bar2d_QR_M"));
	VERIFY(A_Bar2d_QR_A = (pfnA_Bar2d_QR_A) ::GetProcAddress(hPPLA,"A_Bar2d_QR_A"));
	VERIFY(A_GetNetPrinterBufferLen = (pfnA_GetNetPrinterBufferLen) ::GetProcAddress(hPPLA,"A_GetNetPrinterBufferLen"));
	VERIFY(A_EnumNetPrinter = (pfnA_EnumNetPrinter) ::GetProcAddress(hPPLA,"A_EnumNetPrinter"));
	VERIFY(A_CreateNetPort = (pfnA_CreateNetPort) ::GetProcAddress(hPPLA,"A_CreateNetPort"));
	VERIFY(A_Prn_Text_TrueType_Uni = (pfnA_Prn_Text_TrueType_Uni) ::GetProcAddress(hPPLA,"A_Prn_Text_TrueType_Uni"));
	VERIFY(A_Prn_Text_TrueType_UniB = (pfnA_Prn_Text_TrueType_UniB) ::GetProcAddress(hPPLA,"A_Prn_Text_TrueType_UniB"));
	VERIFY(A_GetUSBDeviceInfo = (pfnA_GetUSBDeviceInfo) ::GetProcAddress(hPPLA,"A_GetUSBDeviceInfo"));
	VERIFY(A_Set_EncryptionKey = (pfnA_Set_EncryptionKey) ::GetProcAddress(hPPLA,"A_Set_EncryptionKey"));
	VERIFY(A_Check_EncryptionKey = (pfnA_Check_EncryptionKey) ::GetProcAddress(hPPLA,"A_Check_EncryptionKey"));
	// Load Library end
}

CVC_6Dlg::~CVC_6Dlg()
{
	VERIFY(::FreeLibrary(hPPLA));
}

void CVC_6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVC_6Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVC_6Dlg, CDialog)
	//{{AFX_MSG_MAP(CVC_6Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVC_6Dlg message handlers

BOOL CVC_6Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVC_6Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVC_6Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVC_6Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	// open port.
	int nLen, ret, sw;
	char *ver, *pbuf = new char[128];
	CString strmsg;

	// dll version.
	ver = A_Get_DLL_Version(0);

	// search port.
	nLen = A_GetUSBBufferLen() + 1;
	strmsg.Format("DLL %s\r\n", ver);
	if (nLen > 1)
	{
		char *buf1,*buf2;
		int len1 = 128, len2 = 128;
		buf1 = new char[len1];
		buf2 = new char[len2];
		A_EnumUSB(pbuf);
		A_GetUSBDeviceInfo(1, buf1, &len1, buf2, &len2);
		sw = 1;
		if (sw) {
			ret = A_CreatePrn(12, buf2);// open usb.
		}
		else {
			ret = A_CreateUSBPort(1);// must call A_GetUSBBufferLen() function fisrt.
		}
		if (0 != ret) {
			strmsg += "Open USB fail!";
		}
		else {
			strmsg += "Open USB:\r\nDevice name: ";
			strmsg += buf1;
			strmsg += "\r\nDevice path: ";
			strmsg += buf2;
			//sw = 2;
			if (2 == sw) {
				//get printer status.
				A_WriteData(1, "\x01\x46\r\n", 4);//<SOH>F
				ret = A_ReadData(pbuf, 2, 1000);
			}
		}
	}
	else
	{
		CreateDirectory(szSavePath, NULL);
		ret = A_CreatePrn(0, szSaveFile);// open file.
		strmsg += "Open ";
		strmsg += szSaveFile;
		if (0 != ret) {
			strmsg += " file fail!";
		}
		else {
			strmsg += " file succeed!";
		}
	}
	MessageBox(strmsg);
	if (0 != ret)
		return;

	// sample setting.
	A_Set_DebugDialog(1);
	A_Set_Unit('n');
	A_Set_Syssetting(1,0,0,0,0);
	A_Set_Darkness(8);
	A_Del_Graphic(1, "*");// delete all picture.
	A_Clear_Memory();// clear memory.
	A_WriteData(0, sznop2, (DWORD)strlen(sznop2));
	A_WriteData(1, sznop1, (DWORD)strlen(sznop1));

	//draw box.
	A_Draw_Box('A', 5, 5, 90, 40, 4, 4);

	//print text, true type text.
	A_Prn_Text(30, 30, 1, 2, 0, 1, 1, 'N', 2, "Avalon 4");
	A_Prn_Text_TrueType(30,60,30,"Arial",1,400,0,0,0,"AA","TrueType Font Avalon4",1);//save in ram.

	//barcode.
	A_Prn_Barcode(220, 60, 1, 'A', 0, 0, 20, 'B', 1, "1234");
	A_Bar2d_QR_A(220, 100, 1, '3', 10, 'N', 0, "QR CODE");

	// output.
	A_Print_Out(1, 1, 1, 1);// copy 1.

	// close port.
	A_ClosePrn();
}
