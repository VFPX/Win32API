
## Function name : SCardIsValidContext
Group: Authentication - Library: winscard    
***  


#### Determines whether a smart card context handle is valid.

***  


## Declaration:
```foxpro  
LONG SCardIsValidContext(
	__in  SCARDCONTEXT hContext
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG SCardIsValidContext IN Winscard;
	INTEGER hContext  
```  
***  


## Parameters:
hContext [in] 
Handle that identifies the resource manager context. The resource manager context can be set by a previous call to SCardEstablishContext.
  
***  


## Return value:
If the hContext parameter is valid, the function returns SCARD_S_SUCCESS (0).
  
***  


## Comments:
See also: SCardEstablishContext   
  
***  

