[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InitCommonControlsEx
Group: [Windows Controls](../../functions_group.md#Windows_Controls)  -  Library: [comctl32](../../Libraries.md#comctl32)  
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
lpInitCtrls
Pointer to an INITCOMMONCONTROLSEX structure that contains information specifying which control classes will be registered. 
  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.   
***  


## Comments:
<a href="http://msdn.microsoft.com/library/default.asp?url=/library/en-us/shellcc/platform/commctls/common/structures/initcommoncontrolsex.asp">INITCOMMONCONTROLSEX</a> Structure.  
  
***  

