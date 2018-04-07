[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetRawInputDeviceInfo
Group: [Raw Input](../../functions_group.md#Raw_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves information about the raw input device.
***  


## Code examples:
[Enumerating raw input devices attached to the system (keyboard, mouse, human interface device)](../../samples/sample_571.md)  

## Declaration:
```foxpro  
UINT WINAPI GetRawInputDeviceInfo(
  __in_opt     HANDLE hDevice,
  __in         UINT uiCommand,
  __inout_opt  LPVOID pData,
  __inout      PUINT pcbSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetRawInputDeviceInfo IN user32;
	INTEGER hDevice,;
	LONG uiCommand,;
	STRING @pData,;
	LONG @pcbSize
  
```  
***  


## Parameters:
hDevice [in, optional]
A handle to the raw input device.

uiCommand [in]
Specifies what data will be returned in pData.

pData [in, out, optional]
A pointer to a buffer that contains the information specified by uiCommand. 

pcbSize [in, out]
Type: PUINT

The size, in bytes, of the data in pData.  
***  


## Return value:
If successful, this function returns a non-negative number indicating the number of bytes copied to pData.  
***  


## Comments:
If uiCommand is RIDI_DEVICEINFO, set the cbSize member of RID_DEVICE_INFO to sizeof(RID_DEVICE_INFO) before calling GetRawInputDeviceInfo.  
  
See also: [GetRawInputDeviceList](../user32/GetRawInputDeviceList.md).  
  
***  

