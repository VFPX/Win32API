[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CombineRgn
Group: [Region](../../functions_group.md#Region)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The CombineRgn function combines two regions and stores the result in a third region. The two regions are combined according to the specified mode.
***  


## Code examples:
[How to create transparent areas inside a form -- punching holes in the form](../../samples/sample_126.md)  
[An alternative way of setting Form.Closable to False](../../samples/sample_127.md)  
[How to draw custom Window Caption on FoxPro form](../../samples/sample_499.md)  

## Declaration:
```foxpro  
int CombineRgn(
  HRGN hrgnDest,      // handle to destination region
  HRGN hrgnSrc1,      // handle to source region
  HRGN hrgnSrc2,      // handle to source region
  int fnCombineMode   // region combining mode
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CombineRgn IN gdi32;
	INTEGER hrgnDest,;
	INTEGER hrgnSrc1,;
	INTEGER hrgnSrc2,;
	INTEGER fnCombineMode  
```  
***  


## Parameters:
hrgnDest 
[in] Handle to a new region with dimensions defined by combining two other regions. (This region must exist before CombineRgn is called.) 

hrgnSrc1 
[in] Handle to the first of two regions to be combined. 

hrgnSrc2 
[in] Handle to the second of two regions to be combined. 

fnCombineMode 
[in] Specifies a mode indicating how the two regions will be combined.  
***  


## Return value:
The return value specifies the type of the resulting region. It can be one of the following values.  
***  

