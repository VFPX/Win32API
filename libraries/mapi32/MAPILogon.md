[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MAPILogon
Group: [Simple MAPI](../../functions_group.md#Simple_MAPI)  -  Library: [mapi32](../../Libraries.md#mapi32)  
***  


#### The MAPILogon function begins a Simple MAPI session, loading the default message store and address book providers.
***  


## Code examples:
[Open and close a Simple MAPI Session](../../samples/sample_190.md)  
[Sending email messages with Simple MAPI](../../samples/sample_193.md)  
[How to read email messages using Simple MAPI](../../samples/sample_270.md)  

## Declaration:
```foxpro  
ULONG FAR PASCAL MAPILogon(
  ULONG ulUIParam,
  LPTSTR lpszProfileName,
  LPTSTR lpszPassword,
  FLAGS flFlags,
  ULONG ulReserved,
  LPLHANDLE lplhSession
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MAPILogon IN mapi32;
	INTEGER ulUIParam,;
	STRING lpszProfileName,;
	STRING lpszPassword,;
	INTEGER flFlags,;
	INTEGER ulReserved,;
	INTEGER @lplhSession  
```  
***  


## Parameters:
ulUIParam 
[in] Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. 

lpszProfileName 
[in] Pointer to a null-terminated profile name string, limited to 256 characters or less. This is the profile to use when logging on. 

lpszPassword 
[in] Pointer to a null-terminated credential string, limited to 256 characters or less. 

flFlags 
[in] Bitmask of option flags. 

ulReserved 
Reserved; must be zero. 

lplhSession 
[out] Simple MAPI session handle.  
***  


## Return value:
Returns SUCCESS_SUCCESS (0) in case if the call succeeded and a Simple MAPI session was established; or one of the predefined MAPI_E_* values otherwise.  
***  


## Comments:
In my testing this function used to change active directory to the one of the Outlook Express -- default MAPI provider on my computer.  
  
MSDN: Determine that Simple MAPI is available by checking the [MAIL] section in the computer"s WIN.INI file for the MAPI entry. This entry will have a value of 1 if Simple MAPI is installed, or 0 if uninstalled.   
  
Check example in this reference: [Reading keys in the specified section of the Win.ini file](../../samples/sample_136.md) -- this is how to test Simple MAPI availabliilty on the local computer.  
  
***  

