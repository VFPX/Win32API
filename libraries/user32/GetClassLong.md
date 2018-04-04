[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetClassLong
Group: [Window Class](../../functions_group.md#Window_Class)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves the specified 32-bit (long) value from the WNDCLASSEX structure associated with the specified window.
***  


## Code examples:
[Retrieving long values associated with the class of the VFP window](../../samples/sample_204.md)  

## Declaration:
```foxpro  
DWORD GetClassLong(
  HWND hWnd,  // handle to window
  int nIndex  // offset of value to retrieve
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetClassLong IN user32;
	INTEGER hWnd,;
	INTEGER nIdx  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window and, indirectly, the class to which the window belongs. 

nIndex 
[in] Specifies the 32-bit value to retrieve. 

  
***  


## Return value:
If the function succeeds, the return value is the requested 32-bit value. If the function fails, the return value is zero.  
***  


## Comments:
Within FoxPro this function is more handy comparing to the GetClassInfo and GetClassInfoEx for retrieving most of the window class propeties.  
  
Also this function completely supersedes the GetWindowWord function, which is provided only for compatibility with 16-bit versions of Windows.  
  
***  

