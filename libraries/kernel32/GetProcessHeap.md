<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetProcessHeap
Group: Memory Management - Library: kernel32    
***  


#### The GetProcessHeap function obtains a handle to the heap of the calling process. This handle can then be used in subsequent calls to the HeapAlloc, HeapReAlloc, HeapFree, and HeapSize functions.
***  


## Code examples:
[Using the heap of the calling process to allocate memory blocks](../../samples/sample_199.md)  
[Validating the heap of the calling process](../../samples/sample_200.md)  

## Declaration:
```foxpro  
HANDLE GetProcessHeap(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetProcessHeap IN kernel32  
```  
***  


## Parameters:
```txt  
This function has no parameters.   
```  
***  


## Return value:
If the function succeeds, the return value is a handle to the calling process"s heap. If the function fails, the return value is NULL. 
  
***  


## Comments:
MSDN: The GetProcessHeap function allows you to allocate memory from the process heap without having to first create a heap with the HeapCreate function. The handle obtained by calling this function should not be used in calls to the HeapDestroy function.  
  
***  

