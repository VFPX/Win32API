<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SCardReleaseContext
Group: Authentication - Library: winscard    
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
```txt  
hContext [in]
Handle that identifies the resource manager context.
  
```  
***  


## Return value:
If the function succeeds, the function returns SCARD_S_SUCCESS (0).  
***  


## Comments:
The resource manager context is set by a previous call to SCardEstablishContext.  
  
***  

