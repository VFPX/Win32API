[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindCloseChangeNotification
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
hChangeHandle 
[in] Handle to a change notification handle created by the FindFirstChangeNotification function.  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. 
  
***  

