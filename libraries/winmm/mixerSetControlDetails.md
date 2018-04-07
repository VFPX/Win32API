[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mixerSetControlDetails
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
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
hmxobj
Handle to the mixer device object for which properties are being set.

pmxcd
Pointer to a MIXERCONTROLDETAILS structure. This structure is used to reference control detail structures that contain the desired state for the control. 

fdwDetails
Flags for setting properties for a control.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
All members of the MIXERCONTROLDETAILS structure must be initialized before calling mixerSetControlDetails.  
  
See also: [mixerGetControlDetails](../winmm/mixerGetControlDetails.md).  
  
***  

