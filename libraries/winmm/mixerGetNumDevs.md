[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mixerGetNumDevs
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The mixerGetNumDevs function retrieves the number of mixer devices present in the system.
***  


## Code examples:
[Quering Audio Mixer Device](../../samples/sample_423.md)  

## Declaration:
```foxpro  
UINT mixerGetNumDevs(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mixerGetNumDevs IN winmm  
```  
***  


## Parameters:
This function takes no parameters.  
***  


## Return value:
Returns the number of mixer devices or zero if no mixer devices are available.  
***  

