[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MQHandleToFormatName
Group: [Message and Message Queue](../../functions_group.md#Message_and_Message_Queue)  -  Library: [mqrt](../../Libraries.md#mqrt)  
***  


#### Returns a format name for the queue or subqueue based on its handle.
***  


## Declaration:
```foxpro  
HRESULT APIENTRY MQHandleToFormatName(
  QUEUEHANDLE hQueue,
  LPWSTR lpwcsFormatName,
  LPDWORD lpdwCount
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MQHandleToFormatName IN mqrt;
	INTEGER hQueue,;
	STRING @lpwcsFormatName,;
	INTEGER @lpdwCount  
```  
***  


## Parameters:
hQueue
[in] Handle to the queue or subqueue.

lpwcsFormatName
[out] Buffer to receive the format name for the queue.

lpdwCount
[in, out] On input, specifies the length of the lpwcsFormatName buffer (in Unicode characters).  
***  


## Return value:
MQ_OK (0) indicates success.  
***  


## Comments:
On output, <Em>lpdwCount</Em> indicates the length of the returned format name string, including the null-terminating character.  
  
See also: [MQPathNameToFormatName](../mqrt/MQPathNameToFormatName.md), [MQOpenQueue](../mqrt/MQOpenQueue.md).  
  
***  

