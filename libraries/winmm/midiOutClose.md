<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : midiOutClose
Group: Windows Multimedia - Library: winmm    
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
```txt  
hmo
Handle to the MIDI output device.
  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
See also: midiOutOpen, midiOutReset.  
  
***  

