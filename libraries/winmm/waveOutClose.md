[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveOutClose
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The waveOutClose function closes the given waveform-audio output device.
***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  
[Playing WAV sounds simultaneously](../../samples/sample_523.md)  

## Declaration:
```foxpro  
MMRESULT waveOutClose(
  HWAVEOUT hwo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveOutClose IN winmm;
	INTEGER hwo  
```  
***  


## Parameters:
hwo 
Handle to the waveform-audio output device. If the function succeeds, the handle is no longer valid after this call.  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
If the device is still playing a waveform-audio file, the close operation fails. Use the waveOutReset function to terminate playback before calling waveOutClose.  
  
***  

