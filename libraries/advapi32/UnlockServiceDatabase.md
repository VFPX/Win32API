[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UnlockServiceDatabase
Group: [Service](../../functions_group.md#Service)  -  Library: [advapi32](../../Libraries.md#advapi32)  
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
ScLock 
[in] Lock obtained from a previous call to the LockServiceDatabase function.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

