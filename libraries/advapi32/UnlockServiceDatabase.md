<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : UnlockServiceDatabase
Group: Service - Library: advapi32    
***  


#### The UnlockServiceDatabase function unlocks a service control manager database by releasing the specified lock.

***  


## Code examples:
[Encapsulating access to the Windows Services in a class](../../samples/sample_476.md)  

## Declaration:
```foxpro  
BOOL UnlockServiceDatabase(
  SC_LOCK ScLock
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UnlockServiceDatabase IN advapi32;
	INTEGER ScLock  
```  
***  


## Parameters:
```txt  
ScLock
[in] Lock obtained from a previous call to the LockServiceDatabase function.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

