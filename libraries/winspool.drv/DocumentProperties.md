[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DocumentProperties
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The DocumentProperties function retrieves or modifies printer initialization information or displays a printer-configuration property sheet for the specified printer. 
***  


## Code examples:
[Configuring DEVMODE structure for a printer](../../samples/sample_384.md)  
[Printing Image File, programmatically set print page orientation to landscape](../../samples/sample_555.md)  

## Declaration:
```foxpro  
LONG DocumentProperties(
  HWND hWnd,               // handle to parent window
  HANDLE hPrinter,         // handle to printer object
  LPTSTR pDeviceName,      // device name
  PDEVMODE pDevModeOutput, // modified device mode
  PDEVMODE pDevModeInput,  // original device mode
  DWORD fMode              // mode options
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DocumentProperties IN winspool.drv;
	INTEGER   hWnd,;
	INTEGER   hPrinter,;
	STRING    pDeviceName,;
	STRING  @ pDevModeOutput,;
	STRING  @ pDevModeInput,;
	INTEGER   fMode
  
```  
***  


## Parameters:
hWnd 
[in] Handle to the parent window of the printer-configuration property sheet. 

hPrinter 
[in] Handle to a printer object. Use the OpenPrinter or AddPrinter function to retrieve a printer handle. 

pDeviceName 
[in] Pointer to a null-terminated string that specifies the name of the device for which the printer-configuration property sheet is displayed. 

pDevModeOutput 
[out] Pointer to a DEVMODE structure that receives the printer configuration data specified by the user. 

pDevModeInput 
[in] Pointer to a DEVMODE structure that the operating system uses to initialize the property sheet controls. 

fMode 
[in] Specifies the operations the function performs. If this parameter is zero, the DocumentProperties function returns the number of bytes required by the printer driver"s DEVMODE data structure.   
***  


## Return value:
If the function fails, the return value is less than zero. 

If the function displays the property sheet, the return value is either IDOK or IDCANCEL, depending on which button the user selects. 

If the fMode parameter is zero, the return value is the size of the buffer required to contain the printer driver initialization data. Note that this buffer can be larger than a DEVMODE structure if the printer driver appends private data to the structure.   
***  


## Comments:
Read also Microsoft Help and Support article (former Q102966) <a href="http://support.microsoft.com/kb/q102966/">Registry Entries for Printing</a>.  
  
See also: [PrintDlg](../comdlg32/PrintDlg.md).  
  
***  

