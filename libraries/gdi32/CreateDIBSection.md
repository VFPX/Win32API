[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateDIBSection
Group: [Bitmap](../../functions_group.md#Bitmap)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Creates a DIB that applications can write to directly.
***  


## Declaration:
```foxpro  
HBITMAP CreateDIBSection(
  __in   HDC hdc,
  __in   const BITMAPINFO *pbmi,
  __in   UINT iUsage,
  __out  VOID **ppvBits,
  __in   HANDLE hSection,
  __in   DWORD dwOffset
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateDIBSection IN gdi32;
	INTEGER hdc,;
	STRING @pbmi,;
	LONG iUsage,;
	INTEGER @ppvBits,;
	INTEGER hSection,;
	LONG dwOffset  
```  
***  


## Parameters:
hdc [in] 
A handle to a device context. If the value of iUsage is DIB_PAL_COLORS, the function uses this device context"s logical palette to initialize the DIB colors.

pbmi [in] 
A pointer to a BITMAPINFO structure that specifies various attributes of the DIB, including the bitmap dimensions and colors.

iUsage [in] 
The type of data contained in the bmiColors array member of the BITMAPINFO structure pointed to by pbmi (either logical palette indexes or literal RGB values).

ppvBits [out] 
A pointer to a variable that receives a pointer to the location of the DIB bit values.

hSection [in] 
A handle to a file-mapping object that the function will use to create the DIB. This parameter can be NULL.

dwOffset [in] 
The offset from the beginning of the file-mapping object referenced by hSection where storage for the bitmap bit values is to begin. This value is ignored if hSection is NULL.   
***  


## Return value:
If the function succeeds, the return value is a handle to the newly created DIB, and *ppvBits points to the bitmap bit values.

If the function fails, the return value is NULL, and *ppvBits is NULL.
  
***  


## Comments:
If hSection is NULL, the system allocates memory for the DIB. The system closes the handle to that memory when you later delete the DIB by calling the DeleteObject function.  
  
***  

