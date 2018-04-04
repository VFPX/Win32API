[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mmioCreateChunk
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The mmioCreateChunk function creates a chunk in a RIFF file that was opened by using the mmioOpen function.
***  


## Code examples:
[Class for sound recording](../../samples/sample_420.md)  
[Changing pitch and speed of a wave file](../../samples/sample_422.md)  
[Adding supplementary data to AVI files](../../samples/sample_481.md)  

## Declaration:
```foxpro  
MMRESULT mmioCreateChunk(
  HMMIO hmmio,
  LPMMCKINFO lpck,
  UINT wFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mmioCreateChunk IN winmm;
	INTEGER   hmmio,;
	STRING  @ lpck,;
	INTEGER   wFlags
  
```  
***  


## Parameters:
hmmio
File handle of an open RIFF file.

lpck
Pointer to a buffer that receives a MMCKINFO structure containing information about the chunk to be created. 

wFlags
Flags identifying what type of chunk to create.
  
***  


## Return value:
Returns MMSYSERR_NOERROR (0) if successful or an error otherwise.  
***  


## Comments:
The new chunk is created at the current file position. After the new chunk is created, the current file position is the beginning of the data portion of the new chunk.  
  
***  

