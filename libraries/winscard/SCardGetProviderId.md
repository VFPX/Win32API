<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SCardGetProviderId
Group: Authentication - Library: winscard    
***  


#### Returns the identifier (GUID) of the primary service provider for a given card.
***  


## Code examples:
[Smart Card Database Query Functions](../../samples/sample_539.md)  

## Declaration:
```foxpro  
LONG SCardGetProviderId(
  __in   SCARDCONTEXT hContext,
  __in   LPCTSTR szCard,
  __out  LPGUID pguidProviderId
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG SCardGetProviderId IN Winscard;
	INTEGER hContext,;
	STRING szCard,;
	STRING @pguidProviderId  
```  
***  


## Parameters:
```txt  
hContext [in]
Handle that identifies the resource manager context for the query.

szCard [in]
Name of the card defined to the system.

pguidProviderId [out]
Identifier (GUID) of the primary service provider. This provider may be activated using COM, and will supply access to other services in the card.  
```  
***  


## Return value:
Returns SCARD_S_SUCCESS (0) or error code.  
***  


## Comments:
The SCardGetProviderId function is a database query function.  
  
***  

