<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mixerOpen
Group: Windows Multimedia - Library: winmm    
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
```txt  
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
  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

