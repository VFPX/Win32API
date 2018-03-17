<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Using Beep and Sleep functions to make the old tin <s>buzz</s> sing (WinNT only?)

## Before you begin:
See also:

* [Using MessageBeep](sample_037.md)  
* [How to play MIDI notes](sample_537.md)  
  
***  


## Code:
```foxpro  
DECLARE Sleep IN kernel32 INTEGER dwMilliseconds

DECLARE INTEGER Beep IN kernel32;
	INTEGER dwFreq, INTEGER dwDur

= Beep1(100)
= Beep1(300)
= Beep1(200)
= Beep1(300)
= Beep1(400)
= Beep1(100)
= Beep1(300)
= Beep1(500)

PROCEDURE  Beep1(lnFreq)
	= Beep(lnFreq, 90)
	= Sleep (20)  
```  
***  


## Listed functions:
[Beep](../libraries/kernel32/Beep.md)  
[Sleep](../libraries/kernel32/Sleep.md)  
