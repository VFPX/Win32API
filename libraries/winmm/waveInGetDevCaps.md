[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveInGetDevCaps
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
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
uDeviceID 
Identifier of the waveform-audio output device. It can be either a device identifier or a handle of an open waveform-audio input device. 

pwic 
Pointer to a WAVEINCAPS structure to be filled with information about the capabilities of the device. 

cbwic 
Size, in bytes, of the WAVEINCAPS structure.   
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
If the value specified by the uDeviceID parameter is a device identifier, it can vary from zero to one less than the number of devices present.  
  
***  

