[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MAPIFindNext
Group: [Simple MAPI](../../functions_group.md#Simple_MAPI)  -  Library: [mapi32](../../Libraries.md#mapi32)  
***  


#### The MAPIFindNext function retrieves the next (or first) message identifier of a specified type of incoming message. 
***  


## Code examples:
[How to read email messages using Simple MAPI](../../samples/sample_270.md)  

## Declaration:
```foxpro  
ULONG FAR PASCAL MAPIFindNext(
  LHANDLE lhSession,
  ULONG ulUIParam,
  LPTSTR lpszMessageType,
  LPTSTR lpszSeedMessageID,
  FLAGS flFlags,
  ULONG ulReserved,
  LPTSTR lpszMessageID
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MAPIFindNext IN mapi32;
	INTEGER   lhSession,;
	INTEGER   ulUIParam,;
	STRING    lpszMsgType,;
	STRING    lpszSeedMsgID,;
	INTEGER   flFlags,;
	INTEGER   ulReserved,;
	STRING  @ lpszMsgID  
```  
***  


## Parameters:
lhSession 
[in] Session handle that represents a Simple MAPI session. 

ulUIParam 
[in] Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. 

lpszMessageType 
[in] Pointer to a string identifying the message class to search. 

lpszSeedMessageID 
[in] Pointer to a string containing the message identifier seed for the request. 

flFlags 
[in] Bitmask of option flags. 

ulReserved 
Reserved; must be zero. 

lpszMessageID 
[out] Pointer to the returned message identifier. 
  
***  


## Return value:
SUCCESS_SUCCESS (0) or an error code.  
***  


## Comments:
There is no <Strong>MAPIFindFirst</Strong> function.  
  
When the <Em>lpszSeedMessageID</Em> parameter is NULL or points to an empty string, MAPIFindNext returns the message identifier for the first message of the type specified by the lpszMessageType parameter.   
  
Repeated calls to MAPIFindNext ultimately result in a return of the MAPI_E_NO_MESSAGES value, which means the enumeration is complete.   
  
***  

