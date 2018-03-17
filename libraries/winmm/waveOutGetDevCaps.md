<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveOutGetDevCaps
Group: Windows Multimedia - Library: winmm    
***  


#### Retrieves the capabilities of a given waveform-audio output device.
***  


## Code examples:
[Quering waveform-audio output devices](../../samples/sample_393.md)  

## Declaration:
```foxpro  
MMRESULT waveOutGetDevCaps(
  UINT_PTR      uDeviceID,
  LPWAVEOUTCAPS pwoc,
  UINT          cbwoc
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveOutGetDevCaps IN winmm;
	INTEGER   uDeviceID,;
	STRING  @ pwoc,;
	INTEGER   cbwoc
  
```  
***  


## Parameters:
```txt  
uDeviceID
Identifier of the waveform-audio output device. It can be either a device identifier or a handle of an open waveform-audio output device.

pwoc
Pointer to a WAVEOUTCAPS structure to be filled with information about the capabilities of the device.

cbwoc
Size, in bytes, of the WAVEOUTCAPS structure.  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

