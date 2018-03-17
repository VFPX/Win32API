<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : DrawEdge
Group: Painting and Drawing - Library: user32    
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
```txt  
hdc
[in] Handle to the device context.

qrc
[in/out] Pointer to a RECT structure that contains the logical coordinates of the rectangle.

edge
[in] Specifies the type of inner and outer edges to draw.

grfFlags
[in] Specifies the type of border.

  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

