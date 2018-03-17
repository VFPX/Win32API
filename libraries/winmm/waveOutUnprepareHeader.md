<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveOutUnprepareHeader
Group: Windows Multimedia - Library: winmm    
***  


#### The waveOutUnprepareHeader function cleans up the preparation performed by the waveOutPrepareHeader function. This function must be called after the device driver is finished with a data block. You must call this function before freeing the buffer.
***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  
[Playing WAV sounds simultaneously](../../samples/sample_523.md)  

## Declaration:
```foxpro  
MMRESULT waveOutUnprepareHeader(
  HWAVEOUT hwo,
  LPWAVEHDR pwh,
  UINT cbwh
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveOutUnprepareHeader IN winmm;
	INTEGER   hwi,;
	STRING  @ pwh,;
	INTEGER   cbwh
  
```  
***  


## Parameters:
```txt  
hwo
Handle to the waveform-audio output device.

pwh
Pointer to a WAVEHDR structure identifying the data block to be cleaned up.

cbwh
Size, in bytes, of the WAVEHDR structure.  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
This function complements waveOutPrepareHeader. You must call this function before freeing the buffer.   
  
After passing a buffer to the device driver with the waveOutWrite function, you must wait until the driver is finished with the buffer before calling waveOutUnprepareHeader.  
  
***  

