<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeEnumDBVolumes
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function enumerates all mounted database volumes and returns the name for each. 
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the Object Store Databases](../../samples/sample_445.md)  

## Declaration:
```foxpro  
BOOL CeEnumDBVolumes(
  PCEGUID pceguid,
  LPWSTR lpBuf,
  DWORD dwNumChars
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeEnumDBVolumes IN rapi;
	STRING  @ pceguid,;
	STRING  @ lpBuf,;
	INTEGER   dwNumChars  
```  
***  


## Parameters:
```txt  
pceguid
[in] To begin enumeration, set this parameter to the value returned by CREATE_INVALIDGUID.

lpBuf
[out] Pointer to the allocated buffer that receives the database volume names.

dwNumChars
[in] Specifies the length, in characters, of the buffer.  
```  
***  


## Return value:
TRUE indicates success. FALSE indicates failure.  
***  

