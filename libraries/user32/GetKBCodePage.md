
## Function name : GetKBCodePage
Group: Keyboard Input - Library: user32    
***  


#### Returns the current code page.
***  


## Code examples:
[Retrieving national language settings](../../samples/sample_077.md)  

## Declaration:
```foxpro  
UINT GetKBCodePage(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetKBCodePage IN user32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
The return value is an OEM code-page identifier, or it is the default identifier if the registry value is not readable.  
***  


## Comments:
For a list of OEM code-page identifiers, see GetOEMCP.   
  
This function is provided only for compatibility with 16-bit versions of Windows. Win32-based applications should use the GetOEMCP function to retrieve the OEM code-page identifier for the system.  
  
***  

