
## Function name : SizeofResource
Group: Resource - Library: kernel32    
***  


#### The SizeofResource function returns the size, in bytes, of the specified resource.
***  


## Code examples:
[Storing registration key in the resources of an executable file](../../samples/sample_401.md)  
[Exporting DLL icon resources as .ICO files](../../samples/sample_502.md)  

## Declaration:
```foxpro  
DWORD SizeofResource(
	HMODULE hModule,
	HRSRC hResInfo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SizeofResource IN kernel32;
	INTEGER hModule,;
	INTEGER hResInfo
  
```  
***  


## Parameters:
hModule
[in] Handle to the module whose executable file contains the resource. 

hResInfo
[in] Handle to the resource. This handle must be created by using the FindResource or FindResourceEx function.  
***  


## Return value:
If the function succeeds, the return value is the number of bytes in the resource.  
***  

