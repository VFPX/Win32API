[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetWorldTransform
Group: [Coordinate Space and Transformation](../../functions_group.md#Coordinate_Space_and_Transformation)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Retrieves the current world-space to page-space transformation.
***  


## Declaration:
```foxpro  
BOOL GetWorldTransform(
	HDC hdc,         // handle to device context
	LPXFORM lpXform  // transformation
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetWorldTransform IN gdi32;
	INTEGER hdc,;
	STRING @lpXform  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

lpXform 
[out] Pointer to an XFORM structure that receives the current world-space to page-space transformation. 
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Conversion function <Strong>float2int</Strong> is described in <a href="http://fox.wikis.com/wc.dll?Wiki~VFPFloatingPointDataType">VFP Floating Point Data Type</a> topic on FoxPro Wiki.  
  
The SetWorldTransform function will fail unless the graphics mode for the given device context has been set to GM_ADVANCED by previously calling the SetGraphicsMode function.  
  
See also: [SetWorldTransform](https://msdn.microsoft.com/en-us/library/windows/desktop/dd145104%28v=vs.85%29.aspx?f=255&MSPPError=-2147217396).  
  
***  

