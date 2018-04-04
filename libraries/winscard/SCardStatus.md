[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SCardStatus
Group: [Authentication](../../functions_group.md#Authentication)  -  Library: [winscard](../../Libraries.md#winscard)  
***  


#### Provides the current status of a smart card in a reader.
***  


## Declaration:
```foxpro  
LONG SCardStatus(
  __in     SCARDHANDLE hCard,
  __out    LPTSTR szReaderName,
  __inout  LPDWORD pcchReaderLen,
  __out    LPDWORD pdwState,
  __out    LPDWORD pdwProtocol,
  __out    LPBYTE pbAtr,
  __inout  LPDWORD pcbAtrLen
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG SCardStatus IN Winscard;
	INTEGER hCard,;
	STRING @szReaderName,;
	LONG @pcchReaderLen,;
	LONG @pdwState,;
	LONG @pdwProtocol,;
	STRING @pbAtr,;
	LONG @pcbAtrLen  
```  
***  


## Parameters:
hCard [in] 
Reference value returned from SCardConnect.

szReaderName [out] 
List of display names (multiple string) by which the currently connected reader is known.

pcchReaderLen [in, out] 
On input, supplies the length of the szReaderName buffer. 

pdwState [out] 
Current state of the smart card in the reader.

pdwProtocol [out] 
Current protocol, if any. 

pbAtr [out] 
Pointer to a 32-byte buffer that receives the ATR string from the currently inserted card, if available.

pcbAtrLen [in, out] 
On input, supplies the length of the pbAtr buffer. On output, receives the number of bytes in the ATR string (32 bytes maximum).
  
***  


## Return value:
Returns SCARD_S_SUCCESS (0) or error code.  
***  


## Comments:
You can call it any time after a successful call to SCardConnect and before a successful call to SCardDisconnect.  
  
***  

