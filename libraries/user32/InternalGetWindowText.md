[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternalGetWindowText
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### This function is similar to the GetWindowText function. However, it obtains the window text directly from the window structure associated with the specified window"s handle and then always provides the text as a unicode string. 
***  


## Code examples:
[Simple Window Viewer](../../samples/sample_057.md)  
[Scanning the hierarchy of child windows down from the main VFP window](../../samples/sample_261.md)  

## Declaration:
```foxpro  
int InternalGetWindowText(
	HWND hWnd,
	LPWSTR lpString,
	int nMaxCount
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternalGetWindowText IN user32;
	INTEGER   hWnd,;
	STRING  @ lpString,;
	INTEGER   nMaxCount
  
```  
***  


## Parameters:
hWnd
[in] Handle to the window or control containing the text. 

lpString
[out] Pointer to the wide character buffer that receives the text. 

nMaxCount
[in] Specifies the maximum number of characters to copy to the buffer, including the NULL character.
  
***  


## Return value:
If the function succeeds, the return value is the length, in characters, of the copied string, not including the terminating NULL character.  
***  


## Comments:
MSDN: This is unlike GetWindowText which obtains the text by sending the window a WM_GETTEXT message. If the specified window is a control, the text of the control is obtained.   
  
***  

