[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RemoveProp
Group: [Window Property](../../functions_group.md#Window_Property)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The RemoveProp function removes an entry from the property list of the specified window. The specified character string identifies the entry to be removed. 
***  


## Declaration:
```foxpro  
HANDLE RemoveProp(
  HWND hWnd,         // handle to window
  LPCTSTR lpString   // atom or string
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RemoveProp IN user32;
	INTEGER hWnd,;
	STRING lpString
  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window whose property list is to be changed. 

lpString 
[in] Pointer to a null-terminated character string or contains an atom that identifies a string.   
***  


## Return value:
The return value identifies the specified data. If the data cannot be found in the specified property list, the return value is NULL.  
***  

