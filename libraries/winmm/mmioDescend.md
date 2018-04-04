[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mmioDescend
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The mmioDescend function descends into a chunk of a RIFF file that was opened by using the mmioOpen function. It can also search for a given chunk.
***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  
[Class for sound recording](../../samples/sample_420.md)  
[Changing pitch and speed of a wave file](../../samples/sample_422.md)  
[Adding supplementary data to AVI files](../../samples/sample_481.md)  
[Playing WAV sounds simultaneously](../../samples/sample_523.md)  

## Declaration:
```foxpro  
MMRESULT mmioDescend(
  HMMIO hmmio,
  LPMMCKINFO lpck,
  LPMMCKINFO lpckParent,
  UINT wFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mmioDescend IN winmm;
	INTEGER   hmmio,;
	STRING  @ lpck,;
	STRING  @ lpckParent,;
	INTEGER   wFlags
  
```  
***  


## Parameters:
hmmio 
File handle of an open RIFF file. 

lpck 
Pointer to a buffer that receives an MMCKINFO structure. 

lpckParent 
Pointer to an optional application-defined MMCKINFO structure identifying the parent of the chunk being searched for.

wFlags 
Search flags.  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
The mmioDescend function fills the MMCKINFO structure pointed to by the lpck parameter.  
  
***  

