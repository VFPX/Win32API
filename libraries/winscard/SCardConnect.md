[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SCardConnect
Group: [Authentication](../../functions_group.md#Authentication)  -  Library: [winscard](../../Libraries.md#winscard)  
***  

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.

#### Establishes a connection (using a specific resource manager context) between the calling application and a smart card contained by a specific reader.

***  


## Declaration:
```foxpro  
LONG SCardConnect(
  __in   SCARDCONTEXT hContext,
  __in   LPCTSTR szReader,
  __in   DWORD dwShareMode,
  __in   DWORD dwPreferredProtocols,
  __out  LPSCARDHANDLE phCard,
  __out  LPDWORD pdwActiveProtocol
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG SCardConnect IN Winscard;
	INTEGER hContext,;
	STRING szReader,;
	LONG dwShareMode,;
	LONG dwPreferredProtocols,;
	INTEGER @phCard,;
	LONG @pdwActiveProtocol  
```  
***  


## Parameters:
hContext [in] 
A handle that identifies the resource manager context.

szReader [in] 
The name of the reader that contains the target card.

dwShareMode [in] 
A flag that indicates whether other applications may form connections to the card.

dwPreferredProtocols [in] 
A bitmask of acceptable protocols for the connection.

phCard [out] 
A handle that identifies the connection to the smart card in the designated reader.

pdwActiveProtocol [out] 
A flag that indicates the established active protocol.
  
***  


## Return value:
Returns SCARD_S_SUCCESS (0) or error code.  
***  


## Comments:
<!-- Anatoliy  -->
Purchase complete VFP solution.  
<a href="http://www.news2news.com/vfp/?solution=2&src=fn1140"><img src="../../images/acos3_270_48.png" width=270 height=48 border=0  vspace=5 hspace=5 alt="Download ACOS3 Class Library"></a>  


See also: [SCardReconnect](..//SCardReconnect.md), [SCardDisconnect](../winscard/SCardDisconnect.md).  
  
***  

