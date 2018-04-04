[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SCardReleaseContext
Group: [Authentication](../../functions_group.md#Authentication)  -  Library: [winscard](../../Libraries.md#winscard)  
***  


#### Closes an established resource manager context, freeing any resources allocated under that context, including SCARDHANDLE objects and memory allocated using the SCARD_AUTOALLOCATE length designator.

***  


## Code examples:
[Smart Card Database Query Functions](../../samples/sample_539.md)  

## Declaration:
```foxpro  
LONG SCardReleaseContext(
  __in  SCARDCONTEXT hContext
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG SCardReleaseContext IN Winscard;
	INTEGER hContext  
```  
***  


## Parameters:
hContext [in] 
Handle that identifies the resource manager context.
  
***  


## Return value:
If the function succeeds, the function returns SCARD_S_SUCCESS (0).  
***  


## Comments:
The resource manager context is set by a previous call to SCardEstablishContext.  
  
***  

