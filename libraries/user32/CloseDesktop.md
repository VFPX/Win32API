[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CloseDesktop
Group: Window Station and Desktop - Library: user32    
***  


#### Closes an open handle to a desktop object.
***  


## Code examples:
[How to start the screen saver and how to find whether the screen saver is active](../../samples/sample_196.md)  
[How to prevent users from accessing the Windows Desktop and from switching to other applications](../../samples/sample_492.md)  

## Declaration:
```foxpro  
BOOL CloseDesktop(
	HDESK hDesktop
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CloseDesktop IN user32;
	INTEGER hDesktop  
```  
***  


## Parameters:
hDesktop 
[in] Handle to the desktop to be closed. This can be a handle returned by the CreateDesktop, OpenDesktop, or OpenInputDesktop functions.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Do not specify the handle returned by the GetThreadDesktop function.  
  
The CloseDesktop function will fail if any thread in the calling process is using the specified desktop handle or if the handle refers to the initial desktop of the calling process.  
  
See also: CreateDesktop, OpenDesktop, OpenInputDesktop.  
  
***  

