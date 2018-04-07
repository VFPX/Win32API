[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetErrorMode
Group: [Error Handling](../../functions_group.md#Error_Handling)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Controls whether the system will handle the specified types of serious errors, or whether the process will handle them.
***  


## Code examples:
[Using the SetErrorMode for determining if a floppy drive is ready](../../samples/sample_227.md)  

## Declaration:
```foxpro  
UINT SetErrorMode(
  UINT uMode   // process error mode
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetErrorMode IN kernel32;
	INTEGER uMode  
```  
***  


## Parameters:
uMode 
[in] Specifies the process error mode.  
***  


## Return value:
The return value is the previous state of the error-mode bit flags.   
***  


## Comments:
See also: [GetErrorMode](../kernel32/GetErrorMode.md).  
  
***  

