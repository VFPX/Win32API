[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetEnhMetaFileHeader
Group: [Metafile](../../functions_group.md#Metafile)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The GetEnhMetaFileHeader function retrieves the record containing the header for the specified enhanced-format metafile.
***  


## Code examples:
[How to display picture stored in enhanced-format metafile (*.emf)](../../samples/sample_403.md)  
[How to print picture stored in enhanced-format metafile (*.emf)](../../samples/sample_405.md)  

## Declaration:
```foxpro  
UINT GetEnhMetaFileHeader(
  HENHMETAFILE hemf,      // handle to enhanced metafile
  UINT cbBuffer,          // size of buffer
  LPENHMETAHEADER lpemh   // data buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetEnhMetaFileHeader In gdi32;
	INTEGER   hemf,;
	INTEGER   cbBuffer,;
	STRING  @ lpemh
  
```  
***  


## Parameters:
hemf 
[in] Handle to the enhanced metafile for which the header is to be retrieved. 

cbBuffer 
[in] Specifies the size, in bytes, of the buffer to receive the data. Only this many bytes will be copied. 

lpemh 
[out] Pointer to an ENHMETAHEADER structure that receives the header record.   
***  


## Return value:
If the function succeeds and the structure pointer is NULL, the return value is the size of the record that contains the header; if the structure pointer is a valid pointer, the return value is the number of bytes copied. Otherwise, it is zero.  
***  

