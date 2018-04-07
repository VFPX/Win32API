[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LsaGetLogonSessionData
Group: [Security](../../functions_group.md#Security)  -  Library: [secur32](../../Libraries.md#secur32)  
***  


#### Retrieves information about a specified logon session.
***  


## Code examples:
[How to enumerate logon sessions on local computer](../../samples/sample_591.md)  

## Declaration:
```foxpro  
NTSTATUS NTAPI LsaGetLogonSessionData(
  _In_   PLUID LogonId,
  _Out_  PSECURITY_LOGON_SESSION_DATA *ppLogonSessionData
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LsaGetLogonSessionData IN secur32;
	INTEGER LogonId,;
	INTEGER @ppLogonSessionData  
```  
***  


## Parameters:
LogonId [in]
Specifies a pointer to a LUID that identifies the logon session whose information will be retrieved.

ppLogonSessionData [out]
Address of a pointer to a SECURITY_LOGON_SESSION_DATA structure containing information on the logon session specified by LogonId.  
***  


## Return value:
If the function succeeds, the return value is STATUS_SUCCESS.  
***  


## Comments:
The SECURITY_LOGON_SESSION_DATA structure is allocated by the LSA. When the information is no longer needed, call the LSAFreeReturnBuffer function to free the memory used by this structure.  
  
See also: [LsaEnumerateLogonSessions](../secur32/LsaEnumerateLogonSessions.md), [LSAFreeReturnBuffer](..//LSAFreeReturnBuffer.md).  
  
***  

