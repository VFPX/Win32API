<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mciGetErrorString
Group: Windows Multimedia - Library: winmm    
***  


#### The mciGetErrorString function retrieves a string that describes the specified MCI error code. 
***  


## Code examples:
[Accessing a CD device (cdaudio) with Multimedia Command Strings](../../samples/sample_279.md)  
[Using Multimedia Command Strings to play MIDI files](../../samples/sample_538.md)  

## Declaration:
```foxpro  
BOOL mciGetErrorString(
  DWORD fdwError,
  LPTSTR lpszErrorText,
  UINT cchErrorText
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mciGetErrorString IN winmm;
	INTEGER   fdwError,;
	STRING  @ lpszErrorText,;
	INTEGER   cchErrorText  
```  
***  


## Parameters:
```txt  
fdwError
Error code returned by the mciSendCommand or mciSendString function.

lpszErrorText
Pointer to a buffer that receives a null-terminated string describing the specified error.

cchErrorText
Length of the buffer, in characters, pointed to by the lpszErrorText parameter.  
```  
***  


## Return value:
Returns TRUE if successful or FALSE if the error code is not known.  
***  

