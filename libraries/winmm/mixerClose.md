[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mixerClose
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
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
hmx
Handle to the mixer device.

  
***  


## Return value:
Returns MMSYSERR_NOERROR if successful or an error otherwise.e.  
***  

