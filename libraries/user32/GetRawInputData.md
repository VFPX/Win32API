[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetRawInputData
Group: [Raw Input](../../functions_group.md#Raw_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves the raw input from the specified device.
***  


## Code examples:
[Capturing keyboard activity of another application with the Raw Input API (VFP9)](../../samples/sample_572.md)  

## Declaration:
```foxpro  
UINT WINAPI GetRawInputData(
  __in       HRAWINPUT hRawInput,
  __in       UINT uiCommand,
  __out_opt  LPVOID pData,
  __inout    PUINT pcbSize,
  __in       UINT cbSizeHeader
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetRawInputData IN user32;
	INTEGER hRawInput,;
	LONG uiCommand,;
	STRING @pData,;
	LONG @pcbSize,;
	LONG cbSizeHeader
  
```  
***  


## Parameters:
hRawInput [in]
A handle to the RAWINPUT structure. This comes from the lParam in WM_INPUT.

uiCommand [in]
The command flag: RID_HEADER, RID_INPUT

pData [out, optional]
A pointer to the data that comes from the RAWINPUT structure. This depends on the value of uiCommand.

pcbSize [in, out]
The size, in bytes, of the data in pData.

cbSizeHeader [in]
The size, in bytes, of the RAWINPUTHEADER structure.  
***  


## Return value:
If pData is NULL and the function is successful, the return value is 0. If pData is not NULL and the function is successful, the return value is the number of bytes copied into pData.  
***  


## Comments:
See also: [RegisterRawInputDevices](../user32/RegisterRawInputDevices.md).  
  
***  

