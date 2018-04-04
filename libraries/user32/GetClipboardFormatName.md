[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetClipboardFormatName
Group: [Clipboard](../../functions_group.md#Clipboard)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetClipboardFormatName function retrieves from the clipboard the name of the specified registered format. The function copies the name to the specified buffer. 
***  


## Code examples:
[Enumerating data formats currently available on the clipboard](../../samples/sample_032.md)  
[Retrieving names for the registered clipboard formats](../../samples/sample_268.md)  
[Monitoring clipboard content changes (VFP9)](../../samples/sample_601.md)  

## Declaration:
```foxpro  
int GetClipboardFormatName(
  UINT format,            // clipboard format to retrieve
  LPTSTR lpszFormatName,  // format name
  int cchMaxCount         // length of format name buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetClipboardFormatName IN user32;
	INTEGER   format,;
	STRING  @ lpszFormatName,;
	INTEGER   cchMaxCount  
```  
***  


## Parameters:
format 
[in] Specifies the type of format to be retrieved. 

lpszFormatName 
[out] Pointer to the buffer that is to receive the format name. 

cchMaxCount 
[in] Specifies the maximum length, in TCHARs, of the string to be copied to the buffer.   
***  


## Return value:
If the function succeeds, the return value is the length, in TCHARs, of the string copied to the buffer.  
***  


## Comments:
Registered clipboard formats are identified by values in the range 0xC000 through 0xFFFF.   
  
***  

