[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetTextMetrics
Group: [Font and Text](../../functions_group.md#Font_and_Text)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The GetTextMetrics function fills the specified buffer with the metrics for the currently selected font. 
***  


## Code examples:
[Reading metrics for the currently selected font](../../samples/sample_339.md)  

## Declaration:
```foxpro  
BOOL GetTextMetrics(
	HDC hdc,            // handle to DC
	LPTEXTMETRIC lptm   // text metrics
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetTextMetrics IN gdi32;
	INTEGER   hdc,;
	STRING  @ lptm  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

lptm 
[out] Pointer to the TEXTMETRIC structure that receives the text metrics.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The TEXTMETRIC structure is filled in GetTextMetrics call:  
```cpp
typedef struct tagTEXTMETRIC {   
	LONG tmHeight;   
	LONG tmAscent;   
	LONG tmDescent;   
	LONG tmInternalLeading;   
	LONG tmExternalLeading;   
	LONG tmAveCharWidth;   
	LONG tmMaxCharWidth;   
	LONG tmWeight;   
	LONG tmOverhang;   
	LONG tmDigitizedAspectX;   
	LONG tmDigitizedAspectY;   
	TCHAR tmFirstChar;   
	TCHAR tmLastChar;   
	TCHAR tmDefaultChar;   
	TCHAR tmBreakChar;   
	BYTE tmItalic;   
	BYTE tmUnderlined;   
	BYTE tmStruckOut;   
	BYTE tmPitchAndFamily;   
	BYTE tmCharSet;   
} TEXTMETRIC, *PTEXTMETRIC;
```

***  

