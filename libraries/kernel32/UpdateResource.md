[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UpdateResource
Group: [Resource](../../functions_group.md#Resource)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The UpdateResource function adds, deletes, or replaces a resource in an executable file.
***  


## Code examples:
[Storing registration key in the resources of an executable file](../../samples/sample_401.md)  

## Declaration:
```foxpro  
BOOL UpdateResource(
	HANDLE hUpdate,
	LPCTSTR lpType,
	LPCTSTR lpName,
	WORD wLanguage,
	LPVOID lpData,
	DWORD cbData
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UpdateResource IN kernel32;
	INTEGER hUpdate,;
	INTEGER lpType,;
	INTEGER lpName,;
	INTEGER wLanguage,;
	STRING  lpData,;
	INTEGER cbData
  
```  
***  


## Parameters:
hUpdate
[in] Specifies an update-file handle. This handle is returned by the BeginUpdateResource function. 

lpType
[in] Pointer to a null-terminated string specifying the resource type to be updated. 

lpName
[in] Pointer to a null-terminated string specifying the name of the resource to be updated. 

wLanguage
[in] Specifies the language identifier of the resource to be updated.

lpData
[in] 
Pointer to the resource data to be inserted into the executable file. 
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
An application can use UpdateResource repeatedly to make changes to the resource data. Each call to UpdateResource contributes to an internal list of additions, deletions, and replacements but does not actually write the data to the executable file.   
  
The application must use the EndUpdateResource function to write the accumulated changes to the executable file.   
  
***  

