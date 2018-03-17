<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mixerGetDevCaps
Group: Windows Multimedia - Library: winmm    
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
```txt  
uMxId
Identifier or handle of an open mixer device.

pmxcaps
Pointer to a MIXERCAPS structure that receives information about the capabilities of the device.

cbmxcaps
Size, in bytes, of the MIXERCAPS structure.
  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

