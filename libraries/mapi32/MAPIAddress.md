[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MAPIAddress
Group: [Simple MAPI](../../functions_group.md#Simple_MAPI)  -  Library: [mapi32](../../Libraries.md#mapi32)  
***  


#### The MAPIAddress function creates or modifies a set of address list entries.
***  


## Code examples:
[Simple MAPI: how to pick an email recipient from Outlook Express address book](../../samples/sample_407.md)  

## Declaration:
```foxpro  
ULONG FAR PASCAL MAPIAddress(
  LHANDLE lhSession,
  ULONG ulUIParam,
  LPTSTR lpszCaption,
  ULONG nEditFields,
  LPTSTR lpszLabels,
  ULONG nRecips,
  lpMapiRecipDesc lpRecips,
  FLAGS flFlags,
  ULONG ulReserved,
  LPULONG lpnNewRecips,
  lpMapiRecipDesc FAR * lppNewRecips
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MAPIAddress IN mapi32;
	INTEGER   lhSession,;
	INTEGER   ulUIParam,;
	STRING    lpszCaption,;
	INTEGER   nEditFields,;
	STRING    lpszLabels,;
	INTEGER   nRecips,;
	STRING  @ lpRecips,;
	INTEGER   flFlags,;
	INTEGER   ulReserved,;
	INTEGER @ lpnNewRecips,;
	INTEGER @ lppNewRecips
  
```  
***  


## Parameters:
lhSession 
[in] Session handle that represents a Simple MAPI session or zero.

ulUIParam 
[in] Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal.

lpszCaption 
[in] Pointer to the caption for the address list dialog box, NULL, or an empty string.

nEditFields 
[in] The number of edit controls that should be present in the address list. The values 0 through 4 are valid.

lpszLabels 
[in] Pointer to a string to be used as an edit control label in the address-list dialog box.

nRecips 
[in] The number of entries in the array indicated by the lpRecips parameter.

lpRecips 
[in] Pointer to an array of MapiRecipDesc structures defining the initial recipient entries to be used to populate the address-list dialog box.

flFlags 
[in] Bitmask of option flags.

ulReserved 
Reserved; must be zero.

lpnNewRecips 
[out] Pointer to the number of entries in the lppNewRecips recipient output array.

lppNewRecips 
[out] Pointer to an array of MapiRecipDesc structures containing the final list of recipients.  
***  


## Return value:
SUCCESS_SUCCESS if the call succeeded and a list of recipient entries was returned. Otherwise it is a MAPI Error code.  
***  


## Comments:
Client applications must call the MAPIFreeBuffer function to free this memory after MAPIAddress returns. If any error occurs, no memory was allocated and clients do not need to call MAPIFreeBuffer.  
  
***  

