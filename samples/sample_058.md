[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Setting the last-error code for the FoxPro

## Code:
```foxpro  
DECLARE INTEGER GetLastError IN kernel32
	DECLARE SetLastError IN kernel32 INTEGER dwErrCode

	* setting 54=ERROR_NETWORK_BUSY: the network is busy
	= SetLastError (54)
	? GetLastError()	&& testing the result  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[SetLastError](../libraries/kernel32/SetLastError.md)  

## Comment:
The SetlastError is intended primarily for dynamic-link libraries (DLL). Calling this function after an error occurs lets the DLL emulate the behavior of the Win32 API  
  
***  

