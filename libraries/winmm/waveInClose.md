<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveInClose
Group: Windows Multimedia - Library: winmm    
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
```txt  
hwi
Handle to the waveform-audio input device. If the function succeeds, the handle is no longer valid after this call.  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
If there are input buffers that have been sent with the waveInAddBuffer function and that haven"t been returned to the application, the close operation will fail. Call the waveInReset function to mark all pending buffers as done.  
  
***  

