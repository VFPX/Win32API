[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mciGetDeviceID
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### Retrieves the device identifier corresponding to the name of an open device.
***  


## Declaration:
```foxpro  
MCIDEVICEID mciGetDeviceID(
	LPCTSTR lpszDevice
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mciGetDeviceID IN winmm STRING lpszDevice  
```  
***  


## Parameters:
lpszDevice
Pointer to a null-terminated string that specifies the device name or the alias name by which the device is known.  
***  


## Return value:
Returns the device identifier assigned to the device when it was opened if successful. Otherwise the return value is zero.  
***  


## Comments:
The identifier is used in the mciSendCommand function.  
  
See also: [mciSendCommand](../winmm/mciSendCommand.md), [mciSendString](../winmm/mciSendString.md).  
  
***  

