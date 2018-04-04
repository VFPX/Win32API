[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SCardListInterfaces
Group: [Authentication](../../functions_group.md#Authentication)  -  Library: [winscard](../../Libraries.md#winscard)  
***  


#### Provides a list of interfaces supplied by a given card.
***  


## Code examples:
[Smart Card Database Query Functions](../../samples/sample_539.md)  

## Declaration:
```foxpro  
LONG SCardListInterfaces(
  __in     SCARDCONTEXT hContext,
  __in     LPCTSTR szCard,
  __out    LPGUID pguidInterfaces,
  __inout  LPDWORD pcguidInterfaces
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG SCardListInterfaces IN Winscard;
	INTEGER hContext,;
	STRING szCard,;
	STRING @pguidInterfaces,;
	LONG @pcguidInterfaces  
```  
***  


## Parameters:
hContext [in]
Handle that identifies the resource manager context for the query.

szCard [in]
Name of the smart card already introduced to the smart card subsystem.

pguidInterfaces [out]
Array of interface identifiers (GUIDs) that indicate the interfaces supported by the smart card.

pcguidInterfaces [in, out]
Size of the pcguidInterfaces array, and receives the actual size of the returned array.  
***  


## Return value:
Returns SCARD_S_SUCCESS (0) or error code.  
***  


## Comments:
The SCardListInterfaces function is a database query function.  
  
***  

