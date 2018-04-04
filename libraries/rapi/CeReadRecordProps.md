[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeReadRecordProps
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function reads properties from the current record.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the Object Store Databases](../../samples/sample_445.md)  

## Declaration:
```foxpro  
CEOID CeReadRecordProps(
  HANDLE hDbase,
  DWORD dwFlags,
  LPWORD lpcPropID,
  CEPROPID* rgPropID,
  LPBYTE* lplpBuffer,
  LPDWORD lpcbBuffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeReadRecordProps IN rapi;
	INTEGER   hDbase,;
	INTEGER   dwFlags,;
	INTEGER @ lpcPropID,;
	INTEGER   rgPropID,;
	INTEGER @ lplpBuffer,;
	INTEGER @ lpcbBuffer
  
```  
***  


## Parameters:
hDbase 
[in] Handle to an open database. The database must have been opened by a previous call to the CeOpenDatabase (RAPI) function.

dwFlags 
[in] Specifies a bitmask of read flags.

lpcPropID 
[in/out] Pointer to the number of property identifiers in the array specified by the rgPropID parameter. If rgPropID is NULL, this parameter receives the number of properties retrieved. 

rgPropID 
[in] Pointer to an array of property identifiers for the properties to be retrieved. If this parameter is NULL, CeReadRecordProps (RAPI) retrieves all properties in the record.

lplpBuffer 
[out] Pointer to a long pointer to a buffer that receives the requested properties.

lpcbBuffer 
[out] Long pointer to a variable that contains the size, in bytes, of the buffer specified by the lplpBuffer parameter.  
***  


## Return value:
The object identifier of the record from which the function read indicates success.  
***  


## Comments:
IF <Em>dwFlags</Em> parameter is set to CEDB_ALLOWREALLOC with <Em>lplpBuffer</Em> set to zero, the LocalAlloc function is used by the server behind the scene to allocate the buffer.  
  
***  

