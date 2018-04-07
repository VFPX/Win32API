[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : midiOutClose
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### Closes the specified MIDI output device.

***  


## Code examples:
[Enumerating MIDI output devices](../../samples/sample_507.md)  
[How to play MIDI notes](../../samples/sample_537.md)  

## Declaration:
```foxpro  
MMRESULT midiOutClose(
  HMIDIOUT hmo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER midiOutClose IN Winmm INTEGER hmo  
```  
***  


## Parameters:
hmo
Handle to the MIDI output device.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
See also: [midiOutOpen](../winmm/midiOutOpen.md), [midiOutReset](../winmm/midiOutReset.md).  
  
***  

