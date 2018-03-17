<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : MAPIFreeBuffer
Group: Simple MAPI - Library: mapi32    
***  


#### The MAPIFreeBuffer function frees memory allocated by the messaging system.
***  


## Code examples:
[How to read email messages using Simple MAPI](../../samples/sample_270.md)  
[Simple MAPI: how to pick an email recipient from Outlook Express address book](../../samples/sample_407.md)  
[Simple MAPI: how to resolve a name to unique address list entry](../../samples/sample_408.md)  

## Declaration:
```foxpro  
ULONG FAR PASCAL MAPIFreeBuffer(
  LPVOID pv
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MAPIFreeBuffer IN mapi32;
	INTEGER pv  
```  
***  


## Parameters:
```txt  
pv
[in] Pointer to memory allocated by the messaging system. This pointer is returned by the MAPIReadMail, MAPIAddress, and MAPIResolveName functions.  
```  
***  


## Return value:
SUCCESS_SUCCESS (0) or an error code.  
***  

