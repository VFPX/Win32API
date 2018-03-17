<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : MAPIReadMail
Group: Simple MAPI - Library: mapi32    
***  


#### The MAPIReadMail function retrieves a message for reading. 
***  


## Code examples:
[How to read email messages using Simple MAPI](../../samples/sample_270.md)  

## Declaration:
```foxpro  
ULONG FAR PASCAL MAPIReadMail(
  LHANDLE lhSession,
  ULONG ulUIParam,
  LPTSTR lpszMessageID,
  FLAGS flFlags,
  ULONG ulReserved,
  lpMapiMessage FAR * lppMessage
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MAPIReadMail IN mapi32;
	INTEGER   lhSession,;
	INTEGER   ulUIParam,;
	STRING    lpszMessageID,;
	INTEGER   flFlags,;
	INTEGER   ulReserved,;
	INTEGER @ lppMessage  
```  
***  


## Parameters:
```txt  
lhSession
[in] Handle to a Simple MAPI session.

ulUIParam
[in] Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal.

lpszMessageID
[in] Pointer to a message identifier string for the message to be read.

flFlags
[in] Bitmask of option flags.

ulReserved
Reserved; must be zero.

lppMessage
[out] Pointer to the location where the message is written.  
```  
***  


## Return value:
SUCCESS_SUCCESS (0) or an error code.  
***  


## Comments:
Before calling MAPIReadMail, use the MAPIFindNext function to verify that the message to be read is the one you want to be read.   
  
Messages are written to a MapiMessage structure which can be freed with a single call to the MAPIFreeBuffer function.  
  
***  

