<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mixerClose
Group: Windows Multimedia - Library: winmm    
***  


#### The mixerClose function closes the specified mixer device.
***  


## Code examples:
[Quering Audio Mixer Device](../../samples/sample_423.md)  

## Declaration:
```foxpro  
MMRESULT mixerClose(
  HMIXER hmx
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mixerClose IN winmm;
	INTEGER hmx  
```  
***  


## Parameters:
```txt  
hmx
Handle to the mixer device.

  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR if successful or an error otherwise.e.  
***  

