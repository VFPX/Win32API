[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : midiOutShortMsg
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  

#### Sends a short MIDI message to the specified MIDI output device.
***  


## Code examples:
[How to play MIDI notes](../../samples/sample_537.md)  

## Declaration:
```foxpro  
MMRESULT midiOutShortMsg(
	HMIDIOUT hmo,
	DWORD dwMsg
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER midiOutShortMsg IN Winmm;
	INTEGER hmo,;
	LONG dwMsg  
```  
***  


## Parameters:
hmo
Handle to the MIDI output device. This parameter can also be the handle of a MIDI stream cast to HMIDIOUT.

dwMsg
MIDI message. The message is packed into a DWORD value.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
A MIDI output device must be open prior to calling this function.  
  
Read about [MIDI messages](https://www.midi.org/articles/about-midi-part-3-midi-messages&highlight=WyJtaWRpIiwibWlkaSdzIiwibWlkaXMiLCJtaWRpZWQiLCJtaWRpJ2VkIiwiJ21pZGknLCIsIidtaWRpIiwiJ21pZGknIiwibWVzc2FnZXMiLCJtZXNzYWdlIiwibWVzc2FnaW5nIiwibWlkaSBtZXNzYWdlcyJd) (second parameter in the call) on MIDI.org.  
  
See also: [midiOutOpen](../winmm/midiOutOpen.md).  
  
***  

