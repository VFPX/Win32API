<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetUserName
Group: System Information - Library: advapi32    
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
```txt  
lpBuffer
Points to the buffer to receive the null-terminated string containing the user"s logon name.

nSize
Pointer to a DWORD that, on input, specifies the maximum size, in characters, of the buffer specified by the lpBuffer parameter.  
```  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
SYS(0) -- the network machine information -- returns computer name and user name in one string.  
  
See also: GetUserNameEx, GetComputerName, GetComputerNameEx   
  
***  

