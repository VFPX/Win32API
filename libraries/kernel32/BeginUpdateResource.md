<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : BeginUpdateResource
Group: Resource - Library: kernel32    
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
```txt  
pFileName
[in] Pointer to a null-terminated string that specifies the executable file in which to update resources.

bDeleteExistingResources
[in] Specifies whether to delete the pFileName parameter"s existing resources.  
```  
***  


## Return value:
If the function succeeds, the return value is a handle that can be used by the UpdateResource and EndUpdateResource functions.  
***  


## Comments:
An application must be able to obtain write access to the executable file; <Em>it cannot be currently executing</Em>. If <Strong>pFileName</Strong> does not specify a full path, the system searches for the file in the current directory.   
  
***  

