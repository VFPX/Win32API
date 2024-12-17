[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSystemMetrics
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves various system metrics (widths and heights of display elements) and system configuration settings.

***  


## Code examples:
[Creating irregularly shaped FoxPro form using transparency color key](../../samples/sample_033.md)  
[Retrieving various system metrics](../../samples/sample_079.md)  
[Clipping mouse cursor area](../../samples/sample_080.md)  
[An alternative way of setting Form.Closable to False](../../samples/sample_127.md)  
[Round FoxPro form](../../samples/sample_143.md)  
[Tracking mouse movement to detect when to start dragging](../../samples/sample_281.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[How to draw custom Window Caption on FoxPro form](../../samples/sample_499.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  
[GDI+: how to make VFP controls visually shake and shudder](../../samples/sample_526.md)  
[How to make a VFP form fading out when released (GDI+ version)](../../samples/sample_527.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  

## Declaration:
```foxpro  
int GetSystemMetrics(
  int nIndex   // system metric or configuration setting
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetSystemMetrics IN user32 INTEGER nIndex  
```  
***  


## Parameters:
nIndex 
[in] Specifies the system metric or configuration setting to retrieve.  
***  


## Return value:
If the function succeeds, the return value is the requested system metric or configuration setting.  
***  


## Comments:
All dimensions retrieved by GetSystemMetrics are in pixels.  
  
The SM_REMOTESESSION system metric is used in a Terminal Services environment. If the calling process is associated with a Terminal Services client session, the return value is nonzero.  
  
The SM_REMOTECONTROL is used in a Terminal Services environment. Its value is nonzero if the current session is remotely controlled; otherwise, 0.  
  
Read post <a href="http://blogs.msdn.com/calvin_hsia/archive/2006/01/11/511639.aspx">Detecting Workstation state changes</a> in Calvin Hsia's weblog.  
  
* * *  
System Metrics Foundation Class included in VFP8 and 9 installations provides access to system metric information as mousewheel present, number of mouse buttons, and number of monitors are provided with the class, but any valid system metric can be queried.  
  
See also: [SystemParametersInfo](../user32/SystemParametersInfo.md), [SYSMETRIC( )](http://msdn2.microsoft.com/en-us/library/39ddf2h2(VS.80).aspx).  
  
* * *  
Allegedly, both GetSystemMetrics(SM_CXSIZE) and GetTitleBarInfo <a href="http://social.msdn.microsoft.com/Forums/en-US/windowsuidevelopment/thread/98326a7e-e1e1-4e05-bf58-5b2d324c7604">return wrong values for Vista Aero</a>. For the latter, sending the WM_GETTITLEBARINFOEX suggested to be a replacement.  
  
[Vista Aero Issues](http://fox.wikis.com/wc.dll?Wiki~VistaAeroIssues) on FoxPro Wiki.  
  
***  

