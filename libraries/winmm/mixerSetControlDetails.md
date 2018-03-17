<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mixerSetControlDetails
Group: Windows Multimedia - Library: winmm    
***  


#### Sets properties of a single control associated with an audio line.
***  


## Declaration:
```foxpro  
MMRESULT mixerSetControlDetails(
	HMIXEROBJ hmxobj,
	LPMIXERCONTROLDETAILS pmxcd,
	DWORD fdwDetails
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mixerSetControlDetails IN winmm;
	INTEGER  hmxobj,;
	STRING @ pmxcd,;
	INTEGER  fdwDetails  
```  
***  


## Parameters:
```txt  
hmxobj
Handle to the mixer device object for which properties are being set.

pmxcd
Pointer to a MIXERCONTROLDETAILS structure. This structure is used to reference control detail structures that contain the desired state for the control.

fdwDetails
Flags for setting properties for a control.
  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
All members of the MIXERCONTROLDETAILS structure must be initialized before calling mixerSetControlDetails.  
  
See also: mixerGetControlDetails.  
  
***  

