<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetRgnBox
Group: Region - Library: gdi32    
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
```txt  
hrgn
[in] Handle to the region.

lprc
[out] Pointer to a RECT structure that receives the bounding rectangle in logical units.  
```  
***  


## Return value:
The return value specifies the region"s complexity:
#DEFINE NULLREGION     1
#DEFINE SIMPLEREGION   2
#DEFINE COMPLEXREGION  3
#DEFINE RGN_ERROR      0
  
***  

