[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mixerGetID
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### Retrieves the device identifier for a mixer device associated with a specified device handle.
***  


## Declaration:
```foxpro  
MMRESULT mixerGetID(
	HMIXEROBJ  hmxobj,
	UINT FAR * puMxId,
	DWORD      fdwId
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mixerGetID IN winmm;
	INTEGER   hmxobj,;
	INTEGER @ puMxId,;
	INTEGER   fdwId
  
```  
***  


## Parameters:
hmxobj
Handle to the audio mixer object to map to a mixer device identifier.

puMxId
Pointer to a variable that receives the mixer device identifier. 

fdwId
Flags for mapping the mixer object hmxobj.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

