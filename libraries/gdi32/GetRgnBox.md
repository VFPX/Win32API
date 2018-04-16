[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetRgnBox
Group: [Region](../../functions_group.md#Region)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Retrieves the bounding rectangle of the specified region.
***  


## Code examples:
[Finding parameters for the region specified](../../samples/sample_124.md)  

## Declaration:
```foxpro  
int GetRgnBox(
  HRGN hrgn,   // handle to a region
  LPRECT lprc  // bounding rectangle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetRgnBox IN gdi32;
	INTEGER hrgn,;
	STRING @ lprc  
```  
***  


## Parameters:
hrgn 
[in] Handle to the region. 

lprc 
[out] Pointer to a RECT structure that receives the bounding rectangle in logical units.  
***  


## Return value:
The return value specifies the region"s complexity:
```txt
#DEFINE NULLREGION     1
#DEFINE SIMPLEREGION   2
#DEFINE COMPLEXREGION  3
#DEFINE RGN_ERROR      0
```
  
***  

