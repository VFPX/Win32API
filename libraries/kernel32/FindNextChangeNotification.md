[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindNextChangeNotification
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Requests that the operating system signal a change notification handle the next time it detects an appropriate change.
***  


## Code examples:
[Monitoring changes in a directory](../../samples/sample_117.md)  

## Declaration:
```foxpro  
BOOL FindNextChangeNotification(
  HANDLE hChangeHandle   // handle to change notification
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT FindNextChangeNotification IN kernel32;
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


## Comments:
FindNextChangeNotification should not be used more than once on the same handle without using one of the wait functions. When hChangeHandle is no longer needed, close it by using the FindCloseChangeNotification function.  
  
***  

