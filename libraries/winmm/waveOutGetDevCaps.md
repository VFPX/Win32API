[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveOutGetDevCaps
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
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
uDeviceID 
Identifier of the waveform-audio output device. It can be either a device identifier or a handle of an open waveform-audio output device. 

pwoc 
Pointer to a WAVEOUTCAPS structure to be filled with information about the capabilities of the device. 

cbwoc 
Size, in bytes, of the WAVEOUTCAPS structure.  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

