<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mmioSeek
Group: Windows Multimedia - Library: winmm    
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
```txt  
hmmio
File handle of the file to seek in.

lOffset
Offset to change the file position.

iOrigin
Flags indicating how the offset specified by lOffset is interpreted.
  
```  
***  


## Return value:
Returns the new file position, in bytes, relative to the beginning of the file. If there is an error, the return value is - 1.  
***  


## Comments:
#DEFINE SEEK_CUR 1  
#DEFINE SEEK_END 2  
#DEFINE SEEK_SET 0  
  
***  

