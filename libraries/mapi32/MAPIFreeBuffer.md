[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MAPIFreeBuffer
Group: [Simple MAPI](../../functions_group.md#Simple_MAPI)  -  Library: [mapi32](../../Libraries.md#mapi32)  
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
pv 
[in] Pointer to memory allocated by the messaging system. This pointer is returned by the MAPIReadMail, MAPIAddress, and MAPIResolveName functions.   
***  


## Return value:
SUCCESS_SUCCESS (0) or an error code.  
***  

