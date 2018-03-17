<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SCardListReaderGroups
Group: Authentication - Library: winscard    
***  


#### Provides the list of reader groups that have previously been introduced to the system.

***  


## Code examples:
[Smart Card Database Query Functions](../../samples/sample_539.md)  

## Declaration:
```foxpro  
LONG SCardListReaderGroups(
	__in     SCARDCONTEXT hContext,
	__out    LPTSTR mszGroups,
	__inout  LPDWORD pcchGroups
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG SCardListReaderGroups IN Winscard;
	LONG hContext,;
	STRING @mszGroups,;
	LONG @pcchGroups  
```  
***  


## Parameters:
```txt  
hContext [in]
Handle that identifies the resource manager context for the query.

mszGroups [out]
Multi-string that lists the reader groups defined to the system and available to the current user on the current terminal.

pcchGroups [in, out]
Length of the mszGroups buffer in characters, and receives the actual length of the multi-string structure, including all trailing null characters.
  
```  
***  


## Return value:
If the function succeeds, the function returns SCARD_S_SUCCESS (0).  
***  


## Comments:
The resource manager context can be set by a previous call to SCardEstablishContext. This parameter cannot be NULL.  
  
See also: SCardListReaders   
  
***  

