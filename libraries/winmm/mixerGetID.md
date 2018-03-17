<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mixerGetID
Group: Windows Multimedia - Library: winmm    
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
```txt  
hmxobj
Handle to the audio mixer object to map to a mixer device identifier.

puMxId
Pointer to a variable that receives the mixer device identifier.

fdwId
Flags for mapping the mixer object hmxobj.
  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

