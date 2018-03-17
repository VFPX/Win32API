<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveOutGetNumDevs
Group: Windows Multimedia - Library: winmm    
***  


#### Retrieves the number of waveform-audio output devices present in the system.
***  


## Code examples:
[Quering waveform-audio output devices](../../samples/sample_393.md)  

## Declaration:
```foxpro  
UINT waveOutGetNumDevs(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveOutGetNumDevs IN winmm  
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

