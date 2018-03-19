[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using MessageBeep

## Before you begin:
See also:

* [Using Beep and Sleep](sample_240.md)  
* [How to play MIDI notes](sample_537.md)  
  
***  


## Code:
```foxpro  
#DEFINE MB_OK                0
#DEFINE MB_OKCANCEL          1
#DEFINE MB_ICONHAND         16
#DEFINE MB_ICONQUESTION     32
#DEFINE MB_ICONEXCLAMATION  48
#DEFINE MB_ICONASTERISK     64
#DEFINE MB_ICONMASK        240

DECLARE INTEGER MessageBeep IN "user32" INTEGER wType
	
? MessageBeep (MB_ICONEXCLAMATION)  
```  
***  


## Listed functions:
[MessageBeep](../libraries/user32/MessageBeep.md)  
