<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveOutGetPosition
Group: Windows Multimedia - Library: winmm    
***  


#### The waveOutGetPosition function retrieves the current playback position of the given waveform-audio output device.

***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  

## Declaration:
```foxpro  
MMRESULT waveOutGetPosition(
  HWAVEOUT hwo,
  LPMMTIME pmmt,
  UINT cbmmt
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG waveOutGetPosition IN winmm;
	INTEGER   hwi,;
	STRING  @ pmmt,;
	INTEGER   cbmmt
  
```  
***  


## Parameters:
```txt  
hwo
Handle to the waveform-audio output device.

pmmt
Pointer to an MMTIME structure.

cbmmt
Size, in bytes, of the MMTIME structure.  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
Before calling this function, set the wType member of the MMTIME structure to indicate the time format you want. After calling this function, check wType to determine whether the time format is supported. If the format is not supported, wType will specify an alternative format.  
  
The position is set to zero when the device is opened or reset.  
  
***  

