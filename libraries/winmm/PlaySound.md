[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PlaySound
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### Plays a sound specified by the given file name, resource, or system event.
***  


## Code examples:
[Playing WAV files on InteractiveChange](../../samples/sample_594.md)  

## Declaration:
```foxpro  
BOOL PlaySound(
	LPCTSTR pszSound,
	HMODULE hmod,
	DWORD fdwSound
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PlaySound IN winmm;
	STRING pszSound,;
	INTEGER hmod,;
	LONG fdwSound  
```  
***  


## Parameters:
pszSound
A string that specifies the sound to play. The maximum length, including the null terminator, is 256 characters. 

hmod
Handle to the executable file that contains the resource to be loaded. This parameter must be NULL unless SND_RESOURCE is specified in fdwSound.

fdwSound
Flags for playing the sound.
  
***  


## Return value:
Returns TRUE if successful or FALSE otherwise.  
***  


## Comments:
For playing system sounds rather than sounds stored in WAV files, it is better to declare this function as follows:  
```foxpro
DECLARE INTEGER PlaySound IN winmm;  
	LONG pszSound, INTEGER hmod, LONG fdwSound
```
Below is FoxPro equivalent to sndAlias("S", "W") macro (SND_ALIAS_SYSTEMWELCOME) :  

```foxpro
nSoundId = BITOR(buf2dword(PADR("S",4,CHR(0))),;  
	BITLSHIFT(buf2dword(PADR("W",4,CHR(0))),8)) && returns 22355
```
This will play the SND_ALIAS_SYSTEMWELCOME sound:  
```foxpro
= PlaySound(22355, 0, BITOR(SND_ALIAS_ID, SND_ASYNC))
```
See also: [sndPlaySound](../winmm/sndPlaySound.md).  
  
***  

