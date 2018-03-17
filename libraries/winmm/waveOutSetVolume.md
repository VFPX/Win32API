<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveOutSetVolume
Group: Windows Multimedia - Library: winmm    
***  


#### The waveOutSetVolume function sets the volume level of the specified waveform-audio output device.
***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  

## Declaration:
```foxpro  
MMRESULT waveOutSetVolume(
  HWAVEOUT hwo,
  DWORD dwVolume
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveOutSetVolume IN winmm;
	INTEGER hwo,;
	INTEGER dwVolume
  
```  
***  


## Parameters:
```txt  
hwo
Handle to an open waveform-audio output device. This parameter can also be a device identifier.

dwVolume
New volume setting. The low-order word contains the left-channel volume setting, and the high-order word contains the right-channel setting. A value of 0xFFFF represents full volume, and a value of 0x0000 is silence.  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

