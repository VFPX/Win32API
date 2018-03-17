<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetHandleInformation
Group: Handle and Object - Library: kernel32    
***  


#### Sets certain properties of an object handle.
***  


## Declaration:
```foxpro  
BOOL WINAPI SetHandleInformation(
	__in  HANDLE hObject,
	__in  DWORD dwMask,
	__in  DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetHandleInformation IN kernel32;
	INTEGERh Object,;
	LONG dwMask,;
	LONG dwFlags  
```  
***  


## Parameters:
```txt  
hObject [in]
A handle to an object whose information is to be set.

dwMask [in]
A mask that specifies the bit flags to be changed. Use the same constants shown in the description of dwFlags.

dwFlags [in]
Set of bit flags that specifies properties of the object handle. This parameter can be 0 or one or more of the following values.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: GetHandleInformation, CloseHandle   
  
***  

