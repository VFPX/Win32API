<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : MAPISendMail
Group: Simple MAPI - Library: mapi32    
***  


#### The MAPISendMail function sends a message. 
***  


## Code examples:
[Sending email messages with Simple MAPI](../../samples/sample_193.md)  
[MapiSendMail class for Visual FoxPro application](../../samples/sample_342.md)  

## Declaration:
```foxpro  
ULONG FAR PASCAL MAPISendMail(
  LHANDLE lhSession,
  ULONG ulUIParam,
  lpMapiMessage lpMessage,
  FLAGS flFlags,
  ULONG ulReserved
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MAPISendMail IN mapi32;
	INTEGER   lhSession,;
	INTEGER   ulUIParam,;
	STRING  @ lpMessage,;
	INTEGER   flFlags,;
	INTEGER   ulReserved  
```  
***  


## Parameters:
```txt  
lhSession
[in] Handle to a Simple MAPI session or zero. If the value of the lhSession parameter is zero, MAPI logs on the user and creates a session that exists only for the duration of the call.

ulUIParam
[in] Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal.

lpMessage
[in] Pointer to a MapiMessage structure containing the message to be sent.

flFlags
[in] Bitmask of option flags.

ulReserved
Reserved; must be zero.  
```  
***  


## Return value:
Returns SUCCESS_SUCCESS (0) if the call succeeded and the message was sent; or a predefined MESSAGE_E_* error value otherwise.  
***  


## Comments:
A successful return from MAPISendMail does not necessarily imply recipient validation.  
  
***  

