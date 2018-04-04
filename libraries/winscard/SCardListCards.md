[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SCardListCards
Group: [Authentication](../../functions_group.md#Authentication)  -  Library: [winscard](../../Libraries.md#winscard)  
***  


#### Searches the smart card database and provides a list of named cards previously introduced to the system by the user.
***  


## Code examples:
[Smart Card Database Query Functions](../../samples/sample_539.md)  

## Declaration:
```foxpro  
LONG SCardListCards(
  __in     SCARDCONTEXT hContext,
  __in     LPCBYTE pbAtr,
  __in     LPCGUID rgguidInterfaces,
  __in     DWORD cguidInterfaceCount,
  __out    LPTSTR mszCards,
  __inout  LPDWORD pcchCards
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG SCardListCards IN Winscard;
	INTEGER hContext,;
	INTEGER pbAtr,;
	INTEGER rgguidInterfaces,;
	LONG cguidInterfaceCount,;
	STRING @mszCards,;
	LONG @pcchCards
  
```  
***  


## Parameters:
hContext [in]
Handle that identifies the resource manager context for the query

pbAtr [in]
Address of an ATR string to compare to known cards, or NULL if no ATR matching is to be performed.

rgguidInterfaces [in]
Array of identifiers (GUIDs), or NULL if no interface matching is to be performed.

cguidInterfaceCount [in]
Number of entries in the rgguidInterfaces array. If rgguidInterfaces is NULL, then this value is ignored.

mszCards [out]
Multi-string that lists the smart cards found.

pcchCards [in, out]
Length of the mszCards buffer in characters. Receives the actual length of the multi-string structure, including all trailing null characters.  
***  


## Return value:
Returns SCARD_S_SUCCESS (0) or error code.  
***  


## Comments:
The SCardListCards function is a database query function.  
  
***  

