[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Displaying the main Dial-Up Networking dialog box

## Code:
```foxpro  
DECLARE INTEGER RasPhonebookDlg IN rasdlg;
	STRING @lpszPhonebook, STRING @lpszEntry, STRING @lpInfo
	
*|typedef struct tagRASPBDLG {
*|  IN  DWORD         dwSize;        0:4
*|  IN  HWND          hwndOwner;     4:4
*|  IN  DWORD         dwFlags;       8:4
*|  IN  LONG          xDlg;          12:4
*|  IN  LONG          yDlg;          16:4
*|  IN  DWORD         dwCallbackId;  20:4
*|  IN  RASPBDLGFUNC  pCallback;     24:4
*|  OUT DWORD         dwError;       28:4
*|  IN  ULONG_PTR         reserved;  32:4
*|  IN  ULONG_PTR         reserved2; 36:4
*|} RASPBDLG; total bytes = 40
#DEFINE RASPBDLG_SIZE  40

LOCAL lcBuffer
lcBuffer = Chr(RASPBDLG_SIZE) + Repli(Chr(0), RASPBDLG_SIZE-1)
? RasPhonebookDlg(0,0, @lcBuffer)  
```  
***  


## Listed functions:
[RasPhonebookDlg](../libraries/rasdlg/RasPhonebookDlg.md)  
