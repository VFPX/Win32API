<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : InetIsOffline
Group: Shell Functions - Library: urlmon    
***  


#### Determines whether or not the system is connected to the Internet.
***  


## Code examples:
[Determining whether or not the system is connected to the Internet](../../samples/sample_322.md)  

## Declaration:
```foxpro  
BOOL InetIsOffline(
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InetIsOffline IN url;
	INTEGER dwFlags  
```  
***  


## Parameters:
```txt  
dwFlags
Input flags for the function. This must be set to zero.  
```  
***  


## Return value:
Returns TRUE if the local system is not currently connected to the Internet. Returns FALSE if the local system is connected to the Internet or if no attempt has yet been made to connect to the Internet.
  
***  


## Comments:
See also: InternetAttemptConnect, GetRTTAndHopCount, IcmpSendEcho.  
  
***  

