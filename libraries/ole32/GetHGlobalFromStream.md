<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetHGlobalFromStream
Group: COM - Library: ole32    
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
```txt  
pstm
[in] IStream pointer to the stream object previously created by a call to the CreateStreamOnHGlobal function.

phglobal
[out] Pointer to the current memory handle used by the specified stream object.  
```  
***  


## Return value:
S_OK indicates that the handle was successfully returned.   
***  

