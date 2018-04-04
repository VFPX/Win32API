[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateSemaphore
Group: [Synchronization](../../functions_group.md#Synchronization)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The CreateSemaphore function creates a named or unnamed semaphore object
***  


## Code examples:
[Using the Semaphore object](../../samples/sample_008.md)  
[Using the Semaphore object to allow only one instance of VFP application running](../../samples/sample_147.md)  

## Declaration:
```foxpro  
HANDLE CreateSemaphore(
    LPSECURITY_ATTRIBUTES  lpSemaphoreAttrib, //security attrib. address
    LONG  lInitialCount,	//initial count
    LONG  lMaximumCount,	//maximum count
    LPCTSTR  lpName 	//address of semaphore-object name
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateSemaphore IN kernel32;
	STRING @ lpSemaphoreAttrib,;
	INTEGER  lInitialCount,;
	INTEGER  lMaximumCount,;
	STRING   lpName
  
```  
***  


## Parameters:
lpSemaphoreAttributes
Points to a SECURITY_ATTRIBUTES structure

lInitialCount
Specifies an initial count for the semaphore object

lMaximumCount
Specifies the maximum count for the semaphore object

lpName
Points to a null-terminated string specifying the name of the semaphore object  
***  


## Return value:
If the function succeeds, the return value is a handle of the semaphore object  
***  

