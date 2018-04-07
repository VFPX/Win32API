[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : midiOutOpen
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### Opens a MIDI output device for playback.

***  


## Code examples:
[Enumerating MIDI output devices](../../samples/sample_507.md)  
[How to play MIDI notes](../../samples/sample_537.md)  

## Declaration:
```foxpro  
MMRESULT midiOutOpen(
  LPHMIDIOUT lphmo,
  UINT_PTR   uDeviceID,
  DWORD_PTR  dwCallback,
  DWORD_PTR  dwCallbackInstance,
  DWORD      dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER midiOutOpen IN Winmm;
	INTEGER @lphmo,;
	INTEGER uDeviceID,;
	INTEGER dwCallback,;
	INTEGER dwCallbackInstance,;
	INTEGER dwFlags
  
```  
***  


## Parameters:
lphmo
Pointer to an HMIDIOUT handle. This location is filled with a handle identifying the opened MIDI output device. The handle is used to identify the device in calls to other MIDI output functions.

uDeviceID
Identifier of the MIDI output device that is to be opened.

dwCallback
Pointer to a callback function, an event handle, a thread identifier, or a handle of a window or thread called during MIDI playback to process messages related to the progress of the playback. 

dwCallbackInstance
User instance data passed to the callback. This parameter is not used with window callbacks or threads.

dwFlags
Callback flag for opening the device. It can be the following values.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
See also: [midiOutGetNumDevs](../winmm/midiOutGetNumDevs.md), [midiOutClose](../winmm/midiOutClose.md).  
  
***  

