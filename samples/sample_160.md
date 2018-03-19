[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# FindText -- the hopeless and useless Common Dialog

## Before you begin:
When testing this code, do not push **Find Next** button on the form. Since no callback procedure attached to this control the call is forwarded to zero address. And that would create a System Error message.  
  
***  


## Code:
```foxpro  
#DEFINE GMEM_FIXED        0
#DEFINE FR_DOWN           1
#DEFINE FR_MATCHCASE      4
#DEFINE FR_NOWHOLEWORD 4096

DO decl

*| typedef struct {
*|   DWORD        lStructSize;        4
*|   HWND         hwndOwner;          4
*|   HINSTANCE    hInstance;          4
*|   DWORD        Flags;              4
*|   LPTSTR        lpstrFindWhat;     4
*|   LPTSTR        lpstrReplaceWith;  4
*|   WORD         wFindWhatLen;       2
*|   WORD         wReplaceWithLen;    2
*|   LPARAM        lCustData;         4
*|   LPFRHOOKPROC lpfnHook;           4
*|   LPCTSTR       lpTemplateName;    4
*| } FINDREPLACE, *LPFINDREPLACE;  total: 40 bytes

	LOCAL lcFindReplace, lcFind, hFind, lnFindLen
	lcFind = "any string" + Chr(0)
	lnFindLen = Len(lcFind)
	hFind = GlobalAlloc(GMEM_FIXED, lnFindLen)

	DECLARE RtlMoveMemory IN kernel32 As String2Heap;
		INTEGER Destination, STRING @ Source,;
		INTEGER nLength
	= String2Heap (hFind, @lcFind, Len(lcFind))

	lcFindReplace =;
		num2dword(40) +;
		num2dword(GetActiveWindow()) +;
		num2dword(0) +;
		num2dword(FR_DOWN +;
			FR_MATCHCASE+FR_NOWHOLEWORD) +;
		num2dword(hFind) +;
		num2dword(0) +;
		num2dword(lnFindLen-1) +;
		num2dword(0) +;
		num2dword(0) +;
		num2dword(0) +;
		num2dword(0)

	LOCAL hwndFind
	hwndFind = FindText (@lcFindReplace)

	* releasing system resources
	= GlobalFree (hFind)

PROCEDURE  decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER FindText IN comdlg32 STRING @ lpfr

	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem
	DECLARE INTEGER GlobalAlloc IN kernel32;
		INTEGER wFlags,;
		INTEGER dwBytes

FUNCTION  num2dword (lnValue)
#DEFINE m0       256
#DEFINE m1     65536
#DEFINE m2  16777216
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)  
```  
***  


## Listed functions:
[FindText](../libraries/comdlg32/FindText.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  

## Comment:
By now I do not know such a thing as a pointer to a FoxPro procedure. Had I this pointer, the using of FindText Common Dialog would be a piece of cake. Otherwise it is useless. Do you have any other idea about it?  
  
***  

