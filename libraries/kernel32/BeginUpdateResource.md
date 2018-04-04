[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : BeginUpdateResource
Group: [Resource](../../functions_group.md#Resource)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The BeginUpdateResource function returns a handle that can be used by the UpdateResource function to add, delete, or replace resources in an executable file.
***  


## Code examples:
[Storing registration key in the resources of an executable file](../../samples/sample_401.md)  

## Declaration:
```foxpro  
HANDLE BeginUpdateResource(
	LPCTSTR pFileName,
	BOOL bDeleteExistingResources
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER BeginUpdateResource IN kernel32;
	STRING pFileName,;
	INTEGER bDeleteExistingResources
  
```  
***  


## Parameters:
pFileName
[in] Pointer to a null-terminated string that specifies the executable file in which to update resources.

bDeleteExistingResources
[in] Specifies whether to delete the pFileName parameter"s existing resources.  
***  


## Return value:
If the function succeeds, the return value is a handle that can be used by the UpdateResource and EndUpdateResource functions.  
***  


## Comments:
An application must be able to obtain write access to the executable file; <Em>it cannot be currently executing</Em>. If <Strong>pFileName</Strong> does not specify a full path, the system searches for the file in the current directory.   
  
***  

