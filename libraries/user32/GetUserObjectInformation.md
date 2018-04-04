[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetUserObjectInformation
Group: [Service](../../functions_group.md#Service)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetUserObjectInformation function retrieves information about a window station or desktop object.
***  


## Code examples:
[Obtaining a handle to the desktop associated with the calling thread](../../samples/sample_239.md)  

## Declaration:
```foxpro  
BOOL GetUserObjectInformation(
  HANDLE hObj,            // handle to object
  int nIndex,             // type of information to retrieve
  PVOID pvInfo,           // information buffer
  DWORD nLength,          // size of the buffer
  LPDWORD lpnLengthNeeded // receives required buffer size
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetUserObjectInformation IN user32;
	INTEGER   hObj,;
	INTEGER   nIndex,;
	STRING  @ pvInfo,;
	INTEGER   nLength,;
	INTEGER @ lpnLengthNeeded  
```  
***  


## Parameters:
hObj 
[in] Handle to the window station or desktop object for which to return information. 

nIndex 
[in] Specifies the object information to be retrieved. 

pvInfo 
[out] Pointer to a buffer to receive the object information. 

nLength 
[in] Specifies the size, in bytes, of the buffer pointed to by the pvInfo parameter. 

lpnLengthNeeded 
[out] Pointer to a variable receiving the number of bytes required to store the requested information.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

