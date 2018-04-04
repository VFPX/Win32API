[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EndUpdateResource
Group: [Resource](../../functions_group.md#Resource)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The EndUpdateResource function ends a resource update in an executable file.
***  


## Code examples:
[Storing registration key in the resources of an executable file](../../samples/sample_401.md)  

## Declaration:
```foxpro  
BOOL EndUpdateResource(
	HANDLE hUpdate,
	BOOL fDiscard
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EndUpdateResource IN kernel32;
	INTEGER hUpdate,;
	INTEGER fDiscard
  
```  
***  


## Parameters:
hUpdate
[in] Handle used in a resource update. This handle is returned by the BeginUpdateResource function. 

fDiscard
[in] Specifies whether to write resource updates to an executable file. If this parameter is TRUE, no changes are made to the executable file. If it is FALSE, the changes are made.  
***  


## Return value:
If the function succeeds and the accumulated resource modifications specified by calls to the UpdateResource function are written to the specified executable file, the return value is nonzero.  
***  

