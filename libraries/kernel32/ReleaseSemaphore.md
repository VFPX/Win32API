[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ReleaseSemaphore
Group: [Synchronization](../../functions_group.md#Synchronization)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The ReleaseSemaphore function increases the count of the specified semaphore object by a specified amount
***  


## Code examples:
[Using the Semaphore object](../../samples/sample_008.md)  

## Declaration:
```foxpro  
BOOL ReleaseSemaphore(
    HANDLE  hSemaphore,	// handle of the semaphore object
    LONG  cReleaseCount,	// amount to add to current count
    LPLONG  lplPreviousCount 	// address of previous count
   );	
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ReleaseSemaphore IN kernel32;
	INTEGER   hSemaphore,;
	INTEGER   lReleaseCount,;
	INTEGER @ lpPreviousCount
  
```  
***  


## Parameters:
hSemaphore
Identifies the semaphore object

cReleaseCount
Specifies the amount by which the semaphore object"s current count is to be increased

lplPreviousCount
Points to a 32-bit variable to receive the previous count for the semaphore  
***  


## Return value:
If the function succeeds, the return value is TRUE  
***  

