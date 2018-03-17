<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveInGetNumDevs
Group: Windows Multimedia - Library: winmm    
***  


#### The waveInGetNumDevs function returns the number of waveform-audio input devices present in the system.
***  


## Code examples:
[Quering a waveform-audio input device](../../samples/sample_366.md)  

## Declaration:
```foxpro  
UINT waveInGetNumDevs(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveInGetNumDevs IN winmm  
```  
***  


## Parameters:
```txt  
This function takes no parameters.  
```  
***  


## Return value:
Returns the number of devices. A return value of zero means that no devices are present or that an error occurred.  
***  

