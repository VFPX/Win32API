[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindFirstChangeNotification
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Creates a change notification handle and sets up initial change notification filter conditions.

A wait on a notification handle succeeds when a change matching the filter conditions occurs in the specified directory or subtree.

***  


## Code examples:
[Monitoring changes in a directory](../../samples/sample_117.md)  

## Declaration:
```foxpro  
HANDLE FindFirstChangeNotification(
  LPCTSTR lpPathName,    // directory name
  BOOL bWatchSubtree,    // monitoring option
  DWORD dwNotifyFilter   // filter conditions
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindFirstChangeNotification IN kernel32;
	STRING  lpPathName,;
	INTEGER bWatchSubtree,;
	INTEGER dwNotifyFilter  
```  
***  


## Parameters:
lpPathName 
[in] Pointer to a null-terminated string that specifies the path of the directory to watch. 

bWatchSubtree 
[in] Specifies whether the function will monitor the directory or the directory tree. 

dwNotifyFilter 
[in] Specifies the filter conditions that satisfy a change notification wait.  
***  


## Return value:
If the function succeeds, the return value is a handle to a find change notification object.  
***  


## Comments:
The wait functions can monitor the specified directory or subtree by using the handle returned by the FindFirstChangeNotification function:   
  
SignalObjectAndWait, WaitForSingleObject, WaitForSingleObjectEx, WaitForMultipleObjects, WaitForMultipleObjectsEx, MsgWaitForMultipleObjects, MsgWaitForMultipleObjectsEx.  
  
***  

