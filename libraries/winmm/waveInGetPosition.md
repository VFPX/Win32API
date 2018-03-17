<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveInGetPosition
Group: Windows Multimedia - Library: winmm    
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
```txt  
hwi
Handle to the waveform-audio input device.

pmmt
Pointer to an MMTIME structure.

cbmmt
Size, in bytes, of the MMTIME structure.
  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

