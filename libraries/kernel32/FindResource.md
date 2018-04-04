[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindResource
Group: [Resource](../../functions_group.md#Resource)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The FindResource function determines the location of a resource with the specified type and name in the specified module.
***  


## Code examples:
[Storing registration key in the resources of an executable file](../../samples/sample_401.md)  
[Exporting DLL icon resources as .ICO files](../../samples/sample_502.md)  

## Declaration:
```foxpro  
HRSRC FindResource(
	HMODULE hModule,
	LPCTSTR lpName,
	LPCTSTR lpType
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindResource IN kernel32;
	INTEGER hModule,;
	INTEGER lpName,;
	INTEGER lpType
  
```  
***  


## Parameters:
hModule
[in] Handle to the module whose executable file contains the resource.

lpName
[in] Specifies the name of the resource.

lpType
[in] Specifies the resource type.  
***  


## Return value:
If the function succeeds, the return value is a handle to the specified resource"s information block. To obtain a handle to the resource, pass this handle to the LoadResource function.  
***  


## Comments:
For <Strong>hModule</Strong> a value of NULL specifies the module handle associated with the image file that the operating system used to create the current process.   
  
To specify a language, use the FindResourceEx function.  
  
***  

