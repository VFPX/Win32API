<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PostMessage
Group: Message and Message Queue - Library: user32    
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
```txt  
hWnd
[in] Handle to the window whose window procedure is to receive the message.

Msg
[in] Specifies the message to be posted.

wParam
[in] Specifies additional message-specific information.

lParam
[in] Specifies additional message-specific information.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

