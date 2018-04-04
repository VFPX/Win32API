[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveInUnprepareHeader
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The waveInUnprepareHeader function cleans up the preparation performed by the waveInPrepareHeader function. This function must be called after the device driver fills a buffer and returns it to the application. You must call this function before freeing the buffer.
***  


## Code examples:
[Class for sound recording](../../samples/sample_420.md)  

## Declaration:
```foxpro  
MMRESULT waveInUnprepareHeader(
  HWAVEIN hwi,
  LPWAVEHDR pwh,
  UINT cbwh
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveInUnprepareHeader IN winmm;
	INTEGER hwi,;
	INTEGER pwh,;
	LONG    cbwh
  
```  
***  


## Parameters:
hwi
Handle to the waveform-audio input device.

pwh
Pointer to a WAVEHDR structure identifying the buffer to be cleaned up.

cbwh
Size, in bytes, of the WAVEHDR structure.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

