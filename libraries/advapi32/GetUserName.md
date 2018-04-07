[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetUserName
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Retrieves the user name of the current thread. This is the name of the user currently logged onto the system.
***  


## Code examples:
[Retrieving local computer and user names](../../samples/sample_041.md)  
[Obtaining names of local and global groups for current user (WinNT/XP/2K)](../../samples/sample_431.md)  
[Finding out if the current user is the Guest account](../../samples/sample_566.md)  

## Declaration:
```foxpro  
BOOL GetUserName(
	LPTSTR  lpBuffer,	// address of name buffer
	LPDWORD  nSize 	// address of size of name buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetUserName IN advapi32;
	STRING @lpBuffer,;
	INTEGER @nSize  
```  
***  


## Parameters:
lpBuffer
Points to the buffer to receive the null-terminated string containing the user"s logon name. 

nSize
Pointer to a DWORD that, on input, specifies the maximum size, in characters, of the buffer specified by the lpBuffer parameter.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
SYS(0) -- the network machine information -- returns computer name and user name in one string.  
  
See also: [GetUserNameEx](../secur32/GetUserNameEx.md), [GetComputerName](../kernel32/GetComputerName.md), [GetComputerNameEx](../kernel32/GetComputerNameEx.md).  
  
***  

