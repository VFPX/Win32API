<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

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
