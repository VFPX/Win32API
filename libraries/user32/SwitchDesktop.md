<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SwitchDesktop
Group: Window Station and Desktop - Library: user32    
***  


#### Makes a desktop visible and activates it. This enables the desktop to receive input from the user.
***  


## Code examples:
[How to prevent users from accessing the Windows Desktop and from switching to other applications](../../samples/sample_492.md)  

## Declaration:
```foxpro  
BOOL SwitchDesktop(
	HDESK hDesktop
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SwitchDesktop IN user32;
	INTEGER hDesktop  
```  
***  


## Parameters:
```txt  
hDesktop
[in] Handle to the desktop to be made visible and active. This handle is returned by the CreateDesktop and OpenDesktop functions.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: CreateDesktop, OpenDesktop   
  
***  

