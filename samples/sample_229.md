[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Terminating VFP application using the FatalAppExit

## Code:
```foxpro  
DECLARE FatalAppExit IN kernel32;
	INTEGER uAction, STRING lpMessageText

= FatalAppExit (0, "The application has just decided to quit.")  
```  
***  


## Listed functions:
[FatalAppExit](../libraries/kernel32/FatalAppExit.md)  
