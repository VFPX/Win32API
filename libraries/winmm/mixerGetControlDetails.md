<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mixerGetControlDetails
Group: Windows Multimedia - Library: winmm    
***  


#### Retrieves details about a single control associated with an audio line.
***  


## Declaration:
```foxpro  
MMRESULT mixerGetControlDetails(
	HMIXEROBJ hmxobj,
	LPMIXERCONTROLDETAILS pmxcd,
	DWORD fdwDetails
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mixerGetControlDetails IN winmm;
	INTEGER  hmxobj,;
	STRING @ pmxcd,;
	INTEGER  fdwDetails
  
```  
***  


## Parameters:
```txt  
hmxobj
Handle to the mixer device object being queried.

pmxcd
Pointer to a MIXERCONTROLDETAILS structure, which is filled with state information about the control.

fdwDetails
Flags for retrieving control details.
  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
All members of the MIXERCONTROLDETAILS structure must be initialized before calling this function.  
  
See also: mixerSetControlDetails.  
  
***  

