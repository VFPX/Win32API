<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WNetDisconnectDialog
Group: Windows Networking - Library: mpr    
***  


#### The WNetDisconnectDialog function starts a general browsing dialog box for disconnecting from network resources. The function requires a handle to the owner window for the dialog box.
***  


## Code examples:
[Starting a dialog box for connecting to network resources (mapping network drive)](../../samples/sample_309.md)  

## Declaration:
```foxpro  
DWORD WNetDisconnectDialog(
  HWND hwnd,
  DWORD dwType
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WNetDisconnectDialog IN mpr;
	INTEGER hwnd,;
	INTEGER dwType
  
```  
***  


## Parameters:
```txt  
hwnd
[in] Handle to the owner window for the dialog box.

dwType
[in] Resource type to disconnect from.  
```  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  


## Comments:
If the user chooses OK in the dialog box, the requested network disconnection will have been made when the WNetDisconnectDialog function returns.  
  
dwType -- only RESOURCETYPE_DISK is allowed.  
  
***  

