[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mixerGetDevCaps
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The mixerGetDevCaps function queries a specified mixer device to determine its capabilities.
***  


## Code examples:
[Quering Audio Mixer Device](../../samples/sample_423.md)  

## Declaration:
```foxpro  
MMRESULT mixerGetDevCaps(
  UINT_PTR    uMxId,
  LPMIXERCAPS pmxcaps,
  UINT        cbmxcaps
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mixerGetDevCaps IN winmm;
	INTEGER   uMxId,;
	STRING  @ pmxcaps,;
	INTEGER   cbmxcaps
  
```  
***  


## Parameters:
uMxId
Identifier or handle of an open mixer device.

pmxcaps
Pointer to a MIXERCAPS structure that receives information about the capabilities of the device.

cbmxcaps
Size, in bytes, of the MIXERCAPS structure.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

