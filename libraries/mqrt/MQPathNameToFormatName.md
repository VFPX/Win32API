[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MQPathNameToFormatName
Group: [Message and Message Queue](../../functions_group.md#Message_and_Message_Queue)  -  Library: [mqrt](../../Libraries.md#mqrt)  
***  


#### Returns a format name based on the path name provided.
***  


## Code examples:
[MSMQ: how to open a queue](../../samples/sample_603.md)  

## Declaration:
```foxpro  
HRESULT APIENTRY MQPathNameToFormatName(
  LPCWSTR lpwcsPathName,
  LPWSTR lpwcsFormatName,
  LPDWORD lpdwCount
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MQPathNameToFormatName IN mqrt;
	STRING lpwcsPathName,;
	STRING @lpwcsFormatName,;	
	INTEGER @lpdwCount  
```  
***  


## Parameters:
lpwcsPathName
[in] UNC or DNS path name of the queue. Either private or public Message Queuing path names are valid.

lpwcsFormatName
[out] Pointer to a buffer to receive the format name for the queue.

lpdwCount
[in, out] On input, specifies the length of the lpwcsFormatName buffer (in Unicode characters).   
***  


## Return value:
MQ_OK (0) indicates success.  
***  


## Comments:
See also: [MQHandleToFormatName](../mqrt/MQHandleToFormatName.md), [MQOpenQueue](../mqrt/MQOpenQueue.md).  
  
MQPathNameToFormatName fails if a queue does not exist, not accessible, the name is invalid etc.  
  
#DEFINE MQ_OK 0  
#DEFINE MQ_ERROR_FORMATNAME_BUFFER_TOO_SMALL 0xC00E001F  
#DEFINE MQ_ERROR_QUEUE_NOT_FOUND 0xC00E0003  
#DEFINE MQ_ERROR_INVALID_HANDLE 0xC00E0007  
  
***  

