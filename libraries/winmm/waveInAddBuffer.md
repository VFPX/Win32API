<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveInAddBuffer
Group: Windows Multimedia - Library: winmm    
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
```txt  
hwi
Handle to the waveform-audio input device.

pwh
Pointer to a WAVEHDR structure that identifies the buffer.

cbwh
Size, in bytes, of the WAVEHDR structure.
  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

