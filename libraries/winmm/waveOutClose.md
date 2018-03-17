<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveOutClose
Group: Windows Multimedia - Library: winmm    
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
```txt  
hwo
Handle to the waveform-audio output device. If the function succeeds, the handle is no longer valid after this call.  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
If the device is still playing a waveform-audio file, the close operation fails. Use the waveOutReset function to terminate playback before calling waveOutClose.  
  
***  

