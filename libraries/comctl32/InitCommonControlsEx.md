<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : InitCommonControlsEx
Group: Windows Controls - Library: comctl32    
***  


#### Registers specific common control classes from the common control dynamic-link library (DLL).
***  


## Code examples:
[Using Common Controls: the Header Control](../../samples/sample_298.md)  

## Declaration:
```foxpro  
BOOL InitCommonControlsEx(
	LPINITCOMMONCONTROLSEX lpInitCtrls
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InitCommonControlsEx IN comctl32;
	STRING @ lpInitCtrls  
```  
***  


## Parameters:
```txt  
lpInitCtrls
Pointer to an INITCOMMONCONTROLSEX structure that contains information specifying which control classes will be registered.
  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.   
***  


## Comments:
<a href="http://msdn.microsoft.com/library/default.asp?url=/library/en-us/shellcc/platform/commctls/common/structures/initcommoncontrolsex.asp">INITCOMMONCONTROLSEX</a> Structure.  
  
***  

