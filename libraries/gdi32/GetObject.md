[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetObject
Group: [Device Context](../../functions_group.md#Device_Context)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The GetObject function retrieves information for the specified graphics object.
***  


## Code examples:
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[Using the LoadImage function to have a bitmap file loaded and displayed on VFP main window](../../samples/sample_210.md)  
[How to print a bitmap file](../../samples/sample_211.md)  
[Drawing Windows predefined bitmaps using the LoadBitmap functions](../../samples/sample_253.md)  
[Displaying bitmap using the AlphaBlend function](../../samples/sample_293.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Bitmap Class for Visual FoxPro application](../../samples/sample_295.md)  
[Displaying animated images on FoxPro form with BitBlt and StretchBlt functions](../../samples/sample_355.md)  
[How to convert a bitmap file to monochrome format (1 bpp)](../../samples/sample_493.md)  
[Converting image file to .ICO file](../../samples/sample_503.md)  

## Declaration:
```foxpro  
int GetObject(
  HGDIOBJ hgdiobj,  // handle to graphics object
  int cbBuffer,     // size of buffer for object info
  LPVOID lpvObject  // buffer for object info
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetObject IN gdi32;
AS GetObjectA;
	INTEGER   hgdiobj,;
	INTEGER   cbBuffer,;
	STRING  @ lpvObject
  
```  
***  


## Parameters:
hgdiobj 
[in] Handle to the graphics object of interest. 

cbBuffer 
[in] Specifies the number of bytes of information to be written to the buffer. 

lpvObject 
[out] Pointer to a buffer that receives the information about the specified graphics object.   
***  


## Return value:
If the function succeeds, and lpvObject is a valid pointer, the return value is the number of bytes stored into the buffer.  
***  


## Comments:
Notice that GetObject is a name of a native VFP function with different purpose and interface. So the name GetObject ia already reserved. That is why this external function is declared with an alias.  
  
***  

