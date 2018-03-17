<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : MQCloseQueue
Group: Message and Message Queue - Library: mqrt    
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
```txt  
hQueue
[in] The handle to the queue you want to close.  
```  
***  


## Return value:
MQ_OK (0) indicates success.  
***  


## Comments:
See also: MQOpenQueue   
  
#DEFINE MQ_ERROR_INVALID_HANDLE 0xC00E0007  
  
***  

