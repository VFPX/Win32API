[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetHGlobalFromStream
Group: [COM](../../functions_group.md#COM)  -  Library: [ole32](../../Libraries.md#ole32)  
***  


#### The GetHGlobalFromStream function retrieves the global memory handle to a stream that was created through a call to the CreateStreamOnHGlobal function.
***  


## Declaration:
```foxpro  
WINOLEAPI GetHGlobalFromStream(
  IStream* pstm,
  HGLOBAL* phglobal
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetHGlobalFromStream IN ole32;
	INTEGER   pstm,;
	INTEGER @ phglobal
  
```  
***  


## Parameters:
pstm 
[in] IStream pointer to the stream object previously created by a call to the CreateStreamOnHGlobal function. 

phglobal 
[out] Pointer to the current memory handle used by the specified stream object.   
***  


## Return value:
S_OK indicates that the handle was successfully returned.   
***  

