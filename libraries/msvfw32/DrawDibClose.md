[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DrawDibClose
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [msvfw32](../../Libraries.md#msvfw32)  
***  


#### The DrawDibClose function closes a DrawDib DC and frees the resources DrawDib allocated for it.
***  


## Code examples:
[How to play AVI file on the _screen](../../samples/sample_430.md)  

## Declaration:
```foxpro  
BOOL DrawDibClose(
  HDRAWDIB hdd
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DrawDibClose IN msvfw32;
	INTEGER hdd  
```  
***  


## Parameters:
hdd
Handle to a DrawDib DC.
  
***  


## Return value:
Returns TRUE if successful or FALSE otherwise.  
***  

