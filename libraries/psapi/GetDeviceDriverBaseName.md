<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetDeviceDriverBaseName
Group: Performance Monitoring - Library: psapi    
***  


#### The GetDeviceDriverBaseName function retrieves the base name of the specified device driver.
***  


## Code examples:
[Listing device drivers in the system: load addresses, names](../../samples/sample_174.md)  

## Declaration:
```foxpro  
DWORD GetDeviceDriverBaseName(
  LPVOID ImageBase,  // driver load address
  LPTSTR lpBaseName, // driver base name buffer
  DWORD nSize        // size of buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetDeviceDriverBaseName IN psapi;
	INTEGER   ImageBase,;
	STRING  @ lpBaseName,;
	INTEGER   nSize  
```  
***  


## Parameters:
```txt  
ImageBase
[in] Specifies the load address of the device driver.

lpBaseName
[out] Pointer to the buffer that receives the base name of the device driver.

nSize
[in] Specifies the size, in bytes, of the lpBaseName buffer.  
```  
***  


## Return value:
If the function succeeds, the return value specifies the length of the string copied to the buffer. If the function fails, the return value is zero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 4.0 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

