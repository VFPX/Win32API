[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Creating a device context for the specified printer

## Code:
```foxpro  
DECLARE INTEGER GetLastError IN kernel32

DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc

DECLARE INTEGER CreateDC IN gdi32;
	STRING lpszDriver, STRING lpszDevice,;
	INTEGER lpszOutput, INTEGER lpInitData

* WinNT 4.0
*	hdc = CreateDC ("WINSPOOL", "\\PRNSERVER01\REMOTEPRINTER002", 0, 0)

* WinMe -- both variants work
* hdc = CreateDC ("WINSPOOL", "EPSON Stylus COLOR 660", 0, 0)
hdc = CreateDC (Null, "EPSON Stylus COLOR 660", 0, 0)

IF hdc = 0
	*    2 = ERROR_FILE_NOT_FOUND -> the printer is off
	*    5 = Access is denied
	*  127 = ERROR_PROC_NOT_FOUND -> the printer name not found
	* 1801 = The printer name is invalid
	? "Error code:", GetLastError()
ENDIF

? hdc
= DeleteDC (hdc)  
```  
***  


## Listed functions:
[CreateDC](../libraries/gdi32/CreateDC.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
