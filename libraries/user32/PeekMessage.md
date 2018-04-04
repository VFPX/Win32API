[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PeekMessage
Group: [Message and Message Queue](../../functions_group.md#Message_and_Message_Queue)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The PeekMessage function dispatches incoming sent messages, checks the thread message queue for a posted message, and retrieves the message (if any exist).
***  


## Declaration:
```foxpro  
BOOL PeekMessage(
	LPMSG lpMsg,
	HWND hWnd,
	UINT wMsgFilterMin,
	UINT wMsgFilterMax,
	UINT wRemoveMsg
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PeekMessage IN user32;
	STRING  @ lpMsg,;
	INTEGER   hWnd,;
	INTEGER   wMsgFilterMin,;
	INTEGER   wMsgFilterMax,;
	INTEGER   wRemoveMsg
  
```  
***  


## Parameters:
lpMsg
[out] Pointer to an MSG structure that receives message information.

hWnd
[in] Handle to the window whose messages are to be examined. The window must belong to the current thread. 

wMsgFilterMin
[in] Specifies the value of the first message in the range of messages to be examined.

wMsgFilterMax
[in] Specifies the value of the last message in the range of messages to be examined.

wRemoveMsg
[in] Specifies how messages are handled.

  
***  


## Return value:
If a message is available, the return value is nonzero.  
***  


## Comments:
If hWnd is NULL, PeekMessage retrieves messages for any window that belongs to the current thread, and any messages on the current thread"s message queue whose hwnd value is NULL (see the MSG structure).  
  
***  

