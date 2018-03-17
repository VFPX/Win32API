<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetClipboardSequenceNumber
Group: Clipboard - Library: user32    
***  


#### Retrieves the clipboard sequence number for the current window station.
***  


## Declaration:
```foxpro  
DWORD WINAPI GetClipboardSequenceNumber(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetClipboardSequenceNumber IN user32  
```  
***  


## Parameters:
```txt  
This function has no parameters.  
```  
***  


## Return value:
The return value is the clipboard sequence number. If you do not have WINSTA_ACCESSCLIPBOARD access to the window station, the function returns zero.  
***  


## Comments:
This number is incremented whenever the contents of the clipboard change or the clipboard is emptied.   
  
The system keeps a serial number for the clipboard for each <a href="https://msdn.microsoft.com/en-us/library/windows/desktop/ms687096(v=vs.85).aspx">window station</a>.   
  
A copy-paste adds as many increments as the number of data formats placed on the clipboard.  
  
***  

