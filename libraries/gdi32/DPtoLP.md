[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DPtoLP
Group: Coordinate Space and Transformation - Library: gdi32    
***  


#### Converts device coordinates into logical coordinates.
***  


## Declaration:
```foxpro  
BOOL DPtoLP(
	HDC hdc,           // handle to device context
	LPPOINT lpPoints,  // array of points
	int nCount         // count of points in array
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DPtoLP IN gdi32;
	INTEGER hdc,;
	STRING @lpPoints,;
	INTEGER nCount  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

lpPoints 
[in/out] Pointer to an array of POINT structures. The x- and y-coordinates contained in each POINT structure will be transformed. 

nCount 
[in] Specifies the number of points in the array.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The conversion depends on the mapping mode of the device context, the settings of the origins and extents for the window and viewport, and the world transformation.   
  
<div class="precode">LOCAL hWindow, hDC, cBuffer  
hWindow = _screen.HWnd  
hDC = GetWindowDC(hWindow)  
  
cBuffer = num2dword(100) + num2dword(100)  
? DPtoLP(hDC, @cBuffer, 1)  
  
? buf2dword(SUBSTR(cBuffer,1,4)),;  
	buf2dword(SUBSTR(cBuffer,5,4))  
  
= ReleaseDC(hWindow, hDC)  
</div>  
  
See also: LPtoDP   
  
***  

