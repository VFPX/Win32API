[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EnumDisplayDevices
Group: [Device Context](../../functions_group.md#Device_Context)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The EnumDisplayDevices function lets you obtain information about the display devices in a system. 
***  


## Code examples:
[How to change display settings: screen resolution, screen refresh rate](../../samples/sample_374.md)  
[How to detect if additional monitor is connected and active](../../samples/sample_542.md)  

## Declaration:
```foxpro  
BOOL EnumDisplayDevices(
  LPCTSTR lpDevice,                // device name
  DWORD iDevNum,                   // display device
  PDISPLAY_DEVICE lpDisplayDevice, // device information
  DWORD dwFlags                    // reserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumDisplayDevices IN user32;
	STRING    lpDevice,;
	INTEGER   iDevNum,;
	STRING  @ lpDisplayDevice,;
	INTEGER   dwFlags  
```  
***  


## Parameters:
lpDevice 
[in] Pointer to the device name. If NULL, function returns information for the display adapter(s) on the machine, based on iDevNum.

iDevNum 
[in] Index value that specifies the display device of interest. 

lpDisplayDevice 
[out] Pointer to a DISPLAY_DEVICE structure that receives information about the display device specified by iDevNum.

dwFlags 
This parameter is currently not used and should be set to zero.  
***  


## Return value:
If the function succeeds, the return value is nonzero.   
***  


## Comments:
To query all display devices in the system, call this function in a loop, starting with iDevNum set to 0, and incrementing iDevNum until the function fails.  
  
To get information on the display adapter, call EnumDisplayDevices with lpDevice set to NULL. Then DISPLAY_DEVICE.DeviceString contains the adapter name.   
  
To obtain information on a display monitor, first call EnumDisplayDevices with lpDevice set to NULL. Then call EnumDisplayDevices with lpDevice set to DISPLAY_DEVICE.DeviceName from the first call to EnumDisplayDevices and with iDevNum set to zero. Then DISPLAY_DEVICE.DeviceString is the monitor name.   
  
See also [MonitorFromWindow](MonitorFromWindow.md), [GetMonitorInfo](GetMonitorInfo.md), [EnumDisplaySettings](EnumDisplaySettings.md) functions.  
  
***  

