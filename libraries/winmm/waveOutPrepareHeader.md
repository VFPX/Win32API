[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveOutPrepareHeader
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
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
hwo 
Handle to the waveform-audio output device. 

pwh 
Pointer to a WAVEHDR structure that identifies the data block to be prepared. 

cbwh 
Size, in bytes, of the WAVEHDR structure.   
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
The lpData, dwBufferLength, and dwFlags members of the WAVEHDR structure must be set before calling this function (dwFlags must be zero).  
  
The waveOutWrite function sends a data block to the given waveform-audio output device  
  
***  

