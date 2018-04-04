[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : Shell_NotifyIcon
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Sends a message to the taskbar"s status area.
***  


## Code examples:
[Displaying icons in the system tray (VFP9)](../../samples/sample_235.md)  
[Using FoxTray ActiveX control: System Tray Icon and menu attached to VFP form](../../samples/sample_336.md)  

## Declaration:
```foxpro  
BOOL Shell_NotifyIcon(
    DWORD dwMessage,
    PNOTIFYICONDATA lpdata
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER Shell_NotifyIcon IN shell32;
	INTEGER dwMsg,;
	STRING @lpdata  
```  
***  


## Parameters:
dwMessage 
[in] Variable of type DWORD that specifies the action to be taken. 

lpdata 
[in] Address of a NOTIFYICONDATA structure. The content of the structure depends on the value of dwMessage.   
***  


## Return value:
Returns TRUE if successful or FALSE otherwise.  
***  

