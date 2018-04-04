[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveInPrepareHeader
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The waveInPrepareHeader function prepares a buffer for waveform-audio input.
***  


## Code examples:
[Class for sound recording](../../samples/sample_420.md)  

## Declaration:
```foxpro  
MMRESULT waveInPrepareHeader(
  HWAVEIN hwi,
  LPWAVEHDR pwh,
  UINT cbwh
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveInPrepareHeader IN winmm;
	INTEGER hwi,;
	INTEGER pwh,;
	LONG cbwh
  
```  
***  


## Parameters:
hwi
Handle to the waveform-audio input device.

pwh
Pointer to a WAVEHDR structure that identifies the buffer to be prepared.

cbwh
Size, in bytes, of the WAVEHDR structure.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

