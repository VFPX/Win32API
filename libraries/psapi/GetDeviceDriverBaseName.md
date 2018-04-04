[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetDeviceDriverBaseName
Group: [Performance Monitoring](../../functions_group.md#Performance_Monitoring)  -  Library: [psapi](../../Libraries.md#psapi)  
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
ImageBase 
[in] Specifies the load address of the device driver. 

lpBaseName 
[out] Pointer to the buffer that receives the base name of the device driver. 

nSize 
[in] Specifies the size, in bytes, of the lpBaseName buffer.   
***  


## Return value:
If the function succeeds, the return value specifies the length of the string copied to the buffer. If the function fails, the return value is zero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 4.0 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

