<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveInStart
Group: Windows Multimedia - Library: winmm    
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
```txt  
hwi
Handle to the waveform-audio input device.
  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0)  if successful or an error otherwise.  
***  

