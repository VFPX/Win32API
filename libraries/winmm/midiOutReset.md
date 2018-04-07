[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : midiOutReset
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### Turns off all notes on all MIDI channels for the specified MIDI output device.
***  


## Code examples:
[How to play MIDI notes](../../samples/sample_537.md)  

## Declaration:
```foxpro  
MMRESULT midiOutReset(
	HMIDIOUT hmo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER midiOutReset IN Winmm;
	INTEGER hmo  
```  
***  


## Parameters:
hmo
Handle to the MIDI output device. This parameter can also be the handle of a MIDI stream cast to HMIDIOUT.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
See also: [midiOutOpen](../winmm/midiOutOpen.md), [midiOutClose](../winmm/midiOutClose.md).  
  
***  

