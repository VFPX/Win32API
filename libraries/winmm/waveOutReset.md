<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveOutReset
Group: Windows Multimedia - Library: winmm    
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
```txt  
hwo
Handle to the waveform-audio output device returned by waveOutOpen.  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

