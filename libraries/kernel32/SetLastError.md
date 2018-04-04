[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetLastError
Group: [Error Handling](../../functions_group.md#Error_Handling)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Sets the last-error code for the calling thread. This function is intended primarily for dynamic-link libraries (DLL). Calling this function after an error occurs lets the DLL emulate the behavior of the Win32 API.

If you are defining an error code for your application, be sure that your error code does not conflict with any system-defined error codes.

***  


## Code examples:
[Setting the last-error code for the FoxPro](../../samples/sample_058.md)  

## Declaration:
```foxpro  
VOID SetLastError(
  DWORD dwErrCode   // per-thread error code
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SetLastError IN kernel32 INTEGER dwErrCode  
```  
***  


## Parameters:
dwErrCode 
[in] Specifies the last-error code for the thread  
***  


## Return value:
This function does not return a value  
***  

