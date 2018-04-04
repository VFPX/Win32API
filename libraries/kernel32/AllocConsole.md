[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AllocConsole
Group: [Console](../../functions_group.md#Console)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The AllocConsole function allocates a new console for the calling process.
***  


## Code examples:
[Saying "Hello World!" with VFP and WinAPI](../../samples/sample_119.md)  
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  

## Declaration:
```foxpro  
BOOL AllocConsole(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AllocConsole IN kernel32  
```  
***  


## Parameters:
This function has no parameters.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
A process can be associated with only one console, so the AllocConsole function fails if the calling process already has a console. A process can use the FreeConsole function to detach itself from its current console, then it can call AllocConsole to create a new console or AttachConsole to attach to another console.  
  
***  

