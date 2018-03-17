<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetBoundsRect
Group: Painting and Drawing - Library: gdi32    
***  


#### The GetBoundsRect function obtains the current accumulated bounding rectangle for a specified device context. The system maintains an accumulated bounding rectangle for each application. An application can retrieve and set this rectangle.
***  


## Code examples:
[Obtaining the bounding rectangle for the specified device context](../../samples/sample_237.md)  

## Declaration:
```foxpro  
UINT GetBoundsRect(
  HDC hdc,            // handle to device context
  LPRECT lprcBounds,  // bounding rectangle
  UINT flags          // function options
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetBoundsRect IN gdi32;
	INTEGER   hdc,;
	STRING  @ lprcBounds,;
	INTEGER   flags  
```  
***  


## Parameters:
```txt  
hdc
[in] Handle to the device context whose bounding rectangle the function will return.

lprcBounds
[out] Pointer to the RECT structure that will receive the current bounding rectangle.

flags
[in] Specifies how the GetBoundsRect function will behave.  
```  
***  


## Return value:
The return value specifies the state of the accumulated bounding rectangle; it can be one of the following values.   
***  

