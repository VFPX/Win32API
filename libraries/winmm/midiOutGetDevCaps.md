[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : midiOutGetDevCaps
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### Queries a specified MIDI output device to determine its capabilities.

***  


## Code examples:
[Enumerating MIDI output devices](../../samples/sample_507.md)  

## Declaration:
```foxpro  
MMRESULT midiOutGetDevCaps(
  UINT_PTR      uDeviceID,
  LPMIDIOUTCAPS lpMidiOutCaps,
  UINT          cbMidiOutCaps
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER midiOutGetDevCaps IN Winmm;
	INTEGER uDeviceID,;
	STRING @lpMidiOutCaps,;
	INTEGER cbMidiOutCaps  
```  
***  


## Parameters:
uDeviceID
Identifier of the MIDI output device. The device identifier specified by this parameter varies from zero to one less than the number of devices present. The MIDI_MAPPER constant is also a valid device identifier.

lpMidiOutCaps
Pointer to a MIDIOUTCAPS structure. 

cbMidiOutCaps
Size, in bytes, of the MIDIOUTCAPS structure.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

