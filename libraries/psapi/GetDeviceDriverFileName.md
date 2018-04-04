[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetDeviceDriverFileName
Group: [Performance Monitoring](../../functions_group.md#Performance_Monitoring)  -  Library: [psapi](../../Libraries.md#psapi)  
***  


#### The GetDeviceDriverFileName function retrieves the fully qualified path for the specified device driver.
***  


## Code examples:
[Listing device drivers in the system: load addresses, names](../../samples/sample_174.md)  

## Declaration:
```foxpro  
DWORD GetDeviceDriverFileName(
  LPVOID ImageBase,  // driver load address
  LPTSTR lpFilename, // path buffer
  DWORD nSize        // size of buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetDeviceDriverFileName IN psapi;
	INTEGER   ImageBase,;
	STRING  @ lpFilename,;
	INTEGER   nSize  
```  
***  


## Parameters:
ImageBase 
[in] Specifies the load address of the device driver. 

lpFilename 
[out] Pointer to the buffer that receives the fully qualified path to the device driver. 

nSize 
[in] Specifies the size, in bytes, of the lpFilename buffer.   
***  


## Return value:
If the function succeeds, the return value specifies the length of the string copied to the buffer. If the function fails, the return value is zero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 4.0 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

