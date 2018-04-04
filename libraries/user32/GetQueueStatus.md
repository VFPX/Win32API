[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetQueueStatus
Group: [Message and Message Queue](../../functions_group.md#Message_and_Message_Queue)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetQueueStatus function indicates the type of messages found in the calling thread"s message queue.
***  


## Code examples:
[Simulating DOEVENTS](../../samples/sample_163.md)  

## Declaration:
```foxpro  
DWORD GetQueueStatus(
  UINT flags   // message types
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetQueueStatus IN user32;
	INTEGER flags  
```  
***  


## Parameters:
flags 
[in] Specifies the types of messages for which to check.  
***  


## Return value:
The high-order word of the return value indicates the types of messages currently in the queue. The low-order word indicates the types of messages that have been added to the queue and that are still in the queue since the last call to the GetQueueStatus, GetMessage, or PeekMessage function.   
***  

