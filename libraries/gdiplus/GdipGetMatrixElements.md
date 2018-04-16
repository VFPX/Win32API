[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetMatrixElements
Group: [GDI+ Matrix](../../functions_group.md#GDIplus_Matrix)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets the elements of this matrix. The elements are placed in an array in the order m11, m12, m21, m22, m31, m32, where mij denotes the element in row i, column j.

***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetMatrixElements(
	GDIPCONST GpMatrix *matrix,
	REAL *matrixOut
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetMatrixElements IN gdiplus;
	INTEGER matrix,;
	STRING @matrixOut  
```  
***  


## Parameters:
matrix
[in] Handle to a Matrix object.

matrixOut
[out] Pointer to an array that receives the matrix elements. The size of the array should be 6 �sizeof( REAL).   
***  


## Return value:
Returns GpStatus value; 0 means success.  
***  


## Comments:
```foxpro
cCoords = REPLICATE(CHR(0), 24)  
IF GdipGetMatrixElements(m.hmatrix, @m.cCoords) = 0  
	m11 = Float2Int(buf2dword(SUBSTR(m.cCoords, 1,4)))  
	m12 = Float2Int(buf2dword(SUBSTR(m.cCoords, 5,4)))  
	m21 = Float2Int(buf2dword(SUBSTR(m.cCoords, 9,4)))  
	m22 = Float2Int(buf2dword(SUBSTR(m.cCoords, 13,4)))  
	dx = Float2Int(buf2dword(SUBSTR(m.cCoords, 17,4)))  
	dy = Float2Int(buf2dword(SUBSTR(m.cCoords, 21,4)))  
ENDIF
```
See also: [GdipSetMatrixElements](../gdiplus/GdipSetMatrixElements.md).  
  
***  

