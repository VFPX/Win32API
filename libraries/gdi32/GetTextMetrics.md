<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetTextMetrics
Group: Font and Text - Library: gdi32    
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
```txt  
hdc
[in] Handle to the device context.

lptm
[out] Pointer to the TEXTMETRIC structure that receives the text metrics.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The TEXTMETRIC structure is filled in GetTextMetrics call:  
<div class="precode">typedef struct tagTEXTMETRIC {   
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
</div>  
  
***  

