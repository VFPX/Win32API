<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : MQOpenQueue
Group: Message and Message Queue - Library: mqrt    
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
```txt  
wcsFormatName
[in] Pointer to the format name string of the queue you want to open.

dwAccess
[in] Specifies how the application accesses the queue (peek, send, or receive).

dwShareMode
[in] How the queue will be shared.

phQueue
[out] Pointer to a handle to the opened queue. If MQOpenQueue fails, a NULL pointer is returned.
  
```  
***  


## Return value:
MQ_OK (0) indicates success.  
***  


## Comments:
See also: MQCloseQueue, MQPathNameToFormatName   
  
#DEFINE MQ_RECEIVE_ACCESS 1  
#DEFINE MQ_SEND_ACCESS 2  
#DEFINE MQ_PEEK_ACCESS 32  
  
#DEFINE MQ_DENY_NONE 0  
#DEFINE MQ_DENY_RECEIVE_SHARE 1  
  
***  

