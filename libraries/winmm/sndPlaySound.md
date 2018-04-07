[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : sndPlaySound
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The sndPlaySound function plays a waveform sound specified either by a filename or by an entry in the registry or the WIN.INI file. 
***  


## Code examples:
[How to play a waveform sound (a WAV file in particular)](../../samples/sample_251.md)  
[WAV file recorder](../../samples/sample_421.md)  

## Declaration:
```foxpro  
BOOL sndPlaySound(
  LPCSTR lpszSound,
  UINT fuSound
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER sndPlaySound IN winmm;
	STRING  lpszSound,;
	INTEGER fuSound  
```  
***  


## Parameters:
lpszSound 
A string that specifies the sound to play. 

fuSound 
Flags for playing the sound.   
***  


## Return value:
Returns TRUE if successful or FALSE otherwise.  
***  


## Comments:
This function offers a subset of the functionality of the PlaySound function; sndPlaySound is being maintained for backward compatibility.   
The PlaySound plays sound specified either by a file name, or by an entry in the registry, or by a <Em>resource identifier</Em>.  
  
MSDN: the <Em>lpszSound</Em> parameter can be either an entry in the registry or in WIN.INI that identifies a system sound, or it can be the name of a waveform-audio file.   
  
If the function does not find the entry, the parameter is treated as a filename. If this parameter is NULL, any currently playing sound is stopped.   
  
See also: [PlaySound](../winmm/PlaySound.md).  
  
***  

