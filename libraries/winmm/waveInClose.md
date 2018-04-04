[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveInClose
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The waveInClose function closes the given waveform-audio input device.
***  


## Code examples:
[Quering a waveform-audio input device](../../samples/sample_366.md)  
[Class for sound recording](../../samples/sample_420.md)  

## Declaration:
```foxpro  
MMRESULT waveInClose(
  HWAVEIN hwi
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveInClose IN winmm;
	INTEGER hwi  
```  
***  


## Parameters:
hwi 
Handle to the waveform-audio input device. If the function succeeds, the handle is no longer valid after this call.   
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
If there are input buffers that have been sent with the waveInAddBuffer function and that haven"t been returned to the application, the close operation will fail. Call the waveInReset function to mark all pending buffers as done.  
  
***  

