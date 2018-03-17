<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WNetConnectionDialog1
Group: Windows Networking - Library: mpr    
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
```txt  
lpConnDlgStruct [in, out]
Pointer to a CONNECTDLGSTRUCT structure. The structure establishes the browsing dialog parameters.  
```  
***  


## Return value:
If the user cancels the dialog box, the function returns –1. If the function is successful, it returns NO_ERROR (0).   
***  


## Comments:
The function requires a CONNECTDLGSTRUCT to establish the dialog box parameters.  
  
***  

