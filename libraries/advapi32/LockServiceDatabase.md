[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LockServiceDatabase
Group: [Service](../../functions_group.md#Service)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The LockServiceDatabase function requests ownership of the service control manager database lock. Only one process can own the lock at any given time.

***  


## Code examples:
[Encapsulating access to the Windows Services in a class](../../samples/sample_476.md)  

## Declaration:
```foxpro  
SC_LOCK LockServiceDatabase(
  SC_HANDLE hSCManager
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LockServiceDatabase IN advapi32;
	INTEGER hSCManager  
```  
***  


## Parameters:
hSCManager 
[in] Handle to the service control manager database.  
***  


## Return value:
If the function succeeds, the return value is a lock to the specified service control manager database.  
***  


## Comments:
The <Em>hSCManager</Em> handle is returned by the OpenSCManager function, and must have the SC_MANAGER_LOCK access right.  
  
A call to the StartService function to start a service in a locked database fails. No other service control manager functions are affected by a lock.  
  
See also: [UnlockServiceDatabase](../advapi32/UnlockServiceDatabase.md), [OpenSCManager](../advapi32/OpenSCManager.md).  
  
***  

