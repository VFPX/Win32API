<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mciGetDeviceID
Group: Windows Multimedia - Library: winmm    
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
```txt  
lpszDevice
Pointer to a null-terminated string that specifies the device name or the alias name by which the device is known.  
```  
***  


## Return value:
Returns the device identifier assigned to the device when it was opened if successful. Otherwise the return value is zero.  
***  


## Comments:
The identifier is used in the mciSendCommand function.  
  
See also: mciSendCommand, mciSendString   
  
***  

