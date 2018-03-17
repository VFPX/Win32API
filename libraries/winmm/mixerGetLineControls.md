<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mixerGetLineControls
Group: Windows Multimedia - Library: winmm    
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
```txt  
hmxobj
Handle to the mixer device object that is being queried.

pmxlc
Pointer to a MIXERLINECONTROLS structure.

fdwControls
Flags for retrieving information about one or more controls associated with an audio line.
  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR if successful or an error otherwise.  
***  

