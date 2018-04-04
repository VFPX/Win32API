[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mmioClose
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The mmioClose function closes a file that was opened by using the mmioOpen function.
***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  
[Class for sound recording](../../samples/sample_420.md)  
[Changing pitch and speed of a wave file](../../samples/sample_422.md)  
[Adding supplementary data to AVI files](../../samples/sample_481.md)  
[Playing WAV sounds simultaneously](../../samples/sample_523.md)  

## Declaration:
```foxpro  
MMRESULT mmioClose(
  HMMIO hmmio,
  UINT wFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mmioClose IN winmm;
	INTEGER hmmio,;
	INTEGER wFlags  
```  
***  


## Parameters:
hmmio 
File handle of the file to close. 

wFlags 
Flags for the close operation.  
***  


## Return value:
Returns zero if successful or an error otherwise.  
***  

