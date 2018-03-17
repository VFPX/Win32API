<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : MQHandleToFormatName
Group: Message and Message Queue - Library: mqrt    
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
```txt  
hQueue
[in] Handle to the queue or subqueue.

lpwcsFormatName
[out] Buffer to receive the format name for the queue.

lpdwCount
[in, out] On input, specifies the length of the lpwcsFormatName buffer (in Unicode characters).  
```  
***  


## Return value:
MQ_OK (0) indicates success.  
***  


## Comments:
On output, <Em>lpdwCount</Em> indicates the length of the returned format name string, including the null-terminating character.  
  
See also: MQPathNameToFormatName, MQOpenQueue   
  
***  

