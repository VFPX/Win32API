[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mixerGetControlDetails
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
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
hmxobj
Handle to the mixer device object being queried.

pmxcd
Pointer to a MIXERCONTROLDETAILS structure, which is filled with state information about the control. 

fdwDetails
Flags for retrieving control details. 
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
All members of the MIXERCONTROLDETAILS structure must be initialized before calling this function.  
  
See also: [mixerSetControlDetails](../winmm/mixerSetControlDetails.md).  
  
***  

