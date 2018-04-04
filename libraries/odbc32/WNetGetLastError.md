[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WNetGetLastError
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### The WNetGetLastError function retrieves the most recent extended error code set by a WNet function. 
***  


## Code examples:
[Retrieving a universal form for the drive-based path for a network resource](../../samples/sample_317.md)  
[Connecting a local device to a network resource](../../samples/sample_318.md)  

## Declaration:
```foxpro  
DWORD WNetGetLastError(
  LPDWORD lpError,     // error code
  LPTSTR lpErrorBuf,   // error description buffer
  DWORD nErrorBufSize, // size of description buffer
  LPTSTR lpNameBuf,    // buffer for provider name
  DWORD nNameBufSize   // size of provider name buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WNetGetLastError IN mpr;
	INTEGER @ lpError,;
	STRING  @ lpErrorBuf,;
	INTEGER   nErrorBufSize,;
	STRING  @ lpNameBuf,;
	INTEGER   nNameBufSize
  
```  
***  


## Parameters:
lpError 
[out] Pointer to the variable that receives the error code reported by the network provider. The error code is specific to the network provider. 

lpErrorBuf 
[out] Pointer to the buffer that receives the null-terminated string describing the error. 

nErrorBufSize 
[in] Specifies the size, in characters, of the buffer pointed to by the lpErrorBuf parameter.

lpNameBuf 
[out] Pointer to the buffer that receives the null-terminated string identifying the network provider that raised the error. 

nNameBufSize 
[in] Specifies the size, in characters, of the buffer pointed to by the lpNameBuf parameter.  
***  


## Return value:
If the function succeeds, and it obtains the last error that the network provider reported, the return value is NO_ERROR.   
***  

