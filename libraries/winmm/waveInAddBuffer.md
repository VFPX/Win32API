[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveInAddBuffer
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The waveInAddBuffer function sends an input buffer to the given waveform-audio input device. When the buffer is filled, the application is notified.
***  


## Code examples:
[Class for sound recording](../../samples/sample_420.md)  

## Declaration:
```foxpro  
MMRESULT waveInAddBuffer(
  HWAVEIN hwi,
  LPWAVEHDR pwh,
  UINT cbwh
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveInAddBuffer IN winmm;
	INTEGER hwi,;
	INTEGER pwh,;
	LONG    cbwh
  
```  
***  


## Parameters:
hwi
Handle to the waveform-audio input device.

pwh
Pointer to a WAVEHDR structure that identifies the buffer.

cbwh
Size, in bytes, of the WAVEHDR structure.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

