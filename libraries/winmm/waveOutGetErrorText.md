[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : waveOutGetErrorText
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### Retrieves a textual description of the error identified by the given error number.
***  


## Code examples:
[Quering waveform-audio output devices](../../samples/sample_393.md)  

## Declaration:
```foxpro  
MMRESULT waveOutGetErrorText(
  MMRESULT mmrError,
  LPSTR pszText,
  UINT cchText
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER waveOutGetErrorText IN winmm;
	INTEGER   mmrError,;
	STRING  @ pszText,;
	INTEGER   cchText
  
```  
***  


## Parameters:
mmrError 
Error number. 

pszText 
Pointer to a buffer to be filled with the textual error description. 

cchText 
Size, in characters, of the buffer pointed to by pszText.  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

