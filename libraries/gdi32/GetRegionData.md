
## Function name : GetRegionData
Group: Region - Library: gdi32    
***  


#### Fills the specified buffer with data describing a region. This data includes the dimensions of the rectangles that make up the region.
***  


## Code examples:
[Finding parameters for the region specified](../../samples/sample_124.md)  

## Declaration:
```foxpro  
DWORD GetRegionData(
  HRGN hRgn,            // handle to region
  DWORD dwCount,        // size of region data buffer
  LPRGNDATA lpRgnData   // region data buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetRegionData IN gdi32;
	INTEGER hRgn,;
	INTEGER dwCount,;
	STRING @ lpRgnData  
```  
***  


## Parameters:
hRgn 
[in] Handle to the region. 

dwCount 
[in] Specifies the size, in bytes, of the lpRgnData buffer. 

lpRgnData 
[out] Pointer to a RGNDATA structure that receives the information.  
***  


## Return value:
If the function succeeds and dwCount specifies an adequate number of bytes, the return value is always dwCount.  
***  


## Comments:
A quite usefull function if you need to know geometrical parameters for a region defined by a handle.  
  
***  

