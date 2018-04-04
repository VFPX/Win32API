[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mciGetErrorString
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
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
fdwError 
Error code returned by the mciSendCommand or mciSendString function. 

lpszErrorText 
Pointer to a buffer that receives a null-terminated string describing the specified error. 

cchErrorText 
Length of the buffer, in characters, pointed to by the lpszErrorText parameter.   
***  


## Return value:
Returns TRUE if successful or FALSE if the error code is not known.  
***  

