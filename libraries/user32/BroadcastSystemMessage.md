[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : BroadcastSystemMessage
Group: [Message and Message Queue](../../functions_group.md#Message_and_Message_Queue)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Sends a message to the specified recipients. The recipients can be applications, installable drivers, network drivers, system-level device drivers, or any combination of these system components.
***  


## Declaration:
```foxpro  
long BroadcastSystemMessage(
	DWORD dwFlags,
	LPDWORD lpdwRecipients,
	UINT uiMessage,
	WPARAM wParam,
	LPARAM lParam
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER BroadcastSystemMessage IN user32;
	INTEGER   dwFlags,;
	INTEGER @ lpdwRecipients,;
	INTEGER   uiMessage,;
	INTEGER   wParam,;
	INTEGER   lParam
  
```  
***  


## Parameters:
dwFlags
[in] Specifies the broadcast option.

lpdwRecipients
[in]  Pointer to a variable that contains and receives information about the recipients of the message.

uiMessage
[in] Specifies the message to be sent. 

wParam
[in] Specifies additional message-specific information. 

lParam
[in] Specifies additional message-specific information.   
***  


## Return value:
If the function succeeds, the return value is a positive value.  
***  


## Comments:
As an example, you can <Em>carefully</Em> try this code:
```foxpro
LOCAL nRecipients  
nRecipients = BSM_APPLICATIONS  
= BroadcastSystemMessage(BSF_POSTMESSAGE,;  
	@nRecipients, WM_CLOSE, 0, 0)
```
  
Most likely, it will close all open windows including the taskbar window, leaving you with a bare empty desktop. So before running this code make sure that all critical applications are closed.  
  
Note that <Em>nRecipients</Em> is initialized and then passed to the function by reference. For me, that does not make much sense, since the documentation for this function describes this parameter as <Em>input</Em> only. Who knows, it could be important for some modes, say for BSF_QUERY mode.  
  
In another example we may try to minimize all reachable windows:  
```foxpro
= BroadcastSystemMessage(BSF_POSTMESSAGE,;  
	@nRecipients, WM_SYSCOMMAND, SC_MINIMIZE, 0)
```
The function goes far beyond of what you could expect. Everything gets minimized, including system windows and windows that were initially hidden. So be ready to restart your computer right after you try the second example.  
  
***  

