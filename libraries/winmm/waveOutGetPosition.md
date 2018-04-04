[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveOutGetPosition
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
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
hwo 
Handle to the waveform-audio output device. 

pmmt 
Pointer to an MMTIME structure. 

cbmmt 
Size, in bytes, of the MMTIME structure.  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
Before calling this function, set the wType member of the MMTIME structure to indicate the time format you want. After calling this function, check wType to determine whether the time format is supported. If the format is not supported, wType will specify an alternative format.  
  
The position is set to zero when the device is opened or reset.  
  
***  

