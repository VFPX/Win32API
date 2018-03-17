<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : Shell_NotifyIcon
Group: Shell Functions - Library: shell32    
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
```txt  
dwMessage
[in] Variable of type DWORD that specifies the action to be taken.

lpdata
[in] Address of a NOTIFYICONDATA structure. The content of the structure depends on the value of dwMessage.  
```  
***  


## Return value:
Returns TRUE if successful or FALSE otherwise.  
***  

