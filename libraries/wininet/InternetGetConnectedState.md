[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetGetConnectedState
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Retrieves the connected state of the local system.
***  


## Code examples:
[Retrieving the state of your Internet connection](../../samples/sample_068.md)  

## Declaration:
```foxpro  
BOOL InternetGetConnectedState(
    LPDWORD lpdwFlags,
    DWORD dwReserved
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT InternetGetConnectedState IN wininet;
	INTEGER @ lpdwFlags,;
   	INTEGER   dwReserved  
```  
***  


## Parameters:
lpdwFlags
[out] Pointer to an unsigned long integer variable where the connection description should be returned. 

dwReserved
[in] Reserved. Must be set to zero.
  
***  


## Return value:
Returns TRUE if there is an Internet connection, or FALSE otherwise.  
***  


## Comments:
The InternetGetConnectedStateEx is an extended version of this function.   
  
The InternetCheckConnection allows an application to check if a connection to the Internet can be established.  
  
***  

