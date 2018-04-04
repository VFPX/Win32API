[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : Beep
Group: [Error Handling](../../functions_group.md#Error_Handling)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Generates simple tones on the speaker. The function is synchronous; it does not return control to its caller until the sound finishes.
***  


## Code examples:
[Using Beep and Sleep functions to make the old tin <s>buzz</s> sing (WinNT only?)](../../samples/sample_240.md)  
[Controlling master audio volume by sending WM_APPCOMMAND messages](../../samples/sample_592.md)  

## Declaration:
```foxpro  
BOOL Beep(
  DWORD dwFreq,      // sound frequency
  DWORD dwDuration   // sound duration
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER Beep IN kernel32;
	INTEGER dwFreq,;
	INTEGER dwDuration
  
```  
***  


## Parameters:
dwFreq 
[in] Specifies the frequency, in hertz, of the sound. 

dwDuration 
[in] Specifies the duration, in milliseconds, of the sound.   
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  


## Comments:
Windows 95/98/Me: On computers with a sound card, the function plays the default sound event. On computers without a sound card, the function plays the standard system beep. I"ve never seen such computer in years.  
  
***  

