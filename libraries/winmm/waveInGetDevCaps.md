<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveInGetDevCaps
Group: Windows Multimedia - Library: winmm    
***  


#### The waveInGetDevCaps function retrieves the capabilities of a given waveform-audio input device.
***  


## Code examples:
[Quering a waveform-audio input device](../../samples/sample_366.md)  

## Declaration:
```foxpro  
MMRESULT waveInGetDevCaps(
  UINT_PTR     uDeviceID,
  LPWAVEINCAPS pwic,
  UINT         cbwic
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveInGetDevCaps IN winmm;
	INTEGER   uDeviceID,;
	STRING  @ pwic,;
	LONG      cbwic
  
```  
***  


## Parameters:
```txt  
uDeviceID
Identifier of the waveform-audio output device. It can be either a device identifier or a handle of an open waveform-audio input device.

pwic
Pointer to a WAVEINCAPS structure to be filled with information about the capabilities of the device.

cbwic
Size, in bytes, of the WAVEINCAPS structure.  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
If the value specified by the uDeviceID parameter is a device identifier, it can vary from zero to one less than the number of devices present.  
  
***  

