[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SCardListReaders
Group: [Authentication](../../functions_group.md#Authentication)  -  Library: [winscard](../../Libraries.md#winscard)  
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
hContext [in]
Handle that identifies the resource manager context for the query.

mszGroups [in]
Names of the reader groups defined to the system, as a multi-string.

mszReaders [out]
Multi-string that lists the card readers within the supplied reader groups.

pcchReaders [in, out]
Length of the mszReaders buffer in characters.  
***  


## Return value:
Returns SCARD_S_SUCCESS (0) or error code.  
***  


## Comments:
The SCardListReaders function is a database query function.  
  
***  

