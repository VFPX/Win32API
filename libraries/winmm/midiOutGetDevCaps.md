<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : midiOutGetDevCaps
Group: Windows Multimedia - Library: winmm    
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
```txt  
uDeviceID
Identifier of the MIDI output device. The device identifier specified by this parameter varies from zero to one less than the number of devices present. The MIDI_MAPPER constant is also a valid device identifier.

lpMidiOutCaps
Pointer to a MIDIOUTCAPS structure.

cbMidiOutCaps
Size, in bytes, of the MIDIOUTCAPS structure.
  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

