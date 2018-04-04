[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RealGetWindowClass
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves a string that specifies the window type
***  


## Code examples:
[Obtaining window class name for the main VFP window](../../samples/sample_049.md)  
[Creating a window using CreateWindowEx function](../../samples/sample_050.md)  
[Scanning the hierarchy of child windows down from the main VFP window](../../samples/sample_261.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  
[How to make a VFP form fading out when released (GDI+ version)](../../samples/sample_527.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  

## Declaration:
```foxpro  
UINT RealGetWindowClass(
  HWND  hwnd,      // handle to window
  LPTSTR pszType,  // window type buffer
  UINT  cchType    // size of window type buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RealGetWindowClass IN user32;
	INTEGER  hwnd,;
	STRING @ pszType,;
	INTEGER  cchType  
```  
***  


## Parameters:
hwnd 
[in] Handle to the window whose type will be retrieved. 

pszType 
[out] Pointer to a string that receives the window type. 

cchType 
[in] Specifies the length, in TCHARs, of the buffer pointed to by the pszType parameter  
***  


## Return value:
If the function succeeds, the return value is the number of TCHARs copied to the specified buffer  
***  


## Comments:
Looking for possible applications for this function, so far I used it in combination with the CreateWindow function  
  
***  

