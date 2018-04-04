[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveInReset
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The waveInReset function stops input on the given waveform-audio input device and resets the current position to zero. All pending buffers are marked as done and returned to the application.
***  


## Code examples:
[Quering a waveform-audio input device](../../samples/sample_366.md)  
[Class for sound recording](../../samples/sample_420.md)  

## Declaration:
```foxpro  
MMRESULT waveInReset(
  HWAVEIN hwi
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveInReset IN winmm;
	INTEGER hwi  
```  
***  


## Parameters:
hwi 
Handle to the waveform-audio input device.  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

