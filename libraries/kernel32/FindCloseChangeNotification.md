<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FindCloseChangeNotification
Group: File Management - Library: kernel32    
***  


#### Stops change notification handle monitoring.
***  


## Code examples:
[Monitoring changes in a directory](../../samples/sample_117.md)  

## Declaration:
```foxpro  
BOOL FindCloseChangeNotification(
  HANDLE hChangeHandle   // handle to change notification
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT FindCloseChangeNotification IN kernel32;
	INTEGER hChangeHandle  
```  
***  


## Parameters:
```txt  
hChangeHandle
[in] Handle to a change notification handle created by the FindFirstChangeNotification function.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. 
  
***  

