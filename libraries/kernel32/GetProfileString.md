[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetProfileString
Group: [Registry](../../functions_group.md#Registry)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the string associated with a key in the specified section of the Win.ini file.
***  


## Code examples:
[Reading keys in the specified section of the Win.ini file](../../samples/sample_136.md)  
[Retrieving list of supported paper names (for example, Letter or Legal) for a given printer](../../samples/sample_356.md)  
[Printing text with the Escape function](../../samples/sample_357.md)  
[Retrieving default spooling directory name](../../samples/sample_358.md)  
[Retrieving the name of the default printer for the current user on the local computer (Win NT/XP)](../../samples/sample_360.md)  
[How to retrieve the number of print jobs queued for the printer](../../samples/sample_367.md)  
[Enumerating print jobs and retrieving information for default printer (JOB_INFO_1 structures)](../../samples/sample_368.md)  
[How to retrieve configuration data for a specified printer stored in the registry (PrinterDriverData key)](../../samples/sample_369.md)  
[How to delete all print jobs for a printer](../../samples/sample_370.md)  
[Displaying printer-properties Property Sheet for the specified printer](../../samples/sample_372.md)  
[Simple printer queue monitor: deletes, pauses, resumes print jobs for local printer](../../samples/sample_373.md)  
[Configuring DEVMODE structure for a printer](../../samples/sample_384.md)  
[Enumerating forms supported by a specified printer](../../samples/sample_390.md)  

## Declaration:
```foxpro  
DWORD GetProfileString(
  LPCTSTR lpAppName,        // section name
  LPCTSTR lpKeyName,        // key name
  LPCTSTR lpDefault,        // default string
  LPTSTR lpReturnedString,  // destination buffer
  DWORD nSize               // size of destination buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetProfileString IN kernel32;
	STRING   lpAppName,;
	STRING   lpKeyName,;
	STRING   lpDefault,;
	STRING @ lpReturnedString,;
	INTEGER  nSize  
```  
***  


## Parameters:
lpAppName 
[in] Pointer to a null-terminated string that specifies the name of the section containing the key. 

lpKeyName 
[in] Pointer to a null-terminated string specifying the name of the key whose associated string is to be retrieved. 

lpDefault 
[in] Pointer to a null-terminated default string. 

lpReturnedString 
[out] Pointer to a buffer that receives the character string. 

nSize 
[in] Specifies the size, in TCHARs, of the buffer pointed to by the lpReturnedString parameter.  
***  


## Return value:
The return value is the number of characters copied to the buffer, not including the null-terminating character.  
***  


## Comments:
A section in the Win.ini file must have the following form: <Em>  
[section]  
key=string  
</Em>  
  
***  

