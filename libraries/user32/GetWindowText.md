[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetWindowText
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetWindowText function copies the text of the specified window"s title bar (if it has one) into a buffer
***  


## Code examples:
[Listing child windows for the Windows desktop](../../samples/sample_027.md)  
[Who owns the Windows Clipboard](../../samples/sample_029.md)  
[Who is the first in viewing the Clipboard](../../samples/sample_030.md)  
[Scanning a hierarchy of child windows down from the Windows Desktop](../../samples/sample_045.md)  
[Obtaining window class name for the main VFP window](../../samples/sample_049.md)  
[Simple Window Viewer](../../samples/sample_057.md)  
[Retrieving top-child window for the VFP form](../../samples/sample_209.md)  
[Terminating all running applications from a VFP program](../../samples/sample_243.md)  
[Minimizing all running applications](../../samples/sample_244.md)  
[Scanning the hierarchy of child windows down from the main VFP window](../../samples/sample_261.md)  
[The window and its ancestors](../../samples/sample_266.md)  
[Reading the structure of VFP main menu](../../samples/sample_337.md)  
[Retrieveing information about the active window (even if it is not owned by the calling process)](../../samples/sample_371.md)  
[Extended MessageBox Class](../../samples/sample_418.md)  
[How to change the name and the size of the font in the MessageBox dialog](../../samples/sample_434.md)  
[How to position the GETPRINTER() dialog](../../samples/sample_482.md)  
[Accessing Adobe Reader 7.0 main menu from VFP application](../../samples/sample_495.md)  
[How to control Adobe Reader 9.0 (SDI mode) from VFP application](../../samples/sample_550.md)  

## Declaration:
```foxpro  
int GetWindowText(
    HWND  hWnd,	// handle of window or control with text
    LPTSTR  lpString,	// address of buffer for text
    int  nMaxCount 	// maximum number of characters to copy
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetWindowText IN user32;
	INTEGER hwnd,;
	STRING @lpString,;
	INTEGER cch  
```  
***  


## Parameters:
hWnd
Identifies the window or control containing the text. 

lpString
Points to the buffer that will receive the text. 

nMaxCount
Specifies the maximum number of characters to copy to the buffer. If the text exceeds this limit, it is truncated  
***  


## Return value:
If the function succeeds, the return value is the length, in characters, of the copied string  
***  


## Comments:
Read this: <a href="http://blogs.msdn.com/oldnewthing/archive/2003/08/21/54675.aspx">The secret life of GetWindowText</a> on <Em>The Old New Thing</Em>.  
  
***  

