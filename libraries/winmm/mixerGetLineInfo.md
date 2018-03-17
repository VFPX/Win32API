<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mixerGetLineInfo
Group: Windows Multimedia - Library: winmm    
***  


#### The mixerGetLineInfo function retrieves information about a specific line of a mixer device.
***  


## Code examples:
[Quering Audio Mixer Device](../../samples/sample_423.md)  

## Declaration:
```foxpro  
MMRESULT mixerGetLineInfo(
  HMIXEROBJ hmxobj,
  LPMIXERLINE pmxl,
  DWORD fdwInfo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mixerGetLineInfo IN winmm;
	INTEGER   hmxobj,;
	STRING  @ pmxl,;
	INTEGER   fdwInfo
  
```  
***  


## Parameters:
```txt  
hmxobj
Handle to the mixer device object that controls the specific audio line.

pmxl
Pointer to a MIXERLINE structure.

fdwInfo
Flags for retrieving information about an audio line.
  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR if successful or an error otherwise.  
***  

