[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MQPurgeQueue
Group: [Message and Message Queue](../../functions_group.md#Message_and_Message_Queue)  -  Library: [mqrt](../../Libraries.md#mqrt)  
***  


#### Deletes all of the messages in a queue.
***  


## Declaration:
```foxpro  
HRESULT APIENTRY MQPurgeQueue(
  HANDLE hQueue
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MQPurgeQueue IN mqrt;
	INTEGER hQueue  
```  
***  


## Parameters:
hQueue
[in] The handle to the queue to be purged.  
***  


## Return value:
MQ_OK (0) indicates success.  
***  


## Comments:
See also: [MQOpenQueue](../mqrt/MQOpenQueue.md), [MQCloseQueue](../mqrt/MQCloseQueue.md).  
  
#DEFINE MQ_ERROR_INVALID_HANDLE 0xC00E0007  
  
***  

