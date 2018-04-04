[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateStreamOnHGlobal
Group: [COM](../../functions_group.md#COM)  -  Library: [ole32](../../Libraries.md#ole32)  
***  


#### The CreateStreamOnHGlobal function creates a stream object stored in global memory.
***  


## Declaration:
```foxpro  
WINOLEAPI CreateStreamOnHGlobal(
  HGLOBAL hGlobal,
  BOOL fDeleteOnRelease,
  LPSTREAM* ppstm
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateStreamOnHGlobal IN ole32;
	INTEGER   hGlobal,;
	INTEGER   fDeleteOnRelease,;
	INTEGER @ ppstm
  
```  
***  


## Parameters:
hGlobal 
[in] Memory handle allocated by the GlobalAlloc function. The handle must be allocated as movable and nondiscardable.

fDeleteOnRelease 
[in] Whether the underlying handle for this stream object should be automatically freed when the stream object is released. If set to FALSE, the caller must free the hGlobal after the final release.

ppstm 
[out] Address of IStream* pointer variable that receives the interface pointer to the new stream object. Its value cannot be NULL.   
***  


## Return value:
Returns S_OK (0) if the stream object was created successfully.  
***  

