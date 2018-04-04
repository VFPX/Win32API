[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveInStart
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The waveInStart function starts input on the given waveform-audio input device.
***  


## Code examples:
[Class for sound recording](../../samples/sample_420.md)  

## Declaration:
```foxpro  
MMRESULT waveInStart(
  HWAVEIN hwi
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveInStart IN winmm;
	INTEGER hwi  
```  
***  


## Parameters:
hwi
Handle to the waveform-audio input device.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0)  if successful or an error otherwise.  
***  

