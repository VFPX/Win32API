[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mmioAscend
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The mmioAscend function ascends out of a chunk in a RIFF file descended into with the mmioDescend function or created with the mmioCreateChunk function.
***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  
[Class for sound recording](../../samples/sample_420.md)  
[Changing pitch and speed of a wave file](../../samples/sample_422.md)  
[Adding supplementary data to AVI files](../../samples/sample_481.md)  
[Playing WAV sounds simultaneously](../../samples/sample_523.md)  

## Declaration:
```foxpro  
MMRESULT mmioAscend(
  HMMIO hmmio,
  LPMMCKINFO lpck,
  UINT wFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mmioAscend IN winmm;
	INTEGER   hmmio,;
	STRING  @ lpck,;
	INTEGER   wFlags
  
```  
***  


## Parameters:
hmmio 
File handle of an open RIFF file. 

lpck 
Pointer to an application-defined MMCKINFO structure previously filled by the mmioDescend or mmioCreateChunk function. 

wFlags 
Reserved; must be zero.   
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
If the chunk was descended into by using mmioDescend, mmioAscend seeks to the location following the end of the chunk (past the extra pad byte, if any).  
  
***  

