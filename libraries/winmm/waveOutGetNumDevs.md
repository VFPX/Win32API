[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveOutGetNumDevs
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
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
This function takes no parameters.  
***  


## Return value:
Returns the number of devices. A return value of zero means that no devices are present or that an error occurred.  
***  

