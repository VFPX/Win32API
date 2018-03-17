<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveOutGetErrorText
Group: Windows Multimedia - Library: winmm    
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
```txt  
mmrError
Error number.

pszText
Pointer to a buffer to be filled with the textual error description.

cchText
Size, in characters, of the buffer pointed to by pszText.  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

