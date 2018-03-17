<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WNetEnumResource
Group: Windows Networking - Library: mpr    
***  


#### The WNetEnumResource function continues an enumeration of network resources that was started by a call to the WNetOpenEnum function. 
***  


## Code examples:
[Enumerating network resources](../../samples/sample_313.md)  

## Declaration:
```foxpro  
DWORD WNetEnumResource(
  HANDLE hEnum,          // handle to enumeration
  LPDWORD lpcCount,      // entries to list
  LPVOID lpBuffer,       // buffer
  LPDWORD lpBufferSize   // buffer size
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WNetEnumResource IN mpr;
	INTEGER   hEnum,;
	INTEGER @ lpcCount,;
	STRING  @ lpBuffer,;
	INTEGER @ lpBufferSize  
```  
***  


## Parameters:
```txt  
hEnum
[in] Specifies a handle that identifies an enumeration instance. This handle must be returned by the WNetOpenEnum function.

lpcCount
[in/out] Pointer to a variable specifying the number of entries requested. If the number requested is –1, the function returns as many entries as possible.

lpBuffer
[out] Pointer to the buffer that receives the enumeration results. The results are returned as an array of NETRESOURCE structures.

lpBufferSize
[in/out] Pointer to a variable that specifies the size, in bytes, of the lpBuffer parameter.  
```  
***  


## Return value:
If the function succeeds, the return value is one of the following values: NO_ERROR, ERROR_NO_MORE_ITEMS.  
***  

