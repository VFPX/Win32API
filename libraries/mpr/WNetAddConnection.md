<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WNetAddConnection
Group: Windows Networking - Library: mpr    
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
```txt  
lpRemoteName
[in] Pointer to a constant null-terminated string that specifies the network resource to connect to.

lpPassword
[in] Pointer to a constant null-terminated string that specifies the password to be used to make a connection.

lpLocalName
[in] Pointer to a constant null-terminated string that specifies the name of a local device to be redirected, such as "F:" or "LPT1".  
```  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR.  
***  


## Comments:
A successful connection is persistent, meaning that the system automatically restores the connection during subsequent logon operations.   
  
This function is provided only for compatibility with 16-bit versions of Windows. Other Windows-based applications should call the WNetAddConnection2 or the WNetAddConnection3 function.   
  
Links:  
  
<a href="http://www.cae.wisc.edu/fsg/winnt/netuse.html">Using the <Strong>net use</Strong> command</a>.  
  
<a href="http://www.linuxworld.com/linuxworld/lw-1999-04/lw-04-thereandback.html">Command-line NT: It does exist!</a>.  
  
***  

