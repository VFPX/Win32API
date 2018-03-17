<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : LookupPrivilegeValue
Group: Authorization - Library: advapi32    
***  


#### Retrieves the locally unique identifier (LUID) used on a specified system to locally represent the specified privilege name.
***  


## Code examples:
[How to enable the SE_SHUTDOWN_NAME privilege for the application](../../samples/sample_552.md)  
[Reading and setting system access privileges for the current process](../../samples/sample_554.md)  
[How to load a user profile](../../samples/sample_602.md)  

## Declaration:
```foxpro  
BOOL WINAPI LookupPrivilegeValue(
  __in_opt  LPCTSTR lpSystemName,
  __in      LPCTSTR lpName,
  __out     PLUID lpLuid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LookupPrivilegeValue IN advapi32;
	INTEGER lpSystemName,;
	STRING lpName,;
	STRING @lpLuid  
```  
***  


## Parameters:
```txt  
lpSystemName [in, optional]
A pointer to a null-terminated string that specifies the name of the system on which the privilege name is retrieved.

lpName [in]
A pointer to a null-terminated string that specifies the name of the privilege.

lpLuid [out]
A pointer to a variable that receives the LUID by which the privilege is known on the system specified by the lpSystemName parameter.  
```  
***  


## Return value:
If the function succeeds, the function returns nonzero.  
***  


## Comments:
The LookupPrivilegeValue function supports only the privileges specified in the Defined Privileges section of Winnt.h.  
  
***  

