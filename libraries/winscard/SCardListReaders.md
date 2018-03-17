<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SCardListReaders
Group: Authentication - Library: winscard    
***  


#### Provides the list of readers within a set of named reader groups.
***  


## Code examples:
[Smart Card Database Query Functions](../../samples/sample_539.md)  

## Declaration:
```foxpro  
LONG SCardListReaders(
  __in     SCARDCONTEXT hContext,
  __in     LPCTSTR mszGroups,
  __out    LPTSTR mszReaders,
  __inout  LPDWORD pcchReaders
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG SCardListReaders IN Winscard;
	INTEGER hContext,;
	STRING mszGroups,;
	STRING @mszReaders,;
	LONG @pcchReaders  
```  
***  


## Parameters:
```txt  
hContext [in]
Handle that identifies the resource manager context for the query.

mszGroups [in]
Names of the reader groups defined to the system, as a multi-string.

mszReaders [out]
Multi-string that lists the card readers within the supplied reader groups.

pcchReaders [in, out]
Length of the mszReaders buffer in characters.  
```  
***  


## Return value:
Returns SCARD_S_SUCCESS (0) or error code.  
***  


## Comments:
The SCardListReaders function is a database query function.  
  
***  

