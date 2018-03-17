<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WTSOpenServer
Group: Terminal Services - Library: wtsapi32    
***  


#### Opens a handle to the specified terminal server.

***  


## Code examples:
[How to enumerate sessions and processes on a specified terminal server](../../samples/sample_519.md)  

## Declaration:
```foxpro  
HANDLE WTSOpenServer(
	LPTSTR pServerName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WTSOpenServer IN Wtsapi32;
	STRING pServerName  
```  
***  


## Parameters:
```txt  
pServerName
[in] Pointer to a null-terminated string specifying the NetBIOS name of the terminal server.  
```  
***  


## Return value:
If the function succeeds, the return value is a handle to the specified server.  
***  


## Comments:
When you are finished with the handle returned by WTSOpenServer, call the WTSCloseServer function to close it.  
  
You do not need to open a handle for operations performed on the terminal server on which your application is running. Use the constant WTS_CURRENT_SERVER_HANDLE instead.  
  
***  

