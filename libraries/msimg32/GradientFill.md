[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GradientFill
Group: [Bitmap](../../functions_group.md#Bitmap)  -  Library: [msimg32](../../Libraries.md#msimg32)  
***  


#### The GradientFill function fills rectangle and triangle structures. 
***  


## Code examples:
[Using the GradientFill function](../../samples/sample_353.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  

## Declaration:
```foxpro  
BOOL GradientFill(
  HDC hdc,                   // handle to DC
  PTRIVERTEX pVertex,        // array of vertices
  ULONG dwNumVertex,         // number of vertices
  PVOID pMesh,               // array of gradients
  ULONG dwNumMesh,           // size of gradient array
  ULONG dwMode               // gradient fill mode
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GradientFill IN Msimg32;
	INTEGER  hdc,;
	STRING @ pVertex,;
	LONG     dwNumVertex,;
	STRING @ pMesh,;
	LONG     dwNumMesh,;
	LONG     dwMode  
```  
***  


## Parameters:
hdc 
[in] Handle to the destination device context. 

pVertex 
[in] Pointer to an array of TRIVERTEX structures that each define a triangle vertex. 

dwNumVertex 
[in] The number of vertices in pVertex. 

pMesh 
[in] Array of GRADIENT_TRIANGLE structures in triangle mode, or an array of GRADIENT_RECT structures in rectangle mode. 

dwNumMesh 
[in] The number of elements (triangles or rectangles) in pMesh. 

dwMode 
[in] Specifies gradient fill mode. This parameter can be one of the following values.   
***  


## Return value:
If the function succeeds, the return value is TRUE.  
***  


## Comments:
To add smooth shading to a rectangle, call GradientFill with the upper-left and lower-right coordinates of the rectangle. There are two shading modes used when drawing a rectangle. In horizontal mode, the rectangle is shaded from left-to-right. In vertical mode, the rectangle is shaded from top-to-bottom.   
  
***  

