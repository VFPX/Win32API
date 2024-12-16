[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetWindowsHookEx
Group: [Hook](../../functions_group.md#Hook)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Installs an application-defined hook procedure into a hook chain.
***  


## Declaration:
```foxpro  
HHOOK SetWindowsHookEx(
	int idHook,
	HOOKPROC lpfn,
	HINSTANCE hMod,
	DWORD dwThreadId
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetWindowsHookEx IN user32;
	INTEGER idHook,;
	INTEGER lpfn,;
	INTEGER hMod,;
	LONG dwThreadId  
```  
***  


## Parameters:
idHook
[in] Specifies the type of hook procedure to be installed.

lpfn
[in] Pointer to the hook procedure.

hMod
[in] Handle to the DLL containing the hook procedure pointed to by the lpfn parameter.

dwThreadId
[in] Specifies the identifier of the thread with which the hook procedure is to be associated.  
***  


## Return value:
If the function succeeds, the return value is the handle to the hook procedure.  
***  


## Comments:
See also: [UnhookWindowsHookEx](../user32/UnhookWindowsHookEx.md), [MessageBox](../user32/MessageBox.md).  
  
It is highly unlikely someone would call this function from pure VFP code. This page might easily contain no VFP declaration for that reason.   
  
Though when called from FLL or DLL library, the SetWindowsHookEx can enable VFP application with valuable and unique functionality.   
  
For example, provided a certain windows hook set, each following MESSAGEBOX() dialog within current VFP session would appear not centered but instead would automatically position itself at the specified screen location.  
  
* * *  
Highly recommended reading: Craig Boyd's SPS blog entry <a href="http://www.sweetpotatosoftware.com/spsblog/2005/08/07/BindEventOnSteroids.aspx">BindEvent on Steroids</a>.  
  
***  

