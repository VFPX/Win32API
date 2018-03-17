<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : DrawDibClose
Group: Windows Multimedia - Library: msvfw32    
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
```txt  
hdd
Handle to a DrawDib DC.
  
```  
***  


## Return value:
Returns TRUE if successful or FALSE otherwise.  
***  

