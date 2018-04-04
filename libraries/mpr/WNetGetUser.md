[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WNetGetUser
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [mpr](../../Libraries.md#mpr)  
***  


#### The WNetGetUser function retrieves the current default user name, or the user name used to establish a network connection. 
***  


## Code examples:
[Retrieving current user for the process](../../samples/sample_310.md)  

## Declaration:
```foxpro  
DWORD WNetGetUser(
  LPCTSTR lpName,     // device or resource name
  LPTSTR lpUserName,  // name buffer
  LPDWORD lpnLength   // buffer size
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WNetGetUser IN mpr;
	INTEGER   lpName,;
	STRING  @ lpUserName,;
	INTEGER @ lpnLength  
```  
***  


## Parameters:
lpName 
[in] Pointer to a constant null-terminated string that specifies either the name of a local device or the remote name of a network resource.

lpUserName 
[out] Pointer to a buffer that receives the null-terminated user name. 

lpnLength 
[in/out] Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the lpUserName parameter.  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).   
***  


## Comments:
Compare this function with the GetUserName.  
  
SYS(0) -- the network machine information -- returns computer name and user name in one string.  
  
***  

