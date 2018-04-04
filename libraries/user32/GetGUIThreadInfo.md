[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetGUIThreadInfo
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves information about the active window or a specified graphical user interface (GUI) thread. 
***  


## Code examples:
[Retrieveing information about the active window (even if it is not owned by the calling process)](../../samples/sample_371.md)  

## Declaration:
```foxpro  
BOOL GetGUIThreadInfo(
	DWORD idThread,
	LPGUITHREADINFO lpgui
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetGUIThreadInfo IN user32;
	INTEGER   idThread,;
	STRING  @ lpgui  
```  
***  


## Parameters:
idThread
[in] Identifies the thread for which information is to be retrieved.

lpgui
[out] Pointer to a GUITHREADINFO structure that receives information describing the thread.
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
MSDN: This function succeeds even if the active window is not owned by the calling process. If the specified thread does not exist or have an input queue, the function will fail.   
  
This function is useful for retrieving out-of-context information about a thread. The information retrieved is the same as if an application retrieved the information about itself.   
  
***  

