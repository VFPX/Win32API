<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : StartDoc
Group: Printing and Print Spooler - Library: gdi32    
***  


#### The StartDoc function starts a print job.
***  


## Code examples:
[How to print FoxPro form](../../samples/sample_158.md)  
[How to print a bitmap file](../../samples/sample_211.md)  
[Printing text with the Escape function](../../samples/sample_357.md)  
[How to print picture stored in enhanced-format metafile (*.emf)](../../samples/sample_405.md)  
[How to print FoxPro form -- II](../../samples/sample_406.md)  
[GDI+: printing image file](../../samples/sample_452.md)  
[GDI+: sending image of FoxPro form to printer](../../samples/sample_455.md)  
[Printing Image File, programmatically set print page orientation to landscape](../../samples/sample_555.md)  

## Declaration:
```foxpro  
int StartDoc(
  HDC hdc,              // handle to DC
  CONST DOCINFO* lpdi   // contains file names
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER StartDoc IN gdi32;
	INTEGER hdc,;
	STRING @ lpdi  
```  
***  


## Parameters:
```txt  
hdc
[in] Handle to the device context for the print job.

lpdi
[in] Pointer to a DOCINFO structure containing the name of the document file and the name of the output file.  
```  
***  


## Return value:
If the function succeeds, the return value is greater than zero. This value is the print job identifier for the document.  
***  

