[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mixerOpen
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The mixerOpen function opens a specified mixer device and ensures that the device will not be removed until the application closes the handle.
***  


## Code examples:
[Quering Audio Mixer Device](../../samples/sample_423.md)  

## Declaration:
```foxpro  
MMRESULT mixerOpen(
  LPHMIXER  phmx,
  UINT      uMxId,
  DWORD_PTR dwCallback,
  DWORD_PTR dwInstance,
  DWORD     fdwOpen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mixerOpen IN winmm;
	INTEGER @ phmx,;
	INTEGER   uMxId,;
	INTEGER   dwCallback,;
	INTEGER   dwInstance,;
	INTEGER   fdwOpen
  
```  
***  


## Parameters:
phmx
Pointer to a variable that will receive a handle identifying the opened mixer device.

uMxId
Identifier of the mixer device to open.

dwCallback
Handle to a window called when the state of an audio line and/or control associated with the device being opened is changed. 

dwInstance
User instance data passed to the callback function.

fdwOpen
Flags for opening the device.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

