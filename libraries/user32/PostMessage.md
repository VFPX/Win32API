[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PostMessage
Group: [Message and Message Queue](../../functions_group.md#Message_and_Message_Queue)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Places (posts) a message in the message queue associated with the thread that created the specified window and returns without waiting for the thread to process the message.

***  


## Code examples:
[How to activate Windows Calculator](../../samples/sample_026.md)  
[Terminating all running applications from a VFP program](../../samples/sample_243.md)  

## Declaration:
```foxpro  
BOOL PostMessage(
  HWND hWnd,      // handle to destination window
  UINT Msg,       // message
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT PostMessage IN user32;
	INTEGER   hWnd,;
	INTEGER   Msg,;
	STRING  @ wParam,;
	INTEGER   lParam
  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window whose window procedure is to receive the message. 

Msg 
[in] Specifies the message to be posted. 

wParam 
[in] Specifies additional message-specific information. 

lParam 
[in] Specifies additional message-specific information.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

