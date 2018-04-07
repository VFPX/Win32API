[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetDefaultPrinter
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The GetDefaultPrinter function retrieves the printer name of the default printer for the current user on the local computer.
***  


## Code examples:
[Retrieving the name of the default printer for the current user on the local computer (Win NT/XP)](../../samples/sample_360.md)  
[Enumerating print jobs and retrieving information for default printer (JOB_INFO_1 structures)](../../samples/sample_368.md)  
[Printing Image File, programmatically set print page orientation to landscape](../../samples/sample_555.md)  
[Setting default printer](../../samples/sample_589.md)  

## Declaration:
```foxpro  
BOOL GetDefaultPrinter(
  LPTSTR pszBuffer,   // printer name buffer
  LPDWORD pcchBuffer  // size of name buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetDefaultPrinter IN winspool.drv;
	STRING  @ pszBuffer,;
	INTEGER @ pcchBuffer
  
```  
***  


## Parameters:
pszBuffer 
[in] Pointer to a buffer that receives a null-terminated character string containing the default printer name.

pcchBuffer 
[in/out] On input, specifies the size, in characters, of the pszBuffer buffer.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value and the variable pointed to by pcchBuffer contains the number of characters copied to the pszBuffer buffer, including the terminating null character.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows 2000 and later.  
Windows 95/98/Me: Unsupported.  
  
See also: [SetDefaultPrinter](../winspool.drv/SetDefaultPrinter.md), [EnumPrinters](../winspool.drv/EnumPrinters.md), [PrinterProperties](../winspool.drv/PrinterProperties.md).  
  
***  

