[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SCardDisconnect
Group: [Authentication](../../functions_group.md#Authentication)  -  Library: [winscard](../../Libraries.md#winscard)  
***  


#### Terminates a connection previously opened between the calling application and a smart card in the target reader.
***  


## Declaration:
```foxpro  
LONG SCardDisconnect(
  __in  SCARDHANDLE hCard,
  __in  DWORD dwDisposition
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG SCardDisconnect IN Winscard;
	INTEGER hCard,;
	LONG dwDisposition  
```  
***  


## Parameters:
hCard [in] 
Reference value obtained from a previous call to SCardConnect.

dwDisposition [in] 
Action to take on the card in the connected reader on close.
  
***  


## Return value:
Returns SCARD_S_SUCCESS (0) or error code.  
***  


## Comments:
See also: [SCardConnect](../winscard/SCardConnect.md), [SCardReconnect](..//SCardReconnect.md).  
  
***  

