<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : MAPIResolveName
Group: Simple MAPI - Library: mapi32    
***  


#### The MAPIResolveName function transforms a message recipient"s name as entered by a user to an unambiguous address list entry.
***  


## Code examples:
[Simple MAPI: how to resolve a name to unique address list entry](../../samples/sample_408.md)  

## Declaration:
```foxpro  
ULONG FAR PASCAL MAPIResolveName(
  LHANDLE lhSession,
  ULONG ulUIParam,
  LPTSTR lpszName,
  FLAGS flFlags,
  ULONG ulReserved,
  lpMapiRecipDesc FAR * lppRecip
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MAPIResolveName IN mapi32;
	INTEGER   lhSession,;
	INTEGER   ulUIParam,;
	STRING    lpszName,;
	INTEGER   flFlags,;
	INTEGER   ulReserved,;
	INTEGER @ lppRecip
  
```  
***  


## Parameters:
```txt  
lhSession
[in] Handle that represents a Simple MAPI session or zero.

ulUIParam
[in] Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal.

lpszName
[in] Pointer to the name to be resolved.

flFlags
[in] Bitmask of option flags.

ulReserved
Reserved; must be zero.

lppRecip
[out] Pointer to a recipient structure <u>if the resolution results in a single match</u>.  
```  
***  

