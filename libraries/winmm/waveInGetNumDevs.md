[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveInGetNumDevs
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
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
This function takes no parameters.  
***  


## Return value:
Returns the number of devices. A return value of zero means that no devices are present or that an error occurred.  
***  

