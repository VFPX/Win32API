[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MQDeleteQueue
Group: [Message and Message Queue](../../functions_group.md#Message_and_Message_Queue)  -  Library: [mqrt](../../Libraries.md#mqrt)  
***  


#### Deletes a queue from the directory service (in the case of public queues) or from the local computer (in the case of private queues).
***  


## Declaration:
```foxpro  
HRESULT APIENTRY MQDeleteQueue(
  LPCWSTR lpwcsFormatName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MQDeleteQueue IN mqrt;
	STRING lpwcsFormatName
  
```  
***  


## Parameters:
lpwcsFormatName
[in] Pointer to the format name string of the queue to be deleted.  
***  


## Return value:
MQ_OK (0) indicates success.  
***  


## Comments:
#DEFINE MQ_ERROR_ILLEGAL_FORMATNAME 0xC00E001E  
#DEFINE MQ_ERROR_QUEUE_NOT_FOUND 0xC00E0003  
  
***  

