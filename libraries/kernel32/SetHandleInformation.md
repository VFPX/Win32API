[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetHandleInformation
Group: [Handle and Object](../../functions_group.md#Handle_and_Object)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
hObject [in]
A handle to an object whose information is to be set.

dwMask [in]
A mask that specifies the bit flags to be changed. Use the same constants shown in the description of dwFlags.

dwFlags [in]
Set of bit flags that specifies properties of the object handle. This parameter can be 0 or one or more of the following values.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: [GetHandleInformation](../kernel32/GetHandleInformation.md), [CloseHandle](../kernel32/CloseHandle.md).  
  
***  

