<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WNetConnectionDialog
Group: Windows Networking - Library: mpr    
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
```txt  
hwnd
[in] Specifies a handle to the owner window for the dialog box.

dwType
[in] Specifies the resource type to allow connections to.  
```  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0). If the user cancels the dialog box, the function returns –1.  
***  


## Comments:
<img src="images/mapnetworkdrive_dlg.jpg">  
  
Not much of input parameters this function accepts: nor a drive letter neither a network path.  
  
See also: WNetDisconnectDialog, WNetConnectionDialog1   
  
***  

