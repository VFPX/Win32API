[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DrawEdge
Group: [Painting and Drawing](../../functions_group.md#Painting_and_Drawing)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The DrawEdge function draws one or more edges of rectangle.
***  


## Code examples:
[Drawing a rectangle using Windows regular edges and borders](../../samples/sample_256.md)  

## Declaration:
```foxpro  
BOOL DrawEdge(
  HDC hdc,       // handle to device context
  LPRECT qrc,    // rectangle coordinates
  UINT edge,     // type of edge
  UINT grfFlags  // type of border
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DrawEdge IN user32;
	INTEGER   hdc,;
	STRING  @ qrc,;
	INTEGER   edge,;
	INTEGER   grfFlags  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

qrc 
[in/out] Pointer to a RECT structure that contains the logical coordinates of the rectangle. 

edge 
[in] Specifies the type of inner and outer edges to draw. 

grfFlags 
[in] Specifies the type of border. 

  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

