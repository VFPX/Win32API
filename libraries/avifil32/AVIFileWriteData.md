[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AVIFileWriteData
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [avifil32](../../Libraries.md#avifil32)  
***  


#### Writes supplementary data (other than normal header, format, and stream data) to the file.

***  


## Code examples:
[Adding supplementary data to AVI files](../../samples/sample_481.md)  

## Declaration:
```foxpro  
STDAPI AVIFileWriteData(
	PAVIFILE pfile,
	DWORD ckid,
	LPVOID lpData,
	LONG cbData
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AVIFileWriteData IN avifil32;
	INTEGER  pfile,;
	LONG     ckid,;
	STRING @ lpData,;
	LONG     cbData
  
```  
***  


## Parameters:
pfile
Handle to an open AVI file.

ckid
RIFF chunk identifier (four-character code) of the data.

lpData
Pointer to the buffer used to write the data.

cbData
Size, in bytes, of the memory block referenced by lpData.
  
***  


## Return value:
Returns zero if successful or an error otherwise.  
***  


## Comments:
Use the AVIStreamWriteData function to write data that applies to an individual stream.  
  
***  

