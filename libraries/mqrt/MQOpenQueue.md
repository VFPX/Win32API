[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MQOpenQueue
Group: [Message and Message Queue](../../functions_group.md#Message_and_Message_Queue)  -  Library: [mqrt](../../Libraries.md#mqrt)  
***  


#### Opens a queue for sending, peeking at, retrieving, or purging messages. 
***  


## Code examples:
[MSMQ: how to open a queue](../../samples/sample_603.md)  

## Declaration:
```foxpro  
HRESULT APIENTRY MQOpenQueue(
  LPCWSTR lpwcsFormatName,
  DWORD dwAccess,
  DWORD dwShareMode,
  QUEUEHANDLE * phQueue
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MQOpenQueue IN mqrt;
	STRING lpwcsFormatName,;
	INTEGER dwAccess,;
	INTEGER dwShareMode,;
	INTEGER @phQueue  
```  
***  


## Parameters:
wcsFormatName
[in] Pointer to the format name string of the queue you want to open.

dwAccess
[in] Specifies how the application accesses the queue (peek, send, or receive).

dwShareMode
[in] How the queue will be shared.

phQueue
[out] Pointer to a handle to the opened queue. If MQOpenQueue fails, a NULL pointer is returned.
  
***  


## Return value:
MQ_OK (0) indicates success.  
***  


## Comments:
See also: [MQCloseQueue](../mqrt/MQCloseQueue.md), [MQPathNameToFormatName](../mqrt/MQPathNameToFormatName.md).  
  
#DEFINE MQ_RECEIVE_ACCESS 1  
#DEFINE MQ_SEND_ACCESS 2  
#DEFINE MQ_PEEK_ACCESS 32  
  
#DEFINE MQ_DENY_NONE 0  
#DEFINE MQ_DENY_RECEIVE_SHARE 1  
  
***  

