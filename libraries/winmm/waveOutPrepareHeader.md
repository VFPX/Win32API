<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveOutPrepareHeader
Group: Windows Multimedia - Library: winmm    
***  


#### The waveOutPrepareHeader function prepares a waveform-audio data block for playback with waveOutWrite function.
***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  
[Playing WAV sounds simultaneously](../../samples/sample_523.md)  

## Declaration:
```foxpro  
MMRESULT waveOutPrepareHeader(
  HWAVEOUT hwo,
  LPWAVEHDR pwh,
  UINT cbwh
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveOutPrepareHeader IN winmm;
	INTEGER   hwo,;
	STRING  @ pwh,;
	INTEGER   cbwh
  
```  
***  


## Parameters:
```txt  
hwo
Handle to the waveform-audio output device.

pwh
Pointer to a WAVEHDR structure that identifies the data block to be prepared.

cbwh
Size, in bytes, of the WAVEHDR structure.  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
The lpData, dwBufferLength, and dwFlags members of the WAVEHDR structure must be set before calling this function (dwFlags must be zero).  
  
The waveOutWrite function sends a data block to the given waveform-audio output device  
  
***  

