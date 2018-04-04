[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WNetDisconnectDialog
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [mpr](../../Libraries.md#mpr)  
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
hwnd 
[in] Handle to the owner window for the dialog box. 

dwType 
[in] Resource type to disconnect from.  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  


## Comments:
If the user chooses OK in the dialog box, the requested network disconnection will have been made when the WNetDisconnectDialog function returns.  
  
dwType -- only RESOURCETYPE_DISK is allowed.  
  
***  

