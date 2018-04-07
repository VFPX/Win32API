[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetMouseMovePointsEx
Group: [Mouse Input](../../functions_group.md#Mouse_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves a history of up to 64 previous coordinates of the mouse or pen.
***  


## Code examples:
[GDI+: Implementing image scrolling with inertia](../../samples/sample_595.md)  

## Declaration:
```foxpro  
int WINAPI GetMouseMovePointsEx(
  _In_   UINT cbSize,
  _In_   LPMOUSEMOVEPOINT lppt,
  _Out_  LPMOUSEMOVEPOINT lpptBuf,
  _In_   int nBufPoints,
  _In_   DWORD resolution
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMouseMovePointsEx IN user32;
	INTEGER cbSize,;
	STRING @lppt,;
	STRING @lpptBuf,;
	INTEGER nBufPoints,;
	INTEGER resolution  
```  
***  


## Parameters:
cbSize [in]
The size, in bytes, of the MOUSEMOVEPOINT structure.

lppt [in]
A pointer to a MOUSEMOVEPOINT structure containing valid mouse coordinates (in screen coordinates). It may also contain a time stamp.

lpptBuf [out]
A pointer to a buffer that will receive the points. It should be at least cbSize* nBufPoints in size.

nBufPoints [in]
The number of points to be retrieved (up to 64).

resolution [in]
The resolution desired: GMMP_USE_DISPLAY_POINTS (1), GMMP_USE_HIGH_RESOLUTION_POINTS (2)  
***  


## Return value:
If the function succeeds, the return value is the number of points in the buffer.  
***  


## Comments:
See also: [GetCursorPos](../user32/GetCursorPos.md), [GetTickCount](../kernel32/GetTickCount.md).  
  
***  

