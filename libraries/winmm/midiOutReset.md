<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : midiOutReset
Group: Windows Multimedia - Library: winmm    
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
```txt  
hmo
Handle to the MIDI output device. This parameter can also be the handle of a MIDI stream cast to HMIDIOUT.
  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
See also: midiOutOpen, midiOutClose   
  
***  

