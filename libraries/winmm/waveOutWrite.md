
## Function name : waveOutWrite
Group: Windows Multimedia - Library: winmm    
***  


#### The waveOutWrite function sends a data block to the given waveform-audio output device.
***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  
[Playing WAV sounds simultaneously](../../samples/sample_523.md)  

## Declaration:
```foxpro  
MMRESULT waveOutWrite(
  HWAVEOUT hwo,
  LPWAVEHDR pwh,
  UINT cbwh
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveOutWrite IN winmm;
	INTEGER   hwo,;
	STRING  @ pwh,;
	INTEGER   cbwh
  
```  
***  


## Parameters:
hwo 
Handle to the waveform-audio output device. 

pwh 
Pointer to a WAVEHDR structure containing information about the data block. 

cbwh 
Size, in bytes, of the WAVEHDR structure.   
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
The buffer must be prepared with the waveOutPrepareHeader function before it is passed to waveOutWrite.  
  
When the buffer is finished, the WHDR_DONE bit is set in the dwFlags member of the WAVEHDR structure.  
  
***  

