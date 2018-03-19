
## Function name : FreeConsole
Group: Console - Library: kernel32    
***  


#### The FreeConsole function detaches the calling process from its console.
***  


## Code examples:
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  

## Declaration:
```foxpro  
BOOL FreeConsole(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FreeConsole IN kernel32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
A process can use FreeConsole to detach itself from its current console, and then it can call the AllocConsole function to create a new console or AttachConsole to attach to another console.  
  
***  
