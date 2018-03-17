<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : timeGetDevCaps
Group: Windows Multimedia - Library: winmm    
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
```txt  
ptc
Pointer to a TIMECAPS structure. This structure is filled with information about the resolution of the timer device.

cbtc
Size, in bytes, of the TIMECAPS structure.
  
```  
***  


## Return value:
Returns TIMERR_NOERROR (0) if successful.  
***  


## Comments:
Normally 1 to 1000,000.  
  
***  

