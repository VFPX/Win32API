[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MAPILogoff
Group: [Simple MAPI](../../functions_group.md#Simple_MAPI)  -  Library: [mapi32](../../Libraries.md#mapi32)  
***  


#### The MAPILogoff function ends a session with the messaging system.
***  


## Code examples:
[Open and close a Simple MAPI Session](../../samples/sample_190.md)  
[Sending email messages with Simple MAPI](../../samples/sample_193.md)  
[How to read email messages using Simple MAPI](../../samples/sample_270.md)  

## Declaration:
```foxpro  
ULONG FAR PASCAL MAPILogoff(
  LHANDLE lhSession,
  ULONG ulUIParam,
  FLAGS flFlags,
  ULONG ulReserved
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MAPILogoff IN mapi32;
	INTEGER lhSession,;
	INTEGER ulUIParam,;
	INTEGER flFlags,;
	INTEGER ulReserved  
```  
***  


## Parameters:
lhSession 
[in] Handle for the Simple MAPI session to be terminated. Session handles are returned by the MAPILogon function. 

ulUIParam 
[in] Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. 

flFlags 
Reserved; must be zero. 

ulReserved 
Reserved; must be zero. 
  
***  


## Return value:
Returns SUCCESS_SUCCESS (0) if the call succeeded and the session was terminated; or a predefined MAPI_E_* value otherwise.  
***  

