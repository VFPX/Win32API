<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : Polygon
Group: Filled Shape - Library: gdi32    
***  


#### The Polygon function draws a polygon consisting of two or more vertices connected by straight lines. The polygon is outlined by using the current pen and filled by using the current brush and polygon fill mode.
***  


## Code examples:
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  

## Declaration:
```foxpro  
BOOL Polygon(
  HDC hdc,               // handle to DC
  CONST POINT *lpPoints, // polygon vertices
  int nCount             // count of vertices
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER Polygon IN gdi32;
	INTEGER   hdc,;
	STRING  @ lpPoints,;
	INTEGER   nCount  
```  
***  


## Parameters:
```txt  
hdc
[in] Handle to the device context.

lpPoints
[in] Pointer to an array of POINT structures that specify the vertices of the polygon, in logical coordinates.

nCount
[in] Specifies the number of vertices in the array. This value must be greater than or equal to 2.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

