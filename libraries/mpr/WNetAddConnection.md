[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WNetAddConnection
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [mpr](../../Libraries.md#mpr)  
***  


#### The WNetAddConnection function enables the calling application to connect a local device to a network resource. 
***  


## Code examples:
[Connecting a local device to a network resource](../../samples/sample_318.md)  

## Declaration:
```foxpro  
DWORD WNetAddConnection(
  LPCTSTR lpRemoteName, // network device name
  LPCTSTR lpPassword,   // password
  LPCTSTR lpLocalName   // local device name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WNetAddConnection IN mpr;
	STRING lpRemoteName,;
	STRING lpPassword,;
	STRING lpLocalName  
```  
***  


## Parameters:
lpRemoteName 
[in] Pointer to a constant null-terminated string that specifies the network resource to connect to. 

lpPassword 
[in] Pointer to a constant null-terminated string that specifies the password to be used to make a connection. 

lpLocalName 
[in] Pointer to a constant null-terminated string that specifies the name of a local device to be redirected, such as "F:" or "LPT1".  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR.  
***  


## Comments:
A successful connection is persistent, meaning that the system automatically restores the connection during subsequent logon operations.   
  
This function is provided only for compatibility with 16-bit versions of Windows. Other Windows-based applications should call the WNetAddConnection2 or the WNetAddConnection3 function.   
  
Links:  
  
[Command-line NT: It does exist!](https://www.itworld.com/article/2798267/operating-systems/command-line-nt--it-does-exist-.html)
  
***  

