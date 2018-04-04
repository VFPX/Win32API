[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FormatMessage
Group: [Error Handling](../../functions_group.md#Error_Handling)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The FormatMessage function formats a message string. It can be used to obtain error message strings for the system error codes returned by GetLastError.
***  


## Code examples:
[Retrieving System Error message strings](../../samples/sample_056.md)  
[Testing serial ports](../../samples/sample_308.md)  
[Connecting a local device to a network resource](../../samples/sample_318.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
DWORD FormatMessage(
  DWORD dwFlags,      // source and processing options
  LPCVOID lpSource,   // message source
  DWORD dwMessageId,  // message identifier
  DWORD dwLanguageId, // language identifier
  LPTSTR lpBuffer,    // message buffer
  DWORD nSize,        // maximum size of message buffer
  va_list *Arguments  // array of message inserts
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FormatMessage IN kernel32;
	INTEGER   dwFlags,;
	INTEGER   lpSource,;
	INTEGER   dwMessageId,;
	INTEGER   dwLanguageId,;
	INTEGER @ lpBuffer,;
	INTEGER   nSize,;
	INTEGER   Arguments
  
```  
***  


## Parameters:
dwFlags 
[in] Specifies aspects of the formatting process and how to interpret the lpSource parameter

lpSource 
[in] Specifies the location of the message definition

dwMessageId 
[in] Specifies the message identifier for the requested message. For obtaining system error messages put the error code into this parameter.

dwLanguageId 
[in] Specifies the language identifier for the requested message

lpBuffer 
[out] Pointer to a buffer for the formatted (and null-terminated) message

nSize
Maximum or minimum (depends on settings) number of bytes in the output buffer

Arguments 
[in] Pointer to an array of values that are used as insert values in the formatted message
  
***  


## Return value:
If the function succeeds, the return value is the number of TCHARs stored in the output buffer  
***  


## Comments:
This function retrieves data from the MESSAGETABLE resource in KERNEL32.DLL. Most likely, the same can be accomplished with the FindResource and LoadResource calls (RT_MESSAGETABLE).  
  
***  

