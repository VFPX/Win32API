[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegisterRawInputDevices
Group: [Raw Input](../../functions_group.md#Raw_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Registers the devices that supply the raw input data.
***  


## Code examples:
[Capturing keyboard activity of another application with the Raw Input API (VFP9)](../../samples/sample_572.md)  

## Declaration:
```foxpro  
BOOL WINAPI RegisterRawInputDevices(
  __in  PCRAWINPUTDEVICE pRawInputDevices,
  __in  UINT uiNumDevices,
  __in  UINT cbSize
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegisterRawInputDevices IN user32;
	STRING @pRawInputDevices,;
	LONG uiNumDevices,;
	LONG cbSize  
```  
***  


## Parameters:
pRawInputDevices [in]
An array of RAWINPUTDEVICE structures that represent the devices that supply the raw input.

uiNumDevices [in]
The number of RAWINPUTDEVICE structures pointed to by pRawInputDevices.

cbSize [in]
The size, in bytes, of a RAWINPUTDEVICE structure.  
***  


## Return value:
TRUE if the function succeeds; otherwise, FALSE. If the function fails, call GetLastError for more information.  
***  


## Comments:
To receive WM_INPUT messages, an application must first register the raw input devices using RegisterRawInputDevices.   
  
By default, an application does not receive raw input.  
  
See also: [GetRawInputData](../user32/GetRawInputData.md), [GetRawInputDeviceList](../user32/GetRawInputDeviceList.md).  
  
***  

