
## Function name : AddClipboardFormatListener
Group: Clipboard - Library: user32    
***  


#### Places the given window in the system-maintained clipboard format listener list.
***  


## Code examples:
[Monitoring clipboard content changes (VFP9)](../../samples/sample_601.md)  

## Declaration:
```foxpro  
BOOL WINAPI AddClipboardFormatListener(
  _In_  HWND hwnd
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AddClipboardFormatListener IN user32;
	INTEGER hWindow  
```  
***  


## Parameters:
hwnd [in]
Type: HWND
A handle to the window to be placed in the clipboard format listener list.  
***  


## Return value:
Returns TRUE if successful, FALSE otherwise. Call GetLastError for additional details.  
***  


## Comments:
When a window has been added to the clipboard format listener list, it is posted a WM_CLIPBOARDUPDATE (0x031D) message whenever the contents of the clipboard have changed.  
  
See also: RemoveClipboardFormatListener, ChangeClipboardChain, SetClipboardViewer    
  
***  

