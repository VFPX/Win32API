[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WNetConnectionDialog
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [mpr](../../Libraries.md#mpr)  
***  


#### The WNetConnectionDialog function starts a general browsing dialog box for connecting to network resources. The function requires a handle to the owner window for the dialog box.
***  


## Code examples:
[Starting a dialog box for connecting to network resources (mapping network drive)](../../samples/sample_309.md)  

## Declaration:
```foxpro  
DWORD WNetConnectionDialog(
  HWND hwnd,     // handle to window owning dialog box
  DWORD dwType   // resource type
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WNetConnectionDialog IN mpr;
	INTEGER hwnd,;
	INTEGER dwType  
```  
***  


## Parameters:
hwnd 
[in] Specifies a handle to the owner window for the dialog box. 

dwType 
[in] Specifies the resource type to allow connections to.   
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0). If the user cancels the dialog box, the function returns 1.  
***  


## Comments:

![](../../images/mapnetworkdrive_dlg.jpg)

Not much of input parameters this function accepts: nor a drive letter neither a network path.  
  
See also: [WNetDisconnectDialog](../mpr/WNetDisconnectDialog.md), [WNetConnectionDialog1](../mpr/WNetConnectionDialog1.md).  
  
***  

