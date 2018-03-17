<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : LsaEnumerateLogonSessions
Group: Security - Library: secur32    
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
```txt  
LogonSessionCount [out]
Pointer to a long integer that receives the number of elements returned in the array returned in LogonSessionList parameter.

LogonSessionList [out]
Address of a pointer to a LUID. The pointer receives the first element of an array of logon session identifiers.  
```  
***  


## Return value:
If the function succeeds, the return value is STATUS_SUCCESS (0).  
***  


## Comments:
See also: LsaGetLogonSessionData, LsaFreeReturnBuffer   
  
***  

