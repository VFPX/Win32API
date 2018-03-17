<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : EnumDeviceDrivers
Group: Performance Monitoring - Library: psapi    
***  


#### The EnumDeviceDrivers function retrieves the load address for each device driver in the system.
***  


## Code examples:
[Listing device drivers in the system: load addresses, names](../../samples/sample_174.md)  

## Declaration:
```foxpro  
BOOL EnumDeviceDrivers(
  LPVOID *lpImageBase,  // array of load addresses
  DWORD cb,             // size of array
  LPDWORD lpcbNeeded    // number of bytes returned
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumDeviceDrivers IN psapi;
	STRING  @ lpImageBase,;
	INTEGER   cb,;
	INTEGER @ lpcbNeeded  
```  
***  


## Parameters:
```txt  
lpImageBase
[out] Pointer to an array that receives the list of load addresses for the device drivers.

cb
[in] Specifies the size, in bytes, of the lpImageBase array.

lpcbNeeded
[out] Receives the number of bytes returned in the lpImageBase array.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 4.0 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

