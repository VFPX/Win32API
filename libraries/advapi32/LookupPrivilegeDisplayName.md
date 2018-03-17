<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : LookupPrivilegeDisplayName
Group: Authorization - Library: advapi32    
***  


#### Retrieves the display name that represents a specified privilege.
***  


## Code examples:
[Reading and setting system access privileges for the current process](../../samples/sample_554.md)  

## Declaration:
```foxpro  
BOOL WINAPI LookupPrivilegeDisplayName(
  __in_opt   LPCTSTR lpSystemName,
  __in       LPCTSTR lpName,
  __out_opt  LPTSTR lpDisplayName,
  __inout    LPDWORD cchDisplayName,
  __out      LPDWORD lpLanguageId
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LookupPrivilegeDisplayName IN advapi32;
	INTEGER lpSystemName,;
	STRING lpName,;
	STRING @lpDisplayName,;
	LONG @cchDisplayName,;
	LONG @lpLanguageId  
```  
***  


## Parameters:
```txt  
lpSystemName [in, optional]
A pointer to a null-terminated string that specifies the name of the system on which the privilege name is retrieved.

lpName [in]
A pointer to a null-terminated string that specifies the name of the privilege, as defined in Winnt.h.

lpDisplayName [out, optional]
A pointer to a buffer that receives a null-terminated string that specifies the privilege display name.

cchDisplayName [in, out]
A pointer to a variable that specifies the size, in TCHARs, of the lpDisplayName buffer.

lpLanguageId [out]
A pointer to a variable that receives the language identifier for the returned display name.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Default privileges for VFP9 process on Vista:  
  
<img src="images/vfpprivilegesonvista.png">  
  
See also: LookupPrivilegeName, LookupPrivilegeValue   
  
***  

