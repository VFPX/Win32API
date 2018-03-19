[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving Printer Device Context using PrintDlg function

## Code:
```foxpro  
*| typedef struct tagPD {
*|   DWORD           lStructSize;         4
*|   HWND            hwndOwner;           4
*|   HGLOBAL         hDevMode;            4
*|   HGLOBAL         hDevNames;           4
*|   HDC             hDC;                 4
*|   DWORD           Flags;               4
*|   WORD            nFromPage;           2
*|   WORD            nToPage;             2
*|   WORD            nMinPage;            2
*|   WORD            nMaxPage;            2
*|   WORD            nCopies;             2
*|   HINSTANCE       hInstance;           4
*|   LPARAM          lCustData;           4
*|   LPPRINTHOOKPROC lpfnPrintHook;       4
*|   LPSETUPHOOKPROC lpfnSetupHook;       4
*|   LPCTSTR         lpPrintTemplateName; 4
*|   LPCTSTR         lpSetupTemplateName; 4
*|   HGLOBAL         hPrintTemplate;      4
*|   HGLOBAL         hSetupTemplate;      4
*| } PRINTDLG, *LPPRINTDLG;              66 Bytes

DO decl

#DEFINE PD_ALLPAGES    0
#DEFINE PD_RETURNDC  256
#DEFINE PD_USEDEVMODECOPIESANDCOLLATE  0x40000
#DEFINE PD_RETURNDEFAULT 0x400

	LOCAL lcStruct, hDc, lnFlags

* for this value of flags no Device Context returned
*	lnFlags = PD_ALLPAGES

	lnFlags = PD_USEDEVMODECOPIESANDCOLLATE + PD_RETURNDC
	
	* fill PRINTDLG structure
	lcStruct = num2dword(66) +;
			num2dword(0) +;
			num2dword(0) +;
			num2dword(0) +;
			num2dword(0) +;
		num2dword(lnFlags) +;
		num2word(65535) +;
		num2word(65535) +;
		num2word(1) +;
		num2word(65535) +;
		num2word(1) +;
			num2dword(0) +;
			num2dword(0) +;
			num2dword(0) +;
			num2dword(0) +;
			num2dword(0) +;
			num2dword(0) +;
			num2dword(0) +;
			num2dword(0) +;
			num2dword(0)

	IF PrintDlg (@lcStruct) <> 0
		hDc = buf2dword (SUBSTR (lcStruct, 17, 4))
		? "Printer Device Context returned:", hDc
		
		* release system resources
		= DeleteDC (hDc)
	ENDIF

FUNCTION  num2dword (lnValue)
#DEFINE m0       256
#DEFINE m1     65536
#DEFINE m2  16777216
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3 * m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION  num2word (lnValue)
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
    DECLARE INTEGER PrintDlg IN comdlg32;
		STRING @ lppd  
```  
***  


## Listed functions:
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[PrintDlg](../libraries/comdlg32/PrintDlg.md)  

## Comment:
There are several ways to get a printer device context. Once you obtain the value, you have many GDI functions available for sending graphical output to the printer: print text and images.  
  
Flag PD_RETURNDEFAULT allows you to get the default printer device context without even a displaying the dialog box. I believe this option is quite useful.  
  
***  

