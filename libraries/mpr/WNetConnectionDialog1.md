[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WNetConnectionDialog1
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [mpr](../../Libraries.md#mpr)  
***  


#### Brings up a general browsing dialog for connecting to network resources.
***  


## Code examples:
[Starting a dialog box for connecting to network resources and passing input parameters](../../samples/sample_551.md)  

## Declaration:
```foxpro  
DWORD WNetConnectionDialog1(
  __inout  LPCONNECTDLGSTRUCT lpConnDlgStruct
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG WNetConnectionDialog1 IN mpr;
	INTEGER lpConnDlgStruct  
```  
***  


## Parameters:
lpConnDlgStruct [in, out] 
Pointer to a CONNECTDLGSTRUCT structure. The structure establishes the browsing dialog parameters.  
***  


## Return value:
If the user cancels the dialog box, the function returns –1. If the function is successful, it returns NO_ERROR (0).   
***  


## Comments:
The function requires a CONNECTDLGSTRUCT to establish the dialog box parameters.  
  
***  

