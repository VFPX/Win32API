[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MAPIResolveName
Group: [Simple MAPI](../../functions_group.md#Simple_MAPI)  -  Library: [mapi32](../../Libraries.md#mapi32)  
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
***  

