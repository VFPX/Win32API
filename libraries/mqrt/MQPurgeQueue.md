<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : MQPurgeQueue
Group: Message and Message Queue - Library: mqrt    
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
```txt  
hQueue
[in] The handle to the queue to be purged.  
```  
***  


## Return value:
MQ_OK (0) indicates success.  
***  


## Comments:
See also: MQOpenQueue, MQCloseQueue   
  
#DEFINE MQ_ERROR_INVALID_HANDLE 0xC00E0007  
  
***  

