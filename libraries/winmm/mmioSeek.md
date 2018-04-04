[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mmioSeek
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### Changes the current file position in a file opened by using the mmioOpen function. 
***  


## Declaration:
```foxpro  
LONG mmioSeek(
	HMMIO hmmio,
	LONG lOffset,
	int iOrigin
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mmioSeek IN winmm;
	INTEGER hmmio,;
	LONG    lOffset,;
	INTEGER iOrigin
  
```  
***  


## Parameters:
hmmio
File handle of the file to seek in.

lOffset
Offset to change the file position.

iOrigin
Flags indicating how the offset specified by lOffset is interpreted.
  
***  


## Return value:
Returns the new file position, in bytes, relative to the beginning of the file. If there is an error, the return value is - 1.  
***  


## Comments:
#DEFINE SEEK_CUR 1  
#DEFINE SEEK_END 2  
#DEFINE SEEK_SET 0  
  
***  

