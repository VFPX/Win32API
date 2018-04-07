[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MQCloseQueue
Group: [Message and Message Queue](../../functions_group.md#Message_and_Message_Queue)  -  Library: [mqrt](../../Libraries.md#mqrt)  
***  


#### Closes a given queue or subqueue.
***  


## Code examples:
[MSMQ: how to open a queue](../../samples/sample_603.md)  

## Declaration:
```foxpro  
HRESULT APIENTRY MQCloseQueue(
  QUEUEHANDLE hQueue
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MQCloseQueue IN mqrt;
	INTEGER hQueue  
```  
***  


## Parameters:
hQueue
[in] The handle to the queue you want to close.  
***  


## Return value:
MQ_OK (0) indicates success.  
***  


## Comments:
See also: [MQOpenQueue](../mqrt/MQOpenQueue.md).  
  
#DEFINE MQ_ERROR_INVALID_HANDLE 0xC00E0007  
  
***  

