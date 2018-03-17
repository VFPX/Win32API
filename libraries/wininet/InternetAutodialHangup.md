<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : InternetAutodialHangup
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### Disconnects an automatic dial-up connection.
***  


## Code examples:
[Dial the Net Automatically](../../samples/sample_140.md)  

## Declaration:
```foxpro  
BOOL InternetAutodialHangup(
	DWORD dwReserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetAutodialHangup IN wininet.dll;
	INTEGER dwReserved  
```  
***  


## Parameters:
```txt  
dwReserved
[in] Reserved. Must be set to 0.  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  

