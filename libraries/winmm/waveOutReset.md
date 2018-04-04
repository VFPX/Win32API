[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveOutReset
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The waveOutReset function stops playback on the given waveform-audio output device and resets the current position to zero. All pending playback buffers are marked as done and returned to the application.
***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  
[Playing WAV sounds simultaneously](../../samples/sample_523.md)  

## Declaration:
```foxpro  
MMRESULT waveOutReset(
  HWAVEOUT hwo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveOutReset IN winmm;
	INTEGER hwo  
```  
***  


## Parameters:
hwo 
Handle to the waveform-audio output device returned by waveOutOpen.   
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

