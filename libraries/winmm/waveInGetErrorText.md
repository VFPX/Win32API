<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : waveInGetErrorText
Group: Windows Multimedia - Library: winmm    
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
```txt  
mmrError
Error number.

pszText
Pointer to the buffer to be filled with the textual error description.

cchText
Size, in characters, of the buffer pointed to by pszText.  
```  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  

