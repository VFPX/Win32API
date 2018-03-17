<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : MQDeleteQueue
Group: Message and Message Queue - Library: mqrt    
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
```txt  
lpwcsFormatName
[in] Pointer to the format name string of the queue to be deleted.  
```  
***  


## Return value:
MQ_OK (0) indicates success.  
***  


## Comments:
#DEFINE MQ_ERROR_ILLEGAL_FORMATNAME 0xC00E001E  
#DEFINE MQ_ERROR_QUEUE_NOT_FOUND 0xC00E0003  
  
***  

