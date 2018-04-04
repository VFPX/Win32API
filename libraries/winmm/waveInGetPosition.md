[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveInGetPosition
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The waveInGetPosition function retrieves the current input position of the given waveform-audio input device.
***  


## Code examples:
[Class for sound recording](../../samples/sample_420.md)  

## Declaration:
```foxpro  
MMRESULT waveInGetPosition(
  HWAVEIN hwi,
  LPMMTIME pmmt,
  UINT cbmmt
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveInGetPosition IN winmm;
	INTEGER   hwi,;
	STRING  @ pmmt,;
	LONG      cbmmt  
```  
***  


## Parameters:
hwi
Handle to the waveform-audio input device.

pmmt
Pointer to an MMTIME structure.

cbmmt
Size, in bytes, of the MMTIME structure.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

