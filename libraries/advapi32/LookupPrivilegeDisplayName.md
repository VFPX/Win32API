[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LookupPrivilegeDisplayName
Group: [Authorization](../../functions_group.md#Authorization)  -  Library: [advapi32](../../Libraries.md#advapi32)  
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
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Default privileges for VFP9 process on Vista:  
  
<img src="images/vfpprivilegesonvista.png">  
  
See also: [LookupPrivilegeName](../advapi32/LookupPrivilegeName.md), [LookupPrivilegeValue](../advapi32/LookupPrivilegeValue.md).  
  
***  

