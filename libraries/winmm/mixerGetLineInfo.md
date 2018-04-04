[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mixerGetLineInfo
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
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
hmxobj
Handle to the mixer device object that controls the specific audio line.

pmxl
Pointer to a MIXERLINE structure. 

fdwInfo
Flags for retrieving information about an audio line.
  
***  


## Return value:
Returns MMSYSERR_NOERROR if successful or an error otherwise.  
***  

