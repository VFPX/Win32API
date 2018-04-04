[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mixerGetLineControls
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The mixerGetLineControls function retrieves one or more controls associated with an audio line.
***  


## Code examples:
[Quering Audio Mixer Device](../../samples/sample_423.md)  

## Declaration:
```foxpro  
MMRESULT mixerGetLineControls(
  HMIXEROBJ hmxobj,
  LPMIXERLINECONTROLS pmxlc,
  DWORD fdwControls
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mixerGetLineControls IN winmm;
	INTEGER   hmxobj,;
	STRING  @ pmxlc,;
	INTEGER   fdwControls
  
```  
***  


## Parameters:
hmxobj
Handle to the mixer device object that is being queried.

pmxlc
Pointer to a MIXERLINECONTROLS structure.

fdwControls
Flags for retrieving information about one or more controls associated with an audio line.
  
***  


## Return value:
Returns MMSYSERR_NOERROR if successful or an error otherwise.  
***  

