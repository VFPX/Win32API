[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LsaEnumerateLogonSessions
Group: [Security](../../functions_group.md#Security)  -  Library: [secur32](../../Libraries.md#secur32)  
***  


#### Retrieves the set of existing logon session identifiers (LUIDs) and the number of sessions.

***  


## Code examples:
[How to enumerate logon sessions on local computer](../../samples/sample_591.md)  

## Declaration:
```foxpro  
NTSTATUS NTAPI LsaEnumerateLogonSessions(
  _Out_  PULONG LogonSessionCount,
  _Out_  PLUID *LogonSessionList
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LsaEnumerateLogonSessions IN secur32;
	INTEGER @LogonSessionCount,;
	INTEGER @LogonSessionList  
```  
***  


## Parameters:
LogonSessionCount [out]
Pointer to a long integer that receives the number of elements returned in the array returned in LogonSessionList parameter.

LogonSessionList [out]
Address of a pointer to a LUID. The pointer receives the first element of an array of logon session identifiers.   
***  


## Return value:
If the function succeeds, the return value is STATUS_SUCCESS (0).  
***  


## Comments:
See also: [LsaGetLogonSessionData](../secur32/LsaGetLogonSessionData.md), [LsaFreeReturnBuffer](../secur32/LsaFreeReturnBuffer.md).  
  
***  

