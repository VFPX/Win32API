[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LockResource
Group: [Resource](../../functions_group.md#Resource)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The LockResource function locks the specified resource in memory.
***  


## Code examples:
[Storing registration key in the resources of an executable file](../../samples/sample_401.md)  
[Exporting DLL icon resources as .ICO files](../../samples/sample_502.md)  

## Declaration:
```foxpro  
LPVOID LockResource(
	HGLOBAL hResData
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LockResource IN kernel32;
	INTEGER hResData  
```  
***  


## Parameters:
hResData
[in] Handle to the resource to be locked. The LoadResource function returns this handle.  
***  


## Return value:
If the loaded resource is locked, the return value is a pointer to the first byte of the resource; otherwise, it is NULL.  
***  


## Comments:
MSDN:  
Note that <Strong>hResData</Strong> parameter is listed as an HGLOBAL variable only for backwards compatibility. Do not pass any value as a parameter other than a successful return value from the LoadResource function.   
  
The pointer returned by LockResource is valid until the module containing the resource is unloaded. It is not necessary to unlock resources because the system automatically deletes them when the process that created them terminates.  
  
Do not try to lock a resource by using the handle returned by the FindResource or FindResourceEx function. Such a handle points to random data.  
  
***  

