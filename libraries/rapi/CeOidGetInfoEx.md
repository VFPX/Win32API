<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeOidGetInfoEx
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function retrieves information about an object in the object store or a mounted database volume. 
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the Object Store Databases](../../samples/sample_445.md)  

## Declaration:
```foxpro  
BOOL CeOidGetInfoEx(
  PCEGUID pceguid,
  CEOID oid,
  CEOIDINFO* poidInfo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeOidGetInfoEx IN rapi;
	STRING  @ pceguid,;
	INTEGER   oid,;
	STRING  @ poidInfo  
```  
***  


## Parameters:
```txt  
pceguid
[in] Pointer to the CEGUID that contains the globally unique identifier of a mounted database.

oid
[in] Identifier of the object for which information is to be retrieved.

poidInfo
[out] Pointer to a CEOIDINFO structure that contains information about the object.  
```  
***  


## Return value:
TRUE indicates success. FALSE indicates failure.  
***  


## Comments:
To get extended error information, call CeGetLastError. CeGetLastError may return ERROR_INVALID_HANDLE if the specified object identifier is invalid.  
  
***  

