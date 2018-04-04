[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetProp
Group: [Window Property](../../functions_group.md#Window_Property)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Adds a new entry or changes an existing entry in the property list of the specified window.
***  


## Code examples:
[How to write and read Window Properties for the specified window](../../samples/sample_205.md)  

## Declaration:
```foxpro  
BOOL SetProp(
  HWND hWnd,         // handle to window
  LPCTSTR lpString,  // atom or string
  HANDLE hData       // handle to data
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetProp IN user32;
	INTEGER hWnd,;
	STRING  lpString,;
	INTEGER hData
  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window whose property list receives the new entry. 

lpString 
[in] Pointer to a null-terminated string or contains an atom that identifies a string. 

hData 
[in] Handle to the data to be copied to the property list. The data handle can identify any value useful to the application.   
***  


## Return value:
If the data handle and string are added to the property list, the return value is nonzero. If the function fails, the return value is zero.  
***  


## Comments:
If VFP application sets a property for a window, it should allocate required amount of memory for the property data (for example, by calling GlobalAlloc), and hold this memory either until the window is destroyed, or the RemoveProp is called.  
  
***  

