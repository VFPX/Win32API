[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetRawInputDeviceList
Group: [Raw Input](../../functions_group.md#Raw_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Enumerates the raw input devices attached to the system.
***  


## Code examples:
[Enumerating raw input devices attached to the system (keyboard, mouse, human interface device)](../../samples/sample_571.md)  

## Declaration:
```foxpro  
UINT WINAPI GetRawInputDeviceList(
  __out_opt PRAWINPUTDEVICELIST pRawInputDeviceList,
  __inout PUINT puiNumDevices,
  __in UINT cbSize
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetRawInputDeviceList IN user32;
	STRING @pRawInputDeviceList,;
	LONG @puiNumDevices,;
	LONG cbSize  
```  
***  


## Parameters:
pRawInputDeviceList [out, optional]
An array of RAWINPUTDEVICELIST structures for the devices attached to the system. If NULL, the number of devices are returned in *puiNumDevices.

puiNumDevices [in, out]
If pRawInputDeviceList is NULL, the function populates this variable with the number of devices attached to the system; otherwise, this variable specifies the number of RAWINPUTDEVICELIST structures that can be contained in the buffer to which pRawInputDeviceList points.

cbSize [in]
The size of a RAWINPUTDEVICELIST structure, in bytes.  
***  


## Return value:
If the function is successful, the return value is the number of devices stored in the buffer pointed to by pRawInputDeviceList.  
***  


## Comments:
See also: [GetRawInputDeviceInfo](../user32/GetRawInputDeviceInfo.md).  
  
***  

