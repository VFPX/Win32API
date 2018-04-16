[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdiSetBatchLimit
Group: [Painting and Drawing](../../functions_group.md#Painting_and_Drawing)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Sets the maximum number of function calls that can be accumulated in the calling thread`s current batch. The system flushes the current batch whenever this limit is exceeded. 
***  


## Declaration:
```foxpro  
DWORD GdiSetBatchLimit(
	DWORD dwLimit   // batch limit
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdiSetBatchLimit IN gdi32;
	LONG dwLimit  
```  
***  


## Parameters:
dwLimit 
[in] Specifies the batch limit to be set. A value of 0 sets the default limit. A value of 1 disables batching. 
  
***  


## Return value:
If the function succeeds, the return value is the previous batch limit ( > 0).  
***  


## Comments:
Only GDI drawing functions that return Boolean values can be accumulated in the current batch; calls to any other GDI functions immediately flush the current batch. Exceeding the batch limit or calling the GdiFlush function also flushes the current batch.  
  
The batch limit is maintained for each thread separately. In order to completely disable batching, call GdiSetBatchLimit(1) during the initialization of each thread.   
  
When started the Visual FoxPro 09.00.0000.5815 for Windows sets the batch limit to 20.  
  
See also: .  
* <a href="http://fox.wikis.com/wc.dll?Wiki~VistaAeroIssues">Vista Aero Issues</a> on FoxPro Wiki.  
* <a href="http://www.west-wind.com/wconnect/weblog/ShowEntry.blog?id=571">Visual FoxPro and Vista RTM</a> as blogged by Rick Strahl  
  
***  

