<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SCardDisconnect
Group: Authentication - Library: winscard    
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
```txt  
hCard [in]
Reference value obtained from a previous call to SCardConnect.

dwDisposition [in]
Action to take on the card in the connected reader on close.
  
```  
***  


## Return value:
Returns SCARD_S_SUCCESS (0) or error code.  
***  


## Comments:
See also: SCardConnect, SCardReconnect   
  
***  

