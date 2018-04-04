[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetPrivateProfileSectionNames
Group: [Registry](../../functions_group.md#Registry)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetPrivateProfileSectionNames function retrieves the names of all sections in an initialization file.
***  


## Code examples:
[Retrieving the names of all sections in an initialization file](../../samples/sample_252.md)  

## Declaration:
```foxpro  
DWORD GetPrivateProfileSectionNames(
  LPTSTR lpszReturnBuffer,  // return buffer
  DWORD nSize,              // size of return buffer
  LPCTSTR lpFileName        // initialization file name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetPrivateProfileSectionNames IN kernel32;
	STRING  @ lpszReturnBuffer,;
	INTEGER   nSize,;
	STRING    lpFileName
  
```  
***  


## Parameters:
lpszReturnBuffer 
[out] Pointer to a buffer that receives the section names associated with the named file. 

nSize 
[in] Specifies the size, in TCHARs, of the buffer pointed to by the lpszReturnBuffer parameter. 

lpFileName 
[in] Pointer to a null-terminated string that specifies the name of the initialization file.   
***  


## Return value:
The return value specifies the number of characters copied to the specified buffer, not including the terminating null character.   
***  


## Comments:
This function is provided only for compatibility with 16-bit Windows-based applications. Applications should store initialization information in the registry.   
  
Calls to profile functions might be mapped to the registry instead of to the initialization files. When the operation has been mapped, the GetPrivateProfileSectionNames function retrieves information from the registry, not from the initialization file; the change in the storage location has no effect on the function"s behavior.   
  
***  

