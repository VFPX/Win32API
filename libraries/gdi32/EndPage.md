[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EndPage
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The EndPage function notifies the device that the application has finished writing to a page. This function is typically used to direct the device driver to advance to a new page.
***  


## Code examples:
[How to print FoxPro form](../../samples/sample_158.md)  
[How to print a bitmap file](../../samples/sample_211.md)  
[How to print picture stored in enhanced-format metafile (*.emf)](../../samples/sample_405.md)  
[How to print FoxPro form -- II](../../samples/sample_406.md)  
[GDI+: printing image file](../../samples/sample_452.md)  
[GDI+: sending image of FoxPro form to printer](../../samples/sample_455.md)  
[Printing Image File, programmatically set print page orientation to landscape](../../samples/sample_555.md)  

## Declaration:
```foxpro  
int EndPage(
  HDC hdc   // handle to DC
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EndPage IN gdi32;
	INTEGER hdc  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context for the print job.  
***  


## Return value:
If the function succeeds, the return value is greater than zero.  
***  

