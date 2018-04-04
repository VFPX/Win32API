[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveInGetErrorText
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The waveInGetErrorText function retrieves a textual description of the error identified by the given error number.
***  


## Code examples:
[Quering a waveform-audio input device](../../samples/sample_366.md)  
[Class for sound recording](../../samples/sample_420.md)  

## Declaration:
```foxpro  
MMRESULT waveInGetErrorText(
  MMRESULT mmrError,
  LPSTR pszText,
  UINT cchText
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveInGetErrorText IN winmm;
	INTEGER   mmrError,;
	STRING  @ pszText,;
	LONG      cchText
  
```  
***  


## Parameters:
mmrError 
Error number. 

pszText 
Pointer to the buffer to be filled with the textual error description. 

cchText 
Size, in characters, of the buffer pointed to by pszText.   
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

