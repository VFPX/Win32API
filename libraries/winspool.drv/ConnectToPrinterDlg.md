[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ConnectToPrinterDlg
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The ConnectToPrinterDlg function displays a dialog box that lets users browse and connect to printers on a network. If the user selects a printer, the function attempts to create a connection to it; if a suitable driver is not installed on the server, the user is given the option of creating a printer locally. 
***  


## Code examples:
[How to browse and connect to printers on a network (WinNT)](../../samples/sample_376.md)  

## Declaration:
```foxpro  
HANDLE ConnectToPrinterDlg(
  HWND hwnd,    // handle to parent window
  DWORD Flags   // reserved; must be zero
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ConnectToPrinterDlg IN winspool.drv;
	INTEGER hwnd,;
	INTEGER Flags
  
```  
***  


## Parameters:
hwnd 
[in] Specifies the parent window of the dialog box. 

Flags 
[in] This parameter is reserved and must be zero.   
***  


## Return value:
If the function succeeds and the user selects a printer, the return value is a handle to the selected printer.   
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 3.5 and later.  
Windows 95/98/Me: Unsupported.  
  
An application should call DeletePrinter to delete a local printer. An application should call DeletePrinterConnection to delete a connection to a printer.   
  
***  

