[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DrawDibOpen
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [msvfw32](../../Libraries.md#msvfw32)  
***  


#### The DrawDibOpen function opens the DrawDib library for use and creates a DrawDib DC for drawing.
***  


## Code examples:
[How to play AVI file on the _screen](../../samples/sample_430.md)  

## Declaration:
```foxpro  
HDRAWDIB DrawDibOpen(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DrawDibOpen IN msvfw32  
```  
***  


## Parameters:
This function takes no parameters.  
***  


## Return value:
Returns a handle to a DrawDib DC if successful or NULL otherwise.  
***  


## Comments:
When drawing multiple DIBs <Em>simultaneously</Em>, create a DrawDib DC for each of the images that will be simultaneously on-screen.  
  
***  

