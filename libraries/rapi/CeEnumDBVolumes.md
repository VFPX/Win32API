[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeEnumDBVolumes
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
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
pceguid 
[in] To begin enumeration, set this parameter to the value returned by CREATE_INVALIDGUID. 

lpBuf 
[out] Pointer to the allocated buffer that receives the database volume names. 

dwNumChars 
[in] Specifies the length, in characters, of the buffer.   
***  


## Return value:
TRUE indicates success. FALSE indicates failure.  
***  

