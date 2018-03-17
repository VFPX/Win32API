<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetQueueStatus
Group: Message and Message Queue - Library: user32    
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
```txt  
flags
[in] Specifies the types of messages for which to check.  
```  
***  


## Return value:
The high-order word of the return value indicates the types of messages currently in the queue. The low-order word indicates the types of messages that have been added to the queue and that are still in the queue since the last call to the GetQueueStatus, GetMessage, or PeekMessage function.   
***  

