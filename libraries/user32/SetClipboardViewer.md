[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetClipboardViewer
Group: [Clipboard](../../functions_group.md#Clipboard)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Adds the specified window to the chain of clipboard viewers. 
***  


## Code examples:
[How to disable the Windows Clipboard (VFP9)](../../samples/sample_488.md)  

## Declaration:
```foxpro  
HWND SetClipboardViewer(
	HWND hWndNewViewer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetClipboardViewer IN user32;
	INTEGER hWndNewViewer  
```  
***  


## Parameters:
hWndNewViewer
[in] Handle to the window to be added to the clipboard chain.   
***  


## Return value:
If the function succeeds, the return value identifies the next window in the clipboard viewer chain. If an error occurs or there are no other windows in the clipboard viewer chain, the return value is NULL.  
***  


## Comments:
The windows that are part of the clipboard viewer chain, called clipboard viewer windows, must process the clipboard messages WM_CHANGECBCHAIN and WM_DRAWCLIPBOARD.   
  
Each clipboard viewer window calls the SendMessage function to pass these messages to the next window in the clipboard viewer chain.  
  
See also: [ChangeClipboardChain](../user32/ChangeClipboardChain.md), [AddClipboardFormatListener](../user32/AddClipboardFormatListener.md), [RemoveClipboardFormatListener](../user32/RemoveClipboardFormatListener.md).  
  
***  

