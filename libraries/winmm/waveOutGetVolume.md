[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveOutGetVolume
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The waveOutGetVolume function retrieves the current volume level of the specified waveform-audio output device.
***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  

## Declaration:
```foxpro  
MMRESULT waveOutGetVolume(
  HWAVEOUT hwo,
  LPDWORD pdwVolume
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveOutGetVolume IN winmm;
	INTEGER   hwo,;
	INTEGER @ pdwVolume  
```  
***  


## Parameters:
hwo 
Handle to an open waveform-audio output device. This parameter can also be a device identifier. 

pdwVolume 
Pointer to a variable to be filled with the current volume setting.  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
The low-order word of <Em>pdwVolume</Em> contains the left-channel volume setting, and the high-order word contains the right-channel setting. A value of 0xFFFF represents full volume, and a value of 0x0000 is silence.  
  
***  

