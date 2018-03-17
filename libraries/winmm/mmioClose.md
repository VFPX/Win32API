<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mmioClose
Group: Windows Multimedia - Library: winmm    
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
```txt  
hmmio
File handle of the file to close.

wFlags
Flags for the close operation.  
```  
***  


## Return value:
Returns zero if successful or an error otherwise.  
***  

