<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ChangeDisplaySettings
Group: Device Context - Library: user32    
***  


#### The ChangeDisplaySettings function changes the settings of the default display device to the specified graphics mode. 
***  


## Code examples:
[How to change display settings: screen resolution, screen refresh rate](../../samples/sample_374.md)  

## Declaration:
```foxpro  
LONG ChangeDisplaySettings(
  LPDEVMODE lpDevMode,  // graphics mode
  DWORD dwflags         // graphics mode options
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ChangeDisplaySettings IN user32;
	STRING  @ lpDevMode,;
	INTEGER   dwflags
  
```  
***  


## Parameters:
```txt  
lpDevMode
[in] Pointer to a DEVMODE structure that describes the new graphics mode.

dwflags
[in] Indicates how the graphics mode should be changed.  
```  
***  


## Return value:
The ChangeDisplaySettings function returns one of the predefined values, e.g. DISP_CHANGE_SUCCESSFUL (0).  
***  


## Comments:
Specifying CDS_TEST as <Em>dwflags</Em> allows an application to determine which graphics modes are actually valid, without causing the system to change to that graphics mode.  
  
To change the settings of a specified display device, use the ChangeDisplaySettingsEx function.  
  
***  

