<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

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

