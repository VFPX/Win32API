[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : timeGetDevCaps
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### Queries the timer device to determine its resolution.
***  


## Declaration:
```foxpro  
MMRESULT timeGetDevCaps(
  LPTIMECAPS ptc,
  UINT cbtc
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER timeGetDevCaps IN winmm;
	STRING @ptc,;
	LONG cbtc  
```  
***  


## Parameters:
ptc
Pointer to a TIMECAPS structure. This structure is filled with information about the resolution of the timer device.

cbtc
Size, in bytes, of the TIMECAPS structure.
  
***  


## Return value:
Returns TIMERR_NOERROR (0) if successful.  
***  


## Comments:
Normally 1 to 1000,000.  
  
***  

