[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IsClipboardFormatAvailable
Group: [Clipboard](../../functions_group.md#Clipboard)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The IsClipboardFormatAvailable function determines whether the clipboard contains data in the specified format
***  


## Code examples:
[Getting a bit more than the _CLIPTEXT offers](../../samples/sample_278.md)  
[Converting Unicode data from the Clipboard to a character string using a given code page](../../samples/sample_316.md)  
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  
[GDI+: Storing content of the Clipboard to a bitmap file](../../samples/sample_475.md)  

## Declaration:
```foxpro  
BOOL IsClipboardFormatAvailable(
	UINT  format   // clipboard format
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsClipboardFormatAvailable IN user32;
	INTEGER wFormat  
```  
***  


## Parameters:
format
Specifies a standard or registered clipboard format

For a description of the clipboard formats, see the SetClipboardData function  
***  


## Return value:
If the clipboard format is available, the return value is TRUE  
***  


## Comments:
Compare result obtained from this function to zero to get TRUE or FALSE.   
  
As far as I tested this function, if being called with a particular clipboard format code, it returns the same code as a successful result or zero if data in this format is not available.  
  
***  

