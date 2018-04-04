[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FlashWindowEx
Group: [Error Handling](../../functions_group.md#Error_Handling)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The FlashWindowEx function flashes the specified window. It does not change the active state of the window.
***  


## Code examples:
[Using FlashWindowEx to flash the taskbar button of the VFP application](../../samples/sample_271.md)  

## Declaration:
```foxpro  
BOOL FlashWindowEx(
  PFLASHWINFO pfwi  // flash status information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FlashWindowEx IN user32;
	STRING pfwi
  
```  
***  


## Parameters:
pfwi 
[in] Pointer to the FLASHWINFO structure.   
***  


## Return value:
The return value specifies the window"s state before the call to the FlashWindowEx function.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows 2000 and later.  
Windows 95/98/Me: Included in Windows 98 and later.  
  
***  

