[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DefWindowProc
Group: [Window Procedure](../../functions_group.md#Window_Procedure)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The DefWindowProc function calls the default window procedure to provide default processing for any window messages that an application does not process. This function ensures that every message is processed. DefWindowProc is called with the same parameters received by the window procedure. 
***  


## Declaration:
```foxpro  
LRESULT DefWindowProc(
	HWND hWnd,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DefWindowProc IN user32;
	LONG hWnd,;
	LONG Msg,;
	INTEGER wParam,;
	INTEGER lParam  
```  
***  


## Parameters:
hWnd
[in] Handle to the window procedure that received the message. 

Msg
[in] Specifies the message. 
wParam

[in] Specifies additional message information.

lParam
[in] Specifies additional message information.  
***  


## Return value:
The return value is the result of the message processing and depends on the message.  
***  


## Comments:
You hardly could have a reason to call this frunction directly from VFP code.  
  
***  

