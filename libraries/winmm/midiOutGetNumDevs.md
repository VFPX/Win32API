[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : midiOutGetNumDevs
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### Retrieves the number of MIDI output devices present in the system.
***  


## Code examples:
[Enumerating MIDI output devices](../../samples/sample_507.md)  
[How to play MIDI notes](../../samples/sample_537.md)  

## Declaration:
```foxpro  
UINT midiOutGetNumDevs(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER midiOutGetNumDevs IN Winmm
  
```  
***  


## Parameters:
This function takes no parameters.  
***  


## Return value:
Returns the number of MIDI output devices. A return value of zero means that there are no devices (not that there is no error).  
***  

