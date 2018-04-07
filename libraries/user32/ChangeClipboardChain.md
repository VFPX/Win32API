[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ChangeClipboardChain
Group: [Clipboard](../../functions_group.md#Clipboard)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Removes a specified window from the chain of clipboard viewers.
***  


## Code examples:
[How to disable the Windows Clipboard (VFP9)](../../samples/sample_488.md)  

## Declaration:
```foxpro  
BOOL ChangeClipboardChain(
	HWND hWndRemove,
	HWND hWndNewNext
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ChangeClipboardChain IN user32;
	INTEGER hWndRemove,;
	INTEGER hWndNewNext
  
```  
***  


## Parameters:
hWndRemove
[in] Handle to the window to be removed from the chain. The handle must have been passed to the SetClipboardViewer function.

hWndNewNext
[in] Handle to the window that follows the hWndRemove window in the clipboard viewer chain.  
***  


## Return value:
... is indecisive. 

It indicates the result of passing the WM_CHANGECBCHAIN message to the windows in the clipboard viewer chain. Because a window in the chain typically returns FALSE when it processes WM_CHANGECBCHAIN, the return value from ChangeClipboardChain is typically FALSE.  
***  


## Comments:
The window identified by hWndNewNext replaces the hWndRemove window in the chain. The SetClipboardViewer function sends a WM_CHANGECBCHAIN message to the first window in the clipboard viewer chain.   
  
See also: [SetClipboardViewer](../user32/SetClipboardViewer.md), [AddClipboardFormatListener](../user32/AddClipboardFormatListener.md), [RemoveClipboardFormatListener](../user32/RemoveClipboardFormatListener.md).  
  
***  

