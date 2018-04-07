[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetThreadDesktop
Group: [Window Station and Desktop](../../functions_group.md#Window_Station_and_Desktop)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Assigns the specified desktop to the calling thread. All subsequent operations on the desktop use the access rights granted to hDesktop.
***  


## Code examples:
[How to prevent users from accessing the Windows Desktop and from switching to other applications](../../samples/sample_492.md)  

## Declaration:
```foxpro  
BOOL SetThreadDesktop(
	HDESK hDesktop
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetThreadDesktop IN user32;
	INTEGER hDesktop  
```  
***  


## Parameters:
hDesktop 
[in] Handle to the desktop to be assigned to the calling thread. This handle is returned by the CreateDesktop, GetThreadDesktop, OpenDesktop, or OpenInputDesktop function.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: [CreateDesktop](../user32/CreateDesktop.md), [GetThreadDesktop](../user32/GetThreadDesktop.md), [OpenDesktop](../user32/OpenDesktop.md), [SetProcessWindowStation](..//SetProcessWindowStation.md).  
  
***  

